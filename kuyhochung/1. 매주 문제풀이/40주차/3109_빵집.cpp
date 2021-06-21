#include <iostream>
using namespace std;

#define MAX_R 10000
#define MAX_C 500
#define WALL 'x'

int r, c;
char board[MAX_R][MAX_C];

int simulate (int x, int y) {
    if (x < 0 || x >= r) return 0;
    if (board[x][y] == WALL) return 0;
    board[x][y] = WALL;
    
    if (y == c-1) return 1;
    
    if (simulate(x-1, y+1)) return 1;
    if (simulate(x, y+1)) return 1;
    if (simulate(x+1, y+1)) return 1;
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }
    
    int pipes = 0;
    for (int i = 0; i < r; i++) {
        pipes += simulate (i, 0);
    }
    cout << pipes;
    return 0;
}
