#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tabla_simbolos.h"
#include "analizador_semantico.h"
#include <ctype.h> 
#include <stdbool.h>

void procesarToken(char* token, char* tipoEsperado, int linea);
int validarAnidacion(const char* nombre, const char* ambito1, const char* ambito2, int bloque, int linea) {
    if (strcmp(ambito2, ambito1) == 0) {
        return 0;
    }
    if (strcmp(ambito2, "global") == 0) {
        return 0;
    }
    if (bloque > 1) {
        int amb_actual = atoi(ambito1);
        int amb_variable = atoi(ambito2);
        if (amb_actual > amb_variable) {
            return 0;
        }
        int amb_hermano = amb_variable;
        while (amb_hermano > 0) {
            if (amb_hermano == amb_actual || (amb_hermano < amb_actual && amb_hermano > 0)) {
                return 0;
            }
            amb_hermano--;
        }
    }
    return 1;
}

Error erroresSemanticos[MAX_ERRORES];
int numErrores = 0;
void insertarError(char* mensaje, int linea) {
    if (numErrores < MAX_ERRORES) {
        strcpy(erroresSemanticos[numErrores].mensaje, mensaje);
        erroresSemanticos[numErrores].linea = linea;
        numErrores++;
    } else {
        printf("Error: la tabla de errores semánticos está llena.\n");
    }
}
void validacionExpresionTipo(char* valor, char* tipoEsperado, int linea) {
    char token[64];
    int i = 0, j = 0;
    while (valor[i] != '\0') {
        if (isspace(valor[i]) || valor[i] == '+' || valor[i] == '-' || valor[i] == '*' || valor[i] == '/' || valor[i] == '(' || valor[i] == ')') {
            // Si hay un token acumulado, lo procesamos
            if (j > 0) {
                token[j] = '\0';
                procesarToken(token, tipoEsperado, linea);
                j = 0;
            }
            i++;
        } else {
            token[j++] = valor[i++];
        }
    }

    // Procesar el último token si quedó algo
    if (j > 0) {
        token[j] = '\0';
        procesarToken(token, tipoEsperado, linea);
    }
}
void procesarToken(char* token, char* tipoEsperado, int linea) {
    // Si es un número real (contiene '.')
    if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
        int esReal = strchr(token, '.') != NULL;

        if (esReal && strcmp(tipoEsperado, "flotante") != 0) {
            insertarError("Expresion no valida: Tipo de dato incompatible", linea);
        } else if (!esReal && strcmp(tipoEsperado, "entero") != 0) {
            insertarError("Expresion no valida: Tipo de dato incompatible", linea);
        }
    }
    // Si es un valor booleano
    else if (strcmp(token, "verdadero") == 0 || strcmp(token, "falso") == 0) {
        if (strcmp(tipoEsperado, "booleano") != 0) {
            insertarError("Expresion no valida: Tipo de dato incompatible", linea);
        }
    }
    // Si es una cadena
    else if (token[0] == '"' && token[strlen(token)-1] == '"') {
        if (strcmp(tipoEsperado, "cadena") != 0) {
            insertarError("Expresion no valida: Tipo de dato incompatible", linea);
        }
    }
    // Si es un carácter
    else if (token[0] == '\'' && token[strlen(token)-1] == '\'' && strlen(token) == 3) {
        if (strcmp(tipoEsperado, "caracter") != 0) {
            insertarError("Expresion no valida: Tipo de dato incompatible", linea);
        }
    }
    // Si es una variable
    else {
        Simbolo* simbolo = buscarSimbolo(token);
        if (simbolo != NULL) {
            if (strcmp(simbolo->tipo, tipoEsperado) != 0) {
                char mensaje[128];
                snprintf(mensaje, sizeof(mensaje), "Expresion no valida: Tipo de dato incompatible: variable '%s' es de tipo '%s'", token, simbolo->tipo);
                insertarError(mensaje, simbolo->linea);
            }
        } else {
            char mensaje[128];
            snprintf(mensaje, sizeof(mensaje), "Variable '%s' no declarada", token);
            insertarError(mensaje, linea);
        }
    }
}

int constantes(const char* nombre,const char* tipo,const char* categoria,const char* ambito,const char* parametro,const char* valor, int linea, int bloque) {
    int status=1;
    char* valor2 = strdup(valor);
    char* tipo2 = strdup(tipo);
    Simbolo* simbolo = buscarSimbolo(nombre);
    validacionExpresionTipo(valor2, tipo2, linea);
    free(valor2);
    free(tipo2);
    if(simbolo !=NULL){
        int verificacion=validarAnidacion(nombre,ambito,simbolo->ambito,bloque,linea);
        if(verificacion==0){
            char mensaje[256];
            snprintf(mensaje, sizeof(mensaje), "El identificador: '%s' ya ha sido definido", nombre);
            insertarError(mensaje, linea);
        }else{
            simbolo->bloque = bloque;
            snprintf(simbolo->ambito, sizeof(simbolo->ambito), "%s", ambito);
            snprintf(simbolo->tipo, sizeof(simbolo->tipo), "%s", tipo);
            snprintf(simbolo->categoria, sizeof(simbolo->categoria), "%s", categoria);
            snprintf(simbolo->parametro, sizeof(simbolo->parametro), "%s", parametro);
            snprintf(simbolo->valor, sizeof(simbolo->valor), "%s", valor);
            snprintf(simbolo->nombre, sizeof(simbolo->nombre), "%s", nombre);
            simbolo->linea = linea;
            return 0;
        }
    }

    return status;
}
int variables(const char* nombre,const char* tipo,const char* categoria,const char* ambito,const char* parametro,const char* valor, int linea, int bloque) {
    int status=1;
    char* valor2 = strdup(valor);
    char* tipo2 = strdup(tipo);
    Simbolo* simbolo = buscarSimbolo(nombre);
    if (strcmp(valor,"vacio") != 0) {
        validacionExpresionTipo(valor2, tipo2, linea);
    }
    free(valor2);
    free(tipo2);
    
    if(simbolo !=NULL){
        int verificacion=validarAnidacion(nombre,ambito,simbolo->ambito,bloque,linea);
        if(verificacion==0){
            char mensaje[256];
            snprintf(mensaje, sizeof(mensaje), "El identificador: '%s' ya ha sido definido", nombre);
            insertarError(mensaje, linea);
        }else{
            simbolo->bloque = bloque;
            snprintf(simbolo->ambito, sizeof(simbolo->ambito), "%s", ambito);
            snprintf(simbolo->tipo, sizeof(simbolo->tipo), "%s", tipo);
            snprintf(simbolo->categoria, sizeof(simbolo->categoria), "%s", categoria);
            snprintf(simbolo->parametro, sizeof(simbolo->parametro), "%s", parametro);
            snprintf(simbolo->valor, sizeof(simbolo->valor), "%s", valor);
            snprintf(simbolo->nombre, sizeof(simbolo->nombre), "%s", nombre);
            simbolo->linea = linea;
            return 0;
        }
    }
    return status;
}
int arreglos(const char* nombre,const char* tipo,const char* categoria,const char* ambito,const char* parametro,const char* valor, int linea, int bloque) {
    int status=1;
    char* valor2 = strdup(valor);
    char* tipo2 = strdup(tipo);
    Simbolo* simbolo = buscarSimbolo(nombre);
    if (strcmp(valor,"vacio") != 0) {
        validacionExpresionTipo(valor2, tipo2, linea);
    }
    free(valor2);
    free(tipo2);
    
    if(simbolo !=NULL){
        if(strcmp(simbolo->ambito,ambito) != 0 && simbolo->bloque == 1){
             mostrarSimbolo(simbolo);
            simbolo->bloque = bloque;
            snprintf(simbolo->ambito, sizeof(simbolo->ambito), "%s", ambito);
            snprintf(simbolo->tipo, sizeof(simbolo->tipo), "%s", tipo);
            snprintf(simbolo->categoria, sizeof(simbolo->categoria), "%s", categoria);
            snprintf(simbolo->parametro, sizeof(simbolo->parametro), "%s", parametro);
            snprintf(simbolo->valor, sizeof(simbolo->valor), "%s", valor);
            snprintf(simbolo->nombre, sizeof(simbolo->nombre), "%s", nombre);
            simbolo->linea = linea;
            mostrarSimbolo(simbolo);
            return 0;
        }
        char mensaje[256];
        snprintf(mensaje, sizeof(mensaje), "el arreglo '%s' ya ha sido declarado", nombre);
        insertarError(mensaje, linea);
        status=0;
    }
    return status;
}
int expresiones(const char* nombre, const char* tipo, const char* categoria, const char* ambito, const char* parametro, const char* valor, int linea, int bloque) {
    int status = 0;
    char* valor2 = strdup(valor);
    Simbolo* simbolo = buscarSimbolo(nombre);
    
    if (simbolo == NULL) {
        char mensaje[256];
        snprintf(mensaje, sizeof(mensaje), "El identificador '%s' no ha sido declarado", nombre);
        insertarError(mensaje, linea);
        free(valor2);
        return 0;
    }
    
    // Verificar si es una constante
    if (strcmp(simbolo->categoria, "constante") == 0) {
        char mensaje[256];
        snprintf(mensaje, sizeof(mensaje), "Error de expresion: '%s' es una constante", nombre);
        insertarError(mensaje, linea);
        free(valor2);
        return 0;
    }
    
    // Verificar ámbito global
    if (strcmp(ambito, "global") == 0 && strcmp(simbolo->ambito, "global") != 0) {
        char mensaje[256];
        snprintf(mensaje, sizeof(mensaje), "el identificador: '%s' no ha sido definido", nombre);
        insertarError(mensaje, linea);
        free(valor2);
        return 0;
    }
    
    // Validar anidación de ámbitos
    int verificacion = validarAnidacion(nombre, ambito, simbolo->ambito, bloque, linea);
    
    if (verificacion == 1) {
        char mensaje[256];
        snprintf(mensaje, sizeof(mensaje), "el identificador: '%s' no ha sido definido", nombre);
        insertarError(mensaje, linea);
        free(valor2);
        return 0;
    }
    
    // Validar tipos
    validacionExpresionTipo(valor2, simbolo->tipo, linea);
    free(valor2);
    
    return status;
}
int funciones(const char* nombre,const char* tipo,const char* categoria,const char* ambito,const char* parametro,const char* valor, int linea, int bloque) {
    int status=1;
    Simbolo* simbolo = buscarSimbolo(nombre);
    if(simbolo !=NULL){
        if(strcmp(simbolo->ambito,valor) != 0 && simbolo->bloque == 1){
            simbolo->bloque = bloque;
            snprintf(simbolo->ambito, sizeof(simbolo->ambito), "%s", ambito);
            snprintf(simbolo->tipo, sizeof(simbolo->tipo), "%s", tipo);
            snprintf(simbolo->categoria, sizeof(simbolo->categoria), "%s", categoria);
            snprintf(simbolo->parametro, sizeof(simbolo->parametro), "%s", parametro);
            snprintf(simbolo->valor, sizeof(simbolo->valor), "%s", valor);
            snprintf(simbolo->nombre, sizeof(simbolo->nombre), "%s", nombre);
            simbolo->linea = linea;
            status = 0;
        }else{
            char mensaje[256];
            snprintf(mensaje, sizeof(mensaje), "El identificador '%s' ya ha sido ocupado", nombre);
            insertarError(mensaje, linea);
            status = 0;
        }
    }
    /*for (int i = 0; i < numSimbolos;) {
        if (strcmp(tablaSimbolos[i].ambito, valor)==0) {
            if(strcmp(tablaSimbolos[i].categoria, "expresion") == 0) {
                if(strcmp(tablaSimbolos[i].tipo, "indefinido") == 0) {
                    char mensaje[256];
                    snprintf(mensaje, sizeof(mensaje), "la variable : '%s' no ha sido declarada", tablaSimbolos[i].nombre);
                    insertarError(mensaje, tablaSimbolos[i].linea);
                    i++;
                } else {
                    expresiones(tablaSimbolos[i].nombre, tablaSimbolos[i].tipo, tablaSimbolos[i].categoria, tablaSimbolos[i].ambito, tablaSimbolos[i].parametro, tablaSimbolos[i].valor, tablaSimbolos[i].linea, tablaSimbolos[i].bloque);
                    
                    for (int j = i; j < numSimbolos - 1; j++) {
                        tablaSimbolos[j] = tablaSimbolos[j + 1];
                    }
                    numSimbolos--; 
                }
            } else {
                i++; 
            }
        } else {
            i++; 
        }
    }*/

    return status;
}
int mientras(const char* nombre,const char* tipo,const char* categoria,const char* ambito,const char* parametro,const char* valor, int linea, int bloque) {
    for (int i = 0; i < numSimbolos;) {
        if (strcmp(tablaSimbolos[i].ambito, ambito)==0) {
            if(strcmp(tablaSimbolos[i].categoria, "expresion") == 0) {
                if(strcmp(tablaSimbolos[i].tipo, "indefinido") == 0) {
                    char mensaje[256];
                    snprintf(mensaje, sizeof(mensaje), "la variable : '%s' no ha sido declarada", tablaSimbolos[i].nombre);
                    insertarError(mensaje, tablaSimbolos[i].linea);
                    i++;
                    for (int j = i; j < numSimbolos - 1; j++) {
                        tablaSimbolos[j] = tablaSimbolos[j + 1];
                    }
                    numSimbolos--; 
                } 
            } else {
                i++; 
            }
        } else {
            i++; 
        }
    }
    return 1;
}
int confirmarfuncion(const char* nombre, const char* parametros, int linea){
    Simbolo* simbolo = buscarSimbolo(nombre);
    if(simbolo != NULL){
        if(strcmp(simbolo->categoria, "funcion") != 0){
            char mensaje[256];
            snprintf(mensaje, sizeof(mensaje), "'%s' no es una funcion", nombre);
            insertarError(mensaje, linea);
        } else {
            if(strcmp(simbolo->parametro, "no") == 0){
                if(strcmp(parametros, "") != 0){
                    char mensaje[256];
                    snprintf(mensaje, sizeof(mensaje), "la funcion '%s' no acepta parametros", nombre);
                    insertarError(mensaje, linea);
                }
                return 0;
            }

            if(simbolo->parametro != NULL && strlen(simbolo->parametro) > 0){
                // Contar número de parámetros definidos
                int numParamDef = 0;
                char tempDef[256];
                strncpy(tempDef, simbolo->parametro, sizeof(tempDef));
                tempDef[sizeof(tempDef) - 1] = '\0';
                char* tokDef = strtok(tempDef, ",");
                while(tokDef != NULL){
                    numParamDef++;
                    tokDef = strtok(NULL, ",");
                }

                // Contar número de argumentos recibidos
                int numArgs = 0;
                char tempArgs[256];
                strncpy(tempArgs, parametros, sizeof(tempArgs));
                tempArgs[sizeof(tempArgs) - 1] = '\0';
                char* tokArg = strtok(tempArgs, ",");
                while(tokArg != NULL){
                    numArgs++;
                    tokArg = strtok(NULL, ",");
                }

                // Validaciones de cantidad
                if(numArgs > numParamDef){
                    char mensaje[256];
                    snprintf(mensaje, sizeof(mensaje), "la funcion '%s' recibe maximo %d argumentos, pero se dieron %d", nombre, numParamDef, numArgs);
                    insertarError(mensaje, linea);
                } else if(numArgs < numParamDef){
                    char mensaje[256];
                    snprintf(mensaje, sizeof(mensaje), "faltan argumentos en la llamada a la funcion '%s': se esperaban %d y se recibieron %d", nombre, numParamDef, numArgs);
                    insertarError(mensaje, linea);
                }

                // Procesamiento de parámetros y valores
                char copiaDef[256], copiaVals[256];
                strncpy(copiaDef, simbolo->parametro, sizeof(copiaDef));
                copiaDef[sizeof(copiaDef) - 1] = '\0';
                strncpy(copiaVals, parametros, sizeof(copiaVals));
                copiaVals[sizeof(copiaVals) - 1] = '\0';

                char* tokenDef = strtok(copiaDef, ",");
                char* tokenVal = strtok(copiaVals, ",");

                while(tokenDef != NULL){
                    while(*tokenDef == ' ') tokenDef++; // eliminar espacios iniciales

                    char tipo[128], identificador[128];
                    if(sscanf(tokenDef, "%127s %127s", tipo, identificador) == 2){
                        const char* valor = tokenVal ? tokenVal : "NULL";
                        validacionExpresionTipo((char*)valor, tipo, linea);
                    } 

                    tokenDef = strtok(NULL, ",");
                    tokenVal = strtok(NULL, ",");
                }
            }
        }
    }
    return 0;
}
int confirmarArreglo(const char* nombre, const char* parametros, int linea){
    Simbolo* simbolo = buscarSimbolo(nombre);
    if(simbolo != NULL){
    } else {
        if(strcmp(simbolo->categoria, "arreglo") != 0){
            char mensaje[256];
            snprintf(mensaje, sizeof(mensaje), "'%s' no es un arreglo", nombre);
            insertarError(mensaje, linea);
            return 1;
        } else {
           char mensaje[256];
            snprintf(mensaje, sizeof(mensaje), "el arreglo '%s' no ha sido declarado", nombre);
            insertarError(mensaje, linea);
            return 1;
        }
    }
    return 0;
}
int estructuras(const char* nombre,const char* tipo,const char* categoria,const char* ambito,const char* parametro,const char* valor, int linea, int bloque){
    Simbolo* simbolo = buscarSimbolo(nombre);
    if(simbolo !=NULL){
        int verificacion=validarAnidacion(nombre,ambito,simbolo->ambito,bloque,linea);
        if(verificacion==0){
            char mensaje[256];
            snprintf(mensaje, sizeof(mensaje), "El identificador: '%s' ya ha sido definido", nombre);
            insertarError(mensaje, linea);
        }else{
            simbolo->bloque = bloque;
            snprintf(simbolo->ambito, sizeof(simbolo->ambito), "%s", ambito);
            snprintf(simbolo->tipo, sizeof(simbolo->tipo), "%s", tipo);
            snprintf(simbolo->categoria, sizeof(simbolo->categoria), "%s", categoria);
            snprintf(simbolo->parametro, sizeof(simbolo->parametro), "%s", parametro);
            snprintf(simbolo->valor, sizeof(simbolo->valor), "%s", valor);
            snprintf(simbolo->nombre, sizeof(simbolo->nombre), "%s", nombre);
            simbolo->linea = linea;
            return 0;
        }
    }
    return 1;
}
int validarAsignacionArreglo(const char* nombre,const char* ambito,const char* valor,int linea,int bloque){
    Simbolo* simbolo = buscarSimbolo(nombre);
    if(simbolo != NULL){
        if(strcmp(ambito,"global")==0 && strcmp(simbolo->ambito,"global")!=0){
            char mensaje[256];
            snprintf(mensaje, sizeof(mensaje), "el identificador: '%s' no ha sido definido", nombre);
            insertarError(mensaje, linea);
            return 0;
        }
        int verificacion=validarAnidacion(nombre,ambito,simbolo->ambito,bloque,linea);
        if(strcmp(simbolo->ambito,"global")!=0){
            if(atoi(simbolo->ambito)-1==atoi(ambito)){
                validacionExpresionTipo((char*)valor, simbolo->tipo, linea);
                return 0;
            }
        }
        if(verificacion==1){
            char mensaje[256];
            snprintf(mensaje, sizeof(mensaje), "el identificador: '%s' no ha sido definido", nombre);
            insertarError(mensaje, linea);
        }
    }
    return 0;
}
int validarEstructura(const char* nombre,const char* nombre2,int linea){
    Simbolo* simbolo1=buscarSimbolo(nombre);
    Simbolo* simbolo2=buscarSimbolo(nombre2);
    if(simbolo1==NULL){
        char mensaje[256];
        snprintf(mensaje, sizeof(mensaje), "El identificador: '%s' no ha sido definido", nombre);
        insertarError(mensaje, linea);
        return 0;
    }
    if(simbolo2==NULL){
        char mensaje[256];
        snprintf(mensaje, sizeof(mensaje), "El identificador: '%s' no ha sido definido", nombre2);
        insertarError(mensaje, linea);
        return 0;
    }
    if(strcmp(simbolo1->categoria,"estructura")!=0){
        char mensaje[256];
        snprintf(mensaje, sizeof(mensaje), "El identificador: '%s' no es una estructura", nombre);
        insertarError(mensaje, linea);
        return 0;
    }
    if(strcmp(simbolo2->categoria,"miembro")!=0){
        char mensaje[256];
        snprintf(mensaje, sizeof(mensaje), "El identificador: '%s' no es un miembro", nombre);
        insertarError(mensaje, linea);
        return 0;
    }
    if(strcmp(simbolo1->ambito,simbolo2->ambito)!=0){
        char mensaje[256];
        snprintf(mensaje, sizeof(mensaje), "El miembro: '%s' no pertenece a la estructura", nombre);
        insertarError(mensaje, linea);
        return 0;
    }
    return 1;

}
int validarID(const char* id,int linea){
    Simbolo* simbolo=buscarSimbolo(id);
    if(simbolo!=NULL && strcmp(simbolo->categoria,"miembro")==0){
        char mensaje[256];
        snprintf(mensaje, sizeof(mensaje), "El identificador: '%s' no ha sido declarado", id);
        insertarError(mensaje, linea);
        return 1;
    }
}
bool esOperadorLogico(char c) {
    return (c == '=' || c == '!' || c == '<' || c == '>' || c == '&' || c == '|');
}

bool esOperadorLogicoCompleto(const char* op) {
    return (strcmp(op, "==") == 0 || 
            strcmp(op, "!=") == 0 || 
            strcmp(op, "<") == 0 || 
            strcmp(op, ">") == 0 || 
            strcmp(op, "<=") == 0 || 
            strcmp(op, ">=") == 0 || 
            strcmp(op, "&&") == 0 || 
            strcmp(op, "||") == 0);
}
bool esIdentificador(char c, bool esPrimerCaracter) {
    if (esPrimerCaracter) {
        return isalpha(c) || c == '_';
    } else {
        return isalnum(c) || c == '_';
    }
}
int validarExpresionLogica(const char* expresion, const char* ambito, int bloque, int linea) {
    int longitud = strlen(expresion);
    if (longitud == 0) {
        insertarError("Expresion logica vacia", linea);
        return 0;
    }
    
    char operando1[128] = "";
    char operando2[128] = "";
    char operador[3] = "";
    int estado = 0; 
    int pos_operando1 = 0;
    int pos_operador = 0;
    int pos_operando2 = 0;
    
    for (int i = 0; i < longitud; i++) {
        char c = expresion[i];
        
        // Ignorar espacios
        if (isspace(c)) {
            continue;
        }
        
        switch (estado) {
            case 0: // Esperando operando1
                if (esIdentificador(c, true) || isdigit(c)) {
                    operando1[pos_operando1++] = c;
                    estado = 1;
                } else {
                    char mensaje[128];
                    snprintf(mensaje, sizeof(mensaje), "Caracter inesperado '%c' al inicio de la expresion logica", c);
                    insertarError(mensaje, linea);
                    return 0;
                }
                break;
                
            case 1: // En operando1
                if (esIdentificador(c, false) || isdigit(c)) {
                    if (pos_operando1 < sizeof(operando1) - 1) {
                        operando1[pos_operando1++] = c;
                    } else {
                        insertarError("Operando 1 demasiado largo en expresión logica", linea);
                        return 0;
                    }
                } else if (esOperadorLogico(c)) {
                    operando1[pos_operando1] = '\0';
                    operador[pos_operador++] = c;
                    estado = 3;
                } else {
                    char mensaje[128];
                    snprintf(mensaje, sizeof(mensaje), "Caracter inesperado '%c' en operando 1 de expresion logica", c);
                    insertarError(mensaje, linea);
                    return 0;
                }
                break;
                
            case 2: // Esperando operador
                if (esOperadorLogico(c)) {
                    operador[pos_operador++] = c;
                    estado = 3;
                } else {
                    insertarError("Se esperaba un operador logico", linea);
                    return 0;
                }
                break;
                
            case 3: // En operador
                if (esOperadorLogico(c) && pos_operador < sizeof(operador) - 1) {
                    operador[pos_operador++] = c;
                } else if (esIdentificador(c, true) || isdigit(c)) {
                    operador[pos_operador] = '\0';
                    operando2[pos_operando2++] = c;
                    estado = 5;
                } else {
                    char mensaje[128];
                    snprintf(mensaje, sizeof(mensaje), "Caracter inesperado '%c' en operador de expresion logica", c);
                    insertarError(mensaje, linea);
                    return 0;
                }
                break;
                
            case 4: // Esperando operando2
                if (esIdentificador(c, true) || isdigit(c)) {
                    operando2[pos_operando2++] = c;
                    estado = 5;
                } else {
                    insertarError("Se esperaba un segundo operando en expresion logica", linea);
                    return 0;
                }
                break;
                
            case 5: // En operando2
                if (esIdentificador(c, false) || isdigit(c)) {
                    if (pos_operando2 < sizeof(operando2) - 1) {
                        operando2[pos_operando2++] = c;
                    } else {
                        insertarError("Operando 2 demasiado largo en expresión logica", linea);
                        return 0;
                    }
                } else {
                    char mensaje[128];
                    snprintf(mensaje, sizeof(mensaje), "Caracter inesperado '%c' en operando 2 de expresion logica", c);
                    insertarError(mensaje, linea);
                    return 0;
                }
                break;
        }
    }
    
    // Finalizar las cadenas
    operando1[pos_operando1] = '\0';
    operador[pos_operador] = '\0';
    operando2[pos_operando2] = '\0';
    
    // Validar el operador
    if (!esOperadorLogicoCompleto(operador)) {
        char mensaje[128];
        snprintf(mensaje, sizeof(mensaje), "Operador '%s' no valido en expresion logica", operador);
        insertarError(mensaje, linea);
        return 0;
    }
    
    // Validar que tengamos dos operandos
    if (strlen(operando1) == 0 || strlen(operando2) == 0) {
        insertarError("Falta uno o ambos operandos en expresion logica", linea);
        return 0;
    }
    
    // Verificar si los operandos son números o variables
    if (!isdigit(operando1[0])) {
        // Es una variable, verificar si existe usando buscarSimbolo
        Simbolo* simbolo = buscarSimbolo(operando1);
        if (simbolo == NULL) {
            char mensaje[128];
            snprintf(mensaje, sizeof(mensaje), "La variable '%s' no ha sido declarada", operando1);
            insertarError(mensaje, linea);
            return 0;
        }
        
        // Verificar la anidación/ámbito utilizando validarAnidacion
        if (strcmp(simbolo->ambito, "global") != 0) {
            int verificacion = validarAnidacion(operando1, ambito, simbolo->ambito, bloque, linea);
            if (verificacion == 1) {
                char mensaje[128];
                snprintf(mensaje, sizeof(mensaje), "El identificador: '%s' no ha sido definido en este ambito", operando1);
                insertarError(mensaje, linea);
                return 0;
            }
        }
        
        // Verificar que el tipo sea compatible con una expresión lógica (entero, flotante, booleano)
        if (strcmp(simbolo->tipo, "entero") != 0 && 
            strcmp(simbolo->tipo, "flotante") != 0 && 
            strcmp(simbolo->tipo, "booleano") != 0) {
            char mensaje[128];
            snprintf(mensaje, sizeof(mensaje), "La variable '%s' de tipo '%s' no es valida en una expresion logica", 
                    operando1, simbolo->tipo);
            insertarError(mensaje, linea);
            return 0;
        }
    }
    
    if (!isdigit(operando2[0])) {
        // Es una variable, verificar si existe usando buscarSimbolo
        Simbolo* simbolo = buscarSimbolo(operando2);
        if (simbolo == NULL) {
            char mensaje[128];
            snprintf(mensaje, sizeof(mensaje), "La variable '%s' no ha sido declarada", operando2);
            insertarError(mensaje, linea);
            return 0;
        }
        
        // Verificar la anidación/ámbito utilizando validarAnidacion
        if (strcmp(simbolo->ambito, "global") != 0) {
            int verificacion = validarAnidacion(operando2, ambito, simbolo->ambito, bloque, linea);
            if (verificacion == 1) {
                char mensaje[128];
                snprintf(mensaje, sizeof(mensaje), "El identificador: '%s' no ha sido definido en este ambito", operando2);
                insertarError(mensaje, linea);
                return 0;
            }
        }
        
        // Verificar que el tipo sea compatible con una expresión lógica (entero, flotante, booleano)
        if (strcmp(simbolo->tipo, "entero") != 0 && 
            strcmp(simbolo->tipo, "flotante") != 0 && 
            strcmp(simbolo->tipo, "booleano") != 0) {
            char mensaje[128];
            snprintf(mensaje, sizeof(mensaje), "La variable '%s' de tipo '%s' no es valida en una expresion logica", 
                    operando2, simbolo->tipo);
            insertarError(mensaje, linea);
            return 0;
        }
    }
    
    return 1; // La expresión es válida
}
int validarelegir(const char* nombre,const char* ambito,int bloque,int linea){
    Simbolo* simbolo=buscarSimbolo(nombre);
    if(simbolo != NULL){
        if (strcmp(ambito, "global") == 0 && strcmp(simbolo->ambito, "global") != 0) {
            char mensaje[256];
            snprintf(mensaje, sizeof(mensaje), "el identificador: '%s' no ha sido definido", nombre);
            insertarError(mensaje, linea);
            return 0;
        }
         int verificacion = validarAnidacion(nombre, ambito, simbolo->ambito, bloque, linea);
    
        if (verificacion == 1) {
            char mensaje[256];
            snprintf(mensaje, sizeof(mensaje), "el identificador: '%s' no ha sido definido", nombre);
            insertarError(mensaje, linea);
            return 0;
        }else{
            for (int i = 0; i < numSimbolos; ) {
                if (strcmp(tablaSimbolos[i].categoria, "caso") == 0 &&
                    strcmp(tablaSimbolos[i].tipo, "indefinido") == 0) {
                    expresiones(simbolo->nombre, simbolo->tipo, "caso",
                                tablaSimbolos[i].ambito, "N/A",
                                tablaSimbolos[i].nombre, tablaSimbolos[i].linea,
                                tablaSimbolos[i].bloque);

                    for (int j = i; j < numSimbolos - 1; j++) {
                        tablaSimbolos[j] = tablaSimbolos[j + 1];
                    }
                    numSimbolos--; 
                } else {
                    i++; 
                }
            }

        }
    }else{
        char mensaje[256];
        snprintf(mensaje, sizeof(mensaje), "el identificador: '%s' no ha sido definido", nombre);
        insertarError(mensaje, linea);
        return 0;
    }
    return 0;
}
void mostrarErroresSemanticos() {
    if (numErrores > 0) {
        printf("=== Errores semanticos ===\n");
    }
    for (int i = 0; i < numErrores; i++) {
        printf("Error en la linea %d: %s\n", erroresSemanticos[i].linea, erroresSemanticos[i].mensaje);
    }
}