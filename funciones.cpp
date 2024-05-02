#include <cstdio>
#include <cstring>
#include "funciones.h"
#include "protocolo.h"

void menu(grupo6 & proto){
    int rim;
    printf("Bienvenid@ a la Tarea 1!\n\nFavor, indíquenos ¿Qué acción le gustaría realizar\n");
    printf("1.- Cerrar el programa receptor         3.- Enviar mensaje de texto\n"
           "2.- Enviar mensaje de prueba            4.- Visualizar mensaje de archivo de prueba");
    scanf("%d", rim);   // Respuesta menú inicial

    switch (rim) {

        case 1:
            proto.cmd=1;
            cerrar_receptor();
            break;
        case 2:
            proto.cmd=2;
            mensaje_prueba();
            break;
        case 3:
            proto.cmd=3;
            mensaje_texto();
            break;
        case 4:
            proto.cmd=4;
            archivo_prueba();
            break;
        default:
            proto.cmd=5;
            printf("Acción no encontrada :'(");
            break;
    }
}
void cerrar_receptor(){

}
void mensaje_prueba(){

}
void mensaje_texto(){

}
void archivo_prueba(){

}
int empaquetamiento(grupo6 & proto){
                        // 4 bits 0100        5 bits 0101
    proto.frame[0] = (proto.cmd & 0x0F) | ((proto.lng & 0x0F) << 4);
    proto.frame[1] = ((proto.lng >> 4) & 0x01);
    memcpy(&proto.frame[2], proto.data, proto.lng);

    /*if (proto.lng > 0 && (proto.lng <= LARGO_DATO))
    {                       // 4 bits
        proto.frame[0] |= (proto.data[0] & 0x0F) << 4;
        for (int i = 0; i < proto.lng-1; i++)
        {                       // MSB de data anterior + LSB de data siguiente
            proto.frame[i+1] = proto.data[i] >> 4 | ((proto.data[i+1] & 0x0F) << 4);
        }                           // 4 bits guardados en parte menos significativa
        proto.frame[proto.lng] = (proto.data[proto.lng-1] >> 4 ) & 0x0F;
    }
    proto.fcs = fcs(proto.frame,proto.lng+1); // Se calcula el FCS

    proto.frame[proto.lng] |= (proto.fcs & 0x0F) << 4;
    proto.frame[proto.lng+2] = (proto.fcs >> 4) & 0x03;
    return proto.lng+2;*/
}
bool desempaquetamiento (grupo6 & proto,int tam){
    proto.cmd = proto.frame[0] & 0x0F;
    proto.lng = (proto.frame[0] >> 4) & 0x0F;
    proto.lng = (proto.frame[1] >> 4) & 0x01;
    if (tam != (proto.lng+2)){ // Tamaños incorrectos
        return false;
    }
    if (proto.lng > 0 && (proto.lng <= LARGO_DATO))
    {
        for (int i = 0; i < proto.lng; i++)
        {
            proto.data[i] = ((proto.frame[i] >> 4) & 0x0F) | ((proto.frame[i+1] & 0x0F )<< 4);
        }
    }
    int _fcs = fcs(proto.frame,proto.lng); // Se calcula el FCS solo hasta el byte anterior en donde se almacena FCS
    BYTE arr_aux[1] = { (BYTE) (proto.frame[proto.lng] & 0x0F)}; // se aíslan solo los datos
    _fcs+= fcs(arr_aux,1);
    proto.fcs = proto.frame[proto.lng] >> 4 | ( (proto.frame[proto.lng+2] & 0x03) << 4);
    if (_fcs != proto.fcs){
        return false;
    }
    return true;
}
int fcs(BYTE * arr,int tam){
    int sum_bits=0;
    for (int i = 0; i < tam; i++) // recorrer el arreglo
    {
        for (int j = 0; j < 8; j++)
        {
            sum_bits += (arr[i] >> j) & 0x01;
        }
    }
    return sum_bits;
}
