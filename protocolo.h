#ifndef TAREA_1_PROTOCOLO_H
#define TAREA_1_PROTOCOLO_H
#define BYTE unsigned char // Se define el tipo de byte
#define LARGO_DATO 31
#define LARGO_FRAME 35
/*#define VELOCIDAD 500 // Se define la velocidad
#define PIN_RX 18 // Se define el pin de recepción de señal
#define PIN_RZ 17 // Se define el pin de envío de señal*/

//  Se define la estructura del grupo 6 según el protocolo ya revisado por el profesor
struct grupo6{
    BYTE cmd;   // 4 bits
    BYTE lng;   // 5 bits
    BYTE data[LARGO_DATO];   // 31 bytes
    BYTE fcs;   // 9 bits
    BYTE frame[LARGO_FRAME];
};
struct auxiliares{
    int rim;
};

#endif //TAREA_1_PROTOCOLO_H
