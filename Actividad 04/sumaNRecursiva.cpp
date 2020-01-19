#include <iostream>
using namespace std;

int sumaNatural(int num);

int main(void) {
    int n=0;
    cout << "Digite un numero natural:\n";
    cin>>n;
    int r = sumaNatural(n);
    cout << "Resultado: " << r << endl;
    return 0;
}

int sumaNatural(int num){
  int respuesta = 0;
  if(num==1){
    cout << "n=" << num << " caso base" << endl;
    respuesta = 1;
  }else{
    int x = num - 1;
    respuesta = num + sumaNatural(x);
    cout << "n=" << num << " x=" << x << endl;
  }
  return respuesta;
}