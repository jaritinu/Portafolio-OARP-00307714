#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct brick
{
    string brickType;
    string material;
};

int main(void){
    stack <brick> brickStatck;
    bool continuar = true;
    do{
        char opcion = 's';
        cout << "\nCantidad de ladrillos actual: " << brickStatck.size();
        cout << "\nDesea apilar otro ladrillo? (s/n): ";
        cin >> opcion; cin.ignore();
        
        if(opcion == 's'){
            brick oneBrick;
            cout << "tipo: ";   getline(cin, oneBrick.brickType);
            cout << "Material: ";   getline(cin, oneBrick.material);
            brickStatck.push(oneBrick); 
        }
        else if(opcion == 'n')
            continuar = false;
        else
            cout << "Opcion no valida!" << endl;
    }while(continuar);
    
    // 3) Desapilando ladrillos -----------------------
    cout << "\nDesapilando ladrillos..." << endl;
    while(!brickStatck.empty()){
        // Obtener el ladrillo de encima (sin sacarlo de la pila)
        brick topBrick = brickStatck.top();
        cout << "Ladrillo [" << topBrick.brickType;
        cout << ", " << topBrick.material << "]\n";
        
        // Sacando ladrillo de la pila
        brickStatck.pop();
    }
    cout << "Pila de ladrillos vacia." << endl;

    return 0;
}