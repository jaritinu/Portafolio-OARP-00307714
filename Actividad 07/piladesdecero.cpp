#include <iostream>
#include <string>

using namespace std;

struct brick{
    string brickType;
    string material;
};

typedef struct brick * brickStack;

void initialize(brickStack *s);
bool empty(brickStack *s);
void push(brickStack *s, brick a);
brick pop(brickStack *s);
brick top(brickStack *s);

int main(void){
    brick *brickStack;
    initialize(&brickStack);
   
    bool continuar = true;
    do{
        char opcion = 's';
       // cout << "\nCantidad de ladrillos actual: " << brickStack.size();
        cout << "\nDesea apilar otro ladrillo? (s/n): ";
        cin >> opcion; cin.ignore();
       
        if(opcion == 's'){
            brick oneBrick;
            cout << "tipo: ";   getline(cin, oneBrick.brickType);
            cout << "Material: ";   getline(cin, oneBrick.material);
            push(&brickStack, oneBrick);
        }
        else if(opcion == 'n')
            continuar = false;
        else
            cout << "Opcion no valida!" << endl;
    }while(continuar);
   
    // 3) Desapilando ladrillos -----------------------
    cout << "\nDesapilando ladrillos..." << endl;
    while(!empty(&brickStack)){
        // Obtener el ladrillo de encima (sin sacarlo de la pila)
        brick topBrick = top(&brickStack);
        cout << "Ladrillo [" << topBrick.brickType;
        cout << ", " << topBrick.material << "]\n";
       
        // Sacando ladrillo de la pila
        pop(&brickStack);

    }
    cout << "Pila de ladrillos vacia." << endl;

    return 0;
}


void initialize(brickStack *s){
    *s = NULL;
}

bool empty(brickStack *s){
    return *s == NULL;
}

void push(brickStack *s, float e){
    struct brick *oneBrick;
    oneBrick = new brick[1];
    oneBrick->elemento = e;
    oneBrick->siguiente = *s;
   
    *s = unNodo;
    //cout << "Curiosidad: " << &unNodo << "\t";
    cout << "Nueva direccion: " << *s << endl;
}

brick pop(brickStack *s){
    if(!empty(s)){
        struct nodo *unNodo = *s;
        float e = (*s)->elemento;
        *s = (*s)->siguiente;
        delete(unNodo);
        cout << "Nueva direccion: " << *s << endl;
        return e;
    }
    else{
        cout << "Underflow!" << endl;
        return -1;
    }
}

brick top(brickStack *s){
    if(!empty(s)){
        brick e = (*s)->brickType;
        return e;
    }
    else{
        cout << "Underflow!" << endl;
        return -1;
    }
}

int stackSize(brickStack *s){
int countNodes=0;
brick *auxBrickStack;
brick auxBrick;
while(!empty(s)){
        // Sacando ladrillo de la pila
        auxBrick=pop(s);
        push(&auxBrickStack,auxBrick);
       
        countNodes++;
    }
    while(!empty(&auxBrickStack)){
        // Sacando ladrillo de la pila
        auxBrick=pop(&auxBrickStack);
        push(s,auxBrick);
       
        countNodes++;
    }
   
return countNodes;
}