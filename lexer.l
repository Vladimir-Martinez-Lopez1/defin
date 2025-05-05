%{
#include "parser.tab.h"
#include <stdio.h>

int numTokens = 0;
int numErroresLex = 0;
int numComentarios = 0;
int yylineno = 1;
%}

%x COMMENT

%%

"//".* {
    printf("TOKEN_COMENTARIO (linea %d)\n", yylineno);
    numComentarios++;
}

"/."             { BEGIN(COMMENT); numComentarios++; }
<COMMENT>"./"    { BEGIN(INITIAL); }
<COMMENT>\n      { yylineno++; }
<COMMENT><<EOF>> {
    printf("ERROR: comentario de bloque no cerrado (linea %d)\n", yylineno);
    numErroresLex++;
    BEGIN(INITIAL);
}
<COMMENT>.       { }


"entero"         { printf("TOKEN_TIPO_DATO: entero (linea %d)\n", yylineno); numTokens++; return ENTERO_T; }
"flotante"       { printf("TOKEN_TIPO_DATO: flotante (linea %d)\n", yylineno); numTokens++; return FLOTANTE_T; }
"cadena"         { printf("TOKEN_TIPO_DATO: cadena (linea %d)\n", yylineno); numTokens++; return CADENA_T; }
"booleano"       { printf("TOKEN_TIPO_DATO: booleano (linea %d)\n", yylineno); numTokens++; return BOOLEANO_T; }
"estructura"     { printf("TOKEN_TIPO_DATO: estructura (linea %d)\n", yylineno); numTokens++; return ESTRUCTURA; }

"sino"[ \t\n\r]+"si" {printf("ERROR: se uso 'sino si', se esperaba 'sinosi' (linea %d)\n", yylineno);numErroresLex++;return ERROR;}
"si"             { printf("TOKEN_IF: %s (linea %d)\n", yytext, yylineno); numTokens++; return SI; }
"sino"           { printf("TOKEN_ELSE: %s (linea %d)\n", yytext, yylineno); numTokens++; return SINO; }
"sinosi"         { printf("TOKEN_ELSE_IF: %s (linea %d)\n", yytext, yylineno); numTokens++; return SINOSI; }
"mientras"       { printf("TOKEN_WHILE (linea %d)\n", yylineno); numTokens++; return MIENTRAS; }
"para"           { printf("TOKEN_FOR (linea %d)\n", yylineno); numTokens++; return PARA; }
"devolver"       { printf("TOKEN_CONTROL: devolver (linea %d)\n", yylineno); numTokens++; return DEVOLVER; }
"romper"         { printf("TOKEN_CONTROL: romper (linea %d)\n", yylineno); numTokens++; return ROMPER; }
"continuar"      { printf("TOKEN_CONTROL: continuar (linea %d)\n", yylineno); numTokens++; return CONTINUAR; }
"leer"           { printf("TOKEN_FUNCION: leer (linea %d)\n", yylineno); numTokens++; return LEER; }
"imprimir"       { printf("TOKEN_FUNCION: imprimir (linea %d)\n", yylineno); numTokens++; return IMPRIMIR; }
"void"           { printf("TOKEN_TIPO_DATO: void (linea %d)\n", yylineno); numTokens++; return VOID; }
"elegir"         { printf("TOKEN_ELEGIR: elegir (linea %d)\n", yylineno); numTokens++; return ELEGIR; }
"caso"          { printf("TOKEN_CASO: caso (linea %d)\n", yylineno); numTokens++; return CASO; }
"defecto"        { printf("TOKEN_DEFECTO: defecto (linea %d)\n", yylineno); numTokens++; return DEFECTO; }

"verdadero"      { printf("TOKEN_LITERAL: verdadero (linea %d)\n", yylineno); numTokens++; return VERDADERO; }
"falso"          { printf("TOKEN_LITERAL: falso (linea %d)\n", yylineno); numTokens++; return FALSO; }


\"[^\"]*\"       { printf("TOKEN_CADENA: %s (linea %d)\n", yytext, yylineno); numTokens++; return CADENA; }
[0-9]+"."[0-9]+  { printf("TOKEN_FLOTANTE: %s (linea %d)\n", yytext, yylineno); numTokens++; return FLOTANTE; }
[0-9]+           { printf("TOKEN_ENTERO: %s (linea %d)\n", yytext, yylineno); numTokens++; return ENTERO; }
\'[^\']\'        { printf("TOKEN_CARACTER: %s (linea %d)\n", yytext, yylineno); numTokens++; return CARACTER; }


[a-zA-Z_][a-zA-Z0-9_]* {
    printf("TOKEN_IDENTIFICADOR: %s (linea %d)\n", yytext, yylineno);
    numTokens++;
    return ID;
}


"="            { printf("TOKEN_ASIGNACION: = (linea %d)\n", yylineno); numTokens++; return '='; }

"++"           { printf("TOKEN_INCREMENTO: ++ (linea %d)\n", yylineno); numTokens++; return INCREMENTO; }
"--"           { printf("TOKEN_DECREMENTO: -- (linea %d)\n", yylineno); numTokens++; return DECREMENTO; }
"+"            { printf("TOKEN_MAS: + (linea %d)\n", yylineno); numTokens++; return '+'; }
"-"            { printf("TOKEN_MENOS: - (linea %d)\n", yylineno); numTokens++; return '-'; }
"*"            { printf("TOKEN_MULT: * (linea %d)\n", yylineno); numTokens++; return '*'; }
"/"            { printf("TOKEN_DIV: / (linea %d)\n", yylineno); numTokens++; return '/'; }
"%"            { printf("TOKEN_MOD: %% (linea %d)\n", yylineno); numTokens++; return '%'; }

"||"           { printf("TOKEN_OR: || (linea %d)\n", yylineno); numTokens++; return OR; }
"&&"           { printf("TOKEN_AND: && (linea %d)\n", yylineno); numTokens++; return AND; }
"!"            { printf("TOKEN_NEGACION: ! (linea %d)\n", yylineno); numTokens++; return '!'; }

"=="           { printf("TOKEN_IGUAL: == (linea %d)\n", yylineno); numTokens++; return IGUAL; }
"!="           { printf("TOKEN_DIFERENTE: != (linea %d)\n", yylineno); numTokens++; return DIFERENTE; }
"<="           { printf("TOKEN_MENORIGUAL: <= (linea %d)\n", yylineno); numTokens++; return MENORIGUAL; }
">="           { printf("TOKEN_MAYORIGUAL: >= (linea %d)\n", yylineno); numTokens++; return MAYORIGUAL; }
"<"            { printf("TOKEN_MENOR: < (linea %d)\n", yylineno); numTokens++; return '<'; }
">"            { printf("TOKEN_MAYOR: > (linea %d)\n", yylineno); numTokens++; return '>'; }

"("            { printf("TOKEN_PAR_IZQ: ( (linea %d)\n", yylineno); numTokens++; return '('; }
")"            { printf("TOKEN_PAR_DER: ) (linea %d)\n", yylineno); numTokens++; return ')'; }
"["            { printf("TOKEN_CORCHETE_IZQ: [ (linea %d)\n", yylineno); numTokens++; return '['; }
"]"            { printf("TOKEN_CORCHETE_DER: ] (linea %d)\n", yylineno); numTokens++; return ']'; }
"{"              { printf("TOKEN_LLAVE_ABIERTA: { (linea %d)\n", yylineno); numTokens++; return '{'; }
"}"              { printf("TOKEN_LLAVE_CERRADA: } (linea %d)\n", yylineno); numTokens++; return '}'; }
";"              { printf("TOKEN_PUNTO_COMA: ; (linea %d)\n", yylineno); numTokens++; return ';'; }
","              { printf("TOKEN_COMA: , (linea %d)\n", yylineno); numTokens++; return ','; }
"."              { printf("TOKEN_PUNTO: . (linea %d)\n", yylineno); numTokens++; return '.'; }
":"              { printf("TOKEN_DOSPUNTOS: : (linea %d)\n", yylineno); numTokens++; return ':'; }

[ \t\r]+         { }
\n               { yylineno++; }

.                {
    printf("ERROR LEXICO: simbolo no reconocido '%s' (linea %d)\n", yytext, yylineno);
    numErroresLex++;
}

%%

int yywrap() { return 1; }
