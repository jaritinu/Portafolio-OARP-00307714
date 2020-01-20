#include <iostream>
//#include <math.h>
using namespace std;

int findBinary(int array[],int valor, int low, int high);

int main() {
    int v[8]={1,3,4,5,17,18,31,33};
    int high=7, r=-1;
    int val;
    cout << "Digite el valor a buscar en el arreglo: ";
    cin >> val;
    r=findBinary(v,val,0,high);
    if (r == -1){
        cout << "No se encontro el valor" <<endl;
    }
    else{
        cout << "El valor " << v[r] << " esta en la posicion: " << r <<endl;
    }  
    return 0;
}

int findBinary(int array[],int valor, int low, int high){
    int mid = 0;
    if(low > high){
      return -1;
    }
    mid = (low + high) / 2;
    if(valor == array[mid]){
        return mid;
    }
    if(valor < array[mid]){
        high = mid - 1;
    }
    else{
        low = mid + 1;
    }
    return findBinary(array,valor,low,high);
}