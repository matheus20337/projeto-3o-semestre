#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "produto.h"
#include "utilidades.h"
#include "tela_inicial.h"

/* Como a lista de produtos deverá ser acessível
 * por todo o programa, faz sentido fazê-la uma
 * variável global.
 */
produto *lista_produtos;
int n_produtos_cadastrados;

int main() {
	n_produtos_cadastrados = 0;
	lista_produtos = (produto*) calloc(MAX_PRODUTOS, sizeof(produto));

	if (lista_produtos == NULL) {
		fprintf(stderr, "Erro de alocação.\n");
		return -1;
	}

	tela_inicial();

	free(lista_produtos);
	return 0;
}
