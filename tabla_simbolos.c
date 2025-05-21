#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tabla_simbolos.h"
#include "analizador_semantico.h"
Simbolo tablaSimbolos[MAX_SIMBOLOS];
int numSimbolos = 0;

void insertarSimbolo(const char* nombre, const char* tipo, const char* categoria, const char* ambito, const char* parametro, const char* valor, int linea, int bloque) {
    int validacion = 1;
    if(strcmp(categoria,"variable")==0){ 
        validacion = variables(nombre,tipo,categoria,ambito,parametro,valor,linea,bloque);
    }else if(strcmp(categoria,"constante")==0){ 
        validacion = constantes(nombre,tipo,categoria,ambito,parametro,valor,linea,bloque);
    }else if(strcmp(categoria,"arreglo")==0){ 
        validacion = variables(nombre,tipo,categoria,ambito,parametro,valor,linea,bloque);
    }else if(strcmp(categoria,"expresion")==0){ 
        validacion = expresiones(nombre,tipo,categoria,ambito,parametro,valor,linea,bloque);
    }else if(strcmp(categoria,"parametro")==0){ 
        validacion = variables(nombre,tipo,categoria,ambito,parametro,valor,linea,bloque);
    }else if(strcmp(categoria,"funcion")==0){ 
        validacion = funciones(nombre,tipo,categoria,ambito,parametro,valor,linea,bloque);
    }else if(strcmp(categoria,"mientras")==0){ 
        validacion = mientras(nombre,tipo,categoria,ambito,parametro,valor,linea,bloque);
    }else if(strcmp(categoria,"estructura")==0){ 
        validacion = estructuras(nombre,tipo,categoria,ambito,parametro,valor,linea,bloque);
    }else if(strcmp(categoria,"miembro")==0){ 
        validacion = variables(nombre,tipo,categoria,ambito,parametro,valor,linea,bloque);
    }
      
    if (numSimbolos < MAX_SIMBOLOS && validacion ==1) {
        strcpy(tablaSimbolos[numSimbolos].nombre, nombre);
        strcpy(tablaSimbolos[numSimbolos].tipo, tipo);
        strcpy(tablaSimbolos[numSimbolos].categoria, categoria);
        strcpy(tablaSimbolos[numSimbolos].ambito, ambito);
        strcpy(tablaSimbolos[numSimbolos].parametro, parametro);
        strcpy(tablaSimbolos[numSimbolos].valor, valor);
        tablaSimbolos[numSimbolos].linea = linea; 
        tablaSimbolos[numSimbolos].bloque = bloque;
        numSimbolos++;
    }
}

Simbolo* buscarSimbolo(const char* nombre) {
    for (int i = 0; i < numSimbolos; i++) {
        if (strcmp(tablaSimbolos[i].nombre, nombre) == 0) {
            return &tablaSimbolos[i];
        }
    }
    return NULL;
}
Simbolo* buscarSimboloBloque(const char* nombre,int bloque) {
    for (int i = 0; i < numSimbolos; i++) {
        if (strcmp(tablaSimbolos[i].nombre, nombre) == 0 && tablaSimbolos[i].bloque == bloque) {
            return &tablaSimbolos[i];
        }
    }
    return NULL;
}
Simbolo* buscarparametro(const char* nombre,const char* categoria,char* ambito) {
    for (int i = 0; i < numSimbolos; i++) {
        if (strcmp(tablaSimbolos[i].categoria, categoria) == 0 && strcmp(tablaSimbolos[i].ambito, ambito) == 0 && strcmp(tablaSimbolos[i].nombre, nombre) == 0) {
            return &tablaSimbolos[i];
        }
    }
    return NULL;
}

void mostrarSimbolo(Simbolo* simbolo) {
    if (simbolo != NULL) {
        printf("Nombre: %s\n", simbolo->nombre);
        printf("Tipo: %s\n", simbolo->tipo);
        printf("Categoria: %s\n", simbolo->categoria);
        printf("Ambito: %s\n", simbolo->ambito);
        printf("Parametro: %s\n", simbolo->parametro);
        printf("Valor: %s\n", simbolo->valor);
        printf("Linea: %d\n", simbolo->linea);
        printf("Bloque: %d\n", simbolo->bloque);
    } else {
        printf("Simbolo no encontrado.\n");
    }
}

Parametro parametros[MAX_SIMBOLOS];
int numParametro = 0;

void insertarParametro(const char* nombre, const char* tipo) {
    if (numParametro < MAX_SIMBOLOS) {
        strcpy(parametros[numParametro].nombre, nombre);
        strcpy(parametros[numParametro].tipo, tipo);
        numParametro++;
    } else {
        printf("Error: la tabla de símbolos está llena.\n");
    }
}


