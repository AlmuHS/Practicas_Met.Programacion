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
