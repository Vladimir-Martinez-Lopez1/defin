%{
#include "tokens.h" // Incluye el archivo de definición de tokens
#include "parser.tab.h" // Incluye el archivo de definición de tokens para el parser
#include <stdio.h> // Incluye la biblioteca estándar de entrada/salida
#include <string.h>
int numTokens = 0;      // Contador de tokens reconocidos
int numErroresLex = 0;  // Contador de errores léxicos
int numComentarios = 0; // Contador de comentarios
int yylineno = 1;       // Contador de líneas, comienza en 1
%}
%x COMMENT 
%%
"//".* {agregarToken("COMENTARIO_LINEA",yytext,yylineno);printf("TOKEN_COMENTARIO (linea %d)\n",yylineno);numComentarios++;}//[ \t\r\n]+ {yylineno++;} // Ignorar espacios en blanco y saltos de línea
"/." {agregarToken("COMENTARIO_BLOQUE_INI",yytext,yylineno);BEGIN(COMMENT);numComentarios++;}// Inicia el bloque de comentario
<COMMENT>"./" {agregarToken("COMENTARIO_BLOQUE_FIN",yytext,yylineno);BEGIN(INITIAL);} // Termina el bloque de comentario
<COMMENT>\n {yylineno++;}
<COMMENT><<EOF>> {agregarToken("ERROR_COMENTARIO_NO_CERRADO",yytext,yylineno);printf("ERROR: comentario no cerrado (linea %d)\n",yylineno);numErroresLex++;BEGIN(INITIAL);}// Manejar el final del archivo
<COMMENT>. {}

"entero" {agregarToken("TIPO_DATO","entero",yylineno);yylval.cadena=strdup("entero");printf("TOKEN_TIPO_DATO: entero (linea %d)\n",yylineno);numTokens++;return ENTERO_T;} // Definición de token para entero
"flotante" {agregarToken("TIPO_DATO","flotante",yylineno);yylval.cadena=strdup("flotante");printf("TOKEN_TIPO_DATO: flotante (linea %d)\n",yylineno);numTokens++;return FLOTANTE_T;}// Definición de token para flotante
"cadena" {agregarToken("TIPO_DATO","cadena",yylineno);yylval.cadena=strdup("cadena");printf("TOKEN_TIPO_DATO: cadena (linea %d)\n",yylineno);numTokens++;return CADENA_T;}// Definición de token para cadena
"caracter" {agregarToken("TIPO_DATO","caracter",yylineno);yylval.cadena=strdup("caracter");printf("TOKEN_TIPO_DATO: caracter (linea %d)\n",yylineno);numTokens++;return CARACTER_T;}// Definición de token para caracter
"booleano" {agregarToken("TIPO_DATO","booleano",yylineno);yylval.cadena=strdup("booleano");printf("TOKEN_TIPO_DATO: booleano (linea %d)\n",yylineno);numTokens++;return BOOLEANO_T;}// Definición de token para booleano
"estructura" {agregarToken("PALABRA_RESERVADA","estructura",yylineno);printf("TOKEN_ESTRUCTURA: estructura (linea %d)\n",yylineno);numTokens++;return ESTRUCTURA;}// Definición de token para estructura

"sino"[ \t\n\r]+"si" {agregarToken("ERROR_SINO_SI",yytext,yylineno);printf("ERROR: 'sino si' debería ser 'sinosi' (linea %d)\n",yylineno);numErroresLex++;return ERROR;}//  Definición de token para "sino si"

"si" {agregarToken("PALABRA_RESERVADA","si",yylineno);printf("TOKEN_IF: %s (linea %d)\n",yytext,yylineno);numTokens++;return SI;}// Definición de token para si
"sino" {agregarToken("PALABRA_RESERVADA","sino",yylineno);printf("TOKEN_ELSE: %s (linea %d)\n",yytext,yylineno);numTokens++;return SINO;}// Definición de token para sino
"sinosi" {agregarToken("PALABRA_RESERVADA","sinosi",yylineno);printf("TOKEN_ELSE_IF: %s (linea %d)\n",yytext,yylineno);numTokens++;return SINOSI;}// Definición de token para sino si
"mientras" {agregarToken("PALABRA_RESERVADA","mientras",yylineno);printf("TOKEN_WHILE (linea %d)\n",yylineno);numTokens++;return MIENTRAS;}// Definición de token para mientras
"para" {agregarToken("PALABRA_RESERVADA","para",yylineno);printf("TOKEN_FOR (linea %d)\n",yylineno);numTokens++;return PARA;}// Definición de token para para
"devolver" {agregarToken("PALABRA_RESERVADA","devolver",yylineno);printf("TOKEN_CONTROL: devolver (linea %d)\n",yylineno);numTokens++;return DEVOLVER;}// Definición de token para devolver
"romper" {agregarToken("PALABRA_RESERVADA","romper",yylineno);printf("TOKEN_CONTROL: romper (linea %d)\n",yylineno);numTokens++;return ROMPER;}// Definición de token para romper
"continuar" {agregarToken("PALABRA_RESERVADA","continuar",yylineno);printf("TOKEN_CONTROL: continuar (linea %d)\n",yylineno);numTokens++;return CONTINUAR;}// Definición de token para continuar
"leer" {agregarToken("PALABRA_RESERVADA","leer",yylineno);printf("TOKEN_FUNCION: leer (linea %d)\n",yylineno);numTokens++;return LEER;}// Definición de token para leer
"imprimir" {agregarToken("PALABRA_RESERVADA","imprimir",yylineno);printf("TOKEN_FUNCION: imprimir (linea %d)\n",yylineno);numTokens++;return IMPRIMIR;}// Definición de token para imprimir
"void" {agregarToken("TIPO_DATO","void",yylineno);yylval.cadena=strdup("void");printf("TOKEN_TIPO_DATO: void (linea %d)\n",yylineno);numTokens++;return VOID;}// Definición de token para void
"elegir" {agregarToken("PALABRA_RESERVADA","elegir",yylineno);printf("TOKEN_ELEGIR: elegir (linea %d)\n",yylineno);numTokens++;return ELEGIR;}// Definición de token para elegir
"caso" {agregarToken("PALABRA_RESERVADA","caso",yylineno);printf("TOKEN_CASO: caso (linea %d)\n",yylineno);numTokens++;return CASO;}// Definición de token para caso
"defecto" {agregarToken("PALABRA_RESERVADA","defecto",yylineno);printf("TOKEN_DEFECTO: defecto (linea %d)\n",yylineno);numTokens++;return DEFECTO;}// Definición de token para defecto
"hacer" {agregarToken("PALABRA_RESERVADA","hacer",yylineno);printf("TOKEN_HACER: hacer (linea %d)\n",yylineno);numTokens++;return HACER;}// Definición de token para hacer
"constante" {agregarToken("PALABRA_RESERVADA","constante",yylineno);printf("TOKEN_CONSTANTE: constante (linea %d)\n",yylineno);numTokens++;return CONSTANTE;}// Definición de token para constante

"verdadero" {agregarToken("VALOR_BOOLEANO","verdadero",yylineno);yylval.cadena=strdup("verdadero");printf("TOKEN_LITERAL: verdadero (linea %d)\n",yylineno);numTokens++;return VERDADERO;}// Definición de token para verdadero
"falso" {agregarToken("VALOR_BOOLEANO","falso",yylineno);yylval.cadena=strdup("falso");printf("TOKEN_LITERAL: falso (linea %d)\n",yylineno);numTokens++;return FALSO;}// Definición de token para falso

\"[^\"]*\" {agregarToken("LITERAL_CADENA",yytext,yylineno);yylval.cadena=strdup(yytext);printf("TOKEN_CADENA: %s (linea %d)\n",yytext,yylineno);numTokens++;return CADENA;}// Definición de token para cadena
[0-9]+"."[0-9]+ {agregarToken("LITERAL_FLOTANTE",yytext,yylineno);yylval.cadena=strdup(yytext);printf("TOKEN_FLOTANTE: %s (linea %d)\n",yytext,yylineno);numTokens++;return FLOTANTE;}// Definición de token para flotante
[0-9]+ {agregarToken("LITERAL_ENTERO",yytext,yylineno);yylval.cadena=strdup(yytext);printf("TOKEN_ENTERO: %s (linea %d)\n",yytext,yylineno);numTokens++;return ENTERO;}// Definición de token para entero
\'[^\']\' {agregarToken("LITERAL_CARACTER",yytext,yylineno);yylval.cadena=strdup(yytext);printf("TOKEN_CARACTER: %s (linea %d)\n",yytext,yylineno);numTokens++;return CARACTER;}// Definición de token para caracter

[a-zA-Z_][a-zA-Z0-9_]* {agregarToken("IDENTIFICADOR",yytext,yylineno);printf("TOKEN_IDENTIFICADOR: %s (linea %d)\n",yytext,yylineno);yylval.cadena=strdup(yytext);numTokens++;return ID;}// Definición de token para identificador

"=" {agregarToken("OPERADOR_ASIGNACION","=",yylineno);printf("TOKEN_ASIGNACION: = (linea %d)\n",yylineno);numTokens++;return '=';}// Definición de token para asignación
"++" {agregarToken("OPERADOR_INCREMENTO","++",yylineno);printf("TOKEN_INCREMENTO: ++ (linea %d)\n",yylineno);numTokens++;return INCREMENTO;}// Definición de token para incremento
"--" {agregarToken("OPERADOR_DECREMENTO","--",yylineno);printf("TOKEN_DECREMENTO: -- (linea %d)\n",yylineno);numTokens++;return DECREMENTO;}// Definición de token para decremento
"+" {agregarToken("OPERADOR_SUMA","+",yylineno);printf("TOKEN_MAS: + (linea %d)\n",yylineno);numTokens++;return '+';}// Definición de token para suma
"-" {agregarToken("OPERADOR_RESTA","-",yylineno);printf("TOKEN_MENOS: - (linea %d)\n",yylineno);numTokens++;return '-';}// Definición de token para resta
"*" {agregarToken("OPERADOR_MULT","*",yylineno);printf("TOKEN_MULT: * (linea %d)\n",yylineno);numTokens++;return '*';}// Definición de token para multiplicación
"/" {agregarToken("OPERADOR_DIV","/",yylineno);printf("TOKEN_DIV: / (linea %d)\n",yylineno);numTokens++;return '/';}// Definición de token para división
"%" {agregarToken("OPERADOR_MOD","%",yylineno);printf("TOKEN_MOD: %% (linea %d)\n",yylineno);numTokens++;return '%';}// Definición de token para módulo

"||" {agregarToken("OPERADOR_OR","||",yylineno);printf("TOKEN_OR: || (linea %d)\n",yylineno);numTokens++;return OR;}// Definición de token para OR
"&&" {agregarToken("OPERADOR_AND","&&",yylineno);printf("TOKEN_AND: && (linea %d)\n",yylineno);numTokens++;return AND;}// Definición de token para AND
"!" {agregarToken("OPERADOR_NOT","!",yylineno);printf("TOKEN_NEGACION: ! (linea %d)\n",yylineno);numTokens++;return '!';}// Definición de token para negación

"==" {agregarToken("OPERADOR_IGUALDAD","==",yylineno);printf("TOKEN_IGUAL: == (linea %d)\n",yylineno);numTokens++;return IGUAL;}// Definición de token para igualdad
"!=" {agregarToken("OPERADOR_DIFERENTE","!=",yylineno);printf("TOKEN_DIFERENTE: != (linea %d)\n",yylineno);numTokens++;return DIFERENTE;}// Definición de token para diferente
"<=" {agregarToken("OPERADOR_MENOR_IGUAL","<=",yylineno);printf("TOKEN_MENORIGUAL: <= (linea %d)\n",yylineno);numTokens++;return MENORIGUAL;}// Definición de token para menor o igual
">=" {agregarToken("OPERADOR_MAYOR_IGUAL",">=",yylineno);printf("TOKEN_MAYORIGUAL: >= (linea %d)\n",yylineno);numTokens++;return MAYORIGUAL;}// Definición de token para mayor o igual
"<" {agregarToken("OPERADOR_MENOR","<",yylineno);printf("TOKEN_MENOR: < (linea %d)\n",yylineno);numTokens++;return '<';}// Definición de token para menor
">" {agregarToken("OPERADOR_MAYOR",">",yylineno);printf("TOKEN_MAYOR: > (linea %d)\n",yylineno);numTokens++;return '>';}// Definición de token para mayor

"(" {agregarToken("DELIMITADOR_PAR_IZQ","(",yylineno);printf("TOKEN_PAR_IZQ: ( (linea %d)\n",yylineno);numTokens++;return '(';}// Definición de token para paréntesis izquierdo
")" {agregarToken("DELIMITADOR_PAR_DER",")",yylineno);printf("TOKEN_PAR_DER: ) (linea %d)\n",yylineno);numTokens++;return ')';}// Definición de token para paréntesis derecho
"[" {agregarToken("DELIMITADOR_CORCH_IZQ","[",yylineno);printf("TOKEN_CORCHETE_IZQ: [ (linea %d)\n",yylineno);numTokens++;return '[';}// Definición de token para corchete izquierdo
"]" {agregarToken("DELIMITADOR_CORCH_DER","]",yylineno);printf("TOKEN_CORCHETE_DER: ] (linea %d)\n",yylineno);numTokens++;return ']';}// Definición de token para corchete derecho
"{" {agregarToken("DELIMITADOR_LLAVE_IZQ","{",yylineno);printf("TOKEN_LLAVE_ABIERTA: { (linea %d)\n",yylineno);numTokens++;return '{';}// Definición de token para llave izquierda
"}" {agregarToken("DELIMITADOR_LLAVE_DER","}",yylineno);printf("TOKEN_LLAVE_CERRADA: } (linea %d)\n",yylineno);numTokens++;return '}';}// Definición de token para llave derecha
";" {agregarToken("DELIMITADOR_PUNTO_COMA",";",yylineno);printf("TOKEN_PUNTO_COMA: ; (linea %d)\n",yylineno);numTokens++;return ';';}// Definición de token para punto y coma
"," {agregarToken("DELIMITADOR_COMA",",",yylineno);printf("TOKEN_COMA: , (linea %d)\n",yylineno);numTokens++;return ',';}// Definición de token para coma
"." {agregarToken("DELIMITADOR_PUNTO",".",yylineno);printf("TOKEN_PUNTO: . (linea %d)\n",yylineno);numTokens++;return '.';}// Definición de token para punto
":" {agregarToken("DELIMITADOR_DOS_PUNTOS",":",yylineno);printf("TOKEN_DOSPUNTOS: : (linea %d)\n",yylineno);numTokens++;return ':';}// Definición de token para dos puntos

[ \t\r]+ {}
\n {yylineno++;}// Ignorar espacios en blanco y saltos de línea

. {agregarToken("ERROR_LEXICO",yytext,yylineno);printf("ERROR LEXICO: '%s' (linea %d)\n",yytext,yylineno);numErroresLex++;}// Manejar caracteres no reconocidos
%%
int yywrap() {return 1;}// Función para manejar el final del archivo