%{

#include <stdio.h>
#include <string.h>
#define MAX_ERRORES 100 //manejo de errores
typedef struct {
    int tipoError;
    int linea;
} ErrorSintactico;

int numErroresSintacticos = 0;
ErrorSintactico listaErrores[MAX_ERRORES];

void agregarError(int tipoError, int linea); 
int errorYaRegistrado(int tipoError, int linea); 
void mostrarErrores();

extern int yylineno;
extern int yylex(void);
extern int numErroresLex;
extern int numTokens;
extern int numComentarios;
int errores_sintacticos = 0;
int error_manejado = 0; // Bandera para errores ya manejados

void yyerror(const char *s);
%}

%union {
    int    entero;
    float  flotante;
    char   caracter;
    char*  cadena;
}

/*%token y %left %right  */// (directivas de precedencia si quieres agregar operadores)

// Simbolos terminales
%token <entero> ENTERO
%token <flotante> FLOTANTE
%token <caracter> CARACTER
%token <cadena> CADENA

%token  SI SINOSI SINO ELEGIR CASO DEFECTO MIENTRAS PARA HACER DEVOLVER
%token  ROMPER CONTINUAR
%token  IMPRIMIR LEER
%token  ERROR

%nonassoc SI /*Manejo para if*/
%nonassoc SINO
%nonassoc SINOSI /* Manejo para if else if*/
%nonassoc IMPRIMIR LEER  

%token  ESTRUCTURA
%token  VOID
%token  CONSTANTE
%token OR AND IGUAL DIFERENTE MENORIGUAL MAYORIGUAL INCREMENTO DECREMENTO
%token  ENTERO_T FLOTANTE_T CARACTER_T BOOLEANO_T CADENA_T
%token  VERDADERO FALSO
%token  ID 
%token  ':'

/* Precedencias y asociatividad 
%left indica asociatividad izquierda 
%right indica asociatividad derecha */
%left OR
%left AND
%left IGUAL DIFERENTE
%left '<' '>' MENORIGUAL MAYORIGUAL
%left '+' '-'
%left '*' '/' '%'
%right '='   // asignacion es asociativa a la derecha
%right '!' INCREMENTO DECREMENTO
%left '(' ')' '.' '[' ']'
%left ','

/*    simbolos no terminales
*/
%start programa

%%

/*Reglas de produccion o Gramatica desglosada*/
programa
    : vacio
    | declaraciones
    ;

declaraciones
    : declaraciones declaracion
    | declaracion 
    ;

declaracion
    : funcion
    | estructura
    | variable
    | constante
    | arreglo
    | sentencia
    ;

bloque
    : '{' lista_declaraciones '}'
    | '{' lista_declaraciones error {
        agregarError(1, yylineno); // Falta '}'
        yyerrok;
        errores_sintacticos++; // Solo 1 error
    }
    | error lista_declaraciones '}' {
        agregarError(2, yylineno); // Falta '{'
        yyerrok;
        errores_sintacticos++; // Solo 1 error
    }
    | sentencia {  // Caso especial para cuerpos sin llaves
        // Solo marcar falta de apertura, el cierre puede ser el } siguiente
        agregarError(2, yylineno); // Falta '{'
        errores_sintacticos++;
        // No usar yyerrok aquí para permitir detectar } como cierre
    }
    ;

lista_declaraciones
    : vacio
    | lista_declaraciones declaracion
    ;

tipo
    : tipo_base
    | CONSTANTE tipo_base
    | ID
    ;

tipo_base
    : ENTERO_T
    | FLOTANTE_T
    | CARACTER_T
    | BOOLEANO_T
    | ID
    | CADENA_T
    ;

variable
    : tipo ID ';'
    | tipo ID error  {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    }
    |  tipo ID '=' expresion ';'
    | tipo ID error expresion ';' {  // Falta '='
        agregarError(8, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    }
    |  tipo ID '=' expresion error  {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    }
    ;

constante
    : CONSTANTE tipo_base ID '=' expresion ';'
    | CONSTANTE tipo_base ID error expresion ';'  {  // Falta '='
        agregarError(8, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    }
    | CONSTANTE tipo_base ID '=' expresion error  {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    }
    ;

arreglo
    : tipo ID '[' tamano ']' ';'
    | tipo ID error tamano ']' ';'    {  // Falta '['
        agregarError(6, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    }
    | tipo ID '[' tamano error ';'    {  // Falta ']'
        agregarError(7, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    }
    | tipo ID '[' tamano ']' error  {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    } 
    | tipo ID '[' tamano ']' '=' '{' lista_expresiones '}' ';'
    | tipo ID '[' tamano ']' error '{' lista_expresiones '}' ';'  {  // Falta '='
        agregarError(8, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    }
    | tipo ID ']' tamano ']' '=' '{' lista_expresiones '}' ';' {
        agregarError(6, yylineno); // Se esperaba '[' y se encontró ']'
        yyerrok;
        numErroresSintacticos++;
    }
    | tipo ID ']' tamano ']' ';' {
        agregarError(6, yylineno); // Se esperaba '[' y se encontró ']'
        yyerrok;
        numErroresSintacticos++;
    }
    | tipo ID error tamano ']' '=' '{' lista_expresiones '}' ';' {  // Falta '['
        agregarError(6, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    }
    | tipo ID '[' tamano error '=' '{' lista_expresiones '}' ';'    {  // Falta ']'
        agregarError(7, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    }
    | tipo ID '[' tamano ']' '=' '{' lista_expresiones '}' error  {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    }
    | tipo ID '[' tamano ']' '=' '{' lista_expresiones error ';' {
        agregarError(1, yylineno ); //falta  '}' cierre
        yyerrok;
        numErroresSintacticos++;
    }
    | tipo ID '[' tamano ']' '=' error lista_expresiones '}' ';' {
        agregarError(2, yylineno ); //falta  '}' cierre
        yyerrok;
        numErroresSintacticos++;
    }
    | tipo ID ']' error {
        agregarError(6, yylineno); // Se esperaba '[' y se encontró ']'
        yyerrok;
        numErroresSintacticos++;
    }
    | tipo ID error '=' '{' lista_expresiones '}' ';' {
        agregarError(6, yylineno); // Se esperaba '['
        yyerrok;
        numErroresSintacticos++;
    }

    ;

tamano
    : ENTERO
    | ID
    ;

lista_expresiones
    : expresion
    | lista_expresiones ',' expresion
    | lista_expresiones error expresion   {
        agregarError(11, yylineno ); //falta  ':' 
        yyerrok;
        numErroresSintacticos++;
    }
    ;

sentencia
    : expr_sent
    | si
    | elegir
    | bucle
    | retorno
    | romper
    | CONTINUAR ';'
    | CONTINUAR error {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    }
    ;

estructura
    : ESTRUCTURA ID '{' miembros '}' ';'
    | ESTRUCTURA ID '{' miembros '}' error {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    }
    | ESTRUCTURA ID '{' miembros error ';' {
        agregarError(1, yylineno ); //falta  '}' cierre
        yyerrok;
        numErroresSintacticos++;
    }
    |ESTRUCTURA ID error miembros '}' ';' {
        agregarError(2, yylineno ); //falta  '{' cierre
        yyerrok;
        numErroresSintacticos++;
    }
    ;

miembros
    : vacio
    | miembro miembros
    ;

miembro
    : tipo ID ';'
    | tipo ID error {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    } 
    | tipo ID '=' expresion ';'
    | tipo ID error expresion ';' {  // Falta '='
        agregarError(8, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    }
    | tipo ID '=' expresion  error {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    }
    ;

expr_sent
    : expresion ';'
    | expresion error {  // Falta ';'
        agregarError(5, yylineno );
        yyerrok;
        numErroresSintacticos++;
    }
    | IMPRIMIR '(' argumentos ')' ';'
    | IMPRIMIR '(' argumentos ')' error {
        agregarError(5, yylineno );  // Falta ';'
        yyerrok;
        numErroresSintacticos++;
    }
    | IMPRIMIR error argumentos ')' ';' {
        agregarError(3, yylineno );  // Falta '('
        yyerrok;
        numErroresSintacticos++;
    }
    | IMPRIMIR '(' argumentos error ';' {
        agregarError(4, yylineno );  // Falta ')'
        yyerrok;
        numErroresSintacticos++;
    }
    | LEER '(' ID ')' ';'
    | LEER error ID ')' ';' {
        agregarError(3, yylineno );  // Falta '('
        yyerrok;
        numErroresSintacticos++;
    }
    | LEER '(' ID error ';' {
        agregarError(4, yylineno );  // Falta ')'
        yyerrok;
        numErroresSintacticos++;
    }
    ;


si
    : SI '(' expresion ')' bloque sinosi_opt
    | SI error expresion ')' bloque sinosi_opt {  // Falta '('
        agregarError(3, yylineno);
        yyerrok;
        numErroresSintacticos++;
    }
    | SI '(' expresion error bloque sinosi_opt {  // Falta ')'
        agregarError(4, yylineno);
        yyerrok;
        numErroresSintacticos++;
    }
    | SI '(' expresion ')' error sinosi_opt {  // Falta bloque
        agregarError(1, yylineno);  // Reutilizamos "falta '}'" como indicador de bloque incompleto
        yyerrok;
        numErroresSintacticos++;
    }
    ;

sinosi_opt
    : vacio
    | SINOSI '(' expresion ')' bloque sinosi_opt
    | SINOSI error expresion ')' bloque sinosi_opt {  // Falta '('
        agregarError(3, yylineno);
        yyerrok; numErroresSintacticos++;
    }
    | SINOSI '(' expresion error bloque sinosi_opt {  // Falta ')'
        agregarError(4, yylineno);
        yyerrok; numErroresSintacticos++;
    }
    | SINOSI '(' expresion ')' error sinosi_opt {  // Falta bloque
        agregarError(1, yylineno);
        yyerrok; numErroresSintacticos++;
    }
    | SINO bloque
    | SINO SI '(' expresion ')' bloque {
        yyerror("ERROR SINTACTICO: se esperaba 'sinosi', no 'sino si'");
        agregarError(9, yylineno);
        yyerrok; 
        numErroresSintacticos++;
    }
    | SINO error {  // Falta bloque
        agregarError(1, yylineno);
        yyerrok; numErroresSintacticos++;
    }
    ;


elegir
    : ELEGIR '(' expresion ')' '{' casos '}'
    | ELEGIR '(' expresion ')' '{' casos error {
        agregarError(1, yylineno ); //falta  '}' cierre
        yyerrok;
        numErroresSintacticos++;
    }
    |ELEGIR '(' expresion ')' error casos '}' {
        agregarError(2, yylineno ); //falta  '{' cierre
        yyerrok;
        numErroresSintacticos++;
    }
    ;

casos
    : lista_casos defecto_opt
    ;

lista_casos
    : vacio
    | lista_casos caso
    ;

defecto_opt
    : vacio
    | defecto
    ;

caso
    : CASO expresion ':' sentencias
    | CASO expresion error sentencias   {  // Falta ':'
        agregarError(10, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    }
    ;

sentencias
    : sentencia
    | sentencias sentencia
    ;

defecto
    : DEFECTO ':' sentencias
    | DEFECTO error sentencias {  // Falta ':'
        agregarError(10, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    }
    ;


romper
    : ROMPER ';'
    | ROMPER error {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    }
    ;

bucle
    : mientras
    | para
    | hacer_mientras
    ;

mientras
    : MIENTRAS '(' expresion ')' bloque
    | MIENTRAS error expresion ')' bloque {
        agregarError(3, yylineno ); //falta  '(' abrir
        yyerrok;
        numErroresSintacticos++;
        //fprintf(stderr, "   : '(' de abertura. Linea: %d - %d - %d \n", yyerrok, yylineno, numErroresSintacticos);
    }
    | MIENTRAS '(' expresion error bloque {
        agregarError(4, yylineno ); //falta  ')' cierre
        yyerrok;
        numErroresSintacticos++;
        //fprintf(stderr, "   : ')' de abertura. Linea: %d - %d - %d \n", yyerrok, yylineno, numErroresSintacticos);
    }
    ;

para
    : PARA '(' inicializacion_for ';' expresion ';' expresion ')' bloque
    | PARA '(' inicializacion_for error expresion ';' expresion ')' bloque {
        agregarError(5, yylineno ); // Falta ';'
        yyerrok;
        numErroresSintacticos++;
    }
    | PARA '(' inicializacion_for ';' expresion error expresion ')' bloque {
        agregarError(5, yylineno ); // Falta ';'
        yyerrok;
        numErroresSintacticos++;
    }
    | PARA error inicializacion_for ';' expresion ';' expresion ')' bloque {
        agregarError(3, yylineno ); // Falta '('
        yyerrok;
        numErroresSintacticos++;
    }
    | PARA '(' inicializacion_for ';' expresion ';' expresion error bloque {
        agregarError(4, yylineno ); // Falta ')'
        yyerrok;
        numErroresSintacticos++;
    }
    ;


inicializacion_for
    : decl_var_inicializacion
    | expresion
    | vacio
    ;
    
decl_var_inicializacion
    : tipo ID '=' expresion
    | tipo ID error expresion {  // Falta '='
        agregarError(8, yylineno );
        yyerrok;
        numErroresSintacticos++;
    }
    ;


hacer_mientras
    : HACER bloque MIENTRAS '(' expresion ')' ';'
    | HACER bloque MIENTRAS '(' expresion ')' error {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    }
    | HACER bloque MIENTRAS error expresion ')' ';'   {
        agregarError(3, yylineno ); //falta  '(' abrir
        yyerrok;
        numErroresSintacticos++;
    }
    | HACER bloque MIENTRAS '(' expresion error ';'  {
        agregarError(4, yylineno ); //falta  ')' cierre
        yyerrok;
        numErroresSintacticos++;
    }
    ;

retorno
    : DEVOLVER expresion ';'
    | DEVOLVER expresion error {  // Falta ';'
        agregarError(5, yylineno ); 
        yyerrok;
        numErroresSintacticos++;
    }
    ;

funcion
    : tipo ID '(' parametros ')' bloque
    | tipo ID '(' ')' bloque
    | tipo ID error parametros ')' bloque   {
        agregarError(3, yylineno); //falta '(' abrir
        yyerrok;
        numErroresSintacticos++;
    }
    | tipo ID '(' parametros error bloque  {
        agregarError(4, yylineno); //falta ')' cierre
        yyerrok;
        numErroresSintacticos++;
    }
    | tipo ID '(' parametros ')' error {
        agregarError(2, yylineno); // Falta llave de apertura {
        yyerrok;
        numErroresSintacticos++;
    }
    | VOID ID '(' parametros ')' bloque
    | VOID ID '(' ')' bloque 
    | VOID ID error parametros ')' bloque   {
        agregarError(3, yylineno); //falta '(' abrir
        yyerrok;
        numErroresSintacticos++;
    }
    | VOID ID '(' parametros error bloque  {
        agregarError(4, yylineno); //falta ')' cierre
        yyerrok;
        numErroresSintacticos++;
    }
    | tipo ID '(' ')' error {
        agregarError(2, yylineno); // Falta llave de apertura {
        yyerrok;
        numErroresSintacticos++;
    }
    ;

parametros
    : parametro
    | parametro ',' parametros
    | parametro error parametros  {
        agregarError(11, yylineno ); //falta  ')' cierre
        yyerrok;
        numErroresSintacticos++;
    }
    | vacio
    ;

parametro
    : tipo ID 
    ;

expresion
    : asignacion
    | logica_or
    ;

asignacion
    : lvalor '=' expresion
    | lvalor error expresion {  // Falta '='
        agregarError(8, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    }
    ;

lvalor
    : ID
    | ID '[' expresion ']'
    | ID error expresion ']' {  // Falta '['
        agregarError(6, yylineno); 
        yyerrok;
        numErroresSintacticos++;
    }
    | ID '[' expresion error {  // Falta ']'
        agregarError(7, yylineno); 
        yyerrok;
        numErroresSintacticos++;
    }
    | ID '.' ID
    ;

logica_or
    : logica_and OR logica_and
    | logica_and
    ;

logica_and
    : igualdad AND igualdad
    | igualdad
    ;

igualdad
    : relacional IGUAL relacional
    | relacional DIFERENTE relacional
    | relacional
    ;

relacional
    : aditiva '<' aditiva
    | aditiva MENORIGUAL aditiva
    | aditiva '>' aditiva
    | aditiva MAYORIGUAL aditiva
    | aditiva
    ;

aditiva
    : multiplicativa '+' multiplicativa
    | multiplicativa '-' multiplicativa
    | multiplicativa
    ;

multiplicativa
    : unaria '*' unaria
    | unaria '/' unaria
    | unaria '%' unaria
    | unaria
    ;

unaria
    : '!' unaria
    | '-' unaria
    | INCREMENTO unaria
    | DECREMENTO unaria
    | postfija
    ;

postfija
    : primaria INCREMENTO
    | primaria DECREMENTO
    | primaria
    ;

primaria
    : literal
    | ID
    | ID '(' argumentos ')'
    | ID error argumentos ')'  {
        agregarError(3, yylineno ); //falta  '(' abrir
        yyerrok;
        numErroresSintacticos++;
    }
    | ID '(' argumentos error  {
        agregarError(4, yylineno ); //falta  ')' cierre
        yyerrok;
        numErroresSintacticos++;
    }
    | ID '[' expresion ']'
    | error expresion ']' {  // Falta '['
        agregarError(6, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    }
    | '[' expresion error    {  // Falta ']'
        agregarError(7, yylineno ); // 
        yyerrok;
        numErroresSintacticos++;
    }
    | ID '.' ID
    | '(' expresion ')'
    | error expresion ')'  {
        agregarError(3, yylineno ); //falta  '(' abrir
        yyerrok;
        numErroresSintacticos++;
    }
    | '(' expresion error  {
        agregarError(4, yylineno ); //falta  ')' cierre
        yyerrok;
        numErroresSintacticos++;
    }
    ;
argumentos
    : vacio
    | lista_expresiones
    ;

literal
    : ENTERO
    | FLOTANTE
    | CARACTER
    | VERDADERO
    | FALSO
    | CADENA
    ;


vacio 
    :
    ;

%%
void yyerror(const char *msg) {
    // Solo contar errores no manejados explícitamente
    if (strstr(msg, "syntax error") && !error_manejado) {
        errores_sintacticos++;
    }
    error_manejado = 0;  // Resetear para el próximo error
}
int errorYaRegistrado(int tipoError, int linea) {
    int i;
    for ( i = 0; i < numErroresSintacticos; i++) {
        if (listaErrores[i].tipoError == tipoError && listaErrores[i].linea == linea) {
            return 1; // ya existe
        }
    }
    return 0;
}

void agregarError(int tipoError, int linea) {
    // Verificar si ya existe un error idéntico
    for (int i = 0; i < numErroresSintacticos; i++) {
        if (listaErrores[i].tipoError == tipoError && 
            listaErrores[i].linea == linea) {
            return;  // Error ya registrado
        }
    }
    
    if (numErroresSintacticos < MAX_ERRORES) {
        listaErrores[numErroresSintacticos].tipoError = tipoError;
        listaErrores[numErroresSintacticos].linea = linea;
        numErroresSintacticos++;
        errores_sintacticos++;  // Incrementar el contador general
    }
}

void mostrarErrores() {
    for (int i = 0; i < numErroresSintacticos; i++) {
        switch (listaErrores[i].tipoError) {
            case 1:
                fprintf(stderr, "   Error sintactico: falta simbolo '}' de cierre. Linea:  %d\n", listaErrores[i].linea);
                break;
            case 2:
                fprintf(stderr, "   Error sintactico: falta simbolo '{ ' de abertura. Linea: %d\n", listaErrores[i].linea);
                break;
            case 3:
                fprintf(stderr, "   Error sintactico: falta simbolo '(' de abertura. Linea: %d\n", listaErrores[i].linea);
                break;
            case 4:
                fprintf(stderr, "   Error sintactico: falta simbolo ')' de cierre. Linea: %d\n", listaErrores[i].linea);
                break;
            case 5:
                fprintf(stderr, "   Error sintactico: falta simbolo ';' de cierre. Linea::  %d\n", listaErrores[i].linea);
                break;
            case 6:
                fprintf(stderr, "   Error sintactico: falta simbolo '[' de abertura. Linea:  %d\n", listaErrores[i].linea);
                break;
            case 7:
                fprintf(stderr, "   Error sintactico: falta simbolo ']' de cierre. Linea:  %d\n", listaErrores[i].linea);
                break;
            case 8:
                fprintf(stderr, "   Error sintactico: falta simbolo '=' de asignacion. Linea:  %d\n", listaErrores[i].linea);
                break;
           case 9:
                fprintf(stderr, "   Error sintactico: se uso 'sino si' en lugar de 'sinosi'. Linea: %d\n", listaErrores[i].linea);
                break;
            case 10:
                fprintf(stderr, "   Error sintactico: falta simbolo ':' de asignacion. Linea:  %d\n", listaErrores[i].linea);
                break;
            case 11:
                fprintf(stderr, "   Error sintactico: falta simbolo ',' de asignacion. Linea:  %d\n", listaErrores[i].linea);
                break;
        }
    }
}