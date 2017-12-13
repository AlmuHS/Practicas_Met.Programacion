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

