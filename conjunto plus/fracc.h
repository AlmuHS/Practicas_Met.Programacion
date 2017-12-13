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
