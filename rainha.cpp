/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA

  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535

================================================================================
Rainha.cpp - Implementação da classe Rainha, que representa a peça Rainha do
jogo de xadrez. Ela possui apenas um atributo do tipo BOOL.
Essa classe possui um construtor e cinco métodos(um privado e quatro
públicos), sendo três deles do tipo BOOL e dois do tipo VOID.

DATA DA ULTIMA MODIFICAÇÃO:
25/04/2019
================================================================================
*/

#include "rainha.h"

using namespace std;

void Rainha::desenhar() {
    if(cor=='B')
        std::cout<<"R";
    else
        std::cout<<"r";
}

bool Rainha::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, bool temPeca) {
    // Checa movimentação na mesma linha ou coluna
    if(linhaDestino==linhaOrigem || colunaDestino==colunaOrigem)
        return true;
    // Checa movimentação nas 2 diagonais
    if(abs(linhaDestino-linhaOrigem)==abs(colunaDestino-colunaOrigem))
        return true;

    return false;
}
