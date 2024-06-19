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

void medalhas_continente(Medalha *medalhas, int qnt_medalha){

    int america_do_norte = 0;
    int america_do_sul = 0;
    int europa = 0;
    int africa = 0;
    int asia = 0;
    int oceania = 0;

    printf("SAocoaetggn\n");

    for (int i = 0; i < qnt_medalha; i++) {
        char *codigo_pais = medalhas[i].pais_origem;

        // América do Norte
        if (strcmp(codigo_pais, "USA") == 0 || strcmp(codigo_pais, "CAN") == 0 ||
            strcmp(codigo_pais, "CUB") == 0 || strcmp(codigo_pais, "MEX") == 0 ||
            strcmp(codigo_pais, "PAN") == 0 || strcmp(codigo_pais, "GUA") == 0 ||
            strcmp(codigo_pais, "DOM") == 0 || strcmp(codigo_pais, "PUR") == 0 ||
            strcmp(codigo_pais, "HAI") == 0 || strcmp(codigo_pais, "JAM") == 0 ||
            strcmp(codigo_pais, "TTO") == 0 || strcmp(codigo_pais, "BAR") == 0 ||
            strcmp(codigo_pais, "BWI") == 0 || strcmp(codigo_pais, "GRN") == 0) {
            america_do_norte++;
        }
        // América do Sul
        else if (strcmp(codigo_pais, "ARG") == 0 || strcmp(codigo_pais, "BRA") == 0 ||
                 strcmp(codigo_pais, "CHI") == 0 || strcmp(codigo_pais, "COL") == 0 ||
                 strcmp(codigo_pais, "ECU") == 0 || strcmp(codigo_pais, "VEN") == 0) {
            america_do_sul++;
        }
        // Europa
        else if (strcmp(codigo_pais, "ITA") == 0 || strcmp(codigo_pais, "GBR") == 0 ||
                 strcmp(codigo_pais, "FIN") == 0 || strcmp(codigo_pais, "POR") == 0 ||
                 strcmp(codigo_pais, "FRA") == 0 || strcmp(codigo_pais, "SWE") == 0 ||
                 strcmp(codigo_pais, "BEL") == 0 || strcmp(codigo_pais, "HUN") == 0 ||
                 strcmp(codigo_pais, "POL") == 0 || strcmp(codigo_pais, "NED") == 0 ||
                 strcmp(codigo_pais, "GER") == 0 || strcmp(codigo_pais, "BUL") == 0 ||
                 strcmp(codigo_pais, "ESP") == 0 || strcmp(codigo_pais, "GDR") == 0 ||
                 strcmp(codigo_pais, "FRG") == 0 || strcmp(codigo_pais, "LUX") == 0 ||
                 strcmp(codigo_pais, "IRL") == 0 || strcmp(codigo_pais, "SUI") == 0 ||
                 strcmp(codigo_pais, "GRE") == 0 || strcmp(codigo_pais, "NOR") == 0 ||
                 strcmp(codigo_pais, "TUR") == 0 || strcmp(codigo_pais, "DEN") == 0 ||
                 strcmp(codigo_pais, "SVK") == 0 || strcmp(codigo_pais, "LAT") == 0 ||
                 strcmp(codigo_pais, "EUN") == 0 || strcmp(codigo_pais, "BLR") == 0 ||
                 strcmp(codigo_pais, "EST") == 0 || strcmp(codigo_pais, "CZE") == 0 ||
                 strcmp(codigo_pais, "LTU") == 0 || strcmp(codigo_pais, "SLO") == 0 ||
                 strcmp(codigo_pais, "UKR") == 0 || strcmp(codigo_pais, "ROU") == 0 ||
                 strcmp(codigo_pais, "YUG") == 0 || strcmp(codigo_pais, "AUT") == 0 ||
                 strcmp(codigo_pais, "CRO") == 0 || strcmp(codigo_pais, "ISL") == 0 ||
                 strcmp(codigo_pais, "SRB") == 0 || strcmp(codigo_pais, "TCH") == 0 ||
                 strcmp(codigo_pais, "URS") == 0 || strcmp(codigo_pais, "RUS") == 0) {
            europa++;
        }
        // África
        else if (strcmp(codigo_pais, "KEN") == 0 || strcmp(codigo_pais, "ETH") == 0 ||
                 strcmp(codigo_pais, "MAR") == 0 || strcmp(codigo_pais, "TUN") == 0 ||
                 strcmp(codigo_pais, "ERI") == 0 || strcmp(codigo_pais, "NAM") == 0 ||
                 strcmp(codigo_pais, "RSA") == 0 || strcmp(codigo_pais, "ALG") == 0 ||
                 strcmp(codigo_pais, "ZAM") == 0 || strcmp(codigo_pais, "UGA") == 0 ||
                 strcmp(codigo_pais, "CIV") == 0 || strcmp(codigo_pais, "SUD") == 0 ||
                 strcmp(codigo_pais, "BOT") == 0 || strcmp(codigo_pais, "BDI") == 0 ||
                 strcmp(codigo_pais, "MOZ") == 0 || strcmp(codigo_pais, "CMR") == 0 ||
                 strcmp(codigo_pais, "DJI") == 0 || strcmp(codigo_pais, "NGR") == 0 ||
                 strcmp(codigo_pais, "TAN") == 0) {
            africa++;
        }
        // Ásia
        else if (strcmp(codigo_pais, "CHN") == 0 || strcmp(codigo_pais, "QAT") == 0 ||
                 strcmp(codigo_pais, "KSA") == 0 || strcmp(codigo_pais, "PHI") == 0 ||
                 strcmp(codigo_pais, "SRI") == 0 || strcmp(codigo_pais, "JPN") == 0 ||
                 strcmp(codigo_pais, "IND") == 0 || strcmp(codigo_pais, "IRI") == 0 ||
                 strcmp(codigo_pais, "TPE") == 0 || strcmp(codigo_pais, "KAZ") == 0 ||
                 strcmp(codigo_pais, "TJK") == 0 || strcmp(codigo_pais, "SYR") == 0 ||
                 strcmp(codigo_pais, "KOR") == 0 || strcmp(codigo_pais, "BRN") == 0) {
            asia++;
        }
        // Oceania
        else if (strcmp(codigo_pais, "AUS") == 0 || strcmp(codigo_pais, "NZL") == 0) {
            oceania++;
        }
    }
    printf("Quantidade de medalhas por continente!\n");
    printf("América do Norte: %d\n", america_do_norte);
    printf("América do Sul: %d\n", america_do_sul);
    printf("Europa: %d\n", europa);
    printf("África: %d\n", africa);
    printf("Ásia: %d\n", asia);
    printf("Oceania: %d\n", oceania);
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