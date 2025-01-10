#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/acesso_sequencial.h"
#include "../include/arvore_binaria.h"
#include "../include/arvore_b.h"
#include "../include/arvore_b_star.h"
#include "../include/registro.h"


// Função para gerar arquivo binário com registros
void gerar_arquivo_binario(const char *nome_arquivo, int quantidade, int situacao) {
    FILE *arquivo = fopen(nome_arquivo, "wb");
    if (!arquivo) {
        perror("Erro ao criar arquivo");
        exit(1);
    }

    tipo_registro *registros = (tipo_registro *)malloc(quantidade * sizeof(tipo_registro));

    // Geração de registros de acordo com a situação (ordenado, desordenado, etc)
    for (int i = 0; i < quantidade; i++) {
        registros[i].chave = (situacao == 1) ? i + 1 : (situacao == 2) ? quantidade - i : rand() % 2000000 + 1;
        registros[i].dado1 = rand();
        snprintf(registros[i].dado2, sizeof(registros[i].dado2), "Dado %d", i + 1);
    }

    // Escreve os registros no arquivo
    fwrite(registros, sizeof(tipo_registro), quantidade, arquivo);
    fclose(arquivo);
    free(registros);
}

// Função para exibir as chaves do arquivo
void exibir_chaves(const char *nome_arquivo, int quantidade) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (!arquivo) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    tipo_registro reg;
    for (int i = 0; i < quantidade; i++) {
        fread(&reg, sizeof(tipo_registro), 1, arquivo);
        printf("Chave: %d\n", reg.chave);
    }

    fclose(arquivo);
}

// Função para pesquisa utilizando o método escolhido
void pesquisar(int metodo, const char *nome_arquivo, int chave, int quantidade) {
    clock_t inicio, fim;
    double tempo_execucao;
    int comparacoes = 0, transferencias = 0;

    switch (metodo) {
        case 1:
            // Acesso sequencial indexado
            inicio = clock();
            // Funcoes de acesso sequencial
            fim = clock();
            break;
        case 2:
            // Árvore binária de pesquisa
            inicio = clock();
            // Funcoes de arvore binaria
            fim = clock();
            break;
        case 3:
            // Árvore B
            inicio = clock();
            // Funcoes de Arvore B
            fim = clock();
            break;
        case 4:
            // Árvore B*
            inicio = clock();
            // Funcoes de Arvore B*
            fim = clock();
            break;
        default:
            printf("Método inválido!\n");
            return;
    }

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Chave %d %s encontrada no arquivo!\n", chave, chave > 0 ? "foi" : "não foi");
    printf("Comparações: %d\n", comparacoes);
    printf("Transferências de memória: %d\n", transferencias);
    printf("Tempo de execução: %.4f segundos\n", tempo_execucao);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Uso: %s <método> <quantidade> <situação> <chave> [-P]\n", argv[0]);
        return 1;
    }

    int metodo = atoi(argv[1]);
    int quantidade = atoi(argv[2]);
    int situacao = atoi(argv[3]);
    int chave = atoi(argv[4]);
    int exibir = (argc == 6 && strcmp(argv[5], "-P") == 0) ? 1 : 0;

    const char *nome_arquivo = "registros.bin";

    // Geração do arquivo binário
    gerar_arquivo_binario(nome_arquivo, quantidade, situacao);

    // Exibir as chaves se a opção -P for passada
    if (exibir) {
        exibir_chaves(nome_arquivo, quantidade);
    }

    // Realizar a pesquisa
    pesquisar(metodo, nome_arquivo, chave, quantidade);

    return 0;
}