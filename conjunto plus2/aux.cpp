#include "aux.h"

int mcm(int num1, int num2)
{
    /*int mcm;
    int i=1;
    while((n1*i)!=(n2*i)) i++;
    mcm=n1*i;
    return mcm;*/

    int MCD;
    MCD=mcd(num1,num2);
    return(MCD*(num1/MCD)*(num2/MCD));

}

int mcd(int num1, int num2)
{

    int t,i=2,mcd=1;
    if (num1>num2)
    {
        t=num1;
        num1=num2;
        num2=t;
    }
    do{
    if (num1%i==0 && num2%i==0)
    {
        mcd=mcd*i;
        num1=num1/i;
        num2=num2/i;
        i=2;
    }
    else
        i++;
    }while(i<=num1);
    return(mcd);
}

