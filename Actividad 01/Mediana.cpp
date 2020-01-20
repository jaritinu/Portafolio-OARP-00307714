#include <iostream>
using namespace std;

float mediana (int *p, int size);

int main (){
    int n=0;
    int prueba [5]={1,2,3,4,5};
    int *vector;
    cout<<"Programa para calcular la mediana"<<endl;
    cout<<"Digite el numero de numeros a ingresar"<<endl;
    cin>>n;
    vector=new int[n];
    cout<<"Ingrese los numeros en orden "<<endl;
    for(int i=0;i<n;i++){
        cout<<"Digite un numero: "<<endl;
        cin>>vector[i];
    }
    cout<<"La mediana es: "<<mediana(vector,n)<<endl;
    return 0;
}

float mediana (int *p, int size){
    float mediana;
    if(size%2!=0){//caso impar
        mediana=*(p+(size/2));
    }else{//caso par
        mediana=(float (*(p+(size/2)))+float(*(p+((size/2)-1))))/2;
    }
    return mediana;
}