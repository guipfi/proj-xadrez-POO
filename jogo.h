/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA
  
  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535
*/

#ifndef JOGO_H
#define JOGO_H

#include<iostream>
#include<fstream>
#include<ctype.h>
#include "tabuleiro.h"
#include "jogador.h"
#include "peca.h"
#include "bispo.h"
#include "peao.h"
#include "cavalo.h"
#include "torre.h"
#include "rainha.h"
#include "rei.h"

class Jogo {
    private:
        Peca *pecas[32]; // Guarda endereço das peças do jogo
        Jogador *j[2]; // Guarda endereço dos 2 jogadores
        Tabuleiro *t; // Guarda endereço do tabuleiro
        char vezDeJogar; // Guarda de quem é a vez
        int estado; // Estado do jogo: inicio, cheque, xeque-mate, backup
        char mapeamento[8][8];
    public:
        Jogo(); // Inicializa o tabuleiro, os jogadores e as peças de cada jogador
        ~Jogo(); // Destrói a alocação dos jogadores, das peças e do tabuleiro
        friend std::ostream &operator<<(std::ostream &stream, const Jogo &jogo);
        friend std::istream &operator>>(std::istream &stream, Jogo &jogo);
        bool movimentarPeca(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino); // Função utilizada para movimentar peças
        void imprimirTabuleiro(); // Função para imprimir tabuleiro
        void iniciarJogo(); // Parte principal que controla o jogo
        int isXeque(int linha, int coluna, char vezDeJogar); // Checar se está em xeque 
        int menu(); // Menu do jogo
        void salvar(std::string arquivo); // Salvar o jogo
        void recuperar(std::string arquivo);

};

#endif