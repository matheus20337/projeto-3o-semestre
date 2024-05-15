#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

		printf("Escolha uma opção: ");
		int status_entrada = scanf("%d", &opcao);

		/* scanf retorna o número de valores encontrados e
		 * atribuídos. Se este valor for zero, o usuário não 
		 * digitou um número.
		 *
		 * É importante verificar se o valor é zero para evitar
		 * loops infinitos.
		 */
		if (status_entrada == 0) {
			printf("Opção Inválida.\n");
			setbuf(stdin, NULL);
			continue;
		}

		switch(opcao) {
			case 1:
				printf("\nHAHAHA! Esta opção ainda não foi implementada >:3\n\n");
				break;
			case 2:
				printf("\nNão implementado.\n\n");
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
	} while(!sair);

}

int main() {
	tela_inicial();
		return 0;
}
