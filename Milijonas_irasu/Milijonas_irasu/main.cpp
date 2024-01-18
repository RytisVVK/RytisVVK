#include "headeris.h"



int main() {
    srand(time(0));
    failo_kurimas failoKurimas;
    failoKurimas.SukurtiFailus(); 
    failoKurimas.kieteku_suskirstymas();               //funkciju execution'as
    failoKurimas.vargsiuku_suskirstymas();

    system("pause");
}
