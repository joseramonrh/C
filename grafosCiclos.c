#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


typedef struct vertice vertice;
typedef struct arista arista;

void conectaNodos(vertice * vertices, vertice * verticeConectado);
void agregaArista(vertice * vertices, int grado, int probabilidad);

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

vertice * creaVertices(int grado){
	int i = 0;
	vertice * vertices = NULL;
	for (i = 0; i < grado; ++i)
	{
		agregaVertice(&vertices, i);
	}

	return vertices;
}

void visitaNodos(vertice * vertices){
	arista * aristaVisitar = vertices->arista;
	vertices->visitado = true;
	printf("%d ", vertices->value);
	while(aristaVisitar){
		if (!aristaVisitar->vertice->visitado)
		{
			visitaNodos(aristaVisitar->vertice, previo);
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
void checaCiclos(){
	vertice * vertices;
}

int main()
{
	srand((int)time(NULL));
	int grado = 5;
	int probabilidad = 100;

	vertice * vertices = creaVertices(grado);
	agregaArista(vertices, grado, probabilidad);
	printf("Grafo generado\n");
	imprimete(vertices);
	printf("recorre\n");
	visitaNodos(vertices);

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
