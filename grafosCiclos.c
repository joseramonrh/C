#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


typedef struct vertice vertice;
typedef struct arista arista;

void conectaNodos(vertice * vertices, vertice * verticeConectado);
void agregaArista(vertice * vertices, int grado, int probabilidad);
//LAS DOS ESTRUCTURAS
struct vertice
{
	int value;
	vertice *vertice;
	arista *arista;
	bool visitado;
	bool ciclo;
};
struct arista
{
	arista *arista;
	vertice *vertice;
};

//AGREGA LOS ARISTAS SI EL RANDOM ES MENOR QUE LA PROBA, Y LLAMA AL METODO CONECTA NODOS.
void agregaArista(vertice * vertices, int grado, int probabilidad){
	vertice * primerNodo = vertices;
	vertice * cambianteNodo;

	while(primerNodo){

		cambianteNodo = vertices;
		while(cambianteNodo){
			if (cambianteNodo != primerNodo)
			{
				int l = rand()%100;
				if (l<probabilidad)
				{
					conectaNodos(primerNodo, cambianteNodo);
				}
			}
			cambianteNodo = cambianteNodo->vertice;
		}
		primerNodo = primerNodo->vertice;
	}
}
//AGREGA EL VERTICE, SI EL VERTICE NO APUNTA A NADA SE AGREGA EN SEGUIDA, SI NO SE AGREGA AL FINAL
void agregaVertice(vertice ** vertices, int value){
	vertice * v = (vertice *)calloc(1, sizeof(vertice));
	v->value = value;
	v->vertice;
	v->arista;

	if (*vertices == NULL)
	{
		*vertices = v;
	}
	else{
		vertice * current = *vertices;
		while(current->vertice){
			current = current->vertice;
		}
		current->vertice = v;
	}
}

//CONECTA LOS NODOS, SI EL VERTICE NO TIENE ARISTAS LA PONE AL PRINCIPIO, SI TIENE LA AGREGA AL FINAL
void conectaNodos(vertice * vertices, vertice * verticeConectado){
	arista * aristas = (arista *)calloc(1, sizeof(arista));
	aristas->arista;
	aristas->vertice = verticeConectado;
	if (!vertices->arista)
	{
		vertices->arista = aristas;
	}
	else
	{
		arista * aristasDos = vertices->arista;
		while(aristasDos->arista){
			aristasDos = aristasDos->arista;
		}
		aristasDos->arista = aristas;
	}
}

//LLAMA A AGREGA VERTICE
vertice * creaVertices(int grado){
	int i = 0;
	vertice * vertices = NULL;
	for (i = 0; i < grado; ++i)
	{
		agregaVertice(&vertices, i);
	}

	return vertices;
}
//VISITA LOS NODOS
void visitaNodos(vertice * vertices){
	arista * aristaVisitar = vertices->arista;
	vertices->visitado = true;
	if (vertices->visitado)
	{
		printf("Ciclo\n");
	}
	printf("%d ", vertices->value);
	while(aristaVisitar){
		if (!aristaVisitar->vertice->visitado)
		{
			visitaNodos(aristaVisitar->vertice);
		}
		aristaVisitar = aristaVisitar->arista;
	}
}

void imprimete(vertice * vertices){
	while(vertices){
		printf("%d ->", vertices->value);
		arista * aristas = vertices->arista;
		while(aristas){
			printf("->%d", aristas->vertice->value);
			aristas = aristas->arista;
		}
		printf("\n");
		vertices = vertices->vertice;
	}
}


int main()
{
	srand((int)time(NULL));
	int grado = 5;
	int probabilidad = 30;

	vertice * vertices = creaVertices(grado);
	agregaArista(vertices, grado, probabilidad);
	printf("Grafo generado\n");
	imprimete(vertices);
	printf("recorre\n");
	visitaNodos(vertices);
	printf("\n");
	vertice * checa = vertices->vertice;
	while(checa){
		if (!checa->visitado)
		{
			printf("Parte inconexa del grafo\n");
			visitaNodos(checa);
		}
		checa = checa->vertice;
	}
	printf("\n");

	return 0;
}
