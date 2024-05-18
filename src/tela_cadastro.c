#include <stdio.h>

#include "produto.h"
#include "utilidades.h"

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

	printf("Produto cadastrado no sistema.\n\n");
}
