/*UNIVERSIDADE FEDERAL DE SÃO CARLOS
  CAMPUS SOROCABA

  PROJETO XADREZ

  PROGRAMAÇÃO ORIENTADA À OBJETOS

  GABRIEL VIANA TEIXEIRA        759465
  GUILHERME PEREIRA FANTINI     759468
  TALES BALTAR LOPES DA SILVA   759535

================================================================================
Jogo.cpp - Implementação da classe Jogo que tem como proposito gerenciar um jogo
de Xadrez, possuindo métodos fundamentais para a inicialização do jogo. Possui
cinco atributos: dois do tipo INT, um do tipo Peca* (ponteiro do tipo Peca), um
do tipo Jogador* (ponteiro do tipo Jogador) e um do tipo Tabuleiro* (ponteiro do
tipo Tabuleiro). A classe possui um construtor, um destrutor e dois métodos,
sendo um do tipo BOOL e outro do tipo VOID.

- Para seu funcionamento, é necessário ter o acompanhamento das implementações
Peca.cpp, Jogador.cpp e Tabuleiro.cpp.

DATA DA ULTIMA MODIFICAÇÃO:
25/04/2019
================================================================================
*/

#include "jogo.h" 

std::ostream &operator<<(std::ostream &stream, const Jogo &jogo) {
    char peca;
    stream<<jogo.vezDeJogar<<jogo.estado;
    for(int i=0; i<64; i++) {
        stream<<peca;
    }
    return stream;
}

std::istream &operator>>(std::istream &stream, Jogo &jogo) {
    stream>>jogo.vezDeJogar>>jogo.estado;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            stream>>jogo.mapeamento[i][j];
        }
    }
    return stream;
}

using namespace std;

 Jogo::Jogo(){
    int indiceP=0, indiceB=0, indicePecas=0, opcao; 
    string player;
    Peca *pecasBrancas[16], *pecasPretas[16];

    opcao=menu();
    cin.ignore();
    if(opcao==1) {
        recuperar("config_padrao.txt");
    } else if(opcao==2) {
        recuperar("save_game.txt");
    } 

    try {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            switch(mapeamento[i][j]) {
                case 'P':
                    pecasBrancas[indiceB]= new Peao('B');
                    pecas[indicePecas]=pecasBrancas[indiceB];
                    indiceB++;
                    indicePecas++;
                    break;
                case 'T':
                    pecasBrancas[indiceB]= new Torre('B');
                    pecas[indicePecas]=pecasBrancas[indiceB];
                    indiceB++;
                    indicePecas++;
                    break;
                case 'C':
                    pecasBrancas[indiceB]= new Cavalo('B');
                    pecas[indicePecas]=pecasBrancas[indiceB];
                    indiceB++;
                    indicePecas++;
                    break;
                case 'B':
                    pecasBrancas[indiceB]= new Bispo('B');
                    pecas[indicePecas]=pecasBrancas[indiceB];
                    indiceB++;
                    indicePecas++;
                    break;
                case 'R':
                    pecasBrancas[indiceB]= new Rainha('B');
                    pecas[indicePecas]=pecasBrancas[indiceB];
                    indiceB++;
                    indicePecas++;
                    break;
                case 'K':
                    pecasBrancas[indiceB]= new Rei('B');
                    pecas[indicePecas]=pecasBrancas[indiceB];
                    indiceB++;
                    indicePecas++;
                    break;
                case 'p':
                    pecasPretas[indiceP]= new Peao('P');
                    pecas[indicePecas]=pecasPretas[indiceP];
                    indiceP++;
                    indicePecas++;
                    break;
                case 't':
                    pecasPretas[indiceP]= new Torre('P');
                    pecas[indicePecas]=pecasPretas[indiceP];
                    indiceP++;
                    indicePecas++;
                    break;
                case 'c':
                    pecasPretas[indiceP]= new Cavalo('P');
                    pecas[indicePecas]=pecasPretas[indiceP];
                    indiceP++;
                    indicePecas++;
                    break;
                case 'b':
                    pecasPretas[indiceP]= new Bispo('P');
                    pecas[indicePecas]=pecasPretas[indiceP];
                    indiceP++;
                    indicePecas++;
                    break;
                case 'r':
                    pecasPretas[indiceP]= new Rainha('P');
                    pecas[indicePecas]=pecasPretas[indiceP];
                    indiceP++;
                    indicePecas++;
                    break;
                case 'k':
                    pecasPretas[indiceP]= new Rei('P');
                    pecas[indicePecas]=pecasPretas[indiceP];
                    indiceP++;
                    indicePecas++;
                    break;
                default:
                ;
            }
        }
    }
    
        // Atribuindo ao jogador 0 as peças brancas
        j[0]->setPecas(pecasBrancas);
        // Atribuindo ao jogador 1 as peças pretas
        j[1]->setPecas(pecasPretas);
        // Criando tabuleiro
        t=new Tabuleiro(pecas, mapeamento);
    }
    catch(bad_alloc){
        cout << "Memória Insuficiente" << endl;
        exit(0);
    }
 }
 
Jogo::~Jogo() {
     // Desaloca o tabuleiro -> o tabuleiro desaloca as posições
    delete t;
    // Desaloca os jogadores;
    delete j[0];
    delete j[1];
    // Desaloca as peças
    for(int i=0; i<32; i++) {
        if(pecas[i]) {
            delete pecas[i];
        }
    }
}
 bool Jogo::movimentarPeca(int linhaAtual, int colunaAtual, int linhaDestino, int colunaDestino) {
     if(t->movimentarPeca(linhaAtual, colunaAtual, linhaDestino, colunaDestino, vezDeJogar)) {
         // Se ele se movimentar então a vez de jogar passa para o próximo
         vezDeJogar=(vezDeJogar=='B') ? 'P' : 'B';
         return true;
     } else {
        return false;
     }
 }

void Jogo::imprimirTabuleiro() {
    t->desenharTabuleiro();
}

int Jogo::menu() {
    int opcao;
    string player;

    while(1) {
        cout<<"========================"<<endl;
        cout<<"======== XADREZ ========"<<endl;
        cout<<"========================"<<endl;
        cout<<"1. Novo jogo"<<endl;
        cout<<"2. Continuar jogo"<<endl;

        cin>>opcao;

        switch(opcao) {
            case 1:
                cout<<"Iniciando novo jogo..."<<endl<<endl;
                return 1;
            case 2:
                cout<<"Iniciando jogo..."<<endl<<endl;
                return 2;
            default:
                cout<<"Opção inválida!"<<endl;
        }
    }
}

void Jogo::salvar(string arquivo) {
    char cor, nome;
    ofstream saveGame(arquivo, ios::trunc|ios::out);
    
    saveGame<<this->j[0]->getNome()<<endl<<this->j[1]->getNome()<<endl;
    saveGame<<this->vezDeJogar<<" "<<this->estado<<endl;
    
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(this->t->getPos(i,j)->consultarPos()) {
                cor=this->t->getPos(i,j)->consultarPos()->getCor();
                nome=this->t->getPos(i,j)->consultarPos()->getNome();
                if(cor=='P') {
                    nome=tolower(nome);
                    saveGame<<nome;
                } else {
                    saveGame<<nome;
                }
            } else {
                saveGame<<'0';
            }
        }
        saveGame<<endl;
    }
    saveGame.close();
}

void Jogo::recuperar(string arquivo) {
    string jogadores[2];
    ifstream file;
    try{    
        file.open(arquivo, ios::in);
        if(file.fail())
            throw 25;
        
    }
    catch(int i) {
        arquivo="config_padrao.txt";
        file.open(arquivo, ios::in);
        cout<<"Não há jogos salvos, um novo jogo será iniciado."<<endl<<endl;
    }

    if(arquivo!="config_padrao.txt") {
        getline(file, jogadores[0]);
        getline(file, jogadores[1]);
    } else {
        cout << "Digite seu nome [Peças Brancas]" << endl;
        getline(cin, jogadores[0]);
        cout << "Digite seu nome [Peças Pretas]" << endl;
        getline(cin, jogadores[1]);
    }

    try {
        j[0]= new Jogador(jogadores[0]);
        j[1]= new Jogador(jogadores[1]);
    }
    catch(bad_alloc){
        cout << "Jogadores não foram recuperados" << endl;
        exit(0);
    }

    file>>this->vezDeJogar>>this->estado;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            file>>this->mapeamento[i][j];
        }
    }
}

void Jogo::iniciarJogo() {
    int la,ca,ld,cd, opcao;
    bool exit=false;

    imprimirTabuleiro();
    cout<<endl<<"Bem-vindos, "<<j[0]->getNome()<<" e "<<j[1]->getNome()<<"!" <<endl;

    while(!exit) {

        if(vezDeJogar == 'B')
            cout <<endl<< j[0]->getNome() << " é a sua vez de jogar!"<<endl<<endl;
        else if(vezDeJogar == 'P')
            cout <<endl<< j[1]->getNome() << " é a sua vez de jogar!"<<endl<<endl;

        cin>>la>>ca>>ld>>cd;
        la--;
        ca--;
        ld--;
        cd--;
        if(movimentarPeca(la, ca, ld, cd)) {
            estado=isXeque(ld, cd, vezDeJogar);
            salvar("save_game.txt");
            imprimirTabuleiro();
            if(estado==2) {
                cout<<endl<<"XEQUE LADRAO"<<endl;
            } else if(estado==3) {
                cout<<endl<<"XEQUE-MATE JA ERA"<<endl;
                if(vezDeJogar=='B') {
                    cout<<"Parabéns, "<<j[1]->getNome()<<", você humilhou o "<<j[0]->getNome()<<"!"<<endl;
                } else {
                    cout<<"Parabéns, "<<j[0]->getNome()<<", você humilhou o "<<j[1]->getNome()<<"!"<<endl;
                }
                remove("save_game.txt");
                exit=true;
            }
        } else {
            imprimirTabuleiro();
            cout<<endl<<"Movimento inválido!"<<endl;
        }
    }
}

int Jogo::isXeque(int linha, int coluna, char vezDeJogar) {
    return t->testarXeque(linha,coluna,vezDeJogar);
}


