#include <bits/stdc++.h>

using namespace std;

char tabuleiro[3][3] = { {'1', '2', '3'}, 
                         {'4', '5', '6'}, 
                         {'7', '8', '9'} };

void imprimirTabuleiro (){
    cout << endl << tabuleiro[0][0] << " | " << tabuleiro[0][1] << " | " << tabuleiro[0][2];
    cout << endl << "-----------" << endl;
    cout << tabuleiro[1][0] << " | " << tabuleiro[1][1] << " | " << tabuleiro[1][2];
    cout << endl << "-----------" << endl;
    cout << tabuleiro[2][0] << " | " << tabuleiro[2][1] << " | " << tabuleiro[2][2] << endl;
}

bool vitoria (){
    if ((tabuleiro[0][0] == tabuleiro[0][1] && tabuleiro[0][1] == tabuleiro[0][2])  || // linha 0
        (tabuleiro[1][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[1][2])  || // linha 1
        (tabuleiro[2][0] == tabuleiro[2][1] && tabuleiro[2][1] == tabuleiro[2][2])  || // linha 2
        (tabuleiro[0][0] == tabuleiro[1][0] && tabuleiro[1][0] == tabuleiro[2][0])  || // coluna 1
        (tabuleiro[0][1] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][1])  || // coluna 2
        (tabuleiro[0][2] == tabuleiro[1][2] && tabuleiro[1][2] == tabuleiro[2][2])  || // coluna 3
        (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])  || // diagonal 1
        (tabuleiro[2][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[0][2])) { // diagonal 2
        return true;
    }

    else {
        return false;
    }
}

int main(){
    int linha, coluna, jogada, casas=0, reiniciar=0;
    char jogo = 'S';
    char inicial[3][3] = { {'1','2','3'}, // matriz para conseguir resetar o tabuleiro
                           {'4','5','6'},
                           {'7','8','9'} };

    do{ // repetir o jogo quantas vezes quiser
        if (reiniciar == 1){
            memcpy(tabuleiro, inicial, sizeof(tabuleiro));
            reiniciar = 0;
        }

        imprimirTabuleiro();

        do{ // verificar se a jogada é válida
            cout << endl << "Jogador 1 (X), escolha uma posição: ";
            cin >> jogada;

            if (jogada < 4 && jogada > 0){
                linha = 0;
                coluna = jogada-1;
            }
            else if (jogada < 7 && jogada > 3){
                linha=1;
                coluna = jogada-4;
            }
            else if (jogada < 10 && jogada > 6){
                linha = 2;
                coluna = jogada-7;
            }

            if (jogada >= 10 || jogada <= 0 || 
                tabuleiro[linha][coluna] == 'O' || tabuleiro[linha][coluna] == 'X'){
                    cout << "Posição inválida ou já ocupada! Escolha outra posição." << endl;
                }
        }while(jogada >= 10 || jogada <= 0 || 
                tabuleiro[linha][coluna] == 'O' || tabuleiro[linha][coluna] == 'X');
        
        tabuleiro[linha][coluna] = 'X';
        casas++;
        imprimirTabuleiro();
        if (vitoria() == true){ // verificar se ganhou
            cout << "Parabéns! Jogador 1 venceu!";
            jogo='N';
        }
        
        if (casas == 9 && vitoria() == false){ // verificar se deu velha
            cout << "Empate! Nenhum jogador venceu.";
            jogo='N';
        }
        
        if (jogo != 'N'){ // para o jogo nn continuar msm X já tendo ganhado
            do{ // verificar se a jogada é valida
                cout << endl << "Jogador 2 (O), escolha uma posição: ";
                cin >> jogada;

                if (jogada < 4 && jogada > 0){
                    linha = 0;
                    coluna = jogada-1;
                }
                else if (jogada < 7 && jogada > 3){
                    linha=1;
                    coluna = jogada-4;
                }
                else if (jogada < 10 && jogada > 6){
                    linha = 2;
                    coluna = jogada-7;
                }

                if (jogada >= 10 || jogada <= 0 || 
                    tabuleiro[linha][coluna] == 'O' || tabuleiro[linha][coluna] == 'X'){
                        cout << "Posição inválida ou já ocupada! Escolha outra posição." << endl;
                    }
            }while(jogada >= 10 || jogada <= 0 || 
                    tabuleiro[linha][coluna] == 'O' || tabuleiro[linha][coluna] == 'X');
            
            tabuleiro[linha][coluna] = 'O';
            casas++;
            imprimirTabuleiro();

            if (vitoria() == true){ // verificar se ganhou
                cout << "Parabéns! Jogador 2 venceu!";
                jogo='N';
            }
        }

        if (jogo=='N') { // verifica dps q o jogo acabou se qr jogar dnv
            cout << endl << "Deseja jogar novamente? (S/N): ";
            cin >> jogo;
            if (jogo == 'S'){//para conseguir reiniciar o tabuleiro
                reiniciar=1;
            }
        }

    }while(jogo=='S');


    return 0;

}
