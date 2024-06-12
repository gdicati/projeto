#ifndef MEDALHAS_H
#define MEDALHAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct
{
    int ano;
    char pais[50];
    int ouro;
    int prata;
    int bronze;
} MedalhaPorEdicao;

void le_string(char texto[], int tamanho);

Medalha *vetor_medalhas(int *qtd_medalhas);

Medalha *inserir_atletas(Medalha *medalhas, int *qtd_medalhas);

Medalha *remover_atletas(Medalha *medalhas, int *qtd_medalhas);

void pesquisar_atletas(Medalha *medalhas, int qtd_medalhas);

void ranking_medalhas(Medalha medalhas[], int qtd_medalhas);

void exibir_medalhas(Medalha medalhas[], int qtd_medalhas);

void exportar_para_csv(Medalha medalhas[], int qtd_medalhas);

void salvar_dados_bin(Medalha medalhas[], int qtd_medalhas);
#endif // MEDALHAS_H