#ifndef TAREA_1_FUNCIONES_H
#define TAREA_1_FUNCIONES_H
#include "protocolo.h"

void menu();
void cerrar_receptor();
void mensaje_prueba(grupo6 &proto);
void enviar(grupo6 &proto);
void recibir(grupo6 &proto);
void archivo_texto();

int empaquetamiento(grupo6 &proto);
bool desempaquetamiento(grupo6 &proto, int tam);
int fcs(BYTE *arr, int tam_fcs);

#endif //TAREA_1_FUNCIONES_H
