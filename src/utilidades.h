#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <stdbool.h>

/**
 * Remove os espaços inúteis antes e depois do texto.
 * Ex: "   olá, mundo   " -> "olá, mundo"
 * @param string a ser operada.
 */
void trim_str(char str[]);

/**
 * Coleta uma string do stdin até encontrar uma quebra 
 * de linha, EOF, ou chegar em um limite pré-determinado de caracteres.
 * A quebra de linha não é preservada e espaços inúteis antes e depois
 * da string são removidos.
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
void get_str(char *str, int limite);

/**
 * Pergunta ao usuário um número inteiro repetidas vezes
 * até receber um número inteiro.
 * @param pergunta Pergunta que será mostrada ao usuário.
 * @return A resposta do usuário.
 */
int pergunta_inteiro(char *pergunta);

/**
 * Pergunta ao usuário um número real repetidas vezes
 * até receber um número real.
 * @param pergunta Pergunta que será mostrada ao usuário.
 * @return A resposta do usuário.
 */
float pergunta_float(char *pergunta);

/**
 * Faz uma pergunta de sim ou não ao usuário, retorna um valor booleano.
 * A resposta é, por padrão, negativa.
 * @param pergunta string que será apresentada ao usuário.
 * @return resposta booleana do usuário, verdadeiro para sim e falso para não.
 */
bool pergunta_sim_ou_nao(char *pergunta);

/**
 * Limpa a tela do terminal. Sua implementação é diferente para cada
 * plataforma, só é compatível com windows e sistemas unix.
 */
void limpa_tela();

#endif /* UTILIDADES_H */
