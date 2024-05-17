#include "funciones.h"
#include <cstdio>

int main(){ // Oye, roberto, el nico dice q tienes q inicializar el wiringpi y los pines junto con los clocks (esos los tengo declarados en funciones.h). También implementa el wiringpiISR
    grupo6 proto;
    while (true)
    {
        recibir(proto);
        bool estado = desempaquetamiento(proto, proto.lng);
        if (proto.cmd == 1)
            {
                cerrar_receptor();
            } else if (proto.cmd == 2){
                for (size_t i = 1; i < 10; i++)
                {
                    bool estado = desempaquetamiento(proto, proto.lng);
                    if (estado == true){
                        c = c++;
                        } else {
                            end = end++;
                        }          
                }
                    void porcentajesmensajes();
                } else if (proto.cmd == 3){
                recibir(proto);
                // guardar en un "mensaje.txt"
                } else if (proto.cmd == 4){
                    // mostrar "mensaje.txt" o indicar que no existe el archivo
                }
}
    
    return 0;
}