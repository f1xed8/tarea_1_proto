#include <cstdio>
#include <cstring>
#include "funciones.h"
#include "protocolo.h"

void menu(grupo6 &proto) {
    printf("Bienvenid@ a la Tarea 1!\n\nFavor, indíquenos ¿Qué acción le gustaría realizar\n");
    printf("1.- Cerrar el programa receptor         3.- Enviar mensaje de texto\n"
           "2.- Enviar mensaje de prueba            4.- Visualizar mensaje de archivo de prueba\n");
    int rim = 0;
    scanf("%d", &rim);   // rim = respuesta menú inicial
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
            printf("Acción no encontrada :'(\n");
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
int empaquetamiento(grupo6 &proto) {
    proto.frame[0] = (proto.cmd & 0x0F) | ((proto.lng & 0x0F) << 4); // Agregamos al paquete el cmd y los 4 bits que nos alcanzaron a entrar del lng dentro del primer byte
    proto.frame[1] = ((proto.lng >> 4) & 0x01); // Terminamos de cargar el lng
    memcpy(&proto.frame[2], proto.data, proto.lng);
    proto.fcs = fcs(proto.frame, proto.lng + 2);    // Calculamos fcs adicionando el cmd y el lng
    proto.frame[proto.lng + 2] = proto.fcs & 0xFF;  // Se agregan los bits menos significativos primero
    proto.frame[proto.lng + 3] = (proto.fcs >> 8) & 0x01;
    return proto.lng + 4;   // Indica el tamaño del paquete
}
bool desempaquetamiento(grupo6 &proto, int tam) {
    proto.cmd = proto.frame[0] & 0x0F;
    proto.lng = ((proto.frame[0] >> 4) & 0x0F) | ((proto.frame[1] & 0x01) << 4);
    if (tam != (proto.lng + 2)) { // Arroja error en caso de que el tamaño no coincida
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
int fcs(BYTE *arr, int tam_fcs) {
    int valor_fcs = 0; // Inicializa el valor del fcs a 0
    for (int i = 0; i < tam_fcs; i++) {
        valor_fcs ^= arr[i]; // Realiza una operación XOR con cada byte del arreglo
        for (int j = 0; j < 8; j++) {
            if (valor_fcs & 0x01) {
                valor_fcs = ((valor_fcs >> 1) ^ 0x100);
            } else {
                valor_fcs >>= 1;
            }
        }
    }
    return valor_fcs & 0x1FF; // Ajusta el resultado para que tenga un tamaño de 9 bits
}
void enviar(grupo6 &proto){
    printf("Favor, ingrese su mensaje a enviar\n");
    scanf("%31s", proto.data); // Almacena un mensaje de máximo 31 bytes
    proto.lng = strlen((const char*) proto.data);
    empaquetamiento(proto); // Empaqueta los datos antes de copiarlos en el frame
    printf("enviar: %d\n", proto.lng);
    memcpy(proto.frame, proto.data, proto.lng + 4); // Copia el mensaje empaquetado en el frame
}
void recibir(grupo6 &proto){
    bool estado = desempaquetamiento(proto, proto.lng);
    printf("Se recibió un mensaje de manera %s\n",estado?"correcta":"incorrecta");
    printf("El largo del mensaje es de %d bytes\n¿Desea visualizar el mensaje? (S/N): ", proto.lng);
    char SN;
    scanf(" %c", &SN);
    switch (SN) {
        case 'S':
        case 'Y':
        case 'y':
        case 's':
            printf("%s\n",proto.data);
            break;
        case 'N':
        case 'n':
            printf("Entendido!\n");
            break;
        default:
            printf("Opción inválida.\n");
            break;
    }
}
