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
        if (proto.cmd == 1)
            {
                cerrar_receptor();
            } else if (proto.cmd == 2){
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
                    void recibir_guardar();
                } else if (proto.cmd == 4){
                    void mostrar_archivo();
                }
}
    
    return 0;
}