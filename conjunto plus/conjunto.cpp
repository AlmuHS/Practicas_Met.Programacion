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


#include "conjunto.h"

using namespace std;

conjunto::conjunto(){
    n=0;
    nmax=3;
    T=new fracc[3];
}

bool conjunto::vacio(){
    bool vacio;
    if(n==0) vacio=true;
    else vacio=false;
    return vacio;
}

int conjunto::getn(){
    return n;
}

bool conjunto::pertenece(fracc f){
    bool pertenece;
    int i=1;
    while(i<MAX+1 && T[i]!=f) i++;
    if(T[i]!=f) pertenece=true;
    else pertenece=false;
    return pertenece;
}

void conjunto::ver(){
    cout<<"{";
    for(int i=1; i<n+1; i++)
        cout<<T[i]<<",";
    cout<<"}";
}

void conjunto::agregar(){
    if(n==nmax){
        const int numelem=n;
        fracc aux[numelem];
        for(int i=1; i<numelem+1; i++)
            aux[i]=T[i];
        nmax=nmax+3;
        T=new fracc[nmax];
        for(int j=1; j<n+1; j++)
            T[j]=aux[j];
    }

    char seguir='n';
    do{
        int num, den;
        cout<<"Numerador: ";
        cin>>num;
        cout<<"Denominador: ";
        cin>>den;
        fracc f(num, den);
        T[n]=f;
        n++;
        cout<<"¿desea introducir otra? (s/n)";
        cin>>seguir;
    }while(seguir=='s');
}

void conjunto::agregar(fracc f){
    if(n==nmax){
        const int numelem=n;
        fracc aux[numelem];
        for(int i=1; i<numelem+1; i++)
            aux[i]=T[i];
        nmax=nmax+3;
        T=new fracc[nmax];
        for(int j=1; j<n+1; j++)
            T[j]=aux[j];
    }

    T[n]=f;
    n++;
}


void conjunto::borrar(fracc f){
    bool encontrado=false;
    int i=1;
    while(T[i]!=f && i<n+1) i++;
    if(T[i]==f) encontrado=true;
    if(encontrado==true){
        for(int j=i; j<n; j++){
            fracc tmp;
            T[j]=T[j+1];
        }
        n--;
    }
}

fracc conjunto::operator[](int n){
    return T[n-1];
}

ostream& operator<<(ostream &i, conjunto c){
    i<<"{";
    for(int j=1; j<c.n+1; j++){
        fracc copia(c.T[j].getn(), c.T[j].getd());
        copia.reduce();
        if(copia.getd()>0) i<<copia.getn()<<"/"<<copia.getd()<<",";
        else if(copia.getd()==0) i<<"Inf,";
        else i<< -copia.getn() << "/" << -copia.getd()<<",";
    }
    i<<"}";
    return i;
}
