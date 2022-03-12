//Algorithmo de Busqueda en Profundidad
// Deep first Search Algorithm (DFS)
#include <bits/stdc++.h>
using namespace std;
 
// Creamos la clase Grafo 
class Grafo {
 
    // Algoritmo recursivo auxiliar
    void DFSaux(int v);
 
public:
    map<int, bool> nodos_recorridos;
    map<int, list<int> > aristas;
    // funcion que agrega aristas
    void agregar_arista(int v, int w);
 
    // muestra el recorrido hecho por DFS
    void DFS();
};
 
void Grafo::agregar_arista(int v, int w)
{
    aristas[v].push_back(w); 
}
 
void Grafo::DFSaux(int v)
{
    // Marca el nodo recorrido 
    nodos_recorridos[v] = true;
    cout << v << " ";
 
    // Itera sobre todos los nodos vecinos del nodo elegido
    list<int>::iterator i;
    for (i = aristas[v].begin(); i != aristas[v].end(); ++i)
        if (!nodos_recorridos[*i])
            DFSaux(*i);
}

void Grafo::DFS()
{
    // LLama la funcion recursiva auxiliar y la aplica 
    // por todos los vertices uno a uno.
    for (auto i : aristas)
        if (nodos_recorridos[i.first] == false)
            DFSaux(i.first);
}
 
// Driver  Code
int main()
{
    // Creamos el grafo 
    Grafo g;
    g.agregar_arista(0, 1);
    g.agregar_arista(0, 9);
    g.agregar_arista(1, 2);
    g.agregar_arista(2, 0);
    g.agregar_arista(2, 3);
    g.agregar_arista(9, 3);
 
    cout << "Busqueda en profundida desde el nodo 0 \n";
    g.DFS();
 
    return 0;
}