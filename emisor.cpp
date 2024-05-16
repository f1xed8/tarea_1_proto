#include <cstdio> //Librería para printf
#include <cstdlib>
#include "funciones.h" // Agregamos la cabecera de funciones
#include "protocolo.h" // Agregamos el protocolo
#include <wiringPi.h>

#define DELAY_PIN
#define TX_PIN 2
#define RX_PIN 3
#define CLOCK_PIN 23

int main(){
    
    if(wiringPiSetup() == -1){
    exit(1);
    }

    pinMode(RX_PIN, INPUT);
    pinMode(TX_PIN, OUTPUT);
    pinMode(CLOCK_PIN,INPUT);

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
    return 0;
}