#ifndef MEDALHA_H
#define MEDALHA_H

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

void cadastrar_medalha();
void listar_medalhas();
void pesquisar_medalha();
void alterar_medalha();
void excluir_medalha();
void carregar_dados_iniciais(const char *filename);
void salvar_dados(const char *filename);
void exportar_para_csv(const char *filename);

#endif
