/*
 * Copyright (C) 2013 Almudena García Jurado-Centurión
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
