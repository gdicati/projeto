/**
 * @file main.c
 * @author 
 * @brief 
 * @version 0.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "medalha.h"

int main() {

    int qtd_atletas;
    Medalha *medalhas_recebidas = vetor_medalhas(&qtd_atletas);

    int opcao;
    vetor_medalhas(&qtd_atletas);

    do {
            printf("Bem-vindo ao sistema de gerenciamento de medalhas olímpicas!\n");
            printf("1. Cadastrar medalha\n");
            printf("2. Listar medalhas\n");
            printf("3. Pesquisar medalha\n");
            printf("4. Alterar medalha\n");
            printf("5. Excluir medalha\n");
            printf("6. Exportar dados para CSV\n");
            printf("7. Sair\n");
            printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                inserir_atletas(medalhas_recebidas, &qtd_atletas);
                break;
            case 2:
                exibir_medalhas(medalhas_recebidas, &qtd_atletas);
                break;
            case 3:
                pesquisar_atletas(medalhas_recebidas, &qtd_atletas);
                break;
            case 4:
                remover_atletas(medalhas_recebidas, &qtd_atletas);
                break;
            case 5:
                exportar_para_csv(medalhas_recebidas, &qtd_atletas);
                break;
            case 6:
                salvar_dados_bin(medalhas_recebidas, &qtd_atletas);
                printf("Dados salvos. Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while(opcao < 0 || opcao > 6);

    
    return 0;
}