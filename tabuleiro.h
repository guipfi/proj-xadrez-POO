/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA
  
  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535
*/

#ifndef TABULEIRO_H
#define TABULEIRO_H

#include<iostream>
#include "posicao.h"

class Tabuleiro {
    private:
        Posicao *posicao[8][8]; // Matriz que guarda endereço das posições
        Posicao *reis[2];
        bool movimentoPermitido(int linhaOrigem, int colunaOrigem, 
        						int linhaDestino, int colunaDestino, char vezDeJogar, bool xeque=false); // Checagem do movimento
        void desenhaEspacoB(); // Função auxiliar desenhar em branco no tabuleiro(usado para retirar peça de uma posição)
    public:
        Tabuleiro(Peca *pecas[32], char mapeamento[][8]); // Cria as posições do tabuleiro e mapeia as peças nas posições de backup
        ~Tabuleiro(); // Destrói as posições alocadas
        void desenharTabuleiro(); // Desenhar tabuleiro
        bool movimentarPeca(int linhaOrigem, int colunaOrigem, 
        					int linhaDestino, int colunaDestino, char vezDeJogar); // Movimenta as peças no tabuleiro
        int testarXeque(int linhaDestino, int colunaDestino, char vezDeJogar); // Verifica se o rei está em xeque
        Posicao* getPos(int linha, int coluna); //Retornar nome da peça que está na posicao linha/coluna do tabuleiro
};

#endif
