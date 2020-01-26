#include <iostream>
#include <string>

using namespace std;

struct brick{
    string brickType;
    string material;
};

struct nodeBrick{
    brick onebrick;
    nodeBrick *next;
};

typedef struct nodeBrick *brickStack;

void initialize(brickStack *s);
bool empty(brickStack *s);
void push(brickStack *s, brick a);
brick pop(brickStack *s);
brick top(brickStack *s);

int main(void){
    brickStack bStack;
    initialize(&bStack);
   
    bool continuar = true;
    do{
        char opcion = 's';
        cout << "\nCantidad de ladrillos actual: " << stackSize(&bStack);
        cout << "\nDesea apilar otro ladrillo? (s/n): ";
        cin >> opcion; cin.ignore();
       
        if(opcion == 's'){
            brick oneBrick;
            cout << "tipo: ";   getline(cin, oneBrick.brickType);
            cout << "Material: ";   getline(cin, oneBrick.material);
            push(&bStack, oneBrick);
        }
        else if(opcion == 'n')
            continuar = false;
        else
            cout << "Opcion no valida!" << endl;
    }while(continuar);
   
    // 3) Desapilando ladrillos -----------------------
    cout << "\nDesapilando ladrillos..." << endl;
    while(!empty(&bStack)){
        brick topBrick = top(&bStack);
        cout << "Ladrillo [" << topBrick.brickType;
        cout << ", " << topBrick.material << "]\n";
       
        pop(&bStack);

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

void push(brickStack *s, brick e){
    nodeBrick *oneBrick = new nodeBrick;
    oneBrick->onebrick = e;
    oneBrick->next = *s;
   
    *s = oneBrick;
}

brick pop(brickStack *s){
    if(!empty(s)){
        nodeBrick *oneBrick = *s;
        brick e = (*s)->onebrick;
        *s = (*s)->next;
        delete(oneBrick);
        return e;
    }
    else{
        return {{" "},{" "}};
    }
}

brick top(brickStack *s){
    if(!empty(s)){
        brick e = (*s)->onebrick;
        return e;
    }
    else{
        return {{" "},{" "}};
    }
}

int stackSize(brickStack *s){
    int countNodes=0;
    brickStack auxStack;
    brick auxBrick;
    while(!empty(s)){
            auxBrick=pop(s);
            push(&auxStack,auxBrick);
        
            countNodes++;
        }
        while(!empty(&auxStack)){
            auxBrick=pop(&auxStack);
            push(s,auxBrick);
        
            countNodes++;
        }    
    return countNodes;
}