# Projeto do terceiro semestre
---
O objetivo deste repositório é arquivar o projeto da matéria de Programação Estruturada no curso de Engenharia de Computação da Universidade São Francisco.

Seguem abaixo as instruções para a elaboração do projeto:

> O projeto consiste em criar programa na linguagem C que manipule registros contendo pelo menos 5 campos e armazene essa estrutura em um arquivo CSV na memória não volátil (HD, pen drive, cartão de memória, etc).
> O programa deverá permitir visualizar todos os registros, inserir registro, alterar registro e remover registro.
> O registro manipulado deve ter um contexto que deve ser justificado por meio da necessidade da gravação desses dados, portanto, não será permitido o uso de registros aleatórios sem uma problematização.

## O Projeto
O projeto consiste em um sistema de cadastro de produtos de um super-mercado fictício. A aplicação deve ser capaz de criar, editar, visualizar e remover cadastros de produtos. Ela também deve ser capaz de guardar todos estes registros em um arquivo CSV para uso futuro.

## Instruções para Compilação
O projeto possui dois Makefiles, um para o windows e um para sistemas _unix-like_.

Para compilar o projeto, basta executar a seguinte linha de comando:
```
make -f <makefile desejado>
```
