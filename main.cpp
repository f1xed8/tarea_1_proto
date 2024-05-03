#include <cstdio>
#include "funciones.h"
#include "protocolo.h"

int main() {
    grupo6 proto;
    menu(proto);
    enviar(proto);
    recibir(proto);
    return 0;
}