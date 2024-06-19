#ifndef MEDALHA_H
#define MEDALHA_H

typedef struct
{
    char genero;
    char modalidade[50];
    char cidade[50];
    int ano;
    char tipo_medalha;
    char nome_atleta[50];
    char pais_origem[50];
    char resultado[50];
    int codigo;
} Medalha;

Medalha *vetor_medalhas(int *qnt_medalhas);
void le_string(char texto[], int tamanho);
void medalhas_continente(Medalha *medalhas, int qnt_medalha);
Medalha *inserir_atletas(Medalha *medalhas, int *qnt_medalhas);
Medalha *remover_atletas(Medalha *medalhas, int *qnt_medalhas);
void pesquisar_atletas(Medalha *medalhas, int qnt_medalhas);
void exibir_medalhas(Medalha *medalhas, int qnt_medalhas);
void salvar_dados_bin(Medalha *medalhas, int qnt_medalhas);
void exportar_para_csv(Medalha *medalhas, int qnt_medalhas);
void carregar_dados_iniciais(const char *filename);

#endif






