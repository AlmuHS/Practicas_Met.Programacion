#include <cstdlib>
#include <iostream>
#include "aux.h"
#include "fracc.h"
#include "conjunto.h"
#include "conjuntoplus.h"
using namespace std;



int main(int argc, char *argv[]) {
    fracc f1(4,2), f2(3);
	cout << "\tOperacion realizada: " << "\t\t\tProceso realizado: " << endl;
    cout << "   conjuntoPlus *p = new conjuntoPlus" << "\t";
	conjuntoPlus *p = new conjuntoPlus;
	cout << "   conjuntoPlus *q" << "\t\t";
	conjuntoPlus *q;
	cout << "\n   cout << *p:  " << "\t\t\t";
    cout << "*p: ";
	cout << *p ; //*p: { } – [0/1 1/1] (0/1 1/1)
	cout << "   p->ver()  " << "\t\t\t\t*p: ";
	p->ver();
	cout << "   conjuntoPlus::intervalo_por_defecto(fracc(5,5), fracc(6,5))" << endl;
	cout << "\t\t\t\t";
    conjuntoPlus::intervalo_por_defecto(fracc(5,5), fracc(6,5)); //cambio no permitido
    cout << "   delete p  " << "\t\t\t\t";
	delete p;
	cout << "   conjuntoPlus::intervalo_por_defecto(1, 2)" << "\n\t\t\t\t";
    conjuntoPlus::intervalo_por_defecto(1, 2); //intervalo por defecto: [1/1, 2/1]
	cout << "   p = new conjuntoPlus(fracc(3,3), fracc(4,3))" << "\t";
    p = new conjuntoPlus(fracc(3,3), fracc(4,3)); //*p: { } – [3/3 4/3] (1/1 2/1)
	cout << "   cout << *p:  " << "\t\t\t";
    cout << "*p: ";
	cout << *p ;
	cout << "   p->ver()  " << "\t\t\t\t*p: ";
	p->ver();
	cout << "   p->agregar(1)" << "\t\t";
    p->agregar(1);
	cout << "   p->agregar(fracc(8,6))" << "\t";
	p->agregar(fracc(8,6));
	cout << "   p->agregar(f1)" << "\t\t";
    p->agregar(f1); //*p: { 4/2 } – [3/3 4/3] (1/1 2/1)
	cout << "   cout << *p:  " << "\t\t\t";
    cout << "*p: ";
	cout << *p ;
	cout << "   p->ver()  " << "\t\t\t\t*p: ";
	p->ver();
	cout << "   q = new conjuntoPlus(*p)";
	q = new conjuntoPlus(*p);
	cout << "   cout << *q:  " << "\t\t\t";
    cout << "*q: ";
	cout << *q ;
	cout << "   q->ver()  " << "\t\t\t\t*q: ";
	q->ver();
	//*p: { 2/1 } - [1/1 4/3] (1/1 2/1)
	cout << "   delete p  " << "\t\t\t\t";
	delete p;
	cout << "   conjuntoPlus::intervalo_por_defecto(fracc(0,1), 2)" << "\n\t\t\t\t";
	conjuntoPlus::intervalo_por_defecto(fracc(0,1), 2); //cambio no permitido
	cout << "   q->agregar(f2)" << "\t\t";
    q->agregar(f2);
	cout << "   q->agregar(fracc(6,2))" << "\t";
	q->agregar(fracc(6,2));
	cout << "   q->borrar(2)" << "\t\t\t";
    q->borrar(2);
	cout << "   cout << *q:  " << "\t\t\t";
    cout << "*q: ";
	cout << *q ;
	cout << "   q->ver()  " << "\t\t\t\t*q: ";
	q->ver();
	//*q: { 3/1 } - [1/1 4/3] (1/1 2/1)
	cout << "   delete q  " << "\t\t\t\t";
	delete q;
	cout << "   conjuntoPlus::intervalo_por_defecto(fracc(2,2), 2)" << "\n\t\t\t\t";
	conjuntoPlus::intervalo_por_defecto(fracc(2,2), 2); //intervalo por defecto: [2/2, 2/1]
	cout << "   conjuntoPlus a(fracc(2,4), f1)" << "\t";
	conjuntoPlus a(fracc(2,4), f1);
	cout << "   conjuntoPlus b" << "\t\t\t";
	conjuntoPlus b;
	fracc x(1), y(7,6);
	cout << "   a.ver()  " << "\t\t\t\ta: ";
	a.ver(); //a: { } – [2/4 4/2] (2/2 2/1)
	cout << "   b.ver()  " << "\t\t\t\tb: ";
	b.ver(); //b: { } – [2/2 2/1] (2/2 2/1)
	cout << "   a.conjunto::ver()  " << "\t\t\ta: ";
	a.conjunto::ver(); cout << endl; //a: { }
	cout << "   cout << a:  " << "\t\t\t\t";
	cout << "a: " << a; //a: { } – [1/2 2/1] (1/1 2/1)
	cout << "   a.vacio()  " << "\t\t\t";
	if (a.vacio()) cout << "a esta vacio\n"; //a esta vacio
	else cout << "a no esta vacio\n";
	cout << "   Carga de a:\n";
	cout << "   a.agregar(fracc(1,4))" << "\t";
    a.agregar(fracc(1,4));
	cout << "   a.agregar(fracc(2,6))" << "\t";
	a.agregar(fracc(2,6));
	cout << "   a.agregar()" << "\t\t\tIntroducir las fracciones 2/2, 7/1 y 2/4" << endl;
	a.agregar(); //introduce las fracciones 2/2, 7/1 y2/4
	cout << "   cout << a:  " << "\t\t\t";
    cout << "a: ";
	cout << a; //a: {1/4 1/3 7/1} – [1/2 2/1] (1/1 2/1)
	cout << "   a.ver()  " << "\t\t\ta: ";
	a.ver(); //a: {1/4 2/6 7/1} – [2/4 4/2] (2/2 2/1)
    cout << "\t\t\t\tA tiene " << a.getn() << " fracc\n"; //atiene 3 fracc
	cout << "   conjuntoPlus c(a)";
    conjuntoPlus c(a); //c: {1/4 2/6 7/1} – [2/4 4/2] (2/2 2/1)
	cout << "   cout << c:  " << "\t\t\t";
    cout << "c: ";
	cout << c; //c: {1/4 1/3 7/1} – [1/2 2/1] (1/1 2/1)
	cout << "   c.ver()  " << "\t\t\tc: ";
    c.ver();
	cout << "   a.borrar(7)" << "\t\t\t";
    a.borrar(7);
	cout << "   a.borrar(2)" << "\t\t\t";
	a.borrar(2);
	//a: {1/4 2/6 } – [2/4 4/2] (2/2 2/1)
	cout << "   cout << a:  " << "\t\t\t";
    cout << "a: ";
	cout << a; //c: {1/4 1/3 7/1} – [1/2 2/1] (1/1 2/1)
	cout << "   a.ver()  " << "\t\t\ta: ";
    a.ver();
	cout << "   b=b=a=a  " << "\t\t\t";
    b=b=a=a;
	cout << "   a.cambiar_intervalo(0, 1)" << endl;
    a.cambiar_intervalo(0, 1);
	cout << "   cout << a:  " << "\t\t\t";
    cout << "a: ";
	cout << a; //c: {1/4 1/3 7/1} – [1/2 2/1] (1/1 2/1)
	cout << "   a.ver()  " << "\t\t\ta: ";
    a.ver();
	cout << "   cout << b:  " << "\t\t\t";
    cout << "b: ";
	cout << b; //c: {1/4 1/3 7/1} – [1/2 2/1] (1/1 2/1)
	cout << "   b.ver()  " << "\t\t\tb: ";
    b.ver();
	cout << "   cout << c:  " << "\t\t\t";
    cout << "c: ";
	cout << c; //c: {1/4 1/3 7/1} – [1/2 2/1] (1/1 2/1)
	cout << "   c.ver()  " << "\t\t\tc: ";
    c.ver();
    //a: { } – [0/1 1/1] (1/1 2/1)
    //b: {1/4 1/3 } – [1/2 2/1] (1/1 2/1)
    //c: {1/4 1/3 7/1} – [1/2 2/1] (1/1 2/1)
	cout << "   if (c.pertenece(x*2+fracc(10,2)))" << endl;
    if (c.pertenece(x*2+fracc(10,2)))
    cout << "\t\t\t\tx*2+fracc(10,2) = " << x*2+fracc(10,2) << " esta en c\n"; //esta en c
    return EXIT_SUCCESS;
}
