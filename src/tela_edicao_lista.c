#include <stdio.h>
#include <stdbool.h>

#include "produto.h"
#include "tela_edicao.h"

void tela_edicao_lista() {
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
		}

		printf("Digite o código do produto a ser modificado. Pressione Q para sair. ");
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
				tela_edicao(&lista_produtos[i]);
			} else {
				printf("Produto não encontrado.\n");
			}
		}
	} while (!sair);
}
