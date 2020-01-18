#include <iostream>
#include <string>
using namespace std;

struct continente{
    string name;
    string country[5];
    string capital[5];
    int poblation[5];
    float averageAge[5];
};
//typedef struct continente continet;

continente earth;
continente *pEarth = &earth;
//int cantidadContinentes = 6;

void entrada(continente *p);
void poblacionTotal(continente *p);
void capitalMayor(continente *p);
void promedioContinente(continente *p);

int main(){
   
    entrada(pEarth);
     
    // Mostrar menu al usuario
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1. Mostrar poblacion total\n";
        cout << "2. Capital con mayor poblacion\n";
        cout << "3. Promedio de edad continente\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();
       
        switch(opcion){
            case 1: poblacionTotal(pEarth); break;
            case 2: capitalMayor(pEarth); break;
            case 3: promedioContinente(pEarth); break;
            case 4: continuar = false;
        }
    }while(continuar);

    return 0;
}

void entrada(continente *p){
    // Solicitar datos al usuario
   // for(int i = 0; i < 5; i++){
        cout << "Digite el nombre del continente: ";
        getline(cin, p->name);
        cin.ignore();
        for(int j = 0; j < 5; j++){
            cout << "Digite el nombre del pais "<< j + 1 << ": " <<endl;
            getline(cin, p->country[j]);
            cout << "Digite el nombre de la capital: ";
            getline(cin, p->capital[j]);
            cout << "Digite la poblacion: ";
            cin >> p->poblation[j];
            cout<< "Digite la edad promedio: ";
            cin >> p->averageAge[j];
            cin.ignore();
        }
  //  }
}


void poblacionTotal(continente *p){
   int sumPoblation = 0;
   for(int i = 0; i < 5; i++){
    sumPoblation = sumPoblation + p->poblation[i];        
    }
    cout << "La poblacion total del continente es: " << sumPoblation <<endl;
}

void capitalMayor(continente *p){
    int pos = 0, biggest = p->poblation[0];
    for(int i = 1; i < 5; i++){
        if(p->poblation[i]>biggest){
            biggest=p->poblation[i];
            pos=i;
        }      
    }
    cout << "La capital con mayor poblacion del continente es: " << p->name[pos] <<endl;
}
void promedioContinente(continente *p){
   int sumAge = 0;
   float continentAge;
    for(int i = 1; i < 5; i++){
        sumAge = sumAge + p->poblation[i];
    }
    continentAge = sumAge / 5;
    cout << "La poblacion total del continente es: " << continentAge <<endl;
}