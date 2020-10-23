/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA

  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535
================================================================================
Jogador.cpp - Implementação da classe Jogador que tem o propósito de representar
o jogador de um jogo de xadrez, possuindo um atributo do tipo INT para guardar o
seu ID e um atributo do tipo Peca*(ponteiro do tipo Peca), que guarda o endereço
de suas peças. Essa classe possui apenas um construtor que recebe dois
parâmetros e um destrutor.

- Para seu funcionamento, é necessário ter o acompanhamento da implementação
Peca.cpp.

DATA DA ULTIMA MODIFICAÇÃO:
25/04/2019
================================================================================
*/

#include "jogador.h"

using namespace std;

Jogador::Jogador(string nome) {
    this->nome=nome;
}

void Jogador::setNome(string name){
    nome = name;
}

string Jogador::getNome(){
    return nome;
}

void Jogador::setPecas(Peca *pecas[]) {
    for(int i=0; i<16; i++) {
        this->pecas[i]=pecas[i];
    }
}