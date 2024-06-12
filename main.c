#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "medalha.h"

void mostrar_menu()
{
    printf("Este aqui é o nosso menu de gerenciamento, Digite a opção na qual deseja:\n");
    printf("1. Cadastrar medalha\n");
    printf("2. Listar medalhas\n");
    printf("3. Pesquisar medalha\n");
    printf("4. Alterar medalha\n");
    printf("5. Excluir medalha\n");
    printf("6. Exportar dados para CSV\n");
    printf("7. Sair\n");
}

int main()
{
    int qtd_atletas;
    Medalha *medalhas_recebidas = vetor_medalhas(&qtd_atletas);

    int opcao;

    do
    {
        mostrar_menu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            medalhas_recebidas = inserir_atletas(medalhas_recebidas, &qtd_atletas);
            break;
        case 2:
            exibir_medalhas(medalhas_recebidas, qtd_atletas);
            break;
        case 3:
            pesquisar_atletas(medalhas_recebidas, qtd_atletas);
            break;
        case 4:
            medalhas_recebidas = inserir_atletas(medalhas_recebidas, &qtd_atletas);
            break;
        case 5:
            medalhas_recebidas = remover_atletas(medalhas_recebidas, &qtd_atletas);
            break;
        case 6:
            exportar_para_csv(medalhas_recebidas, qtd_atletas);
            break;
        case 7:
            printf("Dados salvos. Saindo...\n");
            break;
        default:
            printf("Opção inválida. Ops...Deu erro.\n");
        }
    } while (opcao != 7);

    salvar_dados_bin(medalhas_recebidas, qtd_atletas);

    free(medalhas_recebidas);

    return 0;
}