#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <stdbool.h>

void trim_str(char str[]);
void get_str(char *str, int limite);

int pergunta_inteiro(char *pergunta);
float pergunta_float(char *pergunta);

bool pergunta_sim_ou_nao(char *pergunta);

void limpa_tela();

#endif /* UTILIDADES_H */
