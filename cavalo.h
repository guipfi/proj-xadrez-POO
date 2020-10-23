/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA
  
  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535
*/

#ifndef CAVALO_H
#define CAVALO_H

#include<iostream>
#include"peca.h"
#include<cmath>

class Cavalo : public Peca {
    public:
        Cavalo(char cor) : Peca(cor, 'C') {}
        void desenhar();
        bool checaMovimento(int linhaOrigem, int colunaOrigem, 
        					int linhaDestino, int colunaDestino, bool temPeca);
};

#endif
