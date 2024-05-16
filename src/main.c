#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void tela_principal() {
	int opcao;
	bool sair = false;

	do {
		/* TODO: substituir o número 12 pela quantidade real
		 * de produtos cadastrados.
		 */
		printf("Números de produtos cadastrados %d", 10);
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
				printf("\n\nNão implementado.\n");
				break;
			case 2:
				printf("\n\nNão implementdado.\n");
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
	tela_inicial();
	return 0;
}
