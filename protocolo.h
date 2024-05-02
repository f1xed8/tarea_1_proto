#ifndef TAREA_1_PROTOCOLO_H
#define TAREA_1_PROTOCOLO_H
//SE DEFINE EL TIPO BYTE
#define BYTE unsigned char

//SE DEFINEN LOS PINES

//#define VELOCIDAD 500
//#define PIN_RX 18



//  Se define la estructura del grupo 6 según el protocolo ya revisado por el profesor
struct grupo6{
    BYTE cmd;   // 4 -> 0100
    BYTE lng;   // 5 -> 0101
    BYTE data[4];   // 31 -> 1111 1111 1111 1111
    BYTE fcs;   // 9 -> 1001
};

#endif //TAREA_1_PROTOCOLO_H
