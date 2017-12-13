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

#include "fracc.h"
#include <iostream>

using namespace std;

fracc::fracc(int n, int d){
    num=n;
    den=d;
}

int fracc::getd() const{
    return den;
}

int fracc::getn() const{
    return num;
}

void fracc::set(){
    cout<<"Introduce el numerador: ";
    cin>>num;
    cout<<"Introduce el denominador: ";
    cin>>den;
}

void fracc::set(int n, int d){

    if(den<0){
        num=-n;
        den=-d;
    }
    else{
        num=n;
        den=d;
    }
}

void fracc::ver() const{
    cout<<num<<"/"<<den<<endl;
}

fracc fracc::operator*(fracc f) const{
    fracc r(0,0);
    r.num=num*f.num;
    r.den=den*f.den;
    return r;
}

fracc fracc::operator*(int a) const{
    fracc r(0,0);
    r.num = num*a;
    r.den = den;
    return r;
}


fracc fracc::operator/(fracc f) const{
    fracc r(0,0);
    r.num=num*f.den;
    r.den=den*f.num;
    return r;
}

fracc fracc::operator/(int a) const{
    fracc r(0,0);
    r.num = num;
    r.den = den*a;
    return r;
}


fracc fracc::operator-() const{
    fracc r(0,0);
    if(num<0) r.num=-num;
    else if (den<0) r.den=-den;
    else{
        r.num=-num;
        r.den=den;
    }
    return r;
}

fracc fracc::operator+(fracc f) const{
    fracc r(0,0);
    r.den=mcm(den,f.den);
    r.num=(r.den/den)*num+(r.den/f.den)*f.num;
    return r;
}

fracc fracc::operator+(int a) const{
    int den1=mcm(den,1);
    int num1=(den1/den)*num+(den1*a);
    fracc r(num1, den1);
    return r;
}

fracc fracc::operator-(fracc f) const{
    fracc r(0,0);
    r.den=mcm(den,f.den);
    r.num=(r.den/den)*num-(r.den/f.den)*f.num;
    return r;
}

fracc fracc::operator-(int a) const{
    fracc r(0,0);
    r.num = num-(a*den);
    r.den = den;
    return r;
}

fracc fracc::reduce(){
    int MCD=mcd(num,den);//maximo comun divisor
    int n,d;
    if (den==0|| (num==1 && den==1));
    else{
        n=num/MCD;
        d=den/MCD;
    }
    set(n, d);
    return *this;
}

bool fracc::operator==(fracc f) const{
    bool igual;
    if ((float)f.num/(float)f.den==(float)num/(float)den) igual=true;
    else igual=false;
    return igual;
}

bool fracc::operator==(int n) const{
    bool igual;
    if((float)num/(float)den==n) igual=true;
    else igual=false;
    return igual;
}

bool fracc::operator!=(fracc f) const{
    bool distinto;
    if ((float)f.num/(float)f.den!=(float)num/(float)den) distinto=true;
    else distinto=false;
    return distinto;
}

bool fracc::operator>(fracc f) const{
    bool mayor=false;
    if(num==f.num && den<f.den) mayor=true;
    else if(den==f.den && num>f.num) mayor=true;
    else if((float)num/den>(float)f.num/f.den) mayor=true;
    return mayor;
}

fracc & fracc::operator=(const fracc& f){
    den=f.den;
    num=f.num;
    return *this;
}

fracc & fracc::operator=(const int& n){
    num=n;
    den=1;
    return *this;
}

fracc fracc::operator++(){
    *this=*this+1;
    return (*this);
}

fracc fracc::operator++(int notused){
   *this=*this+1;
   return (*this);
}

fracc::operator float(){
    float f=(float)num/(float)den;
    return f;
}

fracc::operator int(){
    int x=num/den;
    return x;
}

ostream& operator<<(ostream &i, fracc f){//debe mostrarse la fraccion simplificada
    fracc copia(f.getn(), f.getd());
    copia.reduce();
    if(copia.getd()>0) i<<copia.getn()<<"/"<<copia.getd();
    else if(copia.getd()==0) i<<"Inf";
    else i<< -copia.getn() << "/" << -copia.getd();
    return i;
}

istream& operator>>(istream &s, fracc &f){
    int n, d;
    cout<<"Numerador: ";
    s>>n;
    do{
        cout<<"Denominador: ";
        s>>d;
    }while(d==0);
    f.set(n,d);
    return s;
}

fracc operator+(int n, fracc f){
    int den=mcm(f.getd(),1);
    int num=(den/f.getd())*f.getn()+(den*n);
    fracc r(num, den);
    return r;
}

fracc operator-(int n, fracc f){
    int den=mcm(f.getd(),1);
    int num=(den*n)-(den/f.getd())*f.getn();
    fracc r(num, den);
    return r;
}


fracc operator*(int n, fracc f){
    int num=n*f.getn();
    int den=f.getd();
    const fracc r(num, den);
    return r;
}


fracc operator/(int n, fracc f){
    int num=n*f.getd();
    int den=f.getn();
    fracc r(num, den);
    return r;
}

bool operator==(int n, fracc f){
    bool igual;
    if((float)f.getn()/(float)f.getd()==n) igual=true;
    else igual=false;
    return igual;
}
