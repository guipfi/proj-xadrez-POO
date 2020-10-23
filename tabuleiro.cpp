/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA

  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535
================================================================================
Tabuleiro.cpp - Implementação da classe Tabuleiro, que possui como propósito
representar o tabuleiro de um jogo de xadrez. Ela possui apenas um atributo do
tipo Posicao*(ponteiro do tipo Posicao). Possui um construtor que recebe um
parâmetro e um destrutor. Além disso, possui quatro métodos(dois privados e dois
públicos), os seus tipos são: dois do tipo BOOL e dois do tipo INT.

- Para seu funcionamento, é necessário ter o acompanhamento das implementações
Peca.cpp e Posicao.cpp.

DATA DA ULTIMA MODIFICAÇÃO:
25/04/2019
================================================================================
*/

#include "tabuleiro.h"
#include <cmath>
using namespace std;

Tabuleiro::Tabuleiro(Peca *pecas[32], char mapeamento[][8]) {
    int indice=0;
    // Inicializando as peças na sua posição
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(mapeamento[i][j]!='0') {
                // Criando as peças
                posicao[i][j]=new Posicao(i,j,pecas[indice]);
                indice++;
                // Salvando a posição do rei
                if(mapeamento[i][j]=='K') {
                    reis[0]=posicao[i][j];
                }
                else if(mapeamento[i][j]=='k') {
                    reis[1]=posicao[i][j];
                }
            } else {
                posicao[i][j]=new Posicao(i,j,NULL);
            }
        }
    }
}

Tabuleiro::~Tabuleiro() {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            // Desalocando as posições
            delete posicao[i][j];
        }
    }
}

void Tabuleiro::desenhaEspacoB() {
    // Metódo auxiliar de desenhar espaço em branco quando não existir peça
    cout<<" ";
}

void Tabuleiro::desenharTabuleiro() {
        // Vetor auxiliar que pega as peças da linha do tabuleiro que está sendo processada
        Peca *peca[8];
        cout<<"       1     2     3     4     5     6     7     8"<<endl;
        cout<<"     _______________________________________________"<<endl;
    for(int i=7; i>-1; i--) {
        for(int j=0; j<8; j++) {
            // Pegando as peças que pertencem a cada linha do tabuleiro
            peca[j]=posicao[i][j]->consultarPos();
        }
        // Desenhando o tabuleiro
        cout<<"    |     |     |     |     |     |     |     |     |"<<endl;
        cout<<i+1<<"   |  "; peca[0] ? peca[0]->desenhar() : desenhaEspacoB();
        for(int z=1; z<8; z++) {
            // Se tiver peça na posição desenha a peça, se não desenha em branco
            cout<<"  |"<<"  "; peca[z] ? peca[z]->desenhar() :desenhaEspacoB();
        }
        cout<<"  |   "<<i+1<<endl;
        cout<<"    |_____|_____|_____|_____|_____|_____|_____|_____|"<<endl;
    }
        cout<<endl<<"       1     2     3     4     5     6     7     8"<<endl;
}

bool Tabuleiro::movimentoPermitido(int linhaAtual, int colunaAtual, int linhaDestino, int colunaDestino, char vezDeJogar, bool xeque) {
    char nomePeca, corPeca;
    int linhaAux, colunaAux;
    // Flag para saber se tem peça inimiga no destino
    bool temPeca=false;
   
    // Checar se está dentro do tabuleiro
    if(linhaDestino>7 || linhaDestino<0 || colunaDestino>7 || colunaDestino<0 || linhaAtual>7 || linhaAtual<0 || colunaAtual>7 || colunaAtual<0) {
        return false;
    }
        
    // Checar se a posição destino é a mesma da origem
    if(linhaDestino==linhaAtual && colunaDestino==colunaAtual) {
        return false;
    }

    // Checar se tem peça na posição origem
    if(!posicao[linhaAtual][colunaAtual]->consultarPos()) {
        return false;
    }

    // Checar se a peça é mesmo do jogador atual
    if(posicao[linhaAtual][colunaAtual]->consultarPos()->getCor() != vezDeJogar){   
        return false;
    }

    // Checar se tem peça no destino(amiga ou inimiga)
    if(posicao[linhaDestino][colunaDestino]->consultarPos()) {
        // Checar se a peça no destino é amiga ou inimiga
        if(posicao[linhaDestino][colunaDestino]->consultarPos()->getCor() == vezDeJogar) {
            // Se uma peça amiga estiver na posição o movimento é inválido
            return false;
        } else {
            // Se tiver uma peça inimiga a flag é ativada
            temPeca=true;
        }
    }

    // Caso for a vez das peças pretas, as posições são invertidas para checar o movimento(a checagem é feita considerando que o jogador está na parte de baixo do tabuleiro)
    int linAtual    = posicao[linhaAtual][colunaAtual]->getLinha();
    int colAtual    = posicao[linhaAtual][colunaAtual]->getColuna();
    int linDest     = linhaDestino;
    int colDest     = colunaDestino;
    if(vezDeJogar=='P'){
      linAtual      = abs(posicao[linhaAtual][colunaAtual]->getLinha() - 7);
      colAtual      = abs(posicao[linhaAtual][colunaAtual]->getColuna() - 7);
      linDest       = abs(linhaDestino-7);
      colDest       = abs(colunaDestino-7);
  }
     // Chamar função da peça checar movimento permitido
    if(!posicao[linhaAtual][colunaAtual]->consultarPos()->checaMovimento(linAtual, colAtual, linDest, colDest, temPeca)){
        return false;
    }

    // Checar se tem peça no caminho, exceto para o cavalo/peao/rei
    nomePeca=posicao[linhaAtual][colunaAtual]->consultarPos()->getNome();
    if(nomePeca!='C' && nomePeca!='K') {
        linhaAux=linhaAtual;
        colunaAux=colunaAtual;
        while(!(linhaAux==linhaDestino && colunaAux==colunaDestino)) {
            // Andando na horinzontal
            if(linhaAux==linhaDestino) {
                // Andando p esquerda ou direita
                colunaAux= (colunaAux>colunaDestino) ? colunaAux-1 : colunaAux+1;
            }
            // Andando na vertical
            else if(colunaAux==colunaDestino) {
                // Andando para cima ou para baixo
                linhaAux= (linhaAux>linhaDestino) ? linhaAux-1 : linhaAux+1;
            }
            // Andando na diagonal
            else {
                linhaAux= (linhaAux>linhaDestino) ? linhaAux-1 : linhaAux+1;
                colunaAux= (colunaAux>colunaDestino) ? colunaAux-1 : colunaAux+1;
            }
            // Se houver peça no caminho não pode se mover
            if(!(linhaAux==linhaDestino && colunaAux==colunaDestino) && posicao[linhaAux][colunaAux]->consultarPos()) {
                return false;
            }
        }
    }

    if(!xeque) {
        // Checar se o movimento irá deixar o próprio rei em xeque
        int linhaRei, colunaRei;
        char vezDeJogarAux;
        // Salvando posição atual
        Posicao aux(linhaAtual, colunaAtual, posicao[linhaAtual][colunaAtual]->consultarPos());
        // Salvando posição destino
        Posicao aux2(linhaDestino, colunaDestino, posicao[linhaDestino][colunaDestino]->consultarPos());
        if(vezDeJogar=='B') {
            // Pega a posição do rei branco
            linhaRei=reis[0]->getLinha();
            colunaRei=reis[0]->getColuna();
            vezDeJogarAux='P';
        } else {
            // Pega posição do rei preto
            linhaRei=reis[1]->getLinha();
            colunaRei=reis[1]->getColuna();
            vezDeJogarAux='B';
        }
        // Se a peça a ser movimentada é o rei, então a posição do rei é atualizada temporariamente
        if(aux.consultarPos()->getNome()=='K') {
            linhaRei=linhaDestino;
            colunaRei=colunaDestino;
        }
        // Simulando o movimento da peça
        posicao[linhaDestino][colunaDestino]->atualizarPos(posicao[linhaAtual][colunaAtual]->consultarPos());
        posicao[linhaAtual][colunaAtual]->atualizarPos(NULL);

        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                // Testar todas as peças do adverśario para ver se alguma poderá eliminar o rei caso o movimento venha a acontecer
                if(!(i==linhaDestino && j==colunaDestino) && posicao[i][j]->consultarPos()) {
                    corPeca=posicao[i][j]->consultarPos()->getCor();
                    if(corPeca==vezDeJogarAux) {
                        //  Chama a função que testa se o movimento é permitido da peça até o rei
                        if(movimentoPermitido(i,j,linhaRei,colunaRei,vezDeJogarAux,true)) {
                            // Retorna a peça na posição que foi retirada(pois foi retirada apenas para simular a jogada)
                            posicao[linhaAtual][colunaAtual]->atualizarPos(aux.consultarPos());
                            posicao[linhaDestino][colunaDestino]->atualizarPos(aux2.consultarPos());
                            return false;
                        }
                    }
                }
            }
        }
        // Retorna a peça na posição que foi retirada(pois foi retirada apenas para simular a jogada)
        posicao[linhaAtual][colunaAtual]->atualizarPos(aux.consultarPos());
        posicao[linhaDestino][colunaDestino]->atualizarPos(aux2.consultarPos());
    }

    // Se passar por todas as condições a movimentação é liberada
    return true;
}

bool Tabuleiro::movimentarPeca(int linhaAtual, int colunaAtual, int linhaDestino, int colunaDestino, char vezDeJogar) {
    if(movimentoPermitido(linhaAtual, colunaAtual, linhaDestino, colunaDestino,vezDeJogar)) {
        // Coloca a peça na posicao destino
        posicao[linhaDestino][colunaDestino]->atualizarPos(posicao[linhaAtual][colunaAtual]->consultarPos());
        // Retira a peça da posição antiga
        posicao[linhaAtual][colunaAtual]->atualizarPos(NULL);
        // Se o rei se movimento deve salvar a posição dele
        if(posicao[linhaDestino][colunaDestino]->consultarPos()->getNome()=='K') {
            if(vezDeJogar=='B') {
                reis[0]=posicao[linhaDestino][colunaDestino];
            } else {
                reis[1]=posicao[linhaDestino][colunaDestino];
            }
        }
        return true;
    } else {
        return false;
    }
}

// Recebe a linha e a coluna em que a peça se movimentou
int Tabuleiro::testarXeque(int linhaDestino, int colunaDestino, char vezDeJogar){

    bool xeque=false;
    int linhaRei, colunaRei, linhaAux, colunaAux;
    char vezDeJogarAux, nomePeca;

    if(vezDeJogar=='B') {
            // Pega a posição do rei branco
            linhaRei= reis[0]->getLinha();
            colunaRei= reis[0]->getColuna();
            vezDeJogarAux='P';
    } else {
            // Pega posição do rei preto
            linhaRei=reis[1]->getLinha();
            colunaRei=reis[1]->getColuna();
            vezDeJogarAux='B';
    }

    // Se não for permitido o movimento de qualquer peça até o rei, então o jogo não está em xeque
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(posicao[i][j]->consultarPos() && posicao[i][j]->consultarPos()->getCor()==vezDeJogarAux) {
                // Se houver algum permitido então está em xeque ou xeque-mate
                if(movimentoPermitido(i,j,linhaRei,colunaRei,vezDeJogarAux)) {
                    xeque=true;
                } 
            }
        }
    }
    if(!xeque){
        return 1;
    } else {
        // Testando todas as possibilidades do movimento do rei para tentar escapar do xeque, se o rei conseguir escapar, então é apenas xeque
        if(movimentoPermitido(linhaRei, colunaRei, linhaRei+1, colunaRei, vezDeJogar)

        || (movimentoPermitido(linhaRei, colunaRei, linhaRei, colunaRei+1, vezDeJogar))

        || (movimentoPermitido(linhaRei, colunaRei, linhaRei-1, colunaRei, vezDeJogar))

        || (movimentoPermitido(linhaRei, colunaRei, linhaRei, colunaRei-1, vezDeJogar))

        || (movimentoPermitido(linhaRei, colunaRei, linhaRei+1, colunaRei+1, vezDeJogar))

        || (movimentoPermitido(linhaRei, colunaRei, linhaRei-1, colunaRei-1, vezDeJogar))

        || (movimentoPermitido(linhaRei, colunaRei, linhaRei+1, colunaRei-1, vezDeJogar))

        || (movimentoPermitido(linhaRei, colunaRei, linhaRei-1, colunaRei+1, vezDeJogar)))
            return 2;

        // Testando se a peça consegue capturar a peça que está atribuindo o xeque
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                if(posicao[i][j]->consultarPos() && posicao[i][j]->consultarPos()->getCor()==vezDeJogar) {
                    // Se a peça conseguir capturar então é apenas xeque
                    if(movimentoPermitido(i,j,linhaDestino,colunaDestino,vezDeJogar)) {
                        return 2;
                    } 
                }
            }
        }

        nomePeca=posicao[linhaDestino][colunaDestino]->consultarPos()->getNome();
        // Se for C, P ou K então não há um caminho entre a peça e o rei
        if(nomePeca!='C' && nomePeca!='P'&& nomePeca!='K') {
            linhaAux=linhaDestino;
            colunaAux=colunaDestino;
            // Percorre o caminho entre a peça e o rei, procurando se alguma peça consegue assumir a posição e proteger o rei
            while(!(linhaAux==linhaRei && colunaAux==colunaRei)) {
                // Andando na horinzontal
                if(linhaAux==linhaRei) {
                    // Andando p esquerda ou direita
                    colunaAux= (colunaAux>colunaRei) ? colunaAux-1 : colunaAux+1;
                }
                // Andando na vertical
                else if(colunaAux==colunaRei) {
                    // Andando para cima ou para baixo
                    linhaAux= (linhaAux>linhaRei) ? linhaAux-1 : linhaAux+1;
                }
                // Andando na diagonal
                else {
                    linhaAux= (linhaAux>linhaRei) ? linhaAux-1 : linhaAux+1;
                    colunaAux= (colunaAux>colunaRei) ? colunaAux-1 : colunaAux+1;
                }

                for(int i=0; i<8; i++) {
                    for(int j=0; j<8; j++) {
                        if(posicao[i][j]->consultarPos() && posicao[i][j]->consultarPos()->getCor()==vezDeJogar) {
                            // Se a peça conseguir entrar no caminho então é apenas xeque
                            if(!(linhaAux==linhaRei && colunaAux==colunaRei) && movimentoPermitido(i,j,linhaAux,colunaAux,vezDeJogar)) {
                                return 2;
                            } 
                        }
                    }
                }
            }
        }
    }
    // Se nenhuma das condições forem possíveis, então é xeque-mate
    return 3;
}

Posicao* Tabuleiro::getPos(int linha, int coluna) {
    return posicao[linha][coluna];
}