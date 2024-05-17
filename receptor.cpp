#include "funciones.h"
#include <cstdio>

int main(){ // Oye, roberto, el nico dice q tienes q inicializar el wiringpi y los pines junto con el clock (esos los tengo declarados en funciones.h). También implementa el wiringpiISR
    grupo6 proto;
    while (true)
    {
        recibir(proto);
        bool estado = desempaquetamiento(proto, proto.lng);
        if (proto.cmd == 1)
            {
                cerrar_receptor();
            } else if (proto.cmd == 2){
                int c = 0; int ed = 0; int end = 0;
                for (size_t i = 1; i < 10; i++)
                {
                    bool estado = desempaquetamiento(proto, proto.lng);
                    if (estado == true){
                        c = c++;
                        } else {
                            end = end++;
                        }          
                }    
        float porcentajec = c/(c + ed + end);
        float porcentajeed = ed/(c + ed + end);
        float porcentajeend = end/(c + ed + end);
        printf("%d mensajes recibidos correctamente\n", c);
        printf("%d mensajes recibidos con error detectado\n", ed);
        printf("%d mensajes recibidos con error no detectado\n", end);
        printf("Entonces tenemos una recepción del %%%f\n", porcentajec);
        printf("Entonces tenemos un porcentaje de error detectado de %%%f\n y un %%%f no detectado", porcentajeed, porcentajeend);
            } else if (proto.cmd == 3){
                recibir(proto);
                // guardar en un "mensaje.txt"
                } else if (proto.cmd == 4){
                    // mostrar "mensaje.txt" o indicar que no existe el archivo
                }
}
    
    return 0;
}