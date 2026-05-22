#include <stdio.h>
#include <stdbool.h>

#define TAMTAB 10
#define TAMPECA 3
#define PREENCHIDA '0'

void criarTabuleiro(char tabuleiro[TAMTAB][TAMTAB]){
    for (int i=0; i<TAMTAB; i++){
        for (int j=0; j<TAMTAB; j++){
            tabuleiro[i][j] = '-';
        }
    }
}

void mostrarPecas(int n){
    char peca[TAMPECA][TAMPECA];
    for (int i = 0; i < TAMPECA; i++){
        for(int j = 0; j < TAMPECA; j++){
            peca[i][j] = ' ';
        }
    }
    switch(n){
        case 1:
            printf("Peca 1: 6 disponiveis\n");
            peca[0][0] = PREENCHIDA; peca[0][1] = PREENCHIDA; peca[0][2] = PREENCHIDA;
            peca[1][0] = PREENCHIDA; peca[1][1] = PREENCHIDA; peca[1][2] = PREENCHIDA;
            peca[2][0] = PREENCHIDA; peca[2][1] = PREENCHIDA; peca[2][2] = PREENCHIDA;
            for(int i = 0; i < TAMPECA; i++){
                for(int j = 0; j < TAMPECA; j++){
                    printf("%c ", peca[i][j]);
                }
                printf("\n");
            }
            mostrarPecas(2);
            break;
        case 2:
            printf("Peca 2: 5 disponiveis\n");
            peca[0][0] = PREENCHIDA;
            peca[1][0] = PREENCHIDA; peca[1][1] = PREENCHIDA;
            for(int i = 0; i < TAMPECA; i++){
                for(int j = 0; j < TAMPECA; j++){
                    printf("%c ", peca[i][j]);
                }
                printf("\n");
            }
            mostrarPecas(3);
            break;
        case 3:
            printf("Peca 3: 7 disponiveis\n");
            peca[0][0] = PREENCHIDA; peca[0][1] = PREENCHIDA;
            for(int i = 0; i < TAMPECA; i++){
                for(int j = 0; j < TAMPECA; j++){
                    printf("%c ", peca[i][j]);
                }
                printf("\n");
            }
            mostrarPecas(4);
            break;
        case 4:
            printf("Peca 4: 5 disponiveis\n");
            peca[0][0] = PREENCHIDA;
            peca[1][0] = PREENCHIDA;
            for(int i = 0; i < TAMPECA; i++){
                for(int j = 0; j < TAMPECA; j++){
                    printf("%c ", peca[i][j]);
                }
                printf("\n");
            }
            mostrarPecas(5);
            break;
        case 5:
            printf("Peca 5: 7 disponiveis\n");
            peca[0][0] = PREENCHIDA;
            for(int i = 0; i < TAMPECA; i++){
                for(int j = 0; j < TAMPECA; j++){
                    printf("%c ", peca[i][j]);
                }
                printf("\n");
            }
            break;
        default:
            break;
    }
}

bool verificarTabuleiroCompleto(char tabuleiro[TAMTAB][TAMTAB]){
    int contador = 0;
    for (int i=0; i<TAMTAB; i++){
        for (int j=0; j<TAMTAB; j++){
            if (tabuleiro[i][j] == PREENCHIDA){
                contador++;
            };
        }
    }
    if(contador == (TAMTAB*TAMTAB)){
        printf("Parabens, voce conseguiu preencher todo o tabuleiro, voce venceu o jogo!");
        return true;
    }
    else{
        return false;
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
            peca[0][0] = PREENCHIDA; peca[0][1] = PREENCHIDA; peca[0][2] = PREENCHIDA;
            peca[1][0] = PREENCHIDA; peca[1][1] = PREENCHIDA; peca[1][2] = PREENCHIDA;
            peca[2][0] = PREENCHIDA; peca[2][1] = PREENCHIDA; peca[2][2] = PREENCHIDA;
            break;
        case 2:
            peca[0][0] = PREENCHIDA;
            peca[1][0] = PREENCHIDA; peca[1][1] = PREENCHIDA;
            break;
        case 3:
            peca[0][0] = PREENCHIDA; peca[0][1] = PREENCHIDA;
            break;
        case 4:
            peca[0][0] = PREENCHIDA;
            peca[1][0] = PREENCHIDA;
            break;
        case 5:
            peca[0][0] = PREENCHIDA;
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

void reduzirPeca(int tipoPeca,int quantidadePecas[5]){
    switch(tipoPeca){
        case 1:
            quantidadePecas[0]--;
            break;
        case 2:
            quantidadePecas[1]--;
            break;
        case 3:
            quantidadePecas[2]--;
            break;
        case 4:
            quantidadePecas[3]--;
            break;
        case 5:
            quantidadePecas[4]--;
            break;
    }
    for(int i = 0; i < 5; i++){
        printf("Peca %d: %d disponivel\n", i + 1, quantidadePecas[i]);
    }
    printf("\n");
}

bool verificacaoTamanhoTabuleiro(int linha, int coluna){
    if (linha>9 || coluna>9 || linha<0 || coluna<0)/*pro caso do indice do vetor passar de 9 ou ser negativo.*/
        {
            return false;
        }
    return true;
}

bool verificarEncaixe(char tabuleiro[TAMTAB][TAMTAB],char peca[TAMPECA][TAMPECA], int linha , int coluna){
    for (int i=0; i<TAMPECA;i++){
        for (int j=0; j<TAMPECA;j++){
            if(peca[i][j] == PREENCHIDA){
                if(verificacaoTamanhoTabuleiro(linha+i,coluna+j) == false){
                    return false;
                }
                else if (tabuleiro[linha+i][coluna+j] == PREENCHIDA){
                    return false;
                }
            }
        }
    }
    return true;
} 

int main(){
    char tabuleiro[TAMTAB][TAMTAB], peca[TAMPECA][TAMPECA];
    int quantidadePecas[5] = {6, 5, 7, 5, 7};
    int inicio = 1;
    
    printf("Wood Blocks Console Game -- Trabalho laboratorio de logica de programacao");
    printf("\n \n");
    criarTabuleiro(tabuleiro);
    printf("Deseja iniciar o jogo ? (1 - Sim / 0 - Nao) ");
    scanf("%d", &inicio);
    if (inicio == 0){
        printf("Jogo encerrado, volte sempre!");
        return 0;
    }

    printf("Pecas disponiveis:\n");
    mostrarPecas(1);

    while(inicio == 1){
        printf("Tabuleiro do jogo:\n");
        mostrarTabuleiro(tabuleiro);
        printf("\n");
        int tipoPeca, linha, coluna;
        printf("Selecione o tipo da peca (1-5) - Selecione 0 se desejar desistir:");
        scanf("%d", &tipoPeca);
        if (tipoPeca == 0){
            printf("Jogo encerrado, volte sempre!");
            return 0;
        }
        else if (tipoPeca <1 || tipoPeca >5){
            printf("Tipo de peca invalido, tente novamente com um numero entre 1 e 5.\n");
            continue;
        }
        escolherPeca(tipoPeca, peca);
        if(quantidadePecas[tipoPeca-1] <= 0){
            printf("Nao ha mais pecas desse tipo disponiveis, escolha outro tipo de peca.\n");
            continue;
        }
        printf("Em qual linha e coluna voce deseja encaixar a peca ? (RESPECTIVAMENTE)");
        scanf("%d",&linha);
        scanf("%d",&coluna);
        if (verificarEncaixe(tabuleiro, peca, linha, coluna) == true){
            encaixarPeca(tabuleiro, peca, linha, coluna);
            reduzirPeca(tipoPeca, quantidadePecas);
        }
        else{
            printf("Nao foi possivel encaixar a peca nessa posicao, tente novamente em outra posicao.\n");
        }
        if(verificarTabuleiroCompleto(tabuleiro) == true){
            break;
        }
    }
    return 0;
}