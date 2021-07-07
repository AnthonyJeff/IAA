
#include <stdio.h>
#include <time.h>
#include <math.h>

long pot1(int x) {
    int i;
    long r = 1;
    
    for (i = 1; i <= x; i++) {
        r = 2 * r;
    }
    return r;
}

long pot2(int x) {
    return x ? 2 * pot2(x - 1) : 1;
}

long pot3(int x) {
    return x ? pot3(x - 1) + pot3(x - 1) : 1;
}

long pot4(int x) {
    long aux;
    if (x == 0) {
        return 1;
    }
    aux = pot4(x - 1);
    return aux + aux;
}

long pot5(int x) {
    long aux;
    if (x == 0) {
        return 1;
    }
    aux = pot5(x / 2);
    return aux * aux * (x % 2 + 1);
    // return x % 2 ? 2 * aux * aux : aux * aux;
}

long pot6(int x) {
    return pow(2, x);
}

long pot7(int x) {
    return 1 << x;
}

void testa(int i, int inicio, int fim, int incremento) {
    int j, k;
    long r, comeco;
    
    comeco = clock();
    printf("\nPot%d ", i);
    for (j = inicio; j <= fim; j = j + incremento) {
        for(k = 0; k < 1000000; k++)
        {
            switch (i) {
                case 1:
                    r = pot1(j);
                    break;
                case 2:
                    r = pot2(j);
                    break;
                case 3:
                    r = pot3(j % 32);
                    break;
                case 4:
                    r = pot4(j);
                    break;
                case 5:
                    r = pot5(j);
                    break;
                case 6:
                    r = pot6(j);
                    break;
                case 7:
                    r = pot7(j);
                    break;
            }
        }
//        printf("2^%d = %ld\n", j, r);
    }
    printf("x = %d    Tempo: %lf ms", inicio, (double) (clock() - comeco) / CLOCKS_PER_SEC * 1000);
//    getchar();
}

int main() {
    for (int i = 1; i <= 7; i++) {
        if (i == 3) { continue; }
        for (int j = 10; j <= 60; j = j + 10) {
            testa(i, j, j, 10);
        }
        printf("\n");
    }
    return 0;
}


