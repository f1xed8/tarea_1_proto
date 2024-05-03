#ifndef TAREA_1_FUNCIONES_H
#define TAREA_1_FUNCIONES_H
#include "protocolo.h"

void menu();
void cerrar_receptor();
void mensaje_prueba();
void mensaje_texto();
void archivo_prueba();

int empaquetamiento(grupo6 &proto);
bool desempaquetamiento(grupo6 &proto, int tam);
int fcs(BYTE *arr, int tam_fcs);
void enviar(grupo6 &proto);
void recibir(grupo6 &proto);

#endif //TAREA_1_FUNCIONES_H
