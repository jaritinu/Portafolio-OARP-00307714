#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct actividad{
    string titulo;
    string hora;
    int duracion;
};

void agregar(), borrar(), borrarTodas(), verTodas();

queue <actividad> colaActividades;

int main()
{
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar una actividad\n";
        cout << "2) Borrar una actividad\n";
        cout << "3) Borrar todas las actividades del dia\n";
        cout << "4) Ver todas las actividades del dia\n";
        cout << "5) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();
       
        switch(opcion){
            case 1: agregar(); break;
            case 2: borrar(); break;
            case 3: borrarTodas(); break;
            case 4: verTodas(); break;
            case 5: continuar = false; break;
            default: cout << "Opcion invalida!\n"; break;
        }
    }while(continuar);
    return 0;
}

void agregar(){
    actividad nuevo;
    cout << "\nTitulo de la actividad: "; getline(cin,nuevo.titulo);
    cout << "\nHora: "; getline(cin, nuevo.hora);
    cout << "\nDuracion: "; cin >> nuevo.duracion;
   
    colaActividades.push(nuevo);
}

void borrar(){
    colaActividades.pop();
}

void borrarTodas(){
    while(!colaActividades.empty()){
        colaActividades.pop();
    }
}

void verTodas(){
    queue <actividad> colaAux;
    actividad temp;
    bool flag=true;
    while(!colaActividades.empty()){
        temp = colaActividades.front();
        cout << "\nTitulo de la actividad: "<< temp.titulo <<endl;
        cout << "\nHora: "<< temp.hora << endl;
        cout << "\nDuracion: "<< temp.duracion << endl;
        colaAux.push(temp);
        colaActividades.pop();
        flag = false;
    }
    while(!colaAux.empty()){
        temp = colaAux.front();
        colaAux.pop();
        colaActividades.push(temp);
    }
    if(flag==true)
        cout << "\nSin actividades" << endl; 
}
