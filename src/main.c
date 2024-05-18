#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "produto.h"
#include "utilidades.h"

/* Como a lista de produtos deverá ser acessível
 * por todo o programa, faz sentido fazê-la uma
 * variável global.
 */
produto *lista_produtos;
int n_produtos_cadastrados;

/**
 * Pergunta ao usuário um número inteiro repetidas vezes
 * até receber um número inteiro.
 */
int pergunta_opcoes(char *pergunta) {
	int resposta, status;

	do {
		puts(pergunta);
		status = scanf("%d", &resposta);

		/* scanf retorna o número de valores encontrados e
		 * atribuídos. Se este valor for zero, o usuário não 
		 * digitou um número.
		 *
		 * É importante verificar se o valor é zero para evitar
		 * loops infinitos.
		 */
		if (status == 0) {
			printf("Opção Inválida.\n");
			setbuf(stdin, NULL);
		}
	} while (status == 0);

	return resposta;
}

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

void tela_cadastro() {
	bool codigo_repetido;
	produto prod_temporario;

	printf("==========================\n");
	printf("| CADASTRAR NOVO PRODUTO |\n");
	printf("==========================\n");
	putchar('\n');

	if (n_produtos_cadastrados >= MAX_PRODUTOS) {
		printf("ERRO: O sistema atingiu o número máximo de registros.\n");
		return;
	}

	do {
		printf("Digite o código do produto: \n");
		scanf("%d", &prod_temporario.codigo);

		codigo_repetido = false;
		for (int i = 0; i < n_produtos_cadastrados; i++) {
			if (prod_temporario.codigo == lista_produtos[i].codigo) {
				printf("ERRO: há um produto com este mesmo código cadastrado no sistema.\n");
				codigo_repetido = true;
			}
		}
	} while (codigo_repetido);

	setbuf(stdin, NULL);

	printf("Digite o nome do produto: ");
	get_str(prod_temporario.nome, MAX_TAMANHO_NOME);
	printf("Digite o fabricante do produto: ");
	get_str(prod_temporario.marca, MAX_TAMANHO_MARCA);
	printf("Digite a categoria do produto: ");
	get_str(prod_temporario.categoria, MAX_TAMANHO_CATEGORIA);
	printf("Digite o custo por pacote: ");
	scanf("%f", &prod_temporario.custo_pacote);
	printf("Digite a quantidade por pacote: ");
	scanf("%d", &prod_temporario.qnt_por_pacote);
	printf("Digite o preço unitário: ");
	scanf("%f", &prod_temporario.preco_unitario);
	printf("Digite a quantidade mínima desejada no estoque: ");
	scanf("%d", &prod_temporario.qnt_minima);
	putchar('\n');
	lista_produtos[n_produtos_cadastrados] = prod_temporario;
	n_produtos_cadastrados++;

	printf("Produto cadastrado no sistema.\n");
}

void tela_principal() {
	int opcao;
	bool sair = false;

	do {
		printf("Números de produtos cadastrados %d/%d", n_produtos_cadastrados, MAX_PRODUTOS);
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
				tela_cadastro();
				break;
			case 2:
				listar_produtos();
				break;
			case 3:
				printf("Não Implementado.\n");
				break;
			case 4:
				printf("Não Implementado.\n");
				break;
			case 5:
				sair = true;
				break;
			default:
				printf("Opção Inválida.\n");
				setbuf(stdin, NULL);

		}
	} while (!sair);
}

void tela_inicial() {
	int opcao;
	bool sair = false;

	do {
		printf("========================\n");
		printf("| CADASTRO DE PRODUTOS |\n");
		printf("========================\n");

		putchar('\n');
		printf("1: Carregar de um arquivo CSV.\n");
		printf("2: Iniciar uma nova base de produtos.\n");
		printf("3: Créditos.\n");
		printf("4: Sair.\n");
		putchar('\n');
		opcao = pergunta_opcoes("Escolha uma opção: ");
		
		switch(opcao) {
			case 1:
				printf("\nHAHAHA! Esta opção ainda não foi implementada >:3\n\n");
				break;
			case 2:
				n_produtos_cadastrados = 0;
				tela_principal();
				break;
			case 3:
				printf("\nSoftware desenvolvido pelos alunos:\nMatheus Ferreira Guedes\nGustavo Eklund França (programador mestre)\nPedro Juliani Gonçalves\n\n");
				break;
			case 4:
				sair = true;
				break;
			default:
				printf("Opção Inválida.\n");
				setbuf(stdin, NULL);
		}
	} while (!sair);

}

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
