#ifndef CONJUNTOPLUS_H
#define CONJUNTOPLUS_H

#include "conjunto.h"
#include <iostream>
using namespace std;

class conjuntoPlus : public conjunto{
    static fracc pdef_inicio, pdef_fin;
    fracc p_inicio, p_fin;
    static int m;
    public:
        conjuntoPlus();
        conjuntoPlus(fracc ini_interval, fracc fin_interval);
        static void intervalo_por_defecto(fracc f1, fracc f2);
        void cambiar_intervalo(fracc f1, fracc f2);
        void agregar();
        void agregar(fracc f);
        void ver();
        friend ostream& operator<<(ostream &i, conjuntoPlus c);

};



#endif
