#ifndef _GRAFO_H_
	#define _GRAFO_H_

	#include "definitions.h"

	// Representação de grafos utilizando matriz de adjacência
	struct grafo {
		trool matriz_adjacencia[VERTICES][VERTICES];
	};
	typedef struct grafo Grafo;

	// Cria um grafo preenchido com zeros
	void cria_grafo_vazio(Grafo *grafo);

	// Apaga o grafo
	void libera_grafo(Grafo *grafo);

	// Imprime a matriz de adjacência
	void imprime_grafo(Grafo *grafo);

	// Insere aresta entre os vértices v1 e v2
	void insere_aresta(int v1, int v2, Grafo *grafo);

	// Insere arco entre os vértices v1 e v2
	void insere_arco(int v1, int v2, Grafo *grafo);

	// Verifica a existência de aresta entre dois vértices
	// ou arcos de v1 para v2 e de v2 para v1
	void existe_aresta(int v1, int v2, Grafo *grafo);

	// Remove aresta entre os vértices v1 e v2
	void retira_aresta(int v1, int v2, Grafo *grafo);

	// Remove arco entre os vértices v1 e v2
	void retira_arco(int v1, int v2, Grafo *grafo);

	// Imprime todos os nós que tem laços
	void lacos(Grafo *grafo);

	// Verifica se o grafo é direcionado ou não direcionado
	void direcionado(Grafo *grafo);

	// Imprime a vizinhança do vértice v1, ou seja, o vértices adjacentes a v1
	void vizinhaca_aberta(int v1, Grafo *grafo);

	// Imprime a vizinhança do vértice v1 e o pŕoprio v1
	void vizinhaca_fechada(int v1, Grafo *grafo);

	// Verifica se os vértives v1 e v2 são adjacentes, seja a adjacência múltua ou não
	void vertices_adjacentes(int v1, int v2, Grafo *grafo);

	// Calcula o grau do vértice v1. Em caso de problemas retorna -1
	int grau_vertice(int v1, Grafo *grafo);

	// Imprime o grau de todos os vértices
	void lista_vertices(Grafo *grafo);

	// Imprime o valor da soma do grau de todos os vértices
	void somatorio_grau(Grafo *grafo);

	// Preenche o grafo_t com a transposição do grafo
	void grafo_transposto(Grafo *grafo, Grafo *grafo_t);

	// Retorna true se for completo, caso contrário retorna false
	trool grafo_completo(Grafo *grafo);

	// Retorna o grau caso seja k-regular, caso contrário retorna -2. Em caso de problema retorna -1
	int grafo_k_regular(Grafo *grafo);

#endif
