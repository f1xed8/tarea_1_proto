#include <cstdio>   //Librería para printf
#include <cstdlib>
#include "funciones.h"  // Agregamos la cabecera de funciones
#include "protocolo.h"  // Agregamos el protocolo
#include <wiringPi.h>   // Agregamos la librería para GPIO

int main(){
    
    if(wiringPiSetup() == -1){  // Condición en caso de que haya algún fallo con la librería
        exit(1);
    }
    
    if(wiringPiISR(DELAY_PIN, INT_EDGE_RISING, &callback) < 0){   // Delcaramos la interrupción
        printf("No se puede iniciar la función de interrupción\n");
    }

    pinMode(TX_PIN, OUTPUT);

    grupo6 proto;
    menu();
    int rim = 0;
    scanf("%d", &rim);   // rim = respuesta menú inicial
    switch (rim) {
        case 1:
            proto.cmd = 1;
            proto.lng = 0;
            proto.frame[0] = (proto.cmd & 0x0F) | ((proto.lng & 0x0F) << 4);
            proto.frame[1] = ((proto.lng >> 4) & 0x01);
            break;
        case 2:
            mensaje_prueba(proto);
            break;
        case 3:
            proto.cmd=3;
            enviar(proto);
            break;
        case 4:
            proto.cmd=4;
            archivo_texto();
            break;
        default:
            proto.cmd=5;
            printf("Acción no encontrada :'(\n");
            break;
    }

    while(transmision_iniciada) {
        delay(1000); // Espera mientras se realiza la transmisión
    }

    return 0;
}