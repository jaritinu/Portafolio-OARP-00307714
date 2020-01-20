#include <iostream>
using namespace std;

void findV(int v1[],int valor, int validos, int i);

int main() {
    int v[7]={1,2,3,4,3,6,8};
    int validos=6;
    int val;
    cout << "Digite el valor a buscar en el arreglo: ";
    cin >> val;
    findV(v,val,validos,0);
    return 0;
}

void findV(int v1[],int valor, int validos, int i){
    if(v1[i]==valor){
        cout << "Valor encontrado en la posicion " << i <<endl;
        return ;
    }else{
        if(validos == i){
            cout << "Valor no encontrado"<<endl;
            return ;
        }else
            findV(v1,valor,validos,i+1);
    }
}