#include <stdio.h>
#include <stdbool.h>

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
		prod_temporario.codigo = pergunta_inteiro("Digite o código do produto: ");

		codigo_repetido = produto_existe(prod_temporario.codigo);

		if (codigo_repetido) {
			printf("ERRO: há um produto com este mesmo código cadastrado no sistema.\n");
		}
	} while (codigo_repetido);

	setbuf(stdin, NULL);

	printf("Digite o nome do produto: ");
	get_str(prod_temporario.nome, MAX_TAMANHO_NOME);
	printf("Digite o fabricante do produto: ");
	get_str(prod_temporario.marca, MAX_TAMANHO_MARCA);
	printf("Digite a categoria do produto: ");
	get_str(prod_temporario.categoria, MAX_TAMANHO_CATEGORIA);
	prod_temporario.custo_pacote = pergunta_float("Digite o custo por pacote: ");
	prod_temporario.qnt_por_pacote = pergunta_inteiro("Digite a quantidade por pacote: ");
	prod_temporario.preco_unitario = pergunta_float("Digite o preço unitário: ");
	prod_temporario.qnt_minima = pergunta_inteiro("Digite a quantidade mínima desejada no estoque: ");
	putchar('\n');

	adicionar_produto(prod_temporario);

	printf("Produto cadastrado no sistema.\n\n");
}
