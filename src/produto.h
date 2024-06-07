#ifndef PRODUTO_H
#define PRODUTO_H
#include <stdbool.h>

/* Tamanhos máximos das strings dentro do registro
 * produto
 */
#define MAX_TAMANHO_NOME 256
#define MAX_TAMANHO_MARCA 256
#define MAX_TAMANHO_CATEGORIA 128

/* Quantidade máxima de produtos no sistema. */
#define MAX_PRODUTOS 10000

typedef struct produto {
	int codigo;
	char nome[MAX_TAMANHO_NOME];
	char marca[MAX_TAMANHO_MARCA];
	char categoria[MAX_TAMANHO_CATEGORIA];
	float custo_pacote;
	int qnt_por_pacote;
	float preco_unitario;
	int qnt_minima;
	bool status;
} produto;

/* Como a lista de produtos deverá ser acessível
 * por todo o programa, faz sentido fazê-la uma
 * variável global.
 */
extern produto *lista_produtos;
extern int n_produtos_cadastrados;
/* Variável utilizada para a mensagem de sair sem salvar. */
extern bool base_alterada;

bool produto_existe(int codigo);
int obter_index(int codigo);
bool adicionar_produto(produto prod);
void editar_produto(produto *original, produto editado);
bool remover_produto(int index);

#endif /* PRODUTO_H */
