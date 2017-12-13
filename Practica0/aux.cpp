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

#include "aux.h"

int mcm(int n1, int n2){
    int mcm;
    int i=1;
    while(n1*i!=n2*i) i++;
    mcm=n1*i;
    return mcm;
}

int mcd(int n1, int n2){
    int mcd=n1*n2/mcm(n1,n2);//maximo comun divisor
    return mcd;
}

