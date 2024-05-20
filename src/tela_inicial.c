#include <stdio.h>
#include <stdbool.h>

#include "tela_principal.h"
#include "utilidades.h"
#include "produto.h"

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
				limpa_tela();
				printf("\nHAHAHA! Esta opção ainda não foi implementada >:3\n\n");
				break;
			case 2:
				limpa_tela();
				n_produtos_cadastrados = 0;
				tela_principal();
				limpa_tela();
				break;
			case 3:
				limpa_tela();
				printf("\nSoftware desenvolvido pelos alunos:\nMatheus Ferreira Guedes\nGustavo Eklund França (programador mestre)\nPedro Juliani Gonçalves\n\n");
				break;
			case 4:
				sair = true;
				break;
			default:
				limpa_tela();
				printf("Opção Inválida.\n");
				setbuf(stdin, NULL);
		}
	} while (!sair);

}
