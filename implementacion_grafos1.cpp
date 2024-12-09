#include <iostream>
using namespace std;


struct Nodo {
    int vertice;   
    Nodo* siguiente; 
};


class Grafo {
private:
    int V;  
    Nodo** adj; 

public:
    // Constructor
    Grafo(int V) {
        this->V = V;
        adj = new Nodo*[V]; 
        for (int i = 0; i < V; i++) {
            adj[i] = nullptr;  
        }
    }

  
    void agregarArista(int v1, int v2) {
 
        Nodo* nuevoNodo = new Nodo{v2, adj[v1]};
        adj[v1] = nuevoNodo;

   
        nuevoNodo = new Nodo{v1, adj[v2]};
        adj[v2] = nuevoNodo;
    }

 
    void mostrar() {
        for (int i = 0; i < V; i++) {
            cout << "Vertice " << i << " -> ";
            Nodo* temp = adj[i];
            while (temp != nullptr) {
                cout << temp->vertice << " ";
                temp = temp->siguiente;
            }
            cout << endl;
        }
    }

    ~Grafo() {
        for (int i = 0; i < V; i++) {
            Nodo* temp = adj[i];
            while (temp != nullptr) {
                Nodo* borrar = temp;
                temp = temp->siguiente;
                delete borrar;  
            }
        }
        delete[] adj;  
    }
};

int main() {
   
    Grafo g(5);

 
    g.agregarArista(0, 1);
    g.agregarArista(0, 2);
    g.agregarArista(1, 3);
    g.agregarArista(2, 3);
    g.agregarArista(3, 4);

    
    g.mostrar();

    return 0;
}
