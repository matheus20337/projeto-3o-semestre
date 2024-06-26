#include <stdio.h>
#include <stdbool.h>

#include "produto.h"
#include "utilidades.h"
#include "tela_cadastro.h"
#include "manipulacao_csv.h"
#include "tela_edicao_lista.h"
#include "tela_remocao.h"

/**
 * Mostra todos os produtos, com todos os seus campos, na tela.
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
		printf("4: Remover cadastro.\n");
		printf("5: Salvar em arquivo CSV.\n");
		printf("6: Sair.\n");
		putchar('\n');

		opcao = pergunta_inteiro("Escolha uma opção: ");

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
				tela_edicao_lista();
				break;
			case 4:
				limpa_tela();
				tela_remocao();
				break;
			case 5:
				limpa_tela();
				salvar_produtos_csv("produtos.csv");
				break;
			case 6:
				if (base_alterada) {
					if (pergunta_sim_ou_nao("Deseja sair sem salvar?")) {
						sair = true;
					}
				} else {
					sair = true;
				}
				break;
			default:
				limpa_tela();
				printf("Opção Inválida.\n");
				setbuf(stdin, NULL);

		}
	} while (!sair);
}
