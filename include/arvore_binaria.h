#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include "registro.h"
#include <stdlib.h>

typedef tipo_registro tipoitem;  // Defina tipoitem como TipoRegistro (ou outro tipo de sua escolha)

typedef struct NodoBinario {
    tipoitem chave;  // A chave de pesquisa
    struct NodoBinario* esquerda;
    struct NodoBinario* direita;
} NodoBinario;

#endif // ARVORE_BINARIA_H
