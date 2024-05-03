#include <cstdio>
#include <cstring>
#include "funciones.h"
#include "protocolo.h"

void menu(grupo6 & proto, auxiliares *aux){
    printf("Bienvenid@ a la Tarea 1!\n\nFavor, indíquenos ¿Qué acción le gustaría realizar\n");
    printf("1.- Cerrar el programa receptor         3.- Enviar mensaje de texto\n"
           "2.- Enviar mensaje de prueba            4.- Visualizar mensaje de archivo de prueba");
    scanf("%d", &aux->rim);   // rim = respuesta menú inicial

    switch (aux->rim) {
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
void cerrar_receptor(auxiliares *aux){
    exit(0);
}
void mensaje_prueba(){

}
void mensaje_texto(){

}
void archivo_prueba(){

}
int empaquetamiento(grupo6 &proto) {
    proto.frame[0] = (proto.cmd & 0x0F) | ((proto.lng & 0x0F) << 4); // Agregamos al paquete el cmd y los 4 bits que nos alcanzaron a entrar del lng dentro del primer byte
    proto.frame[1] = ((proto.lng >> 4) & 0x01); // Terminamos de cargar el lng
    memcpy(&proto.frame[2], proto.data, proto.lng);
    proto.fcs = fcs(proto.frame, proto.lng + 2);    // Calculamos fcs adicionando el cmd y el lng
    proto.frame[proto.lng + 2] = proto.fcs & 0xFF;  // Se agregan los bits menos significativos primero
    proto.frame[proto.lng + 3] = (proto.fcs >> 8) & 0x01;
    return proto.lng + 3;   // Indica el tamaño del paquete
}
bool desempaquetamiento(grupo6 &proto, int tam) {
    proto.cmd = proto.frame[0] & 0x0F;
    proto.lng = (proto.frame[0] >> 4) & 0x0F;
    proto.lng |= (proto.frame[1] & 0x01) << 4;
    if (tam != (proto.lng + 3)) { // Arroja error en caso de que el tamaño no coincida
        return false;
    }
    if (proto.lng > 0 && (proto.lng <= LARGO_DATO)) {   // En caso de que lng sea mayor a 0, y menor o igual a largo dato, comienza a desempaquetar
        for (int i = 0; i < proto.lng; i++) {
            proto.data[i] = ((proto.frame[i+1] >> 4) & 0x0F) | ((proto.frame[i+2] & 0x0F) << 4);
        }
    }
    int fcs_calculado = fcs(proto.frame, proto.lng + 2); // Calcula el fcs sobre los bits del paquete
    int fcs_recibido = proto.frame[proto.lng + 1] | ((proto.frame[proto.lng + 2] & 0x03) << 4); // Extrae el fcs
    if (fcs_calculado != fcs_recibido) {
        return false;
    }
    return true;
}
int fcs(BYTE *arr, int tamaño_fcs) {
    int fcs_value = 0; // Inicializa el valor del FCS a 0
    for (int i = 0; i < tamaño_fcs; i++) {
        fcs_value ^= arr[i]; // Realiza una operación XOR con cada byte del arreglo
        for (int j = 0; j < 8; j++) {
            if (fcs_value & 0x01) {
                fcs_value = (fcs_value >> 1) ^ 0x100); // Realiza una operación XOR con el polinomio CRC (0x100 = x^8)
            } else {
                fcs_value >>= 1;
            }
        }
    }

    return fcs_value & 0x1FF; // Ajusta el resultado para que tenga un tamaño de 9 bits
}