#include "Multiconjunto.h"

using namespace std;

template <typename T> Multiconjunto<T>::Multiconjunto(){
    num=0;
}

template <typename T> bool Multiconjunto<T>::esVacio()const {
    return (num==0);
}

template <typename T> int Multiconjunto<T>::cardinalidad() const{
    return num;
}

template <typename T> void Multiconjunto<T>::anade(const T& objeto){
    c[num]=objeto;
    num++;
}

template <typename T> void Multiconjunto<T>::elimina(const T& objeto){
    for (int i=0; i<num; i++){
        if(c[i]==objeto) c[i]=c[num-1];
    }
    num--;
}

template <typename T> bool Multiconjunto<T>::pertenece(const T& objeto) const{
    int i=0;
    bool pertenece=false;
    while (!pertenece && i<num){
        if(c[i]==objeto) pertenece=true;
        else i++;
    }
    return pertenece;
}

template class Multiconjunto<char>;
template class Multiconjunto<int>;
template class Multiconjunto<Persona>;
