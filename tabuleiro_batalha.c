#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração do tabuleiro 10x10 e inicialização com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios
    int linha_navio_horizontal = 2;
    int coluna_navio_horizontal = 4;

    int linha_navio_vertical = 5;
    int coluna_navio_vertical = 1;

    // POSICIONANDO O NAVIO HORIZONTAL
    // Verifica se o navio cabe horizontalmente dentro do tabuleiro
    if (coluna_navio_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int pode_posicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] == 3) {
                pode_posicionar = 0;
                break;
            }
        }
        if (pode_posicionar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] = 3;
            }
        } else {
            printf("Erro: Sobreposição detectada ao posicionar o navio horizontal.\n");
            return 1;
        }
    } else {
        printf("Erro: O navio horizontal não cabe no tabuleiro.\n");
        return 1;
    }

    // POSICIONANDO O NAVIO VERTICAL
    // Verifica se o navio cabe verticalmente dentro do tabuleiro
    if (linha_navio_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int pode_posicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] == 3) {
                pode_posicionar = 0;
                break;
            }
        }
        if (pode_posicionar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = 3;
            }
        } else {
            printf("Erro: Sobreposição detectada ao posicionar o navio vertical.\n");
            return 1;
        }
    } else {
        printf("Erro: O navio vertical não cabe no tabuleiro.\n");
        return 1;
    }

    // EXIBINDO O TABULEIRO
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
    