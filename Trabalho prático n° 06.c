#include <stdio.h>

#define MAX_L 100
#define MAX_C 100

int main() {
    int L, C, P;
    scanf("%d %d", &L, &C);
    scanf("%d", &P);

    int mapa[MAX_L][MAX_C];
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            mapa[i][j] = 0;
        }
    }

    while (P--) {
        int Xi, Yi;
        scanf("%d %d", &Xi, &Yi);
        mapa[Xi - 1][Yi - 1] = 1;
    }

    int maxBrancas = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (mapa[i][j] == 0) {
                maxBrancas++;
                if (i > 0) mapa[i - 1][j] = 1;     // Acima
                if (i < L - 1) mapa[i + 1][j] = 1; // Abaixo
                if (j > 0) mapa[i][j - 1] = 1;     // À esquerda
                if (j < C - 1) mapa[i][j + 1] = 1; // À direita
            }
        }
    }

    printf("%d\n", maxBrancas);

    return 0;
}