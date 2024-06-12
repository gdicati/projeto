#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "medalha.h"

void mostrar_menu() {
    printf("Este aqui é o nosso menu de gerenciamento, Digite a opção na qual deseja:\n");
    printf("Quer cadastrar a medalha? 1\n");
    printf("Quer lista medalha? 2\n");
    printf("Quer pesquisar medalha? 3\n");
    printf("Quer alterar medalha? 3\n");
    printf("Quer excluir medalha? 4\n");
    printf("Quer exportar dados para csv? 5\n");
    printf("Quer sair? 7\n");
}

int main() {

    int qtd_atletas;
    Medalha *medalhas_recebidas = vetor_medalhas(&qtd_atletas);

    int opcao;
    carregar_dados_iniciais("medalhas.csv");
    vetor_medalhas(&qtd_atletas);

    do {
        mostrar_menu();
             printf("Este aqui é o nosso menu de gerenciamento, Digite a opção na qual deseja:\n");
             printf("Quer cadastrar a medalha? 1\n");
             printf("Quer lista medalha? 2\n");
             printf("Quer pesquisar medalha? 3\n");
             printf("Quer alterar medalha? 3\n");
            printf("Quer excluir medalha? 4\n");
            printf("Quer exportar dados para csv? 5\n");
            printf("Quer sair? 7\n");
                 scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrar_medalha();
                inserir_atletas(medalhas_recebidas, &qtd_atletas);
                break;
            case 2:
                listar_medalhas();
                exibir_medalhas(medalhas_recebidas, &qtd_atletas);
                break;
            case 3:
                pesquisar_medalha();
                pesquisar_atletas(medalhas_recebidas, &qtd_atletas);
                break;
            case 4:
                alterar_medalha();
                remover_atletas(medalhas_recebidas, &qtd_atletas);
                break;
            case 5:
                excluir_medalha();
                exportar_para_csv(medalhas_recebidas, &qtd_atletas);
                break;
            case 6:
                exportar_para_csv("medalhas_exportadas.csv");
                break;
            case 7:
                salvar_dados("medalhas.dat");
                salvar_dados_bin(medalhas_recebidas, &qtd_atletas);
                printf("Dados salvos. Saindo...\n");
                break;
            default:
                printf("Opção inválida. Ops...Deu erro.\n");
        }
    } while(opcao != 7);
    } while(opcao < 0 || opcao > 6);


    return 0;