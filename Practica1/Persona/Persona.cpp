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

#include "Persona.h"

Persona::Persona(const string& n, int e){
    nombre=n;
    edad=e;
}

const string& Persona::getnombre() const{
    return nombre;
}

int Persona::getEdad() const{
    return edad;
}

void Persona::setNombre(const string& n){
    nombre=n;
}

void Persona::setEdad(int e){
    edad=e;
}

bool Persona::operator==(const Persona& p) const{
    bool igual;
    if(p.edad==edad && p.nombre==nombre) igual=true;
    else igual=false;
    return igual;
}

