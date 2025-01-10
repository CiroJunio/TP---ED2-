#ifndef REGISTRO_H
#define REGISTRO_H

// Estrutura para representar um registro
typedef struct {
    int chave;      // Chave do registro
    long dado1;     // Dado adicional (pode ser alterado conforme necessário)
    char dado2[5000]; // Dado adicional em formato de string (5000 caracteres)
} tipo_registro;

#endif // REGISTRO