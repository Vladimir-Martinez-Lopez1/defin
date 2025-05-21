#include "tokens.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Este archivo contiene la implementación de las funciones para gestionar los tokens generados por el analizador léxico.
Token *listaTokens = NULL;// Lista de tokens
int numTokensGuardados = 0;// Contador de tokens guardados

// Función para agregar un token a la lista
void agregarToken(const char *tipo, const char *texto, int linea) {
    Token *nuevoToken = (Token *)malloc(sizeof(Token)); // Crear un nuevo token
    nuevoToken->tipo = strdup(tipo);// Copiar el tipo del token
    nuevoToken->texto = strdup(texto);// Copiar el texto del token
    nuevoToken->linea = linea;// Guardar la línea del token
    nuevoToken->siguiente = NULL;// Inicializar el siguiente puntero a NULL

    // Agregar el nuevo token a la lista
    // Si la lista está vacía, el nuevo token es el primero
    // Si no, recorrer la lista hasta el final y agregar el nuevo token
    // al final de la lista
    if (listaTokens == NULL) {
        listaTokens = nuevoToken;
    } else {
        Token *actual = listaTokens;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoToken;
    }
    numTokensGuardados++;
}


// Esta función libera la memoria ocupada por los tokens almacenados en la lista
void liberarTokens() {
    Token *actual = listaTokens;// Inicializar el puntero actual a la cabeza de la lista
    while (actual != NULL) { // Recorrer la lista
        Token *temp = actual;
        actual = actual->siguiente;
        free(temp->texto);// Liberar la memoria del texto del token
        free(temp->tipo);// Liberar la memoria del tipo del token
        free(temp);// Liberar la memoria del token
    }
    listaTokens = NULL; // Reiniciar la lista de tokens a NULL
    numTokensGuardados = 0; // Reiniciar el contador de tokens guardados a 0
}


// Esta función imprime la lista de tokens almacenados en la lista
// y el número total de tokens almacenados
void imprimirListaTokens() {
    Token *actual = listaTokens;
    printf("\n=== Lista de Tokens Almacenados ===\n");
    while (actual != NULL) {
        printf("TOKEN_%s: %s (linea %d)\n", 
               actual->tipo, actual->texto, actual->linea);
        actual = actual->siguiente;
    }
    printf("Total de tokens almacenados: %d\n", numTokensGuardados);
}