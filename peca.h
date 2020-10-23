/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA
  
  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535
*/

#ifndef PECA_H
#define PECA_H

#include<iostream>

class Peca {
    protected:
        char nome; // Guarda qual é a peça
        char cor; // Guarda a cor da peça
    public: 
        Peca(char cor, char tipo);
        virtual void desenhar() = 0; // Chama função relativa de desenhar a peça
        virtual bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, bool temPeca) = 0; // Chama função de checar movimento da peça
        char getCor(); 
        char getNome(); 
};

#endif
