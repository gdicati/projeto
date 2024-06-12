#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "medalha.h"

Medalha *vetor_medalhas(int *qnt_medalhas)
{
    FILE *fp;
    char linha[1024];
    int capacidade = 10;
    int tamanho = 0;

    Medalha *medalhas = malloc(capacidade * sizeof(Medalha));

    fp = fopen("medalhas.csv", "r");
    if (fp == NULL)
    {
        perror("O arquivo não abriu, tente de novo!");
        exit(1);
    }

    while (fgets(linha, sizeof(linha), fp) != NULL)
    {
        if (tamanho == capacidade)
        {
            capacidade *= 2;
            Medalha *temp = realloc(medalhas, capacidade * sizeof(Medalha));
            if (temp == NULL)
            {
                perror("Ops...Deu erro, não consegui realocar a memória!");
                free(medalhas);
                fclose(fp);
                exit(1);
            }
            medalhas = temp;
        }

        char *entrada = strtok(linha, ",");
        if (entrada != NULL)
        {
            medalhas[tamanho].genero = entrada[0];
            entrada = strtok(NULL, ",");
        }

        if (entrada != NULL)
        {
            strcpy(medalhas[tamanho].modalidade, entrada);
            entrada = strtok(NULL, ",");
        }

        if (entrada != NULL)
        {
            strcpy(medalhas[tamanho].cidade, entrada);
            entrada = strtok(NULL, ",");
        }

        if (entrada != NULL)
        {
            medalhas[tamanho].ano = atoi(entrada);
            entrada = strtok(NULL, ",");
        }

        if (entrada != NULL)
        {
            medalhas[tamanho].tipo_medalha = entrada[0];
            entrada = strtok(NULL, ",");
        }

        if (entrada != NULL)
        {
            strcpy(medalhas[tamanho].nome_atleta, entrada);
            entrada = strtok(NULL, ",");
        }

        if (entrada != NULL)
        {
            strcpy(medalhas[tamanho].pais_origem, entrada);
            entrada = strtok(NULL, ",");
        }

        if (entrada != NULL)
        {
            strcpy(medalhas[tamanho].resultado, entrada);
        }

        medalhas[tamanho].codigo = tamanho;
        tamanho++;
    }

    Medalha *temp = realloc(medalhas, tamanho * sizeof(Medalha));
    if (temp == NULL)
    {
        perror("Ops...Deu erro, não consegui realocar a memória!");
        free(medalhas);
        fclose(fp);
        exit(1);
    }
    medalhas = temp;

    *qnt_medalhas = tamanho;
    fclose(fp);
    return medalhas;
}

void le_string(char texto[], int tamanho)
{
    setbuf(stdin, NULL);
    fgets(texto, tamanho, stdin);
    texto[strcspn(texto, "\n")] = '\0';
}

Medalha *inserir_atletas(Medalha *medalhas, int *qnt_medalhas)
{
    Medalha *temp = realloc(medalhas, (*qnt_medalhas + 1) * sizeof(Medalha));
    if (temp == NULL)
    {
        perror("Ops...Deu erro, não consegui realocar a memória!");
        free(medalhas);
        exit(1);
    }
    medalhas = temp;

    printf("De acordo com o atleta, qual é o seu respectivo gênero:(Digite) \n");
    scanf(" %c", &medalhas[*qnt_medalhas].genero);
    printf("Qual é a modalidade do atleta:(Digite) \n");
    le_string(medalhas[*qnt_medalhas].modalidade, 50);
    printf("Qual é a cidade do atleta: (Digite)\n");
    le_string(medalhas[*qnt_medalhas].cidade, 50);
    printf("Qual é o ano do atleta:(Digite) \n");
    scanf("%d", &medalhas[*qnt_medalhas].ano);
    printf("Qual é a medalha conquistada pelo atleta (G/S/B)?:(Digite) \n");
    scanf(" %c", &medalhas[*qnt_medalhas].tipo_medalha);
    printf("Qual o nome do respectivo atleta(INFORME): \n");
    le_string(medalhas[*qnt_medalhas].nome_atleta, 50);
    printf("Qual é o país do respectivo atleta (DIGITE): \n");
    le_string(medalhas[*qnt_medalhas].pais_origem, 50);
    printf("Qual o resultado do atleta (Digite): ");
    le_string(medalhas[*qnt_medalhas].resultado, 50);

    medalhas[*qnt_medalhas].codigo = *qnt_medalhas;
    (*qnt_medalhas)++;
    return medalhas;
}

Medalha *remover_atletas(Medalha *medalhas, int *qnt_medalhas)
{
    char pesquisa_atleta[50];
    int encontrado = 0;

    printf("Já que você gostaria de retirar um atleta, digite qual atleta você quer retirar: ");
    le_string(pesquisa_atleta, 50);

    for (int i = 0; i < *qnt_medalhas; i++)
    {
        if (strcmp(medalhas[i].nome_atleta, pesquisa_atleta) == 0)
        {
            encontrado = 1;
            for (int j = i; j < *qnt_medalhas - 1; j++)
            {
                medalhas[j] = medalhas[j + 1];
                medalhas[j].codigo = j;
            }
            (*qnt_medalhas)--;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Ops...Deu erro, não encontrei seu atleta\n");
    }

    if (*qnt_medalhas > 0)
    {
        Medalha *temp = realloc(medalhas, (*qnt_medalhas) * sizeof(Medalha));
        if (temp == NULL)
        {
            perror("Ops...Deu erro, não consegui realocar a memória!\n");
            free(medalhas);
            exit(1);
        }
        medalhas = temp;
    }
    else
    {
        free(medalhas);
        medalhas = NULL;
    }
    return medalhas;
}

void pesquisar_atletas(Medalha *medalhas, int qnt_medalhas)
{
    char pesquisa_atleta[50];
    int encontrado = 0;

    printf("Qual o atleta que você quer pesquisar (DIGITE): ");
    le_string(pesquisa_atleta, 50);

    for (int i = 0; i < qnt_medalhas; i++)
    {
        if (strcmp(medalhas[i].nome_atleta, pesquisa_atleta) == 0)
        {
            encontrado = 1;
            printf("Gênero: %c\nModalidade: %s\nCidade: %s\nAno: %d\nMedalha: %c\nNome: %s\nPaís: %s\nResultado: %s\n",
                   medalhas[i].genero, medalhas[i].modalidade, medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo_medalha,
                   medalhas[i].nome_atleta, medalhas[i].pais_origem, medalhas[i].resultado);
            break;
        }
    }

    if (!encontrado)
    {
        printf("Ops...Deu erro, não encontrei seu atleta\n");
    }
}

void exibir_medalhas(Medalha *medalhas, int qnt_medalhas)
{
    for (int i = 0; i < qnt_medalhas; i++)
    {
        printf("Código: %d\n", medalhas[i].codigo);
        printf("Gênero: %c\n", medalhas[i].genero);
        printf("Modalidade: %s\n", medalhas[i].modalidade);
        printf("Cidade: %s\n", medalhas[i].cidade);
        printf("Ano: %d\n", medalhas[i].ano);
        printf("Tipo da medalha: %c\n", medalhas[i].tipo_medalha);
        printf("Nome do atleta: %s\n", medalhas[i].nome_atleta);
        printf("País do atleta: %s\n", medalhas[i].pais_origem);
        printf("Resultado: %s\n", medalhas[i].resultado);
        printf("\n");
    }
}

void salvar_dados_bin(Medalha *medalhas, int qnt_medalhas)
{
    FILE *arqBinario = fopen("dadosMedalhas.bin", "wb");
    if (arqBinario == NULL)
    {
        perror("Ops...Deu erro, erro ao criar arquivo\n");
        exit(1);
    }

    fwrite(medalhas, sizeof(Medalha), qnt_medalhas, arqBinario);
    fclose(arqBinario);
}

void exportar_para_csv(Medalha *medalhas, int qnt_medalhas)
{
    FILE *fp_new = fopen("novo_medalhas.csv", "w");
    if (fp_new == NULL)
    {
        perror("Erro ao abrir o arquivo!");
        exit(1);
    }

    for (int i = 0; i < qnt_medalhas; i++)
    {
        fprintf(fp_new, "%c,%s,%s,%d,%c,%s,%s,%s", medalhas[i].genero, medalhas[i].modalidade, medalhas[i].cidade,
                medalhas[i].ano, medalhas[i].tipo_medalha, medalhas[i].nome_atleta, medalhas[i].pais_origem, medalhas[i].resultado);
    }

    fclose(fp_new);
}