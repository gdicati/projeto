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
#include "utilidades.h"
#include "medalha.h"

void mostrar_menu() {
    printf("Bem-vindo ao sistema de gerenciamento de medalhas olímpicas!\n");
    printf("1. Cadastrar medalha\n");
    printf("2. Listar medalhas\n");
    printf("3. Pesquisar medalha\n");
    printf("4. Alterar medalha\n");
    printf("5. Excluir medalha\n");
    printf("6. Exportar dados para CSV\n");
    printf("7. Sair\n");
}

int main() {
    int opcao;
    carregar_dados_iniciais("medalhas.csv");

    do {
        mostrar_menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                cadastrar_medalha();
                break;
            case 2:
                listar_medalhas();
                break;
            case 3:
                pesquisar_medalha();
                break;
            case 4:
                alterar_medalha();
                break;
            case 5:
                excluir_medalha();
                break;
            case 6:
                exportar_para_csv("medalhas_exportadas.csv");
                break;
            case 7:
                salvar_dados("medalhas.dat");
                printf("Dados salvos. Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while(opcao != 7);

    
    return 0;
}