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

#ifndef FRACCH
#define FRACCH

#include "aux.h"
#include <ostream>
#include <istream>

using namespace std;

    class fracc{
        int num, den;
        public:
            fracc(int n=0, int d=1);
            int getn() const;
            int getd() const;
            void set();
            void set(int n, int d);
            void ver() const;
            fracc reduce();
            fracc operator+(fracc f) const;//correcto
            fracc operator+(int a) const;//correcto
            fracc operator-(fracc f) const;//correcto
            fracc operator-(int a) const;//correcto
            fracc operator*(fracc f) const;//correcto
            fracc operator*(int a) const;//correcto
            fracc operator/(fracc f) const;//correcto
            fracc operator/(int a) const;//correcto
            fracc operator-() const;//correcto
            bool operator==(fracc f) const;
            bool operator==(int n) const;
            bool operator!=(fracc c) const;
            bool operator>(fracc f) const;
            fracc& operator=(const fracc& f);
            fracc & operator=(const int& n);
            fracc operator++();
            fracc operator++(int notused);
            operator float();
            operator int();
    };

    fracc operator+(int n, fracc f);//correcto
    fracc operator-(int n, fracc f);//correcto
    fracc operator*(int n, fracc f);//correcto
    fracc operator/(int n, fracc f);//correcto
    bool operator==(int n, fracc f);
    ostream& operator<<(ostream &i, fracc f);
    istream& operator>>(istream &i, fracc &f);

#endif
