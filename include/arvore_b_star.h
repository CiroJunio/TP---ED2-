#ifndef ARVORE_B_STAR_H
#define ARVORE_B_STAR_H

#include "registro.h"
#include <stdlib.h>

#define MM 4           // Número máximo de chaves em uma página interna.
#define MM2 (MM - 1)   // Número máximo de registros em uma página externa.

typedef long TipoChave; // Define o tipo da chave como um número longo.

typedef enum {Interna, Externa} TipoIntExt; // Enum para distinguir entre páginas internas e externas.

typedef struct TipoPaginaBStar* TipoApontadorBstar; // Apontador para uma página da árvore.

typedef struct TipoPaginaBStar {
    TipoIntExt Pt; // Tipo da página (interna ou externa).
    union {        // União para armazenar dados específicos de páginas internas ou externas.
        struct {   // Estrutura para páginas internas.
            int ni;                        // Número de chaves na página interna.
            TipoChave ri[MM];             // Vetor de chaves da página interna.
            TipoApontadorBstar pi[MM + 1];     // Vetor de ponteiros para filhos.
        } U0;
        struct {   // Estrutura para páginas externas.
            int ne;                       // Número de registros na página externa.
            tipo_registro re[MM2];    // Vetor de registros da página externa.
        } U1;
    } UU;
} TipoPaginaBStar;

#endif // ARVORE_B_STAR_H
