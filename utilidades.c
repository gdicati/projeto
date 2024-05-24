#include "utilidades.h"
#include <stdio.h>
#include <string.h>

// Função para alocar dinamicamente um vetor de inteiros
int* alocar_vetor_int(int tamanho) {
    if (tamanho <= 0) {
        return NULL;
    }
    int* vetor = (int*)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    return vetor;
}

// Função para ler uma string do usuário
char* ler_string() {
    char buffer[100];
    printf("Digite uma string: ");
    if (fgets(buffer, 100, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove o caractere de nova linha
        char* string = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        if (string == NULL) {
            perror("Erro ao alocar memória");
            exit(EXIT_FAILURE);
        }
        strcpy(string, buffer);
        return string;
    }
    return NULL;
}

int ler_numero_positivo() {
    int numero;
    do {
        printf("Digite um número positivo: ");
        scanf("%d", &numero);
        if (numero < 0) {
            printf("O número deve ser positivo. Tente novamente.\n");
        }
    } while (numero < 0);
    return numero;
}
