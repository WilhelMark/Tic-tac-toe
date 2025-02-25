#include <iostream>
using namespace std;

// Функция для вывода игрового поля
void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
            if (j < 2) cout << "| ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

// Функция для проверки победы
bool checkWin(char board[3][3], char symbol) {
    // Проверка горизонталей
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;
        }
    }
    // Проверка вертикалей
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return true;
        }
    }
    return false;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char gamerName = 'X';
    int moves = 0;

    while (moves < 9) {
        int row, col;
        cout << "Player " << gamerName << ", enter row (1-3): ";
        cin >> row;
        cout << "Player " << gamerName << ", enter column (1-3): ";
        cin >> col;

        // Проверка на корректность координат
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "Invalid coordinates. Please try again." << endl;
            continue;
        }

        // Проверка на занятость клетки
        if (board[row - 1][col - 1] != ' ') {
            cout << "Cell is occupied. Please choose another one." << endl;
            continue;
        }

        // Размещение символа
        board[row - 1][col - 1] = gamerName;

        // Вывод текущего состояния поля
        printBoard(board);

        // Проверка на победу
        if (checkWin(board, gamerName)) {
            cout << "Player " << gamerName << " wins!" << endl;
            return 0;
        }

        // Смена игрока
        if (gamerName == 'X') {
            gamerName = 'O';
        } else {
            gamerName = 'X';
        }

        moves++;
    }

    // Ничья
    if (moves == 9) {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
