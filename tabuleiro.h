#pragma once

#define PLAYERX 'X'
#define PLAYERO 'O'
#define BRANCO ' '
#define VAZIO 0

struct tabuleiro {
    int** matriz;
    int linhas;
    int colunas;
} typedef TABULEIRO;

void montar_mapa(TABULEIRO* t);
void alocar_mapa(TABULEIRO* t);
void liberar(TABULEIRO* t);
bool pode_jogar(TABULEIRO* t,  int x,  int y);
bool entrada_valida(TABULEIRO* t,  int x,  int y);
bool posicao_valida(TABULEIRO* t,  int x,  int y);