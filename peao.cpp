/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA

  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535
================================================================================
Peao.cpp - Implementação da classe Peao, que representa a peça Peão do jogo de
xadrez. Ela possui dois atributos: um do tipo INT e outro do tipo BOOL
Essa classe possui um construtor e cinco métodos(um privado e quatro
públicos), sendo três deles do tipo BOOL e dois do tipo VOID.

DATA DA ULTIMA MODIFICAÇÃO:
25/04/2019
================================================================================
*/

#include "peao.h"

using namespace std;

void Peao::desenhar() {
    if(cor=='B')
        std::cout<<"P";
    else
        std::cout<<"p";
}

bool Peao::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, bool temPeca) {
    // Ver se o peão já executou algum movimento
    bool movimentou=false;
    if(linhaOrigem!=1) {
        movimentou=true;
    }

    if(!temPeca) {
        // Caso geral, andar 1 casa
        if(colunaDestino==colunaOrigem && linhaDestino==linhaOrigem+1) {
            return true;
        }
        // Caso primeira movimentação, andar 2 casas
        if(!movimentou && colunaDestino==colunaOrigem && linhaDestino==linhaOrigem+2) {
            return true;
        }
    } else {
        // Caso comer peça na diagonal
        if(abs(colunaDestino-colunaOrigem)==1 && linhaDestino==linhaOrigem+1) {
            return true;
        }
    }
    return false;
}
