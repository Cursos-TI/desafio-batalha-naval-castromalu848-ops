#include <stdio.h>

int main() {
    
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    
    int navio_horizontal[3] = {3, 3, 3};  // Navio horizontal
    int navio_vertical[3] = {3, 3, 3};    // Navio vertical

    
    int linha_h = 2;  // comeca na linha 2
    int coluna_h = 4; // comeca na coluna 4

    int linha_v = 6;  // comeca na linha 6
    int coluna_v = 1; // comeca na coluna 1


    for (int i = 0; i < 3; i++) {
        
        if (coluna_h + i < 10) {
            tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
        }
    }

    for (int i = 0; i < 3; i++) {
        
        if (linha_v + i < 10) {
    
            if (tabuleiro[linha_v + i][coluna_v] == 0) {
                tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
            }
        }
    }

    printf("=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
