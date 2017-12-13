#include "fracc.h"
#include <iostream>

using namespace std;

fracc::fracc(int n, int d){
    num=n;
    den=d;
}

int fracc::getd(){
    return den;
}

int fracc::getn(){
    return num;
}

void fracc::set(){
    cout<<"Introduce el numerador: ";
    cin>>num;
    cout<<"Introduce el denominador: ";
    cin>>den;
}

void fracc::set(int n, int d){
    num=n;
    den=d;
}

void fracc::ver(){
    cout<<num<<"/"<<den;
}

fracc fracc::operator*(fracc f){
    fracc r(0,0);
    r.num=num*f.num;    fracc operator+(int n, fracc f);

    r.den=den*f.den;
    return r;
}


fracc fracc::operator/(fracc f){
    fracc r(0,0);
    r.num=num*f.den;
    r.den=den*f.num;
    return r;
}


fracc fracc::operator-(){
    fracc r(0,0);
    r.num=-num;
    r.den=den;
    return r;
}

fracc fracc::operator+(fracc f){
    fracc r(0,0);
    r.den=mcm(den,f.den);
    r.num=(r.den/den)*num+(r.den/f.den)*f.num;
    return r;
}



fracc fracc::operator-(fracc f){
    fracc r(0,0);
    r.den=mcm(den,f.den);
    r.num=(r.den/den)*num-(r.den/f.den)*f.num;
    return r;
}

void fracc::reduce(){
    int MCD=mcd(num,den);//maximo comun divisor
    num=num/MCD;
    den=den/MCD;
}

bool fracc::operator==(fracc f){
    bool igual;
    if (f.num/f.den==num/den) igual=true;
    else igual=false;
    return igual;
}

bool fracc::operator>(fracc f){
    bool mayor;
    if(num/den>f.num/f.den) mayor=true;
    else mayor=false;
    return mayor;
}


/*ostream &operator<<(ostream &i, const fracc f){
    if(f.getd()>0) f.ver();
    else if(f.getd()==0) i<<"Inf";
    else i<< -f.getn() << "/" << -f.getd();
    return i;
}*/

fracc operator+(int n, fracc f){
    int den=mcm(f.getd(),1);
    int num=(den/f.getd())*f.getn()+(den*n);
    fracc r(num, den);
    return r;
}

fracc operator-(int n, fracc f){
    int den=mcm(f.getd(),1);
    int num=(den/f.getd())*f.getn()-(den*n);
    fracc r(num, den);
    return r;
}

fracc operator*(int n, fracc f){
    int num=n*f.getn();
    int den=f.getd();
    fracc r(num, den);
    return r;
}


fracc operator/(int n, fracc f){
    int num=f.getn();
    int den=f.getd()*n;
    fracc r(num, den);
    return r;
}
