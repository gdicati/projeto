#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "medalha.h"

// Lista dinâmica de medalhas
Medalha *medalhas = NULL;
int num_medalhas = 0;

// Funções 
void cadastrar_medalha() {
    Medalha nova;
    nova.codigo = num_medalhas + 1;

    printf("Genero (M/F): ");
    scanf(" %c", &nova.genero);
    printf("Modalidade: ");
    scanf(" %49s[^\n]", nova.modalidade);
    printf("Cidade: ");
    scanf(" %49s", nova.cidade);
    printf("Ano: ");
    scanf("%d", &nova.ano);
    printf("Tipo de Medalha (O/P/B): ");
    scanf(" %c", &nova.tipo_medalha);
    printf("Nome do Atleta: ");
    scanf(" %49s[^\n]", nova.nome_atleta);
    printf("Pais de Origem: ");
    scanf(" %49s[^\n]", nova.pais_origem);
    printf("Tipo de Resultado (T: Tempo, D: Distancia, N: Nota, S: Descricao): ");
    scanf(" %49s[^\n]", &nova.resultado);
  

    medalhas = realloc(medalhas, sizeof(Medalha) * (num_medalhas + 1));
    medalhas[num_medalhas] = nova;
    num_medalhas++;
    
}

void listar_medalhas(){
    for (int i = 0; i < num_medalhas; i++) {
        Medalha m = medalhas[i];
        printf("Codigo: %d, Genero: %c, Modalidade: %s, Cidade: %s, Ano: %d, Tipo Medalha: %c, Nome Atleta: %s, Pais Origem: %s, Resultado: %s \n",
            m.codigo, m.genero, m.modalidade, m.cidade, m.ano, m.tipo_medalha, m.nome_atleta, m.pais_origem, m.resultado);

        }
}
 
void pesquisar_medalha() {
    printf("Deseja pesquisar por codigo(C) ou nome(N)? ");
    char opcao;
    scanf(" %c", &opcao);
    if (opcao == 'C') {
        int codigo;
        printf("Digite o codigo da medalha: ");
        scanf("%d", &codigo);
        
        for (int i = 0; i < num_medalhas; i++) {
            if (medalhas[i].codigo == codigo) {
                Medalha m = medalhas[i];
                printf("Codigo: %d, Genero: %c, Modalidade: %s, Cidade: %s, Ano: %d, Tipo Medalha: %c, Nome Atleta: %s, Pais Origem: %s, Resultado: %s \n",
            m.codigo, m.genero, m.modalidade, m.cidade, m.ano, m.tipo_medalha, m.nome_atleta, m.pais_origem, m.resultado);
            }
        }
    }
    
    else if (opcao == 'N') {
        char nome[50];
        printf("Digite o nome do atleta: ");
        scanf(" %49s[^\n]", nome);
        
    }
}

void alterar_medalha() {
    
}

void excluir_medalha() {
    
}

void carregar_dados_iniciais(const char *filename) {
    
}

void salvar_dados(const char *filename) {
    
}

void exportar_para_csv(const char *filename) {
    
}
