#include <stdio.h>

/**
 * Coleta uma string do stdin até encontrar uma quebra 
 * de linha, EOF, ou chegar em um limite pré-determinado de caracteres.
 * A quebra de linha não é preservada.
 *
 * Abaixo está o motivo desta função existir:
 * 1. scanf() e gets() não respeitam um limite de
 * caracteres, logo não são seguras.
 * 2. fgets preserva a quebra de linha na string coletada,
 * algo que não é desejado para nossa aplicação.
 *
 * Embora seja possível simplesmente remover a quebra de linha,
 * acredito ser mais claro e eficiente simplesmente ignorá-la por
 * completo.
 *
 * @param str variável para onde será armazenada a string.
 * @param limite tamanho máximo da string.
 */
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
}
