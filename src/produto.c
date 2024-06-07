#include <stdbool.h>
#include <stdio.h>

#include "produto.h"

bool produto_existe(int codigo) {
	for(int i = 0; i < n_produtos_cadastrados; i++) {
		if (codigo == lista_produtos[i].codigo) {
			return true;
		}
	}
	return false;
}

int obter_index(int codigo) {
	for (int i = 0; i < n_produtos_cadastrados; i++) {
		if (codigo == lista_produtos[i].codigo) {
			return i;
		}
	}
	return -1;
}

bool adicionar_produto(produto prod) {
	if (n_produtos_cadastrados < MAX_PRODUTOS) {
		lista_produtos[n_produtos_cadastrados++] = prod;
		base_alterada = true;
		return true;
	}
	return false;
}

void editar_produto(produto *original, produto editado) {
	*original = editado;
	base_alterada = true;
}

bool remover_produto(int index) {
	printf("Index: %d\n", index);
	if (index < 0 || index >= n_produtos_cadastrados) {
		fprintf(stderr, "Erro: Index fora dos limites.\n");
		return false;
	}
	/* Se o produto for o último da lista, basta decrementar
	 * n_produtos_cadastrados.
	 */
	if (index == (n_produtos_cadastrados-1)) {
		n_produtos_cadastrados--;
		base_alterada = true;
		return true;
	}

	/* Se o produto não for o útlimo da lista, devemos
	 * sobreescrevê-lo com todos os produtos à sua frente
	 * e depois decrementar n_produtos_cadastrados.
	 */
	n_produtos_cadastrados--;
	for (int i = index; i < n_produtos_cadastrados; i++) {
		lista_produtos[i] = lista_produtos[i+1];
	}
	base_alterada = true;
	return true;
}
