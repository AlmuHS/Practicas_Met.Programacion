#ifndef FRACCH
#define FRACCH

#include "aux.h"

using namespace std;

    class fracc{
        int num, den;
        public:
            fracc(int n, int d);
            int getn();
            int getd();
            void set();
            void set(int n, int d);
            void ver();
            void reduce();
            fracc operator+(fracc f);

            fracc operator-(fracc f);

            fracc operator*(fracc f);

            fracc operator/(fracc f);

            fracc operator-();
            bool operator==(fracc f);
            bool operator>(fracc f);
    };

    fracc operator+(int n, fracc f);
    fracc operator-(int n, fracc f);
    fracc operator*(int n, fracc f);
    fracc operator/(int n, fracc f);
    //ostream&  operator<<(ostream &i, const fracc & f);

#endif
