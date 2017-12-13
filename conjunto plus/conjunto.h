#ifndef CONJUNTO_H
#define CONJUNTO_H

#include "fracc.h"
#include <iostream>

#define MAX 50

class conjunto{
    fracc *T;
    int n;
    int nmax;
    public:
        conjunto();
        int getn();
        bool vacio();
        bool pertenece(fracc f);
        void ver();
        void agregar();
        void agregar(fracc f);
        void borrar(fracc f);
        fracc operator[](int n);
        friend ostream& operator<<(ostream &i, conjunto c);
};




#endif
