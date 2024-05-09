#include <cstdio>
#include "funciones.h"
#include "protocolo.h"
// Explicacion 08/05

int main() {
    grupo6 proto;
    menu(proto);
    enviar(proto);
    recibir(proto);
    return 0;
}