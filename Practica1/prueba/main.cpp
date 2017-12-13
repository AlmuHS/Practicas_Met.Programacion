#include <iostream>
#include "../Multiconjunto/Multiconjunto.h"
#include "../Persona/Persona.h"

using namespace std;

int main()
{
    Multiconjunto<Persona> prueba2;
    Persona p;
    Persona q("Jack", 23);
    Persona l("fugito");
    if(prueba2.esVacio()) prueba2.anade(p);
    if(prueba2.pertenece(p)) prueba2.anade(q);
    else cout<<"\nFallo de insercion en elemento p";
    if (prueba2.pertenece(q)) prueba2.anade(l);
    else cout<<"\nFallo de insercion en elemento q";
    if(prueba2.pertenece(l)) cout<<"\n\nInsercion correcta";
    else cout<<"\nFallo de insercion en elemento l";
    cout<<"\nNumero de elementos: "<<prueba2.cardinalidad();

    if(prueba2.pertenece(l)) prueba2.elimina(l);
    if(prueba2.pertenece(q)) prueba2.elimina(q);
    if(prueba2.pertenece(p)) prueba2.elimina(p);
    if(!prueba2.pertenece(l) && !prueba2.pertenece(q) && !prueba2.pertenece(p))
        cout<<"\nEliminacion correcta\n";
    cout<<"Numero de elementos: "<<prueba2.cardinalidad();


    Multiconjunto<char> prueba;
    char ascii='0';
    if(prueba.esVacio()) cout<<"\n\nEl conjunto esta vacio\n";
    cout<<ascii<<"\t";
    while(prueba.cardinalidad()<100){//añade los primeros 30 caracteres ascii al conjunto
        prueba.anade(ascii);
        ascii++;
        cout<<ascii<<"\t";
    }
    if(prueba.pertenece('}')) cout<<"\nEl caracter } esta dentro del conjunto";
    if (prueba.pertenece('|')){
        prueba.elimina('|');
        if (!prueba.pertenece('|')) cout<<"\ncaracter | eliminado";
    }
    cout<<"\nNumero de elementos: "<<prueba.cardinalidad();
    return 0;
}
