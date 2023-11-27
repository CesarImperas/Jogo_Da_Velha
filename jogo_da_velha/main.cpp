// Caio Cesar 24/11/23
// Jogo da velha

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

// Cabeçalho da função para uso
void menuInicial();

// Função para limpar a tela
void limpaTela(){
    system("CLS");
}

// Função para preencher a matriz
void preencheTabuleiro(char tabuleiro[3][3]){
    // Auxiliares da matriz
    int linha, coluna;

    // Preenchendo a matriz
    for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 3; coluna++){
            tabuleiro[linha][coluna] = '-';
        }
    }
}

// Função para exibir o tabuleiro com marcação no final
void exibeTabuleiroFinal(char tabuleiro[3][3]){
    // Auxiliares da matriz
    int linha, coluna;

    // Cores para marcação
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    string normal = "\e[0m";

    // Quebra de linha
    cout << endl;

    // Exibindo a matriz
    for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 3; coluna++){
            if(tabuleiro[linha][coluna] == '1'){
                tabuleiro[linha][coluna] = 'X';
                cout << green << tabuleiro[linha][coluna] << " " << normal;
            }else if(tabuleiro[linha][coluna] == '2'){
                tabuleiro[linha][coluna] = 'O';
                cout << green << tabuleiro[linha][coluna] << " " << normal;
            }else{
                cout << tabuleiro[linha][coluna] << " ";
            }
        }
        cout << endl;
    }
    // Quebra de linha
    cout << endl;
}

// Função para exibir a matriz
void exibeTabuleiro(char tabuleiro[3][3]){
    // Auxiliares da matriz
    int linha, coluna;

    // Quebra de linha
    cout << endl;

    // Exibindo a matriz
    for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 3; coluna++){
            cout << tabuleiro[linha][coluna] << " ";
        }
        cout << endl;
    }
    // Quebra de linha
    cout << endl;
}

// Função para conferir o jogo (caso haja vencedor)
bool verificaGanhador(char tabuleiro[3][3]){
    // Variáveis de linhas e colunas
    int linhas, colunas, cont;

    // Confere as linhas
    for(linhas = 0; linhas < 3; linhas++){
        if((tabuleiro[linhas][0] == 'X') && (tabuleiro[linhas][0] == tabuleiro[linhas][1]) && (tabuleiro[linhas][1] == tabuleiro[linhas][2])){
            limpaTela();
            cout << "\nJogador 'X' ganhou nas linhas!" << endl;
            // Preenchendo com 1 indicando 'X' para marcação
            for(cont = 0; cont < 3; cont++){
                tabuleiro[linhas][cont] = '1';
            }
            return true;
        }else if((tabuleiro[linhas][0] == 'O') && (tabuleiro[linhas][0] == tabuleiro[linhas][1]) && (tabuleiro[linhas][1] == tabuleiro[linhas][2])){
            limpaTela();
            cout << "\nJogador 'O' ganhou nas linhas!" << endl;
            // Preenchendo com 2 indicando 'O' para marcação
            for(cont = 0; cont < 3; cont++){
                tabuleiro[linhas][cont] = '2';
            }
            return true;
        }
    }

    // Confere as colunas
    for(colunas = 0; colunas < 3; colunas++){
        if((tabuleiro[0][colunas] == 'X') && (tabuleiro[0][colunas] == tabuleiro[1][colunas]) && (tabuleiro[1][colunas] == tabuleiro[2][colunas])){
            limpaTela();
            cout << "\nJogador 'X' ganhou nas colunas!" << endl;
            // Preenchendo com 1 indicando 'X' para marcação
            for(cont = 0; cont < 3; cont++){
                tabuleiro[cont][colunas] = '1';
            }
            return true;
        }else if((tabuleiro[0][colunas] == 'O') && (tabuleiro[0][colunas] == tabuleiro[1][colunas]) && (tabuleiro[1][colunas] == tabuleiro[2][colunas])){
            limpaTela();
            cout << "\nJogador 'O' ganhou nas colunas!" << endl;
            // Preenchendo com 2 indicando 'O' para marcação
            for(cont = 0; cont < 3; cont++){
                tabuleiro[cont][colunas] = '2';
            }
            return true;
        }
    }

    // Confere diagonal principal
    if((tabuleiro[0][0] != '-') && (tabuleiro[0][0] == tabuleiro[1][1]) && (tabuleiro[1][1] == tabuleiro[2][2])){
        if(tabuleiro[0][0] == 'X'){
            limpaTela();
            // Preenchendo com 1 indicando 'X' para marcação
            for(cont = 0; cont < 3; cont++){
                tabuleiro[cont][cont] = '1';
            }
            cout << "\nJogador 'X' ganhou na diagonal principal!" << endl;
            return true;
        }else{
            limpaTela();
            // Preenchendo com 2 indicando 'O' para marcação
            for(cont = 0; cont < 3; cont++){
                tabuleiro[cont][cont] = '2';
            }
            cout << "\nJogador 'O' ganhou na diagonal principal!" << endl;
            return true;
        }
    }

    // Confere diagonal secundaria
    if((tabuleiro[0][2] != '-') && (tabuleiro[0][2] == tabuleiro[1][1]) && (tabuleiro[1][1] == tabuleiro[2][0])){
        if(tabuleiro[0][2] == 'X'){
            limpaTela();
            // Preenchendo com 1 indicando 'X' para marcação
            tabuleiro[0][2] = '1';
            tabuleiro[1][1] = '1';
            tabuleiro[2][0] = '1';
            cout << "\nJogador 'X' ganhou na diagonal secundaria!" << endl;
            return true;
        }else{
            limpaTela();
            // Preenchendo com 2 indicando 'O' para marcação
            tabuleiro[0][2] = '2';
            tabuleiro[1][1] = '2';
            tabuleiro[2][0] = '2';
            cout << "\nJogadro 'O' ganhou na diagonal secundaria!" << endl;
            return true;
        }
    }

    // Nenhum vencedor
    return false;
}

// Função para exibir instruções
void exibeInstrucoes(){

    cout << "Mapa de posicoes!" << endl;
    cout << "\n7 | 8 | 9";
    cout << "\n4 | 5 | 6";
    cout << "\n1 | 2 | 3" << endl;
}

// Função do jogo
void jogo(){
    /// Variáveis gerais
    char tabuleiro[3][3];                               // Tabuleiro (matriz)
    int linhaJogada, colunaJogada, posicaoJogada;       // Linhas e colunas escolhidas pelo jogador + a posição conforme o mapa de instruções
    int turnoJogador = 1;                               // 1 = 'X' | 2 = 'O'
    int rodadas = 1;                                    // Quantas rodadas ja se passaram
    int opcao;                                          // Opção de reiniciar ou sair do jogo
    bool estadoJogo = true;                             // Verificar se o jogo acabou ou não
    bool posicionouJogada;                              // Verifica se o jogador posicionou corretamente um jogada

    // Função preencher tabuleiro
    preencheTabuleiro(tabuleiro);

    while(rodadas < 10 && estadoJogo){
        // Limpar a tela a cada jogada
        limpaTela();

        cout << "Jogo da velha!" << endl;

        // Função para exibir o tabuleiro
        exibeTabuleiro(tabuleiro);

        // Função para exibir instruções
        exibeInstrucoes();

        // Exibe mensagem
        cout << "\nRodada: " << rodadas << endl;

        // Posição numérica através da matriz de posições
        int posicoes[9][2] = {{2,0}, {2,1}, {2,2}, {1,0}, {1,1}, {1,2}, {0,0}, {0,1}, {0,2}};

        // Atualizando variável de verificação
        posicionouJogada = false;

        // Repetição até mudar a verificação
        while(posicionouJogada == false){
            // Verificar quem é a ver (turno) para tal jogada
            if(turnoJogador == 1){
                cout << "Jogador 'X', digite uma posicao conforme o mapa acima: ";
                cin >> posicaoJogada;

                // Reaproveitamento de códigos, sabendo que no vetor 'posicoes', a primeira posição se refere as linhas, e a segunda as colunas
                // Diminui um nos valores para o acesso do par ordenado, pois no mapa não possui o número '0', começando pelo 1, então é necessário essa retirada
                linhaJogada = posicoes[posicaoJogada - 1][0];
                colunaJogada = posicoes[posicaoJogada - 1][1];

                // Verifica se a posição esta vazia
                if(tabuleiro[linhaJogada][colunaJogada] == '-'){

                    posicionouJogada = true;

                    // Coloque um 'X' na linha e coluna digitada pelo jogador
                    tabuleiro[linhaJogada][colunaJogada] = 'X';

                    // Troca de vez
                    turnoJogador = 2;
                }
            }else{
                cout << "Jogador 'O', digite uma posicao conforme o mapa acima: ";
                cin >> posicaoJogada;

                // Reaproveitamento de códigos, sabendo que no vetor 'posicoes', a primeira posição se refere as linhas, e a segunda as colunas
                // Diminui um nos valores para o acesso do par ordenado, pois no mapa não possui o número '0', começando pelo 1, então é necessário essa retirada
                linhaJogada = posicoes[posicaoJogada - 1][0];
                colunaJogada = posicoes[posicaoJogada - 1][1];

                // Verifica se a posição esta vazia
                if(tabuleiro[linhaJogada][colunaJogada] == '-'){

                    posicionouJogada = true;
                    // Coloque um 'O' na linha e coluna digitada pelo jogador
                    tabuleiro[linhaJogada][colunaJogada] = 'O';

                    // Troca de vez
                    turnoJogador = 1;
                }
            }
        }

        // Confere vencedor
        if(verificaGanhador(tabuleiro)){
            // Houve vencedor
            estadoJogo = false;
        }

        // Aumenta a rodada
        rodadas++;
    }

    // Caso haja empate
    if(rodadas == 10){
        limpaTela();
        cout << "Deu velha (houve empate)!" << endl;
    }

    // Fim de jogo
    exibeTabuleiroFinal(tabuleiro);

    cout << "Fim de jogo!" << endl;
    cout << "\nDeseja reiniciar o jogo?";
    cout << "\n1 - Sim (retornar ao menu)";
    cout << "\n2 - Nao (sair do jogo)\n";
    cout << "\nEscolha uma opcao e tecla ENTER: ";
    cin >> opcao;

    if(opcao == 1){
        limpaTela();
        // Retorna ao menu
        menuInicial();
    }else{
        limpaTela();
        cout << "Ate mais! <3" << endl;
    }
}

// Função do menu do jogo
void menuInicial(){
    // Opção escolhida pelo usuário
    int opcao = 0;

    while (opcao < 1 || opcao > 3){
        cout << "Bem-vindo(a) ao jogo!";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair\n";
        cout << "\nEscolha uma opcao e tecla ENTER: ";

        cin >> opcao;

        // Limpar a tela
        limpaTela();

        switch (opcao){
            case 1:
                // Início do jogo
                jogo();
                break;
            case 2:
                // Informações do jogo
                cout << "Informacoes do jogo!" << endl;
                cout << "\nJogo criado por Caio Cesar 25/11/2023, utilizando linguagem C++" << endl;
                cout << "\nBaseado no classico jogo da velha, no qual dois jogadores, um representado pelo 'X', e o outro representado pelo 'O',\n";
                cout << "precisa formar uma sequencia de 3 posicoes alocadas por uma das letras da sua escolha ('X' ou 'O'), seja nas linhas, colunas, ou diagonais (principal ou secundaria)\n";
                cout << "\nJogo feito como parte de projetos do curso da Udemy, e que se necessario, passara por melhorias ao longo do tempo, muito obrigado e ate a proxima!\n";
                cout << "\nContato: github.com/CesarImperas" << endl;
                cout << "\n1 - Voltar";
                cout << "\n2 - Sair\n";
                cout << "\nEscolha uma opcao e tecle ENTER: ";
                cin >> opcao;

                // Retornar ao menu, ou fechar o jogo
                if(opcao == 1){
                    limpaTela();
                    menuInicial();
                }else{
                    limpaTela();
                    cout << "Ate mais! <3" << endl;
                }

                break;
            case 3:
                // Sair do jogo
                cout << "Ate mais! <3" << endl;
                break;
        }
    }
}

// Função principal
int main(){
    // Chamar o menu
    menuInicial();

    return 0;
}