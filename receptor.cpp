#include "funciones.h"
#include <cstdio>

int main(){
    grupo6 proto;
    desempaquetamiento(proto, proto.lng);
    if (proto.cmd == 1)
    {
        cerrar_receptor();
    } else if (proto.cmd == 2){
        int c; int ed; int end;
        printf("%d mensajes recibidos correctamente\n", c);
        printf("%d mensajes recibidos con error detectado\n", ed);
        printf("%d mensajes recibidos con error no detectado\n", end);
    } else if (proto.cmd == 3){
        recibir(proto);
        // guardar en un "mensaje.txt"
    } else if (proto.cmd == 4){
        // mostrar "mensaje.txt" o indicar que no existe el archivo
    }
    
    return 0;
}