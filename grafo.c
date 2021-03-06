#include "grafo.h"
#include "definitions.h"

#include <stdio.h>
#include <stdlib.h>

// O(n^2)
void cria_grafo_vazio(Grafo *grafo) {
   if(grafo == NULL)
      return; // Erro: Grafo � null

   int i, j;
   for (i = 0; i < VERTICES; i++)
      for (j = 0; j < VERTICES; j++)
         grafo->matriz_adjacencia[i][j] = 0;
}

// Provavelmente O(n^2)
void libera_grafo(Grafo *grafo) {
   if(grafo == NULL)
      return; // Erro: Grafo � null

   free(grafo);
   grafo = NULL;
}

// O(n^2)
void imprime_grafo(Grafo *grafo) {
   if(grafo == NULL)
      return; // Erro: Grafo � null
      
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
      return; // Erro: V�rtice est� fora dos limites
   if(v2 <= 0 || v2 > VERTICES)
      return; // Erro: V�rtice est� fora dos limites
   if(grafo == NULL)
      return; // Erro: Grafo � null

   v1--;
   v2--;

   grafo->matriz_adjacencia[v1][v2] = 1;
   grafo->matriz_adjacencia[v2][v1] = 1;
}

// O(1)
void insere_arco(int v1, int v2, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return; // Erro: V�rtice est� fora dos limites
   if(v2 <= 0 || v2 > VERTICES)
      return; // Erro: V�rtice est� fora dos limites
   if(grafo == NULL)
      return; // Erro: Grafo � null

   v1--;
   v2--;

   grafo->matriz_adjacencia[v1][v2] = 1;
}

// O(1)
int existe_aresta(int v1, int v2, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return -1; // Erro: V�rtice est� fora dos limites
   if(v2 <= 0 || v2 > VERTICES)
      return -1; // Erro: V�rtice est� fora dos limites
   if(grafo == NULL)
      return -1; // Erro: Grafo � null

   v1--;
   v2--;

	if(grafo->matriz_adjacencia[v1][v2] == 1 && grafo->matriz_adjacencia[v2][v1] == 1) {
		printf("Existe aresta %d,%d\n", v1+1, v2+1);
		return 0;
	}
	else if(grafo->matriz_adjacencia[v1][v2] == 1) {
		printf("Existe arco %d,%d\n", v1+1, v2+1);
		return 1;
	}
	else if(grafo->matriz_adjacencia[v2][v1] == 1) {
		printf("Existe arco %d,%d\n", v2+1, v1+1);
		return 2;
	}

	return -1; // Erro: Desconhecido
}

// O(1)
void retira_aresta(int v1, int v2, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return; // Erro: V�rtice est� fora dos limites
   if(v2 <= 0 || v2 > VERTICES)
      return; // Erro: V�rtice est� fora dos limites
   if(grafo == NULL)
      return; // Erro: Grafo � null
      
   v1--;
   v2--;

   grafo->matriz_adjacencia[v1][v2] = 0;
   grafo->matriz_adjacencia[v2][v1] = 0;
}

// O(1)
void retira_arco(int v1, int v2, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return; // Erro: V�rtice est� fora dos limites
   if(v2 <= 0 || v2 > VERTICES)
      return; // Erro: V�rtice est� fora dos limites
   if(grafo == NULL)
      return; // Erro: Grafo � null
      
   v1--;
   v2--;

   grafo->matriz_adjacencia[v1][v2] = 0;
}

// O(n)
void lacos(Grafo *grafo) {
   if(grafo == NULL)
      return; // Erro: Grafo � null

	int i;
	for(i = 0; i < VERTICES; i++)
		if(grafo->matriz_adjacencia[i][i] == 1)
			printf("O vertice %d tem um laco\n", i);
}

// O(n^2)
int direcionado(Grafo *grafo) {
   if(grafo == NULL)
      return -1; // Erro: Grafo � null

	int i, j;
	for(i = 0; i < VERTICES; i++)
		for(j = 0; j < i; j++)
			if(grafo->matriz_adjacencia[i][j] != grafo->matriz_adjacencia[j][i]) {
				puts("Grafo N�o-Direcionado");
				return 0;
			}

	puts("Grafo Direcionado");
	return 1;
}

// O(n)
void vizinhanca_aberta(int v1, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return; // Erro: V�rtice est� fora dos limites
   if(grafo == NULL)
      return; // Erro: Grafo � null

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
      return; // Erro: V�rtice est� fora dos limites
   if(grafo == NULL)
      return; // Erro: Grafo � null

   int i;
   v1--;
   
   printf("Vizinhan�a fechada de %d:\n", v1+1);

   for(i = 0; i < v1; i++)
      if(grafo->matriz_adjacencia[v1][i] != 0)
         printf("%d ", i+1);

	printf("%d ", v1+1);
	
   for(i = v1+1; i < VERTICES; i++)
      if(grafo->matriz_adjacencia[v1][i] != 0)
         printf("%d\n", i+1);
}

// O(1)
int vertices_adjacentes(int v1, int v2, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return -1; // Erro: V�rtice est� fora dos limites
   if(v2 <= 0 || v2 > VERTICES)
      return -1; // Erro: V�rtice est� fora dos limites
   if(grafo == NULL)
      return -1; // Erro: Grafo � null
      
   v1--;
   v2--;

	if(grafo->matriz_adjacencia[v1][v2] == 1 && grafo->matriz_adjacencia[v2][v1] == 1) {
		printf("Existe adjacencia multua entre os vertices %d e %d\n", v1+1, v2+1);
		return 0;
	}
	else if(grafo->matriz_adjacencia[v1][v2] == 1) {
		printf("O vertice %d eh adjacente ao %d, mas nao o oposto\n", v2+1, v1+1);
		return 1;
	}
	else if(grafo->matriz_adjacencia[v2][v1] == 1) {
		printf("O vertice %d eh adjacente ao %d, mas nao o oposto\n", v1+1, v2+1);
		return 2;
	}

	return -1; // Erro: Desconhecido
}

// O(n)
int grau_positivo(int v1, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return -1; // Erro: V�rtice est� fora dos limites
   if(grafo == NULL)
      return -1; // Erro: Grafo � null

	int i, grau_positivo = 0;
	v1--;

	for(i = 0; i < VERTICES; i++)
		if(grafo->matriz_adjacencia[v1][i] != 0)
			grau_positivo++;

	return grau_positivo;
}

// O(n)
int grau_negativo(int v1, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return -1; // Erro: V�rtice est� fora dos limites
   if(grafo == NULL)
      return -1; // Erro: Grafo � null

	int i, grau_negativo = 0;
	v1--;

	for(i = 0; i < VERTICES; i++)
		if(grafo->matriz_adjacencia[i][v1] != 0)
			grau_negativo++;

	return grau_negativo;
}

// O(n)
int grau_vertice(int v1, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return -1; // Erro: V�rtice est� fora dos limites
   if(grafo == NULL)
      return -1; // Erro: Grafo � null

	int direc = direcionado(grafo);

   int i, grau = 0;
   
	if(direc)
		grau = grau_positivo(v1, grafo) + grau_negativo(v1, grafo);
	else {
		v1--;
		for(i = 0; i < VERTICES; i++)
			if(grafo->matriz_adjacencia[v1][i] != 0)
				grau++;
	}
         
   return grau;
}

// O(n)
int vertice_isolado(int v1, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return -1; // Erro: V�rtice est� fora dos limites
   if(grafo == NULL)
      return -1; // Erro: Grafo � null

	return grau_vertice(v1, grafo) ? 0 : 1 ;
}

// O(n)
int vertice_pendente(int v1, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return -1; // Erro: V�rtice est� fora dos limites
   if(grafo == NULL)
      return -1; // Erro: Grafo � null

	return grau_vertice(v1, grafo)==1 ? 1 : 0 ;
}

// O(n^2)
void lista_vertices(Grafo *grafo) {
   if(grafo == NULL)
      return; // Erro: Grafo � null

   int i;
   printf("Lista de vertices e seus respectivos graus:\n");
   for(i = 1; i <= VERTICES; i++)
      printf("%3d - %d\n", i, grau_vertice(i, grafo));
}

// O(n^2)
void somatorio_grau(Grafo *grafo) {
   if(grafo == NULL)
      return; // Erro: Grafo � null
      
   int i, somatorio = 0;
   for(i = 1; i <= VERTICES; i++)
      somatorio += grau_vertice(i, grafo);
   
   printf("A soma do grau de todos os vertices � igual a %d\n", somatorio);
}

// O(n^2)
void grafo_transposto(Grafo *grafo, Grafo *grafo_t) {
   if(grafo == NULL)
      return; // Erro: Grafo � null
   if(grafo_t == NULL)
      return; // Erro: Grafo � null

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
      return error; // Erro: Grafo � null

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
      return -1; // Erro: Grafo � null

   int i, grau;
   grau = grau_vertice(1, grafo);
   
   for(i = 2; i <= VERTICES; i++)
      if(grau_vertice(i, grafo) != grau)
         return -2;
         
   return grau;
}

// Provavelmente O(n^2) 
void conexo_recursivo(int v1, int num_componente, int *componente, Grafo *grafo) {
	componente[v1] = num_componente;

	int vertice;
	for(vertice = 0; vertice < VERTICES; vertice++)
		if(grafo->matriz_adjacencia[vertice][v1] == 1 && componente[vertice] == 0)
			conexo_recursivo(vertice, num_componente, componente, grafo);

	return;
}

// Provavelmente O(n^2)
int componente_conexa(int *componente, Grafo *grafo) {
   if(grafo == NULL)
      return -1; // Erro: Grafo � null

	if(componente == NULL) {
		componente = (int*) calloc(VERTICES, sizeof(int));

		if(componente == NULL)
			return -1; // Erro: Array n�o alocada
	}

	int num_componente = 0;

	int vertice;
	for(vertice = 0; vertice < VERTICES; vertice++)
		if(componente[vertice] == 0) {
			num_componente++;
			conexo_recursivo(vertice, num_componente, componente, grafo);
		}

	return num_componente;
}

// Provavelmente O(n^2)
int vertice_conectado(int v1, int v2, Grafo *grafo) {
   if(v1 <= 0 || v1 > VERTICES)
      return -1; // Erro: V�rtice est� fora dos limites
   if(v2 <= 0 || v2 > VERTICES)
      return -1; // Erro: V�rtice est� fora dos limites
   if(grafo == NULL)
      return -1; // Erro: Grafo � null

	int *componente = (int*) calloc(VERTICES, sizeof(int));
	if(componente == NULL)
		return -1; // Erro: Array n�o alocada

	v1--;
	v2--;

	conexo_recursivo(v1, 1, componente, grafo);

	return componente[v1] == componente[v2] ? 1 : 0;
}

// Provavelmente O(n^2)
int grafo_conexo(Grafo *grafo) {
   if(grafo == NULL)
      return -1; // Erro: Grafo � null

	int *componente = (int*) calloc(VERTICES, sizeof(int));
	if(componente == NULL)
		return -1; // Erro: Array n�o alocada

	conexo_recursivo(0, 1, componente, grafo);

	int i;
	for(i = 0; i < VERTICES; i++)
		if(componente[i] != 1)
			return 0;

	return 1;
}
/*
// 
void imprime_componente_conexa(Grafo *grafo) {
   if(grafo == NULL)
      return -1; // Erro: Grafo � null

	int *componente = (int*) calloc(VERTICES, sizeof(int));
	if(componente == NULL)
		return NULL; // Erro: Array n�o alocada

	int num_componente = componente_conexa(componente, grafo);

	int *placeholder[num_componente];

	int i;
	for(i = 0; i < VERTICES; i++) {
		
	}
}*/
