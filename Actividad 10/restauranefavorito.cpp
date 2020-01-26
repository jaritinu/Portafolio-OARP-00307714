#include <iostream>
#include <string>
using namespace std;

struct orden{
    string nombreCliente;
    int tacos;
    int sopas;
    int tortas;
};
typedef orden T;
const T noValido = {{" "},-1,-1,-1};


struct nodo{
    T elemento;
    nodo* siguiente;
};

struct Cola{
    nodo* frente;
    nodo* final;
};

struct Taqueria{
    Cola colaPedidos;
    int ordenesServidas;
};
Taqueria TacoInn;

void agregarOrden();
void consultar();
void servir();
void vertodos();

void initialize(Cola *q);
bool empty(Cola *q);
T front(Cola *q);
T back(Cola *q);
void enqueue(Cola *q, T x);
T dequeue(Cola *q);
int size(Cola *q);

int main(void){
    int a;
   
    return 0;
}
void agregarOrden(){
   
}
void consultar(){
   
}
void servir(){
   
}
void vertodos(){
   
}

void initialize(Cola *q){
    q->frente = NULL;
    q->final = NULL;
}

bool empty(Cola *q){
    return (q->frente == NULL) ? true : false;
}

T front(Cola *q){
    if (empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->final)->elemento;
}

T back(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->final)->elemento;
}

void enqueue(Cola *q, T x){
    nodo *unNodo = new nodo;
    unNodo->elemento = x;
    unNodo->siguiente = NULL;
   
    if(q->final==NULL)
        q->frente = unNodo;
    else
        (q->final)->siguiente = unNodo;
       
    q->final = unNodo;
}

T dequeue(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    nodo *unNodo = q->frente;
    T x = unNodo->elemento;
    q->frente = unNodo->siguiente;
    if(q->frente == NULL)
        q->final = NULL;
    delete(unNodo);
    return x;
}

int size(Cola *q){
   
}
