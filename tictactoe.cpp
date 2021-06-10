#include <cstdlib>
#include <cstdio>

#include "tictactoe.h"
#include "tabuleiro.h"

TABULEIRO t;
int jogadas = 0, ganhador = 0, fim = 0;

int main() {        
    montar_mapa(&t);

    do {
        imprime_mapa(&t);
        joga(&t);
    } while(!acabou(&t, &ganhador));

    imprime_mapa(&t);
    printf("O vencedor eh o jogador %d, parabens!", ((jogadas - 1) & 1 ? 2 : 1));
    scanf("%d", &fim);

    liberar(&t);
}

void imprime_mapa(TABULEIRO* t){
    printf("\n");
    for(int i = 0; i < t->linhas; ++i){
        printf(" %c |", printa_bloco(t->matriz[i][0]));
        printf(" %c |", printa_bloco(t->matriz[i][1]));
        printf(" %c \n", printa_bloco(t->matriz[i][2]));
        
        if(i != 2)
            printf("___ ___ ___ \n\n");
    }
}

char printa_bloco(const int bloco)
{
    if(bloco == 0)
        return BRANCO;
    if(bloco == 1)
        return PLAYERX;
    return PLAYERO;
}

void joga(TABULEIRO* t){
    int x = 0, y = 0;
    
    printf("\n");
    printf("Vez do jogador %d\n", jogadas & 1 ? 2 : 1);
    printf("Digite a linha: \n");
    scanf("%d", &x);
    printf("Digite a coluna: \n");
    scanf("%d", &y);

    x--;y--;
    if(!pode_jogar(t, x, y)){
        printf("Jogada invalida\n");
        return;
    }
        
    
    t->matriz[x][y] = jogadas & 1 ? -1 : 1;
    jogadas++;
}

bool acabou(TABULEIRO* t, int* ganhador){
    //se 3 então p1 ganhou, se -3 então p2 ganhou
    int sum = 0, linha = 0, coluna = 0;
    //checa horizontal
    for(linha = 0; linha < t->linhas; ++linha){
        sum = 0;
        for(coluna = 0; coluna < t->colunas; ++coluna){
            sum += t->matriz[linha][coluna];
        }
        if(sum == 3){
            *ganhador = 1;
            return true;
        }
        if(sum == -3){
            *ganhador = -1;
            return true;
        }
    }
    //checa vertical
    for(coluna = 0; coluna < t->colunas; ++coluna){
        sum = 0;
        for(linha = 0; linha < t->linhas; ++linha){
            sum += t->matriz[linha][coluna];
        }
        if(sum == 3){
            *ganhador = 1;
            return true;
        }
        if(sum == -3){
            *ganhador = -1;
            return true;
        }
    }

    //diagonal
    sum = 0;
    for(linha = 0; linha < t->colunas; ++linha) {
        sum += t->matriz[linha][linha];
    }
    if(sum == 3){
        *ganhador = 1;
        return true;
    }
    if(sum == -3){
        *ganhador = -1;
        return true;
    }
    sum = t->matriz[0][2] + t->matriz[1][1] + t->matriz[2][0];
    if(sum == 3){
        *ganhador = 1;
        return true;
    }
    if(sum == -3){
        *ganhador = -1;
        return true;
    }
    return false;
}