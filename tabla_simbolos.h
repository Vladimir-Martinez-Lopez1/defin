#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#define MAX_SIMBOLOS 1000

typedef struct Simbolo {
    char nombre[128];
    char tipo[128];
    char categoria[128];
    char ambito[128];
    char parametro[128];
    char valor[128];
    int linea; 
    int bloque;
} Simbolo;

typedef struct Parametro {
    char nombre[64];
    char tipo[64];
} Parametro;

// Declaraciones de funciones
void insertarSimbolo(const char* nombre, const char* tipo, const char* categoria, const char* ambito, const char* parametro, const char* valor, int linea, int bloque);
void insertarParametro(const char* nombre, const char* tipo);
void generarSimbolosDesdeParametros(const char* ambito, int linea,char* bloques);
Simbolo* buscarSimbolo(const char* nombre);
void mostrarSimbolo(Simbolo* simbolo);
Simbolo* buscarSimboloBloque(const char* nombre,int bloque);
Simbolo* buscarparametro(const char* nombre,const char* categoria,char* ambito) ;

// Tabla de símbolos (externa)
extern Simbolo tablaSimbolos[MAX_SIMBOLOS];
extern int numSimbolos;

#endif
