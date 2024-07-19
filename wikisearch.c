#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <jansson.h>
#include "wikisearch.h"

#define TAMANHO_BUFFER  (256 * 1024)  // 256 KB
#define URL_API_WIKI 

// Estrutura para armazenar um bloco de memória dinâmica
struct MemoriaStruct {
    char *memoria;    // Ponteiro para a memória alocada
    size_t tamanho;   // Tamanho atual da memória
};

// Função de callback para escrever conteúdo na memória
static size_t EscreverCallback(void *conteudo, size_t tamanho, size_t nmemb, void *userp) {
    size_t tamanho_real = tamanho * nmemb;
    struct MemoriaStruct *mem = (struct MemoriaStruct *)userp;

    // Realocar memória para acomodar novos dados
    char *ptr = realloc(mem->memoria, mem->tamanho + tamanho_real + 1);
    if(ptr == NULL) {
        fprintf(stderr, "memória insuficiente (realloc retornou NULL)\n");
        return 0;
    }

    // Copiar os dados recebidos para a memória alocada
    mem->memoria = ptr;
    memcpy(&(mem->memoria[mem->tamanho]), conteudo, tamanho_real);
    mem->tamanho += tamanho_real;
    mem->memoria[mem->tamanho] = 0;

    return tamanho_real;
}

// Função para buscar informações relacionadas ao atleta na Wikipedia
char* buscar_wikipedia(const char *atleta) {
    CURL *curl_handle;
    CURLcode res;

    struct MemoriaStruct chunk;
    chunk.memoria = malloc(1);   // Alocar memória inicial
    chunk.tamanho = 0;

    curl_global_init(CURL_GLOBAL_ALL);   // Inicializar libcurl globalmente

    curl_handle = curl_easy_init();   // Inicializar sessão do curl
    if(curl_handle) {
        char *atleta_codificado = curl_easy_escape(curl_handle, atleta, 0);
        if (atleta_codificado) {
            char url[TAMANHO_BUFFER];
            snprintf(url, sizeof(url), "%s%s", URL_API_WIKI, atleta_codificado);

            curl_easy_setopt(curl_handle, CURLOPT_URL, url);
            curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, EscreverCallback);
            curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

            res = curl_easy_perform(curl_handle);   // Realizar a requisição

            if(res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() falhou: %s\n", curl_easy_strerror(res));
                free(chunk.memoria);
                chunk.memoria = NULL;
            } else {
                printf("%lu bytes recuperados\n", (unsigned long)chunk.tamanho);
            }

            curl_free(atleta_codificado);   // Liberar string codificada alocada
        } else {
            fprintf(stderr, "curl_easy_escape() falhou\n");
        }

        curl_easy_cleanup(curl_handle);   // Limpar sessão do curl
    }

    curl_global_cleanup();   // Limpar libcurl globalmente

    return chunk.memoria;   // Retornar bloco de memória alocada
}

// Função para exibir os resultados da busca obtidos da API da Wikipedia
void exibir_resultados_wikipedia(const char *json_resposta) {
    json_t *root;
    json_error_t erro;
    root = json_loads(json_resposta, 0, &erro);   // Parsear resposta JSON

    if (!root) {
        fprintf(stderr, "erro: na linha %d: %s\n", erro.line, erro.text);
        return;
    }

    json_t *query = json_object_get(root, "query");
    if (!json_is_object(query)) {
        fprintf(stderr, "erro: o objeto 'query' não é um objeto\n");
        json_decref(root);   // Decrementar contagem de referência
        return;
    }

    json_t *search = json_object_get(query, "search");
    if (!json_is_array(search)) {
        fprintf(stderr, "erro: o objeto 'search' não é um array\n");
        json_decref(root);   // Decrementar contagem de referência
        return;
    }

    // Limitar a exibição a no máximo 3 resultados
    size_t num_resultados = json_array_size(search);
    size_t num_a_exibir = num_resultados > 3 ? 3 : num_resultados;

    for (size_t indice = 0; indice < num_a_exibir; ++indice) {
        json_t *valor = json_array_get(search, indice);
        if (json_is_object(valor)) {
            json_t *titulo = json_object_get(valor, "title");
            json_t *trecho = json_object_get(valor, "snippet");
            if (json_is_string(titulo) && json_is_string(trecho)) {
                const char *texto_titulo = json_string_value(titulo);
                const char *texto_trecho = json_string_value(trecho);
                printf("%zu: %s\n   %s\n", indice + 1, texto_titulo, texto_trecho);
            }
        } else {
            fprintf(stderr, "erro: o resultado no índice %zu não é um objeto\n", indice);
        }
    }

    json_decref(root);   // Decrementar contagem de referência
}


// Função para recuperar a URL da Wikipedia para o resultado de busca selecionado
char* obter_url_wikipedia(const char *json_resposta, size_t selecao) {
    CURL *curl_handle = curl_easy_init();   // Inicializar sessão do curl
    if (!curl_handle) {
        fprintf(stderr, "erro: falha ao inicializar o curl\n");
        return NULL;
    }

    json_t *root;
    json_error_t erro;
    root = json_loads(json_resposta, 0, &erro);   // Parsear resposta JSON

    if(!root) {
        fprintf(stderr, "erro: na linha %d: %s\n", erro.line, erro.text);
        return NULL;
    }

    json_t *query = json_object_get(root, "query");
    if(!json_is_object(query)) {
        fprintf(stderr, "erro: o objeto 'query' não é um objeto\n");
        json_decref(root);   // Decrementar contagem de referência
        return NULL;
    }

    json_t *search = json_object_get(query, "search");
    if(!json_is_array(search)) {
        fprintf(stderr, "erro: o objeto 'search' não é um array\n");
        json_decref(root);   // Decrementar contagem de referência
        return NULL;
    }

    json_t *valor = json_array_get(search, selecao - 1);
    if(!json_is_object(valor)) {
        fprintf(stderr, "erro: o resultado selecionado não é um objeto\n");
        json_decref(root);   // Decrementar contagem de referência
        return NULL;
    }

    json_t *titulo = json_object_get(valor, "title");
    if(!json_is_string(titulo)) {
        fprintf(stderr, "erro: o título não é uma string\n");
        json_decref(root);   // Decrementar contagem de referência
        return NULL;
    }

    const char *texto_titulo = json_string_value(titulo);
    
    // Alocar memória para o título formatado
    char texto_formatado[strlen(texto_titulo) + 1];
    strcpy(texto_formatado, texto_titulo);

    // Substituir espaços por underline
    for (size_t i = 0; i < strlen(texto_formatado); i++) {
        if (texto_formatado[i] == ' ') {
            texto_formatado[i] = '_';
        }
    }

    char *titulo_codificado = curl_easy_escape(curl_handle, texto_formatado, 0);   
    char *url = malloc(TAMANHO_BUFFER);   // Alocar memoria para url
    snprintf(url, TAMANHO_BUFFER, "https://en.wikipedia.org/wiki/%s", titulo_codificado);   // Formato da url da wikipedia
    curl_free(titulo_codificado);   // Limpa a string codificada

    curl_easy_cleanup(curl_handle);   // Limpa a sessao do curl
    json_decref(root);   // Decrementar contagem de referência

    return url;   // Retorna a url alocada
}
