#include <stdio.h>
#include <stdbool.h>

#include "produto.h"
#include "utilidades.h"

void tela_edicao(produto *prod) {
	char entrada;
	int opcao;
	bool sair = false;

	do {
		limpa_tela();
		printf("================================\n");
		printf("Código: %d\n", prod->codigo);
		printf("1: Nome: %s\n", prod->nome);
		printf("2: Fabricante: %s\n", prod->marca);
		printf("3: Categoria: %s\n", prod->categoria);
		printf("4: Custo por pacote: %f\n", prod->custo_pacote);
		printf("5: Quantidade por pacote: %d\n", prod->custo_pacote);
		printf("6: Preço unitário: %f\n", prod->preco_unitario);
		printf("7: Quantidade mínima: %d\n", prod->qnt_minima);
		printf("8: Status: %s\n", prod->status ? "Ativo" : "Intativao");
		printf("================================\n");

		printf("\nSelecione um campo para editá-lo. Pressione Q para sair.\n");
		/* Como a entrada pode ser tanto um número inteiro quanto um caractere,
		 * não podemos utilizar as maravilhosas funções de entrada declaradas
		 * em `produtos.h`.
		 */
		setbuf(stdin, NULL);
		if (scanf("%d", &opcao) == 0) {
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
		
		setbuf(stdin, NULL);
		switch(opcao) {
			case 1:
				printf("Digite o novo nome do produto: ");
				get_str(prod->nome, MAX_TAMANHO_NOME);
				break;
			case 2:
				printf("Digite o novo fabricante do produto: ");
				get_str(prod->marca, MAX_TAMANHO_MARCA);
				break;
			case 3:
				printf("Digite a nova categoria do produto: ");
				get_str(prod->categoria, MAX_TAMANHO_CATEGORIA);
				break;
			case 4:
				prod->custo_pacote = pergunta_float("Digite o novo custo por pacote: ");
				break;
			case 5:
				prod->qnt_por_pacote = pergunta_inteiro("Digite a nova quantidade por pacote: ");
				break;
			case 6:
				prod->preco_unitario = pergunta_float("Digite o novo preço unitário: ");
				break;
			case 7:
				prod->qnt_minima = pergunta_inteiro("Digite a nova quantidade mínima desejada no estoque: ");
				break;
			case 8:
				prod->status = !prod->status;
				break;
			default:
				printf("Opção inválida.\n");
		}
	} while (!sair);
}
