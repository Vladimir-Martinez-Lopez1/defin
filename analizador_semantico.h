#ifndef ANALIZADOR_SEMANTICO_H
#define ANALIZADOR_SEMANTICO_H

#define MAX_ERRORES 100

typedef struct Error {
    char mensaje[256];
    int linea;
} Error;

void insertarError(char* mensaje, int linea);
int variables(const char* nombre,const char* tipo,const char* categoria,const char* ambito,const char* parametro,const char* valor, int linea, int bloque);
int constantes(const char* nombre,const char* tipo,const char* categoria,const char* ambito,const char* parametro,const char* valor, int linea, int bloque);
int arreglos(const char* nombre,const char* tipo,const char* categoria,const char* ambito,const char* parametro,const char* valor, int linea, int bloque);
int expresiones(const char* nombre,const char* tipo,const char* categoria,const char* ambito,const char* parametro,const char* valor, int linea, int bloque);
int funciones(const char* nombre,const char* tipo,const char* categoria,const char* ambito,const char* parametro,const char* valor, int linea, int bloque);
int mientras(const char* nombre,const char* tipo,const char* categoria,const char* ambito,const char* parametro,const char* valor, int linea, int bloque);
int estructuras(const char* nombre,const char* tipo,const char* categoria,const char* ambito,const char* parametro,const char* valor, int linea, int bloque);
int validarEstructura(const char* nombre,const char* nombre2,int linea);
void mostrarErroresSemanticos();
int confirmarfuncion(const char* nombre, const char* parametros, int linea);
int confirmarArreglo(const char* nombre, const char* tipo, int linea);
int validarAsignacionArreglo(const char* nombre,const char* ambito,const char* valor,int linea,int bloque);
int validarID(const char* id,int linea);
int validarExpresionLogica(const char* expresion, const char* ambito, int bloque, int linea);
int validarAnidacion(const char* nombre, const char* ambito1, const char* ambito2, int bloque, int linea);
int validarelegir(const char* nombre,const char* ambito,int bloque,int linea);

extern Error erroresSemanticos[MAX_ERRORES];
extern int numErrores;

#endif // ANALIZADOR_SEMANTICO_H