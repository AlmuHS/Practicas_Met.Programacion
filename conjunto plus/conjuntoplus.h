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
