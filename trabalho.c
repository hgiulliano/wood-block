#include <stdio.h>
#include <stdbool.h>

#define TAMTAB 10
#define TAMPECA 3

void criarTabuleiro(char tabuleiro[TAMTAB][TAMTAB]){
    for (int i=0; i<TAMTAB; i++){
        for (int j=0; j<TAMTAB; j++){
            tabuleiro[i][j] = ' ';
        }
    }
}
void mostrarTabuleiro(char tabuleiro[TAMTAB][TAMTAB]){
    for (int i=0; i<TAMTAB; i++){
        for (int j=0; j<TAMTAB; j++){
            printf("%c ",tabuleiro[i][j]);
        }
        printf("\n");
    }
}
void escolherPeca(int tipoPeca, char peca[TAMPECA][TAMPECA]){
    for (int i=0;i<TAMPECA;i++){
        for (int j=0;j<TAMPECA;j++){
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
        case TAMPECA:
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

void encaixarPeca(char tabuleiro[TAMTAB][TAMTAB],char peca[TAMPECA][TAMPECA], int linha, int coluna){
    for (int i = 0; i<TAMPECA;i++){
        for (int j = 0; j<TAMPECA;j++){
            if (peca[i][j]!= ' '){
                tabuleiro[linha+i][coluna+j] = peca[i][j];
            }
        }
    }
}

bool verificacaoTamanhoTabuleiro(int linha, int coluna){
    if (linha>=9 || coluna>9 || linha<0 || coluna<0)/*pro caso do indice do vetor passar de 9 ou ser negativo.*/
        {
            return false;
        }
    return true;
}

bool verificarEncaixe(char tabuleiro[TAMTAB][TAMTAB],char peca[TAMPECA][TAMPECA], int linha , int coluna){
    for (int i=0; i<TAMPECA;i++){
        for (int j=0; j<TAMPECA;j++){
            if (verificacaoTamanhoTabuleiro(linha+i,coluna+j))/*pro caso do indice do vetor passar de 9 ou ser negativo.*/
            {
                return false;
            }
            else if (peca[i][j] == '1' && tabuleiro[linha+i][coluna+j] == '1'){    
                return false;
            } 
        }
    }
    return true;
} 

void main(){
    char tabuleiro[TAMTAB][TAMTAB], peca[TAMPECA][TAMPECA];
    
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