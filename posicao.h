/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA
  
  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535
*/

#ifndef POSICAO_H
#define POSICAO_H

#include<iostream>
#include "peca.h"

class Posicao {
    private:
        int linha; // Guarda linha da pos
        int coluna; // Guarda coluna da pos
        Peca *peca; // Guarda endereço da peça que se encontra na pos

    public:
        Posicao(int l, int c, Peca *p); // Inicializa a posição com a peça
        void atualizarPos(Peca *p); // Coloca uma nova peça na posição
        Peca* consultarPos(); // Retornar a peça que esta na posicão
        bool temPeca(); // Retornar se tem peça na posiçao
        int getLinha(); // Retorna linha da posição
        int getColuna(); // Retorna coluna da posição
};

#endif
