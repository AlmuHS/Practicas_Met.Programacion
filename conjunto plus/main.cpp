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
#include "fracc.h" //definicion de la clase fracc
#include "conjunto.h" //definicion de la clase conjunto
#include "conjuntoplus.h" //definicion de la clase ConjuntoPlus
using namespace std;

int main(int argc, char *argv[]) {
    fracc f1(4,2), f2(3);
    conjuntoPlus *p = new conjuntoPlus, *q;
    cout << "*p: ";
    cout << *p << endl;
    //*p: { } – [0/1 1/1] (0/1 1/1)
    conjuntoPlus::intervalo_por_defecto(fracc(5,5), fracc(6,5)); //cambio no permitido
    delete p;
    conjuntoPlus::intervalo_por_defecto(1, 2); //intervalo por defecto: [1/1, 2/1]
    p = new conjuntoPlus(fracc(3,3), fracc(4,3));
    //*p: { } – [3/3 4/3] (1/1 2/1)
    p->agregar(1); p->agregar(fracc(8,6));
    p->agregar(f1);
    //*p: { 4/2 } – [3/3 4/3] (1/1 2/1)
    q = new conjuntoPlus(*p);
    cout << "*p: "; cout << *p << endl;
    //*p: { 2/1 } - [1/1 4/3] (1/1 2/1)
    delete p;
    conjuntoPlus::intervalo_por_defecto(fracc(0,1), 2); //cambio no permitido
    q->agregar(f2);
    q->agregar(fracc(6,2));
    q->borrar(2);
    cout << "*q: ";
    cout << *q << endl;
    //*q: { 3/1 } - [1/1 4/3] (1/1 2/1)
    delete q;
    conjuntoPlus::intervalo_por_defecto(fracc(2,2), 2); //intervalo por defecto: [2/2, 2/1]
    conjuntoPlus a(fracc(2,4), f1), b;
    fracc x(1), y(7,6);
    cout << "a: ";
    a.ver();
    cout << endl;
    //a: { } – [2/4 4/2] (2/2 2/1)
    cout << "b: ";
    b.ver();
    cout << endl;
    //b: { } – [2/2 2/1] (2/2 2/1)
    cout << "a: "; a.conjunto::ver(); cout << endl;
    //a: { }
    cout << "a: " << a << endl;
    //a: { } – [1/2 2/1] (1/1 2/1)
    if (a.vacio()) cout << "a esta vacio\n";
    //a esta vacio
    else cout << "a no esta vacio\n";
    cout << "Carga de a:\n";
    a.agregar(fracc(1,4));
    a.agregar(fracc(2,6));
    a.agregar(); //introduce las fracciones 2/2, 7/1 y 2/4
    cout << "a: " << a << endl; //a: {1/4 1/3 7/1} – [1/2 2/1] (1/1 2/1)
    cout << "a: "; a.ver(); cout << endl; //a: {1/4 2/6 7/1} – [2/4 4/2] (2/2 2/1)
    cout << "a tiene " << a.getn() << " fracc\n"; //a tiene 3 fracc
    conjuntoPlus c(a); //c: {1/4 2/6 7/1} – [2/4 4/2] (2/2 2/1)
    a.borrar(7);
    a.borrar(2); //a: {1/4 2/6 } – [2/4 4/2] (2/2 2/1)
    b=b=a=a;
    a.cambiar_intervalo(0, 1);
    cout << "a: " << a << endl; //a: { } – [0/1 1/1] (1/1 2/1)
    cout << "b: " << b << endl; //b: {1/4 1/3 } – [1/2 2/1] (1/1 2/1)
    cout << "c: " << c << endl; //c: {1/4 1/3 7/1} – [1/2 2/1] (1/1 2/1)
    if (c.pertenece(x*2+fracc(10,2)))
        cout << "x*2+fracc(10,2) = " << x*2+fracc(10,2) << " esta en c\n"; //esta en c
return EXIT_SUCCESS;
}
