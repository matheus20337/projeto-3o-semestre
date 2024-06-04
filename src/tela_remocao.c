#include <stdio.h>
#include <stdbool.h>

#include "produto.h"
#include "utilidades.h"

bool remover_produto(int index) {
	if (index < 0 || index >= n_produtos_cadastrados) {
		fprintf(stderr, "Erro: Index fora dos limites.\n");
		return false;
	}
	/* Se o produto for o último da lista, basta decrementar
	 * n_produtos_cadastrados.
	 */
	if (index == (n_produtos_cadastrados-1)) {
		n_produtos_cadastrados--;
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
	return true;
}

void tela_remocao() {
	bool sair = false;
	int codigo;
	char entrada;
	do {

		if (n_produtos_cadastrados > 0) {
			for (int i = 0; i < n_produtos_cadastrados; i++) {
				printf("=========================\n");
				printf("COD: %d|NOME:%s\n", lista_produtos[i].codigo, lista_produtos[i].nome);
				printf("=========================\n");
			}
		} else {
			printf("Não há produtos para remover.\n");
			return;
		}

		printf("Digite o código do produto a ser removido. Pressione Q para sair. ");
		/* Como a entrada pode ser tanto um número inteiro quanto um caractere,
		 * não podemos utilizar as maravilhosas funções de entrada declaradas
		 * em `produtos.h`.
		 */
		setbuf(stdin, NULL);
		if (scanf("%d", &codigo) == 0) {
			/* Se scanf encontrar zero resultados válidos, ele ajusta o
			 * stdin para o ponto de onde ele começou sua busca. Por isso é possível
			 * perguntar por um número e um caractere qualquer ao mesmo tempo.
			 */
			scanf("%c", &entrada);
			/* De que adianta declarar uma variável `sair` se
			 * ela nunca é verificada? Boa pergunta! Eu não gosto
			 * de loops infinitos.
			 */
			if (entrada == 'q' || entrada == 'Q') {
				sair = true;
				break;
			} else {
				printf("Entrada inválida.\n");
				continue;
			}
		}
		for (int i = 0; i < n_produtos_cadastrados; i++) {
			if (codigo == lista_produtos[i].codigo) {
				remover_produto(i);
				break;
			}
		}
		limpa_tela();
	} while (!sair);
}
