#include <stdio.h>

void criarTabuleiro(char tabuleiro[8][8]){
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            tabuleiro[i][j] = '0';
        }
    }
}
void mostrarTabuleiro(char tabuleiro[8][8]){
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            printf("%c ",tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void main(){
    char tabuleiro[8][8];

    criarTabuleiro(tabuleiro);
    mostrarTabuleiro(tabuleiro);
    printf("Hello World");
}