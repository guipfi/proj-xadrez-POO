/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA

  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535
==============================================================================
Torre.cpp - Implementação da classe Torre, que representa a peça Torre do
jogo de xadrez. Ela possui apenas um atributo do tipo BOOL.
Essa classe possui um construtor e cinco métodos(um privado e quatro
públicos), sendo três deles do tipo BOOL e dois do tipo VOID.

DATA DA ULTIMA MODIFICAÇÃO:
25/04/2019
================================================================================
*/

#include "torre.h"

using namespace std;

void Torre::desenhar() {
    if(cor=='B')
        std::cout<<"T";
    else
        std::cout<<"t";
}

bool Torre::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, bool temPeca) {
    // Checa movimentação na mesma linha ou mesma coluna
    if(linhaDestino==linhaOrigem || colunaDestino==colunaOrigem)
        return true;

    return false;
}
