/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA

  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535
================================================================================
Rei.cpp - Implementação da classe Rei, que representa a peça Rei do
jogo de xadrez. Ela possui apenas um atributo do tipo BOOL.
Essa classe possui um construtor e cinco métodos(um privado e quatro
públicos), sendo três deles do tipo BOOL e dois do tipo VOID.

DATA DA ULTIMA MODIFICAÇÃO:
25/04/2019
================================================================================
*/
#include "rei.h"

using namespace std;

void Rei::desenhar() {
    if(cor=='B')
        std::cout<<"K";
    else
        std::cout<<"k";
}

bool Rei::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, bool temPeca) {
    // Checa movimentos para qualquer lado(1 casa)
    if(abs(linhaDestino-linhaOrigem)<=1 && abs(colunaDestino-colunaOrigem)<=1)
        return true;
        
    return false;
}
