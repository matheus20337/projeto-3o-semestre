#include <stdio.h>

#include "produto.h"

void ler_arquivo_csv(char* nome_arquivo) {
	FILE* arquivo = fopen(nome_arquivo, "r");
	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo para leitura.\n");
		return;
	}

	// Lê as informações dos produtos do arquivo CSV
	int n_dados;
	while (!feof(arquivo)) {
		n_dados = fscanf(arquivo, "%d,%[^,],%[^,],%[^,],%f,%d,%f,%d,%d",
				&lista_produtos[n_produtos_cadastrados].codigo,
				lista_produtos[n_produtos_cadastrados].nome,
				lista_produtos[n_produtos_cadastrados].marca,
				lista_produtos[n_produtos_cadastrados].categoria,
				&lista_produtos[n_produtos_cadastrados].custo_pacote,
				&lista_produtos[n_produtos_cadastrados].qnt_por_pacote,
				&lista_produtos[n_produtos_cadastrados].preco_unitario,
				&lista_produtos[n_produtos_cadastrados].qnt_minima,
				&lista_produtos[n_produtos_cadastrados].status);
		if (n_dados == 9) {
			n_produtos_cadastrados++;
		} else {
			/* se o fscanf não encontrar valor algum, a 
			 * posição na stream voltará para onde ele começou.
			 * Caso isto ocorrer, devemos avançar para a próxima
			 * linha e esperar ela seja válida.
			 */

			int c;
			while ((c = fgetc(arquivo)) != EOF && c != '\n');
		}
	}

	// Fecha o arquivo CSV
	fclose(arquivo);
}

void salvar_produtos_csv(const char *nome_arquivo) {
	FILE *arquivo = fopen(nome_arquivo, "w");
	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo para escrita.\n");
		return;
	}

	// Escreve o cabeçalho do arquivo CSV
	fprintf(arquivo, "Código,Nome,Marca,Categoria,Custo Pacote,Quantidade por Pacote,Preço Unitário,Quantidade Mínima,Status\n");

	// Itera sobre a lista de produtos e escreve cada um no arquivo CSV
	for (int i = 0; i < n_produtos_cadastrados; i++) {
		fprintf(arquivo, "%d,%s,%s,%s,%.2f,%d,%.2f,%d,%d\n",
				lista_produtos[i].codigo,
				lista_produtos[i].nome,
				lista_produtos[i].marca,
				lista_produtos[i].categoria,
				lista_produtos[i].custo_pacote,
				lista_produtos[i].qnt_por_pacote,
				lista_produtos[i].preco_unitario,
				lista_produtos[i].qnt_minima,
				lista_produtos[i].status);
	}

	fclose(arquivo);
	printf("Produtos salvos com sucesso em '%s'.\n", nome_arquivo);
}