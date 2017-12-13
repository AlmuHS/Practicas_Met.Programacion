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
        ~conjunto();
        int getn();
        bool vacio();
        bool pertenece(fracc f);
        virtual void ver();
        virtual void agregar();
        virtual void agregar(fracc f);
        void borrar(fracc f);
        virtual fracc operator[](int n);
        friend ostream& operator<<(ostream &i, conjunto c);
};




#endif
