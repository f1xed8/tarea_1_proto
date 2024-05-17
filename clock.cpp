#include <wiringPi.h>
#include <stdlib.h>

#define PWM_PIN 1   // 18 BCM
#define PWM_CLOCK_DIVISOR 192   // Divisor del reloj
#define PWM_RANGE 1000   // Rango asignado para el trabajo

int main(){

    if(wiringPiSetup() == -1){  // Condición en caso de que haya algún fallo con la librería
    exit(1);
    }

    pinMode(PWM_PIN, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS); //Mark Space Mode  ??
    pwmSetRange(PWM_RANGE); // Definimos valores de la macro
    pwmSetClock(PWM_CLOCK_DIVISOR); // Definimos valores de la macro
    pwmWrite(PWM_PIN, PWM_RANGE/2); // Medio ciclo del rango, para tratar de dar en medio de la señal

    while(1){   // Consumimos el bit
    delay(PWM_RANGE/4);
    }

    return 0;
}