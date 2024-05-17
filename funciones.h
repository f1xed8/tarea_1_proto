#ifndef TAREA_1_FUNCIONES_H
#define TAREA_1_FUNCIONES_H
#include "protocolo.h"

#define PWM_PIN 1   // 18 BCM
#define PWM_CLOCK_DIVISOR 192   // Divisor del reloj
#define PWM_RANGE 1000   // Rango asignado para el trabajo
#define DELAY_PIN 23    // Pin para el delay
#define TX_PIN 2    // Pin de emisión
bool transmision_iniciada = false;

void menu();
void cerrar_receptor();
void mensaje_prueba(grupo6 &proto);
void enviar(grupo6 &proto);
void recibir(grupo6 &proto);
void archivo_texto();

int empaquetamiento(grupo6 &proto);
bool desempaquetamiento(grupo6 &proto, int tam);
int fcs(BYTE *arr, int tam_fcs);

void callback();
void startTransmission();

#endif //TAREA_1_FUNCIONES_H
