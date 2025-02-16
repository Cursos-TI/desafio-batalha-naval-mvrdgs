#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void printBoard(int board[10][10]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void positionShip(int board[10][10], int x, int y, int size, char orientation) {
    for (int i = 0; i < size; i++) {
        switch (orientation) {
        case 'H':
            board[x][y + i] = 3;
            break;
        case 'V':
            board[x + i][y] = 3;
            break;
        case 'R':
            board[x + i][y + i] = 3;
            break;
        case 'L':
            board[x + i][y - i] = 3;
            break;
        default:
            break;
        }
    }
}

void positionSkill(int board[10][10], int x, int y, char skill) {
    switch (skill) {
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    case 'C':
        for (int i = 0; i < 3; i++) {
            for (int j = -i; j <= i; j++) {
                if (j >= -i || j <= i) {
                    board[x + i][y + j] = 1;
                }
            }
        }
        break;
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0
    case 'O':
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if ((i == 0) || (i != 0 && j == 0)) {
                    board[x + i][y + j] = 1;
                }
            }
        }
        break;
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    case 'X':
        for (int i = -1; i <= 1; i++) {
            for (int j = -2; j <= 2; j++) {
                if ((i == 0) || (i != 0 && j == 0)) {
                    board[x + i][y + j] = 1;
                }
            }
        }
        break;
    default:
        break;
    }

}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int board[10][10] = {0};

    printBoard(board);
    
    // Posição do navio 1 (horizontal)
    positionShip(board, 1, 1, 3, 'H');

    // Posição do navio 2 (vertical)
    positionShip(board, 4, 2, 3, 'V');

    printBoard(board);
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Posição do navio 3 (diagonal)
    positionShip(board, 1, 6, 3, 'R');
    // Posição do navio 4 (diagonal)
    positionShip(board, 6, 6, 3, 'L');

    printBoard(board);
    

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1

    positionSkill(board, 2, 5, 'C');
    printBoard(board);
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    positionSkill(board, 7, 1, 'O');
    printBoard(board);

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    
    positionSkill(board, 8, 7, 'X');
    printBoard(board);

    return 0;
}
