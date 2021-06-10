#include "tabuleiro.h"

#include <cstdlib>
#include <cstdio>

void montar_mapa(TABULEIRO* t){
    t->linhas = 3;
    t->colunas = 3;
    alocar_mapa(t);

    for(int i = 0; i < t->linhas; ++i){
        for(int j = 0; j < t->colunas; ++j){
            t->matriz[i][j] = 0;
        }
    }
}

void alocar_mapa(TABULEIRO* t){
    t->matriz = static_cast<int**>(malloc(sizeof(int**) * t->linhas));
    for(int i = 0; i < t->colunas; ++i){
        t->matriz[i] = static_cast<int*>(malloc(sizeof(int*) * t->colunas));
    }
}

void liberar(TABULEIRO* t){
    for(int i = 0; i < t->colunas; ++i){
        free(t->matriz[i]);
    }
    free(t->matriz);
}

bool pode_jogar(TABULEIRO* t, const int x, const int y){
    return posicao_valida(t, x, y) && entrada_valida(t, x, y);
}

bool entrada_valida(TABULEIRO* t, const int x, const int y){
    return t->matriz[x][y] == VAZIO;
}

bool posicao_valida(TABULEIRO* t, const int x, const int y){
    if(x < 0 || y < 0)
        return false;
    if(x > t->linhas)
        return false;
    if(y > t->colunas)
        return false;
    return true;
}