#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void trim_str(char str[]) {
	int i = 0;

	/* Index do primeiro caractere não em branco da string. */
	int primeiro_char = 0;
	/* Index do último caractere não em branco da string. */
	int ultimo_char = 0;

	/* Houve algum caractere em branco inútil?
	 * (' ', '\t' ou '\n' no final ou começo da string) */
	bool final_houve_nao_branco = false;
	bool comeco_houve_nao_branco = false;

	/* Primeiro, verificamos onde fica o primeiro e o último caractere útil da string. */
	while (str[i] != '\0') {
		if (!isspace(str[i])) {
			final_houve_nao_branco = true;
			ultimo_char = i;

			if (!comeco_houve_nao_branco) {
				comeco_houve_nao_branco = true;
				primeiro_char = i;
			}
		}

		i++;
	}
	int tamanho_da_string_util = (ultimo_char - primeiro_char) + 1;

	/* Depois, devemos mover todos os caracteres últeis para o começo da string */
	if (primeiro_char > 0) {
		/* Partindo do primeiro caractere útil, mostra onde estamos na string útil */
		int char_atual = primeiro_char;

		for (i = 0; i < tamanho_da_string_util; i++) {
			str[i] = str[char_atual];
			char_atual++;
		}
	}

	/* Por fim, terminamos a string com o caractere nulo */
	str[tamanho_da_string_util] = '\0';
}

void get_str(char *str, int limite) {
	char c;
	int i = 0;
	c = getchar();

	while ((c != EOF && c != '\n') && i < (limite - 1)) {
		str[i] = c;
		i++;
		c = getchar();
	}
	str[i] = '\0';
	trim_str(str);
}

int pergunta_inteiro(char *pergunta) {
	int resposta, status;

	do {
		printf("%s", pergunta);
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

float pergunta_float(char *pergunta) {
	int status;
	float resposta;

	do {
		printf("%s", pergunta);
		status = scanf("%f", &resposta);

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

bool pergunta_sim_ou_nao(char *pergunta) {
	char c;

	setbuf(stdin, NULL);

	printf("%s [s/N] ", pergunta);
	scanf("%c", &c);

	if (c == 's' || c == 'S') return true;

	return false;
}

void limpa_tela() {
	#ifdef _WIN32
	system("cls");
	#elif __unix /* _WIN32 */
	system("clear");
	#endif /* __unix */
}
