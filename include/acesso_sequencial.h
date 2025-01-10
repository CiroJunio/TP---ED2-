#ifndef ACESSO_SEQUENCIAL_H
#define ACESSO_SEQUENCIAL_H

#include "registro.h"
#include <stdlib.h>
#include <stdio.h>

// Definindo um índice simples para o arquivo
#define ITENSPAGINA 4
#define MAX_INDICE 500   // Máximo de blocos no índice

// Estrutura para o índice simples
typedef struct {
    int posicao; // Posição no arquivo onde o bloco começa
    int chave;   // Chave mínima do bloco
} tipoindice;

#endif // ACESSO_SEQUENCIAL_H
