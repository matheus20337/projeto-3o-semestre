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

/**
 * Verifica se existe algum produto na lista com
 * o código especificado.
 * @param codigo código a ser verificado
 * @return verdadeiro se houver algum produto com este código, falso caso o contrário.
 */
bool produto_existe(int codigo);

/**
 * Retorna o index do produto na lista com o código especificado.
 * @param codigo código a ser verificado.
 * @return o index do produto com o códico especificado. Retorna um valor menor que zero caso não houver um produto com o código especificado.
 */
int obter_index(int codigo);

/**
 * Adiciona um produto no final da lista, altera a base de produtos.
 * @param prod struct produto a ser adicionada.
 * return verdadeiro pra sucesso, falso caso não o produto não pode ser adicionado.
 */
bool adicionar_produto(produto prod);

/**
 * Sobreescreve um produto na lista com informações diferentes, alterda a base de produtos.
 * @param original ponteiro para um produto na lista.
 * @param editado estrutura produto que será armazenada no ponteiro original.
 */
void editar_produto(produto *original, produto editado);

/**
 * Remove um produto da lista, altera a base de produtos.
 * @param index Índice do produto na lista.
 * @return verdadeiro para sucesso, falso para caso não seja possível remover o produto.
 */
bool remover_produto(int index);

#endif /* PRODUTO_H */
