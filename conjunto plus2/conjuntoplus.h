#ifndef CONJUNTOPLUS_H
#define CONJUNTOPLUS_H

#include "conjunto.h"
#include <iostream>
using namespace std;

typedef char cadena[20];


class conjuntoPlus : public conjunto{
    static fracc pdef_inicio, pdef_fin;
    fracc p_inicio, p_fin;
    static int m;
    char *nombre;
    public:
        conjuntoPlus(cadena nom);
        conjuntoPlus(fracc ini_interval, fracc fin_interval, cadena nom);
        static void intervalo_por_defecto(fracc f1, fracc f2);
        void cambiar_intervalo(fracc f1, fracc f2);
        void agregar();
        void agregar(fracc f);
        void ver();
        friend ostream& operator<<(ostream &i, conjuntoPlus c);
        friend bool operator==(conjuntoPlus a, conjuntoPlus b);

};

void borrarMin(conjunto *c[], int tam);

#endif
