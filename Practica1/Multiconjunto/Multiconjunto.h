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

#ifndef MULTICONJUNTO_H
#define MULTICONJUNTO_H

#include "../Persona/Persona.h"

template <typename T> class Multiconjunto{
    public:
        Multiconjunto(); //constructor
        bool esVacio() const; //Comprueba si el multiconjunto es o no vacio
        int cardinalidad() const; //Devuelve el numero de elementos
        void anade(const T& objeto); //Añade un objeto de tipo T al multiconjunto
            //Se permiten elementos repetidos
        void elimina(const T& objeto); //Elimina todas las ocurriencias del objeto
            //pasado como parametro
        bool pertenece(const T& objeto) const;
        //Comprueba si el objeto pasado como parametro existe en el multiconjunto
    private:
        T c[100]; //Vector de almacenamiento de elementos
        int num; //Indica el numero de elementos en el multiconjunto
};

#endif
