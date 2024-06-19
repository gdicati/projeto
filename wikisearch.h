#ifndef WIKISEARCH_H
#define WIKISEARCH_H
#include <stddef.h>

//todo: n deixar minha chave de api pública o.O

/**
 * @brief Busca informações relacionadas ao atleta especificado na Wikipedia.
 * 
 * @param atleta O nome do atleta a ser buscado.
 * @return char* A resposta JSON da API da Wikipedia, ou NULL em caso de erro.
 */
char* buscar_wikipedia(const char *atleta);

/**
 * @brief Exibe os resultados da busca obtidos da API da Wikipedia.
 * 
 * @param json_resposta A string JSON contendo os resultados da busca.
 */
void exibir_resultados_wikipedia(const char *json_resposta);

/**
 * @brief Recupera a URL da Wikipedia para o resultado de busca selecionado.
 * 
 * @param json_resposta A string JSON contendo os resultados da busca.
 * @param selecao O índice do resultado selecionado.
 * @return char* A URL da Wikipedia para o resultado selecionado, ou NULL em caso de erro.
 */
char* obter_url_wikipedia(const char *json_resposta, size_t selecao);

#endif /* WIKISEARCH_H */
