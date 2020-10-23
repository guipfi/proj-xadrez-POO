/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA

  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535

================================================================================
Peca.cpp - Implementação da classe Peca possui como o propósito a conexão entre
as classes das peças individuais(Torre, Cavalo, Bispo, Rainha, Rei e Peão) com
as outras classes do jogo. Possui oito atributos, sendo um deles do tipo INT e
um do tipo CHAR. Os outros atributos são ponteiros do tipo Rei, Rainha, Bispo,
Cavalo, Torre e Peão.
Essa classe possui um construtor que recebe um parâmetro, um destrutor e quatro
métodos: dois do tipo VOID, um do tipo BOOL e um do tipo INT.

- Para seu funcionamento, é necessário ter o acompanhamento das implementações
Rei.cpp, Rainha.cpp, Bispo.cpp, Cavalo.cpp, Torre.cpp e Peao.cpp

DATA DA ULTIMA MODIFICAÇÃO:
25/04/2019
================================================================================
*/

#include "peca.h"

using namespace std;

Peca::Peca(char cor, char nome) {
    this->cor=cor;
    this->nome=nome;
}

char Peca::getCor() {
    return cor;
}

char Peca::getNome() {
    return nome;
}