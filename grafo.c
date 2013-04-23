#include "grafo.h"
#include "definitions.h"

#include <stdio.h>
#include <stdlib.h>

// O(n^2)
void cria_grafo_vazio(Grafo *grafo) {
   if(grafo == NULL)
      return; // Erro: Grafo é null

   int i, j;
   for (i = 0; i < VERTICES; i++)
      for (j = 0; j < VERTICES; j++)
         grafo->matriz_adjacencia[i][j] = 0;
}

// Provavelmente O(n^2)
void libera_grafo(Grafo *grafo) {
   if(grafo == NULL)
      return; // Erro: Grafo é null

   free(grafo);
   grafo = NULL;
}

// O(n^2)
void imprime_grafo(Grafo *grafo) {
   if(grafo == NULL)
      return; // Erro: Grafo é null
      
   int i, j;
   for (i = 0; i < VERTICES; i++) {
      for (j = 0; j < VERTICES; j++)
         printf ("%3d", grafo->matriz_adjacencia[i][j]);
      puts ("");
   }
}

// O(1)
void insere_aresta(int v1, int v2, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return; // Erro: Vértice está fora dos limites
   if(v2 <= 0 || v2 > VERTICES)
      return; // Erro: Vértice está fora dos limites
   if(grafo == NULL)
      return; // Erro: Grafo é null

   v1--;
   v2--;

   grafo->matriz_adjacencia[v1][v2] = 1;
   grafo->matriz_adjacencia[v2][v1] = 1;
}

// O(1)
void insere_arco(int v1, int v2, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return; // Erro: Vértice está fora dos limites
   if(v2 <= 0 || v2 > VERTICES)
      return; // Erro: Vértice está fora dos limites
   if(grafo == NULL)
      return; // Erro: Grafo é null

   v1--;
   v2--;

   grafo->matriz_adjacencia[v1][v2] = 1;
}

// O(1)
void existe_aresta(int v1, int v2, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return; // Erro: Vértice está fora dos limites
   if(v2 <= 0 || v2 > VERTICES)
      return; // Erro: Vértice está fora dos limites
   if(grafo == NULL)
      return; // Erro: Grafo é null

   v1--;
   v2--;

	if(grafo->matriz_adjacencia[v1][v2] == 1 && grafo->matriz_adjacencia[v2][v1] == 1)
		printf("Existe aresta %d,%d\n", v1+1, v2+1);
	else if(grafo->matriz_adjacencia[v1][v2] == 1)
		printf("Existe arco %d,%d\n", v1+1, v2+1);
	else if(grafo->matriz_adjacencia[v2][v1] == 1)
		printf("Existe arco %d,%d\n", v2+1, v1+1);
}

// O(1)
void retira_aresta(int v1, int v2, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return; // Erro: Vértice está fora dos limites
   if(v2 <= 0 || v2 > VERTICES)
      return; // Erro: Vértice está fora dos limites
   if(grafo == NULL)
      return; // Erro: Grafo é null
      
   v1--;
   v2--;

   grafo->matriz_adjacencia[v1][v2] = 0;
   grafo->matriz_adjacencia[v2][v1] = 0;
}

// O(1)
void retira_arco(int v1, int v2, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return; // Erro: Vértice está fora dos limites
   if(v2 <= 0 || v2 > VERTICES)
      return; // Erro: Vértice está fora dos limites
   if(grafo == NULL)
      return; // Erro: Grafo é null
      
   v1--;
   v2--;

   grafo->matriz_adjacencia[v1][v2] = 0;
}

// O(n)
void lacos(Grafo *grafo) {
   if(grafo == NULL)
      return; // Erro: Grafo é null

	int i;
	for(i = 0; i < VERTICES; i++)
		if(grafo->matriz_adjacencia[i][i] = 1)
			printf("O vertice %d tem um laco\n", i);
}

// O(n^2)
void direcionado(Grafo *grafo) {
   if(grafo == NULL)
      return; // Erro: Grafo é null

	int i, j;
	for(i = 0; i < VERTICES; i++)
		for(j = 0; j < i; j++)
			if(grafo->matriz_adjacencia[i][j] != grafo->matriz_adjacencia[j][i])
				puts("Grafo Não-Direcionado");

	puts("Grafo Direcionado");
}

// O(n)
void vizinhanca_aberta(int v1, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return; // Erro: Vértice está fora dos limites
   if(grafo == NULL)
      return; // Erro: Grafo é null

   int i;
   v1--;
   
   printf("Vizinhanca aberta de %d:\n", v1+1);
   for(i = 0; i < VERTICES; i++)
      if(grafo->matriz_adjacencia[v1][i] != 0)
         printf("%d ", i+1);
}

// O(n)
void vizinhanca_fechada(int v1, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return; // Erro: Vértice está fora dos limites
   if(grafo == NULL)
      return; // Erro: Grafo é null

   int i;
   v1--;
   
   printf("Vizinhança fechada de %d:\n", v1+1);

   for(i = 0; i < v1; i++)
      if(grafo->matriz_adjacencia[v1][i] != 0)
         printf("%d ", i+1);

	printf("%d ", v1+1);
	
   for(i = v1+1; i < VERTICES; i++)
      if(grafo->matriz_adjacencia[v1][i] != 0)
         printf("%d\n", i+1);
}

// O(1)
void vertices_adjacentes(int v1, int v2, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return; // Erro: Vértice está fora dos limites
   if(v2 <= 0 || v2 > VERTICES)
      return; // Erro: Vértice está fora dos limites
   if(grafo == NULL)
      return; // Erro: Grafo é null
      
   v1--;
   v2--;

	if(grafo->matriz_adjacencia[v1][v2] == 1 && grafo->matriz_adjacencia[v2][v1] == 1)
		printf("Existe adjacencia multua entre os vertices %d e %d\n", v1+1, v2+1);
	else if(grafo->matriz_adjacencia[v1][v2] == 1)
		printf("O vertice %d eh adjacente ao %d, mas nao o oposto\n", v2+1, v1+1);
	else if(grafo->matriz_adjacencia[v2][v1] == 1)
		printf("O vertice %d eh adjacente ao %d, mas nao o oposto\n", v1+1, v2+1);
}

// O(n)
int grau_vertice(int v1, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return -1; // Erro: Vértice está fora dos limites
   if(grafo == NULL)
      return -1; // Erro: Grafo é null

   int i, grau = 0;
   v1--;
   
   for(i = 0; i < VERTICES; i++)
      if(grafo->matriz_adjacencia[i][v1] != 0)
         grau++;
         
   return grau;
}

// O(n^2)
void lista_vertices(Grafo *grafo) {
   if(grafo == NULL)
      return; // Erro: Grafo é null

   int i;
   printf("Lista de vertices e seus respectivos graus:\n");
   for(i = 1; i <= VERTICES; i++)
      printf("%3d - %d\n", i, grau_vertice(i, grafo));
}

// O(n^2)
void somatorio_grau(Grafo *grafo) {
   if(grafo == NULL)
      return; // Erro: Grafo é null
      
   int i, somatorio = 0;
   for(i = 1; i <= VERTICES; i++)
      somatorio += grau_vertice(i, grafo);
   
   printf("A soma do grau de todos os vertices é igual a %d\n", somatorio);
}

// O(n^2)
void grafo_transposto(Grafo *grafo, Grafo *grafo_t) {
   if(grafo == NULL)
      return; // Erro: Grafo é null
   if(grafo_t == NULL)
      return; // Erro: Grafo é null

   int i, j;
   for (i = 0; i < VERTICES; i++)
      for (j = 0; j < VERTICES; j++)
         if(i != j) {
            if(grafo->matriz_adjacencia[i][j] == 0)
               grafo_t->matriz_adjacencia[i][j] = 1;
            else
               grafo_t->matriz_adjacencia[i][j] = 0;
         }
}

// O(n^2)
trool grafo_completo(Grafo *grafo) {
   if(grafo == NULL)
      return error; // Erro: Grafo é null

   int i, j;
   for(i = 0; i < VERTICES; i++)
      for(j = 0; j < VERTICES; j++)
         if(grafo->matriz_adjacencia[i][j] == 0 && i != j)
            return false;

   return true;
}

// O(n^2)
int grafo_k_regular(Grafo *grafo) {
   if(grafo == NULL)
      return -1; // Erro: Grafo é null

   int i, grau;
   grau = grau_vertice(1, grafo);
   
   for(i = 2; i <= VERTICES; i++)
      if(grau_vertice(i, grafo) != grau)
         return -2;
         
   return grau;
}
