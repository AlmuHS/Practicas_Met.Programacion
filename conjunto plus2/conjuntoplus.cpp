#include "conjuntoplus.h"

using namespace std;


fracc conjuntoPlus::pdef_inicio=fracc(0,1);
fracc conjuntoPlus::pdef_fin=fracc(1,1);
int conjuntoPlus::m = 0;

conjuntoPlus::conjuntoPlus(cadena nom) :conjunto(){
    nombre=new char[20];
    nombre=nom;
    p_inicio = pdef_inicio;
    p_fin = pdef_fin;
    m++;
}

conjuntoPlus::conjuntoPlus(fracc ini_interval, fracc fin_interval, cadena nom):conjunto(){
    nombre=new char[20];
    nombre=nom;
    p_inicio=ini_interval;
    p_fin=fin_interval;
    m++;
}

void conjuntoPlus::intervalo_por_defecto(fracc f1, fracc f2){
    if(m==0){
        pdef_inicio=f1;
        pdef_fin=f2;
    }
}

void conjuntoPlus::cambiar_intervalo(fracc f1, fracc f2){
    int num_elem=m;

    for(int i=1; i<num_elem+1; i++){
        fracc f=conjunto::operator[](i);
        if(f>f1 && f2>f) borrar(f);
    }//fin for
    p_inicio=f1;
    p_fin=f2;
}

void conjuntoPlus::agregar(){
    char seguir='n';
    do{
        int num, den;
        cout<<"Numerador: ";
        cin>>num;
        cout<<"Denominador: ";
        cin>>den;
        fracc f(num, den);
        if(p_inicio>f || f>p_fin) conjunto::agregar(f);
        cout<<"¿desea introducir otra? (s/n)";
        cin>>seguir;
        m++;
    }while(seguir=='s');
}

void conjuntoPlus::agregar(fracc f){
    if(p_inicio>f || f>p_fin) conjunto::agregar(f);
    m++;
}

void conjuntoPlus::ver(){
    cout<<"{";
    for(int i=1; i<m+1; i++)
        cout<<conjunto::operator[](i)<<",";
    cout<<"}-["<<p_inicio<<", "<<p_fin<<"]("<<p_inicio<<", "<<p_fin<<")";
}


ostream& operator<<(ostream &i, conjuntoPlus c){
    i<<"{";
    for(int j=1; j<c.m+1; j++){
        fracc copia(c[j].getn(), c[j].getd());
        copia.reduce();
        if(copia.getd()>0) i<<copia.getn()<<"/"<<copia.getd()<<",";
        else if(copia.getd()==0) i<<"Inf,";
        else i<< -copia.getn() << "/" << -copia.getd()<<",";
    }
    i<<"}-["<<conjuntoPlus::pdef_inicio<<"\t"<<conjuntoPlus::pdef_fin<<"](0/1 1/1)";
    return i;
}


bool operator==(conjuntoPlus a, conjuntoPlus b){
    bool iguales;
    if(a.getn()!=b.getn() || a.p_inicio!=b.p_inicio || a.p_fin!= b.p_fin) iguales=false;
    else{
        int j=1;
        while(a[j]==b[j] && j<a.getn()+1) j++;
        if(j==a.getn()) iguales=true;
    }
    return iguales;
}


void borrarMin(conjunto *c[], int tam){
    for(int i=0; i<tam; i++){
        fracc minimo=c[i]->operator[](0);
        int posmin=1;
        for(int j=1; j<c[i]->getn()+1; j++){
            if(minimo>c[i]->operator[](j)){
                minimo=c[i]->operator[](j);
                posmin=j;
            }//fin if
        }//fin for j
        c[i]->borrar(posmin);
    }//fin for i
}


