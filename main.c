#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
extern int yyparse();
extern int numTokens;
extern int numErroresLex;
extern int errores_sintacticos;
extern int numComentarios;
extern int yylineno;
extern void mostrarErrores(void);//errores sintacticos


int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s archivo.phc\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    printf("=== Iniciando analisis lexico y sintactico ===\n");
    yyparse();
    printf("=== Fin del analisis ===\n\n");

    printf("=== Resumen del analisis ===\n");
    printf("Total de lineas procesadas: %d\n", yylineno);
    printf("Analisis completado con %d errores encontrados.\n\n", numErroresLex + errores_sintacticos);
    printf("Errores lexicos: %d\n", numErroresLex);
    printf("Errores sintacticos: %d\n", errores_sintacticos);
    printf("Comentarios detectados: %d\n", numComentarios);
    mostrarErrores();
    fclose(yyin);
    return 0;
}
