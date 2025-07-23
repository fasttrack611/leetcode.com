#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool check(char** board, int r, int c, int m, int n, char* word) {
    int len = strlen(word);

    // horizontal
    if (c + len <= n) {
        bool match = true;
        for (int i = 0; i < len; i++) {
            if (board[r][c + i] != ' ' && board[r][c + i] != word[i]) {
                match = false;
                break;
            }
        }
        if (match && (c == 0 || board[r][c - 1] == '#') && (c + len == n || board[r][c + len] == '#')) return true;

        match = true;
        for (int i = 0; i < len; i++) {
            if (board[r][c + i] != ' ' && board[r][c + i] != word[len - 1 - i]) {
                match = false;
                break;
            }
        }
        if (match && (c == 0 || board[r][c - 1] == '#') && (c + len == n || board[r][c + len] == '#')) return true;
    }

    // vertical
    if (r + len <= m) {
        bool match = true;
        for (int i = 0; i < len; i++) {
            if (board[r + i][c] != ' ' && board[r + i][c] != word[i]) {
                match = false;
                break;
            }
        }
        if (match && (r == 0 || board[r - 1][c] == '#') && (r + len == m || board[r + len][c] == '#')) return true;

        match = true;
        for (int i = 0; i < len; i++) {
            if (board[r + i][c] != ' ' && board[r + i][c] != word[len - 1 - i]) {
                match = false;
                break;
            }
        }
        if (match && (r == 0 || board[r - 1][c] == '#') && (r + len == m || board[r + len][c] == '#')) return true;
    }

    return false;
}

bool placeWordInCrossword(char** board, int boardSize, int* boardColSize, char * word){
    int m = boardSize;
    int n = *boardColSize;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != '#' && check(board, i, j, m, n, word)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    char* board[] = {"# #", " # ", "# #"};
    int boardSize = 3;
    int boardColSize[] = {3, 3, 3};
    char* word = "a";
    printf("Can place word: %s\n", placeWordInCrossword(board, boardSize, boardColSize, word) ? "true" : "false");
    return 0;
}
