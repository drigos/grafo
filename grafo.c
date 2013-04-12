#include <stdio.h>
#include <stdlib.h>

#define VERTICES 10

/* Tipo booleano */
enum ternario {
   false,
   true,
   error
};
typedef enum ternario trool;

/* Representação de grafos utilizando matriz de adjacência */
struct grafo {
   trool matriz_adjacencia[VERTICES][VERTICES];
};
typedef struct grafo Grafo;

/* O(n^2) */
/* Cria um grafo preenchido com zeros */
void cria_grafo_vazio(Grafo *grafo) {
   if(grafo == NULL)
      return; /* Erro: Grafo é null */

   int i, j;
   for (i = 0; i < VERTICES; i++)
      for (j = 0; j < VERTICES; j++)
         grafo->matriz_adjacencia[i][j] = 0;
}

/* O(1) */
/* Insere aresta entre os vértices v1 e v2 */
void insere_aresta(int v1, int v2, Grafo *grafo) {
   if(v1 <= 0 && v1 > VERTICES)
      return; /* Erro: Vértice está fora dos limites*/
   if(v2 <= 0 && v2 > VERTICES)
      return; /* Erro: Vértice está fora dos limites*/
   if(grafo == NULL)
      return; /* Erro: Grafo é null */

   grafo->matriz_adjacencia[v1][v2] = 1;
   grafo->matriz_adjacencia[v2][v1] = 1;
}

/* O(1) */
/* Verifica a existência de aresta entre dois vértices */
trool existe_aresta(int v1, int v2, Grafo *grafo) {
   if(v1 <= 0 && v1 > VERTICES)
      return error; /* Erro: Vértice está fora dos limites*/
   if(v2 <= 0 && v2 > VERTICES)
      return error; /* Erro: Vértice está fora dos limites*/
   if(grafo == NULL)
      return error; /* Erro: Grafo é null */
      
   return (grafo->matriz_adjacencia[v2][v1] != 0);
}

/* O(1) */
/* Remove aresta entre os vértices v1 e v2 */
void retira_aresta(int v1, int v2, Grafo *grafo) {
   if(v1 <= 0 && v1 > VERTICES)
      return; /* Erro: Vértice está fora dos limites*/
   if(v2 <= 0 && v2 > VERTICES)
      return; /* Erro: Vértice está fora dos limites*/
   if(grafo == NULL)
      return; /* Erro: Grafo é null */
      
   grafo->matriz_adjacencia[v1][v2] = 0;
   grafo->matriz_adjacencia[v2][v1] = 0;
}

/* Provavelmente O(n^2) */
/* Apaga o grafo */
void libera_grafo(Grafo *grafo) {
   if(grafo == NULL)
      return; /* Erro: Grafo é null */

   free(grafo);
   grafo = NULL;
}

/* O(n^2) */
/* Imprime a matriz de adjacência */
void imprime_grafo(Grafo *grafo) {
   if(grafo == NULL)
      return; /* Erro: Grafo é null */
      
   int i, j;
   for (i = 0; i < VERTICES; i++) {
      for (j = 0; j < VERTICES; j++)
         printf ("%3d", grafo->matriz_adjacencia[i][j]);
      puts ("");
   }
}

/* O(n^2) */
/* Preenche o grafo_t com a transposição do grafo*/
void grafo_transposto(Grafo *grafo, Grafo *grafo_t) {
   if(grafo == NULL)
      return; /* Erro: Grafo é null */
   if(grafo_t == NULL)
      return; /* Erro: Grafo é null */

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

/* O(n) */
/* Imprime os vértices adjacêntes ao vértice v1 */
void vertice_adjacente(int v1, Grafo *grafo) {
   if(v1 <= 0 && v1 > VERTICES)
      return; /* Erro: Vértice está fora dos limites*/
   if(grafo == NULL)
      return; /* Erro: Grafo é null */

   int i;
   v1--;
   
   printf("Vertices adjacentes de %d:\n", v1+1);
   for(i = 0; i < VERTICES; i++)
      if(grafo->matriz_adjacencia[i][v1] != 0)
         printf("%d\n", i+1);
}

/* O(n) */
/* Calcula o grau do vértice v1. Em caso de problemas retorna -1 */
int grau_vertice(int v1, Grafo *grafo) {
   if(v1 <= 0 && v1 > VERTICES)
      return -1; /* Erro: Vértice está fora dos limites*/
   if(grafo == NULL)
      return -1; /* Erro: Grafo é null */

   int i, grau = 0;
   v1--;
   
   for(i = 0; i < VERTICES; i++)
      if(grafo->matriz_adjacencia[i][v1] != 0)
         grau++;
         
   return grau;
}

/* O(n^2) */
/* Imprime o grau de todos os vértices */
void lista_vertices(Grafo *grafo) {
   if(grafo == NULL)
      return; /* Erro: Grafo é null */

   int i;
   printf("Lista de vertices e seus respectivos graus:\n");
   for(i = 1; i <= VERTICES; i++)
      printf("%3d - %d\n", i, grau_vertice(i, grafo));
}

/* O(n^2) */
/* Imprime o valor da soma do grau de todos os vértices */
void somatorio_grau(Grafo *grafo) {
   if(grafo == NULL)
      return; /* Erro: Grafo é null */
      
   int i, somatorio = 0;
   for(i = 1; i <= VERTICES; i++)
      somatorio += grau_vertice(i, grafo);
   
   printf("A soma do grau de todos os vertices é igual a %d\n", somatorio);
}

/* O(n^2) */
/* Retorna true se for completo, caso contrário retorna false */
trool grafo_completo(Grafo *grafo) {
   if(grafo == NULL)
      return error; /* Erro: Grafo é null */

   int i, j;
   for(i = 0; i < VERTICES; i++)
      for(j = 0; j < VERTICES; j++)
         if(grafo->matriz_adjacencia[i][j] == 0 && i != j)
            return false;

   return true;
}

/* O(n^2) */
/* Retorna o grau caso seja k-regular, caso contrário retorna -2. Em caso de problema retorna -1 */
int grafo_k_regular(Grafo *grafo) {
   if(grafo == NULL)
      return -1; /* Erro: Grafo é null */

   int i, grau;
   grau = grau_vertice(1, grafo);
   
   for(i = 2; i <= VERTICES; i++)
      if(grau_vertice(i, grafo) != grau)
         return -2;
         
   return grau;
}

int main(int argc, char *argv[])
{
   Grafo *a = (Grafo *) malloc (sizeof(Grafo));
   if (a == NULL)
		return 1;

   cria_grafo_vazio(a);
   imprime_grafo(a);
   
   return 0;
}