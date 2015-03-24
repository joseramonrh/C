#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


typedef struct vertice vertice;
typedef struct arista arista;

struct vertice
{
	int value;
	vertice *vertice;
	vertice *arista;
	bool visitado;
}
struct arista
{
	arista *arista;
	arista *vertice;
}
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

void agregaVertice(vertice ** vertices, int valor){
	vertice * v = (vertice *)calloc(1, sizeof(vertice));
	v->value = valor;
	v->vertice;
	v->artista;



	if (*vertices == NULL)
	{
		*vertices = v;
	}
	else{
		vertice *current = *vertices;
		while(*current->vertice != NULL){
			current = current->vertice;
		}
		current->vertice = v;
	}
}

void conectaNodos(vertice * vertices, vertice * verticeConectado){
	artista * aristas = (artista *)calloc(1, sizeof(artista));
	aristas->arista;
	aristas->vertice;
	if (!vertices->arista)
	{
		vertices->arista = aristas;
	}
	else
	{
		arista * artistasDos = vertices->arista;
		while(artistasDos->arista){
			artistasDos = artistasDos->arista;
		}
		artistasDos->artista = artistas;
	}
}

vertice * creaVertices(int grado){
	int i = 0;
	vertice * vertices = NULL;
	for (i = 0; i < grado; ++i)
	{
		agregaVertice(&vertice, i);
	}
}

void visitaNodos(vertice * vertices){
	arista * aristaVisitar = vertices->arista;
	vertices->visitado = true;
	printf("%d ", vertices->valor);
	while(aristaVisitar){
		if (!aristaVisitar->vertice->visitado)
		{
			visitaNodos(aristaVisitar->vertice);
		}
		aristaVisitar = aristaVisitar->arista:
	}
}

void imprimete(vertice * vertices){
	while(vertices){
		printf("%d ->", vertices->valor);
		arista * aristas = vertices->arista;
		while(aristas){
			printf("%d", aristas->vertice->valor);
			aristas = aristas->arista;
		}
		printf("|l-\n");
		vertices = vertices->vertice;
	}
}


int main()
{
	srand((int)time(NULL));
	int grado = 10;
	int probabilidad = 20;

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


	




}