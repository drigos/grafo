#include "grafo.h"

#include <stdlib.h>

int main(int argc, char *argv[])
{
   Grafo *a = (Grafo *) malloc (sizeof(Grafo));
   if (a == NULL)
		return 1;

   cria_grafo_vazio(a);
   imprime_grafo(a);
   
   return 0;
}
