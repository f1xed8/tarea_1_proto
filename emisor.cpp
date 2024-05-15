#include <cstdio> //Librería para printf
#include <cstdlib> //Librería para system
#include "funciones.h" // Agregamos la cabecera de funciones
#include "protocolo.h" // Agregamos el protocolo

int main(){
    system("gnome-terminal -- ./receptor");
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