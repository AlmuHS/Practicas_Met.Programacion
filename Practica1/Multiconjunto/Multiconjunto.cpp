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

#include "Multiconjunto.h"

using namespace std;

template <typename T> Multiconjunto<T>::Multiconjunto(){
    num=0;
}

template <typename T> bool Multiconjunto<T>::esVacio()const {
    return (num==0);
}

template <typename T> int Multiconjunto<T>::cardinalidad() const{
    return num;
}

template <typename T> void Multiconjunto<T>::anade(const T& objeto){
    c[num]=objeto;
    num++;
}

template <typename T> void Multiconjunto<T>::elimina(const T& objeto){
    for (int i=0; i<num; i++){
        if(c[i]==objeto) c[i]=c[num-1];
    }
    num--;
}

template <typename T> bool Multiconjunto<T>::pertenece(const T& objeto) const{
    int i=0;
    bool pertenece=false;
    while (!pertenece && i<num){
        if(c[i]==objeto) pertenece=true;
        else i++;
    }
    return pertenece;
}

template class Multiconjunto<char>;
template class Multiconjunto<int>;
template class Multiconjunto<Persona>;
