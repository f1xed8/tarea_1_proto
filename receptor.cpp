#include <cstdio>   //Librería para printf
#include "funciones.h"  // Agregamos la cabecera de funciones
#include <unistd.h>               // for linux 

int main(){
    grupo6 proto;
    while (true)
    {
        recibir(proto);
        sleep(1000);   // Se le da un timepo para que se reciba el mensaje 
        bool estado = desempaquetamiento(proto, proto.lng);
        printf("Aviso: se recibió el empaquetamiento\n");
        if (proto.cmd == 1)
            {
                printf("Aviso: se iniciará la función cerrar_receptor desde receptor\n");
                cerrar_receptor();
            } else if (proto.cmd == 2){
                printf("Aviso: se iniciará la opción de recepción 2\n");
                for (size_t i = 1; i < 10; i++)
                {
                    bool estado = desempaquetamiento(proto, proto.lng);
                    if (estado == true){
                        //c = c++;
                    } else {
                          //  end = end++;
                        }          
                }
                    void porcentajesmensajes();
                } else if (proto.cmd == 3){
                    printf("Aviso: se iniciará la función recibir_guardar desde receptor\n");
                    void recibir_guardar();
                } else if (proto.cmd == 4){
                    printf("Aviso: se iniciará la función mostrar_archivo desde receptor\n");
                    void mostrar_archivo();
                }
}
    
    return 0;
}