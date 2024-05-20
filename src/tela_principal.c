#include <stdio.h>
#include <stdbool.h>

#include "produto.h"
#include "utilidades.h"
#include "tela_cadastro.h"
/**
 * Mostra todos os produtos na tela.
 */
void listar_produtos() {
	if (n_produtos_cadastrados >= 1) {
		for (int i = 0; i < n_produtos_cadastrados; i++) {
			printf("------------\n");
			printf("Nome: %s\n", lista_produtos[i].nome);
			printf("Código: %d\n", lista_produtos[i].codigo);
			printf("Fabricante: %s\n", lista_produtos[i].marca);
			printf("Categoria: %s\n", lista_produtos[i].categoria);
			printf("Custo por pacote: R$%.2f\n", lista_produtos[i].custo_pacote);
			printf("Quantidade por pacote: %d\n", lista_produtos[i].qnt_por_pacote);
			printf("Preço unitário: R$%.2f\n", lista_produtos[i].preco_unitario);
			printf("Quantidade mínima no estoque: %d\n", lista_produtos[i].qnt_minima);
			if (lista_produtos[i].status) {
				printf("Status: Ativo no sistema.\n");
			} else {
				printf("Status: Produto desativado.\n");
			}
			printf("------------\n");
		}
	} else {
		printf("Não há produto algum cadastrado no sistema.\n");
	}
}

void tela_principal() {
	int opcao;
	bool sair = false;

	do {
		printf("Números de produtos cadastrados %d/%d\n", n_produtos_cadastrados, MAX_PRODUTOS);
		putchar('\n');
		printf("1: Cadastrar produto.\n");
		printf("2: Listar todos os produtos.\n");
		printf("3: Editar cadastro.\n");
		printf("4: Salvar em arquivo CSV.\n");
		printf("5: Sair.\n");
		putchar('\n');

		opcao = pergunta_opcoes("Escolha uma opção: ");

		switch (opcao) {
			case 1:
				limpa_tela();
				tela_cadastro();
				limpa_tela();
				break;
			case 2:
				limpa_tela();
				listar_produtos();
				break;
			case 3:
				limpa_tela();
				printf("Não Implementado.\n");
				break;
			case 4:
				limpa_tela();
				printf("Não Implementado.\n");
				break;
			case 5:
				sair = true;
				break;
			default:
				limpa_tela();
				printf("Opção Inválida.\n");
				setbuf(stdin, NULL);

		}
	} while (!sair);
}
