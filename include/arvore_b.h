#ifndef ARVORE_B_H
#define ARVORE_B_H

#include "registro.h"
#include <stdlib.h>

#define MM 4 // Define o número máximo de chaves que uma página pode conter.

typedef long TipoChave; // Define o tipo da chave usada nos registros.

typedef struct TipoPaginaB* TipoApontadorB; // Define um ponteiro para uma página da árvore.

typedef struct TipoPaginaB {
    short n;               // Número atual de registros armazenados na página.
    tipo_registro r[MM];   // Vetor de registros armazenados na página.
    TipoApontadorB p[MM + 1]; // Vetor de apontadores para as páginas filhas.
} TipoPaginaB;

#endif // ARVORE_B_H
