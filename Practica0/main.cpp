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

#include <cstdlib>
#include <iostream>
#include "fracc.h"

using namespace std;

int main()
{
    fracc a(1,2), b(3,4) ,c(1,-3), d(-3,-2), e(6,2);
    int x,y,z;
    e.reduce(); //e = 3/1
    a.set(a.getn()+1,-1*a.getd()); //a =-2/2
    b=c+d;
    //b = 7/6
    c=5+c+a+2;
    //c = 34/Ŕ6
    a=b+c-d*d/e;
    //a = 73/12
    a=-a;
    //a =-73/12
    b=7-c*2+2/a*c;
    //b =-2714/438
    a=5/b-c/b;
    //a = 1752/16284
    x=mcm(4,10);
    //x = 20
    y=mcd(x,30);
    //y = 10
    a.ver();
    //1752/16284
    b.ver();
    //-2714/438
    c.ver();
    //34/6
    d.ver();
    //3/2
    e.ver();
    //3/1
    /*if (a==d) cout << a << " == " << d << endl;
    else cout << a << " <> " << d << endl;
    if (d>b) cout << a << " > " << d << endl;
    else cout << a << " no es mayor que " << d << "\n";*/
    //system("PAUSE");
    return 0;
}


