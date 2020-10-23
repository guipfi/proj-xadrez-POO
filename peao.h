/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA
  
  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535
*/

#ifndef PEAO_H
#define PEAO_H

#include<iostream>
#include"peca.h"
#include<cmath>

class Peao : public Peca {
    public:
        Peao(char cor) : Peca(cor,'P') {}
        void desenhar();
        bool checaMovimento(int linhaOrigem, int colunaOrigem, 
                            int linhaDestino, int colunaDestino, 
                            bool temPeca);
}; 

#endif