/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA
  
  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535
*/

#ifndef RAINHA_H
#define RAINHA_H

#include<iostream>
#include"peca.h"
#include<cmath>

class Rainha : public Peca{
    public:
        Rainha(char cor) : Peca(cor,'R') {}
        void desenhar();
        bool checaMovimento(int linhaOrigem, int colunaOrigem, 
        					int linhaDestino, int colunaDestinono, bool temPeca);
};   

#endif