#include <stdio.h>
//#include <wiringPi.h>
#include "protocolo.h"


int main (){

    //  Menú
    int rim;
    printf("Bienvenid@ a la Tarea 1!\n\nFavor, indíquenos ¿Qué acción le gustaría realizar\n");
    printf("1.- Cerrar el programa receptor         3.- Enviar mensaje de texto\n"
           "2.- Enviar mensaje de prueba            4.- Visualizar mensaje de archivo de prueba");
    scanf("%d", rim);   // Respuesta menú inicial

    switch (rim) {

        case 1:
            cmd=1;
            cerrar_receptor();
            break;
        case 2:
            cmd=2;
            mensaje_prueba();
            break;
        case 3:
            cmd=3;
            mensaje_texto();
            break;
        case 4:
            cmd=4;
            archivo_prueba();
            break;
        default:
            cmd=5;
            printf("Acción no encontrada :'(");
            break;
    }
    // Fin menú

    return 0;
}

