CC=gcc

all: main.o utilidades.o tela_cadastro.o tela_principal.o tela_inicial.o manipulacao_csv.o
	$(CC) main.o utilidades.o manipulacao_csv.o tela_cadastro.o tela_principal.o tela_inicial.o -o cadastro.exe

unix: main.o utilidades.o tela_cadastro.o tela_principal.o tela_inicial.o manipulacao_csv.o
	$(CC) main.o utilidades.o manipulacao_csv.o tela_cadastro.o tela_principal.o tela_inicial.o -o cadastro

main.o: src/main.c src/produto.h src/utilidades.h src/tela_inicial.h
	$(CC) -c src/main.c
utilidades.o: src/utilidades.c
	$(CC) -c src/utilidades.c
manipulacao_csv.o: src/manipulacao_csv.c src/produto.h
	$(CC) -c src/manipulacao_csv.c
tela_cadastro.o: src/tela_cadastro.c src/produto.h src/utilidades.h
	$(CC) -c src/tela_cadastro.c
tela_principal.o: src/tela_principal.c src/produto.h src/utilidades.h src/tela_cadastro.h src/manipulacao_csv.h
	$(CC) -c src/tela_principal.c
tela_inicial.o: src/tela_inicial.c src/tela_principal.h src/utilidades.h src/produto.h src/manipulacao_csv.h
	$(CC) -c src/tela_inicial.c

clean:
	rm *.o cadastro cadastro.exe
