#include <iostream>
using namespace std;

int mostrar(int v1[],int validos, int i);

int main() {
    int v[7]={1,2,3,4,3,6,8};
    int validos=7;
    mostrar(v,validos,0);
    return 0;
}

int mostrar(int v1[],int validos, int i){
  int respuesta = 0;
  if(validos<i){
    cout << v1[i] << endl;
    respuesta = 1;
  }else{
    mostrar(v1,validos,i+1);
    cout << v1[i] << endl;  
  }
  return respuesta;
}