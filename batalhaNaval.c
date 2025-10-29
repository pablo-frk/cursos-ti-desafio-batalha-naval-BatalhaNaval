#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define MAR 0

int tabuleiro[TAMANHO][TAMANHO] = {0}; // inicializa tudo com 0 (mar)


void posicionarNavioVertical(int tamanho, int linha, int coluna) {
    for (int i = 0; i < tamanho; i++) {
        if (linha + i < TAMANHO) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}


void posicionarNavioHorizontal(int tamanho, int linha, int coluna) {
    for (int i = 0; i < tamanho; i++) {
        if (coluna + i < TAMANHO) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    }
}

void posicionarNavioDiagonalPrincipal(int tamanho, int linha, int coluna) {
    for (int i = 0; i < tamanho; i++) {
        if (linha + i < TAMANHO && coluna + i < TAMANHO) {
            tabuleiro[linha + i][coluna + i] = NAVIO;
        }
    }
}

void posicionarNavioDiagonalSecundaria(int tamanho, int linha, int coluna) {
    for (int i = 0; i < tamanho; i++) {
        if (linha + i < TAMANHO && coluna - i >= 0) {
            tabuleiro[linha + i][coluna - i] = NAVIO;
        }
    }
}

void exibirTabuleiro() {
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    printf("    ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%d ", j);
    }
    printf("\n");

    char letra = 'A';
    for (int i = 0; i < TAMANHO; i++) {
        printf("%c - ", letra);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
        letra++;
    }
}
-
int main() {

    posicionarNavioVertical(4, 1, 2);
    posicionarNavioHorizontal(3, 3, 5);
    posicionarNavioDiagonalPrincipal(3, 5, 5);
    posicionarNavioDiagonalSecundaria(4, 2, 9);

    exibirTabuleiro();

    return 0;
}
