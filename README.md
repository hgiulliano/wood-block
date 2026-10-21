# 🧱 Wood Block

Jogo de quebra-cabeça para terminal, escrito em C. O objetivo é encaixar todas as peças disponíveis em um tabuleiro 10x10, preenchendo todos os espaços sem sobreposição.

Projeto da disciplina de **Laboratório de Lógica de Programação**, CEFET-MG.

## Como jogar

- O tabuleiro tem 10x10 casas. As linhas e colunas vão de **0 a 9**.
- Existem 5 tipos de peça, cada um com uma quantidade limitada:

| Peça | Formato | Quantidade |
|------|---------|-----------|
| 1 | Quadrado 3x3 | 6 |
| 2 | L de 3 blocos | 5 |
| 3 | 2 blocos na horizontal | 7 |
| 4 | 2 blocos na vertical | 5 |
| 5 | 1 bloco | 7 |

- A cada rodada, escolha o tipo da peça (1 a 5) e a linha e a coluna onde ela será encaixada. A posição informada é o canto superior esquerdo da peça.
- Digite `0` no tipo da peça para desistir.
- Você vence ao preencher todo o tabuleiro.

## Como rodar

Você precisa de um compilador C, como o `gcc`.

```bash
gcc trabalho.c -o woodblock
./woodblock
```

## Conceitos praticados

Funções, matrizes bidimensionais, recursão (`mostrarPecas`), `switch`, constantes com `#define` e validação de limites do tabuleiro.

## Autores

- Henrique Giulliano Vilano Silva
- Guilherme Pinheiro Oliveira Menez
