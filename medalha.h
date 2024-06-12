#ifndef MEDALHA_H
#define MEDALHA_H
#define MAX_MEDALHAS 100


typedef struct {
    int codigo;
    char genero;
    char modalidade[50];
    char cidade[50];
    int ano;
    char tipo_medalha;
    char nome_atleta[50];
    char pais_origem[50];
    char resultado[50]; // Assumindo string para resultado
} Medalha;

Medalha medalhas[MAX_MEDALHAS];
int num_medalhas = 0;

typedef struct
{
    int ano;
    char pais[100];
    int bronze;
    int prata;
    int ouro;
} MedalhaPorEdicao;


Medalha vetor_medalhas(intnumMedalhas);
Medalha inserir_atletas(Medalhamedalhas, int numMedalhas);
Medalharemover_atletas(Medalha medalhas, intnumMedalhas);

void pesquisar_atletas(Medalha medalhas, int numMedalhas);
void ranking_medalhas(Medalhamedalhas, int numMedalhas);
void exibir_medalhas(Medalha medalhas, int numMedalhas);
void salvar_dados_bin(Medalhamedalhas, int numMedalhas);
void exportar_para_csv(Medalha *medalhas, int numMedalhas);

void le_string(char texto[], int tamanho);
#endif