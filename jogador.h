/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA
  
  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535
*/

#ifndef JOGADOR_H
#define JOGADOR_H

#include<iostream>
#include "peca.h"

class Jogador {
    private:
        int id; // Guarda id do jogador
        std::string nome;
        Peca *pecas[16]; // Guarda endereço das peças do jogador
    public:
        Jogador(std::string nome); // Construtor inicializa jogador com
        void setNome(std::string name);
        std::string getNome();
        void setPecas(Peca *pecas[]); 
        
};

#endif