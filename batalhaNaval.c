#include <stdio.h>

#define TAM 10          
#define AGUA 0          
#define NAVIO 3         
#define TAMANHO_NAVIO 3 

// Inicializa  o tabuleiro 
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Verifica se uma posição é valida e esta livre
int posicaoValida(int tabuleiro[TAM][TAM], int linha, int coluna) {
    return (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM && tabuleiro[linha][coluna] == AGUA);
}

// Posiciona um navio horizontal 
int posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAM) return 0; 
    for (int j = 0; j < TAMANHO_NAVIO; j++) {
        if (!posicaoValida(tabuleiro, linha, coluna + j)) return 0; 
    }
    for (int j = 0; j < TAMANHO_NAVIO; j++) {
        tabuleiro[linha][coluna + j] = NAVIO;
    }
    return 1;
}

// Posiciona um navio na diagonal 
int posicionarNavioDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAM || coluna + TAMANHO_NAVIO > TAM) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!posicaoValida(tabuleiro, linha + i, coluna + i)) return 0;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = NAVIO;
    }
    return 1;
}

// Posiciona um navio na diagonal 
int posicionarNavioDiagonalSecundaria(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAM || coluna - (TAMANHO_NAVIO - 1) < 0) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!posicaoValida(tabuleiro, linha + i, coluna - i)) return 0;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = NAVIO;
    }
    return 1;
}

// Exibe o tabuleiro 
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Dois horizontais
    posicionarNavioHorizontal(tabuleiro, 2, 1); 
    posicionarNavioHorizontal(tabuleiro, 6, 5); 

    // Dois diagonais
    posicionarNavioDiagonalPrincipal(tabuleiro, 0, 6); 
    posicionarNavioDiagonalSecundaria(tabuleiro, 4, 4); 

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}