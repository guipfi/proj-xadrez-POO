/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA

  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535
================================================================================
Cavalo.cpp - Implementação da classe Cavalo, que representa a peça Cavalo do
jogo de xadrez. Ela possui apenas um atributo do tipo BOOL.
Essa classe possui um construtor e cinco métodos(um privado e quatro
públicos), sendo três deles do tipo BOOL e dois do tipo VOID.

DATA DA ULTIMA MODIFICAÇÃO:
25/04/2019
================================================================================
*/

#include "cavalo.h"

using namespace std;

void Cavalo::desenhar() {
    if(cor=='B')
        std::cout<<"C";
    else
        std::cout<<"c";
}

bool Cavalo::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, bool temPeca) {
    // Checa 4 movimentos em L(frente e trás)
    if(abs(linhaDestino-linhaOrigem)==2 && abs(colunaDestino-colunaOrigem)==1)
        return true;
    // Checa 4 movimentos em L(laterais)
    if(abs(linhaDestino-linhaOrigem)==1 && abs(colunaDestino-colunaOrigem)==2)
        return true;
        
    return false;
}
