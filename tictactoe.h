#pragma once

#include "tabuleiro.h"

bool entrada_valida();
bool acabou(TABULEIRO* t, int* ganhador);
void imprime_mapa(TABULEIRO* t);
void joga(TABULEIRO* t);
char printa_bloco(int bloco);