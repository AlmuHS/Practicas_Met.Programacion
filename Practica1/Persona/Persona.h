#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona{
    string nombre;
    int edad;

    public:
        Persona(const string& n="", int e=0);
        const string& getnombre() const;
        int getEdad() const;
        void setNombre(const string& n);
        void setEdad(int e);
        bool operator==(const Persona& p) const;
};

#endif
