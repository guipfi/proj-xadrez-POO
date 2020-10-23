/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA

  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535
================================================================================
Posicao.cpp - Implementação da classe Posicao, que possui como propósito a
representação das 64 posições existentes de um tabuleiro de xadrez. Ela possui
três atributos: dois do tipo INT e um do tipo Peca*(ponteiro do tipo Peca), além
disso possui um construtor que recebe três parâmetros e cinco métodos: dois do
tipo INT, um do tipo BOOL, um do tipo VOID e um do tipo Peca*.

- Para seu funcionamento, é necessário ter o acompanhamento da implementação
Peca.cpp.

DATA DA ULTIMA MODIFICAÇÃO:
25/04/2019
================================================================================
*/

#include "posicao.h"

using namespace std;

Posicao::Posicao(int l, int c, Peca *p) {
    linha=l;
    coluna=c;
    peca=p;
}

void Posicao::atualizarPos(Peca *p) {
    peca=p;
}

Peca* Posicao::consultarPos() {
    return peca;
}

bool Posicao::temPeca() {
    if(peca)
        return true;
    else
        return false;
}

int Posicao::getLinha(){
  return linha;
}

int Posicao::getColuna(){
  return coluna;
}
