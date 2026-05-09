#include <stdio.h>

void criarTabuleiro(char tabuleiro[10][10]){
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            tabuleiro[i][j] = ' ';
        }
    }
}
void mostrarTabuleiro(char tabuleiro[10][10]){
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            printf("%c ",tabuleiro[i][j]);
        }
        printf("\n");
    }
}
void escolherPeca(int tipoPeca, char peca[3][3]){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            peca[i][j] = ' ';
        }
    }
    switch(tipoPeca){
        case 1:
            peca[0][0] = '1'; peca[0][1] = '1'; peca[0][2] = '1';
            peca[1][0] = '1'; peca[1][1] = '1'; peca[1][2] = '1';
            peca[2][0] = '1'; peca[2][1] = '1'; peca[2][2] = '1';
            break;
        case 2:
            peca[0][0] = '1';
            peca[1][0] = '1'; peca[1][1] = '1';
            break;
        case 3:
            peca[0][0] = '1'; peca[0][1] = '1';
            break;
        case 4:
            peca[0][0] = '1';
            peca[1][0] = '1';
            break;
        case 5:
            peca[0][0] = '1';
            break;
        }
}
void encaixarPeca(char tabuleiro[10][10],char peca[3][3], int linha, int coluna){
    for (int i = 0; i<3;i++){
        for (int j = 0; j<3;j++){
            if (peca[i][j]!= ' '){
                tabuleiro[linha+i][coluna+j] = peca[i][j];
            }
        }
    }
}

void main(){
    char tabuleiro[10][10], peca[3][3];
    
    printf("Wood Blocks Console Game -- Trabalho laboratorio de logica de programacao");
    printf("\n \n");
    criarTabuleiro(tabuleiro);
    escolherPeca(1,peca);
    encaixarPeca(tabuleiro,peca,5,6);
    escolherPeca(1,peca);
    encaixarPeca(tabuleiro,peca,2,3);
    escolherPeca(2,peca);
    encaixarPeca(tabuleiro,peca,1,7);
    mostrarTabuleiro(tabuleiro);
}