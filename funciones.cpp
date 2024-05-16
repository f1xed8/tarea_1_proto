#include <cstdio>
#include <cstring>
#include <cstdlib>  // Para exit(0)
#include "funciones.h"
#include "protocolo.h"

void menu() {
    printf("Bienvenid@ a la Tarea 1!\n\nFavor, indíquenos ¿Qué acción le gustaría realizar?\n");
    printf("1.- Cerrar el programa receptor         3.- Enviar mensaje de texto\n"
           "2.- Enviar mensaje de prueba            4.- Visualizar mensaje de archivo de texto\n");
}
void cerrar_receptor(){
    exit(0);
}
void mensaje_prueba(grupo6 &proto){
    for (size_t i = 0; i < 10; i++)
    {
        proto.cmd=2;
        const char* mensaje_de_prueba = "Mensaje de prueba Grupo 6";
        strcpy(reinterpret_cast<char*>(proto.data), mensaje_de_prueba); // Copiamos el mensaje en data
        proto.lng = strlen(mensaje_de_prueba);
        empaquetamiento(proto); // Empaqueta los datos antes de copiarlos en el frame
        printf("Mensaje %ld enviado correctamente!\n", i+1);
    }
    printf("Mensajes enviados correctamente!\n");
    printf("El mensaje es: %s\n",proto.data);
    printf("El largo del mensaje es de: %d bytes\n",proto.lng);
    printf("El comando para esta acción es: %d\n",proto.cmd);
}
void enviar(grupo6 &proto){
    printf("Favor, ingrese su mensaje a enviar\n");
    while (true) {
        scanf("%s", proto.data); // Almacena un mensaje de máximo 31 bytes
        proto.lng = strlen((const char*) proto.data);   // Asigna a lng el largo de data con strlen
        if (proto.lng > 31) {   // Condiciona que el mensaje sea de máximo 31 bytes
                                // En caso de usar %31s generaba errores cuando el usuario ingresaba más bits,
                                // ya que a utilizaba esas entradas como valores de las siguientes variables
            printf("El mensaje sobrepasa la capacidad de almacenamiento que tiene nuestro protocolo\n");
            printf("Favor, ingrese su mensaje a enviar con un máximo de 31 bytes\n");
        } else {
            break; // Prosigue con el código en caso de que se cumpla la condición
        }
    }
    empaquetamiento(proto); // Empaqueta los datos antes de copiarlos en el frame
    printf("Mensaje enviado correctamente!\n");
}
void recibir(grupo6 &proto){
    bool estado = desempaquetamiento(proto, proto.lng); // Definimos la variable estado para almacenar el retorno de la función desempaquetamiento
    printf("Se recibió un mensaje de manera %s\n",estado?"correcta":"incorrecta");
    printf("El largo del mensaje es de %d bytes\n¿Desea visualizar el mensaje? (S/N): ", proto.lng);
    char SN;
    scanf(" %c", &SN);
    switch (SN) {
        case 'S':
        case 's':
        case 'Y':
        case 'y':
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
void archivo_texto(){
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