#include <iostream>
using namespace std;
#include <limits.h>

#define V 9

//esta es una funcion la cual se encarga de encontrar el vertice con la menor distancia
// desde el conjunto de vertices aun no incluido en la ruta mas corta
int minDistance(int dist[], bool sptSet[]) {

	//Declaramos la variable para encontrar el menor valor o vertice
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

//esta funcion se encarga de imprimir la distancia del array que estemos construyendo
void printSolution(int dist[]) {

	cout << "Vertice \t Distancia desde el punto" << endl;

	for (int i = 0; i < V; i++)
		cout << i << "\t\t" << dist[i] << endl;

}

//esta funcion implementa el algoritmo de Dijkstra 
//para un grafico el cual esta representado por una matriz de adyacencia
void dijkstra(int graph[V][V], int src) {
	
	// esta matriz es la que mantendra la distancia mas corta
	// de la src a la variable i 
	int dist[V];

	//esta variable sera la que vaya llevando en cuenta cual es camino 
	// mas corto, esta es la que podemos decir que va validando cada ruta que se toma
	bool sptSet[V];

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {

		int u = minDistance(dist, sptSet);

		sptSet[u] = true;

		for (int v = 0; v < V; v++)

			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	printSolution(dist);
}

int main() {

	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
					   { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
					   { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
					   { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
					   { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
					   { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
					   { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
					   { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
					   { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	dijkstra(graph, 0);

	return 0;
}
