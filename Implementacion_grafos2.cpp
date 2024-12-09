#include <iostream>

using namespace std;

class GrafoDirigido {
private:
    int V; 
    int **matrizAdj;  

public:

    GrafoDirigido(int V) {
        this->V = V;

        matrizAdj = new int*[V];
        for (int i = 0; i < V; ++i) {
            matrizAdj[i] = new int[V];
            for (int j = 0; j < V; ++j) {
                matrizAdj[i][j] = 0; 
            }
        }
    }

   
    ~GrafoDirigido() {
        for (int i = 0; i < V; ++i) {
            delete[] matrizAdj[i];
        }
        delete[] matrizAdj;
    }

  
    void agregarArista(int origen, int destino) {
        if (origen >= 0 && origen < V && destino >= 0 && destino < V) {
            matrizAdj[origen][destino] = 1;  
        }
    }

   
    void mostrarGrafo() {
        for (int i = 0; i < V; ++i) {
            cout << "Vértice " << i << " -> ";
            for (int j = 0; j < V; ++j) {
                if (matrizAdj[i][j] == 1) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }

    void obtenerAdyacentes(int nodo) {
        if (nodo >= 0 && nodo < V) {
            cout << "Nodos adyacentes a " << nodo << ": ";
            for (int i = 0; i < V; ++i) {
                if (matrizAdj[nodo][i] == 1) {
                    cout << i << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
   
    GrafoDirigido grafo(5);

 
    grafo.agregarArista(0, 1);
    grafo.agregarArista(0, 2);
    grafo.agregarArista(1, 3);
    grafo.agregarArista(2, 3);
    grafo.agregarArista(3, 4);

 
    grafo.mostrarGrafo();

   
    grafo.obtenerAdyacentes(0);

    return 0;
}
