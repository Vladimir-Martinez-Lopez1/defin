#ifndef TOKENS_H
#define TOKENS_H
// Este archivo contiene la definición de la estructura Token y las funciones relacionadas con la gestión de tokens.
// En esta estructura se almacenan los tokens generados por el analizador léxico.
typedef struct Token {
    char *texto;
    char *tipo;
    int linea;
    struct Token *siguiente;
} Token;

// Declaración de la lista de tokens y el número de tokens guardados
extern Token *listaTokens;
extern int numTokensGuardados;

// Funciones para agregar, liberar e imprimir tokens
void agregarToken(const char *tipo, const char *texto, int linea);
void liberarTokens();
void imprimirListaTokens();

#endif