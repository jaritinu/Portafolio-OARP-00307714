#include <iostream>
using namespace std;

void mostrar(int v1[],int validos, int i);

int main() {
    int v[7]={1,2,3,4,3,6,8};
    int validos=6;
    mostrar(v,validos,0);
    return 0;
}

void mostrar(int v1[],int validos, int i){
  if(validos < i){
    return ;
  }else{
    cout << v1[i] << " ";  
    return mostrar(v1,validos,i+1);
  }
}