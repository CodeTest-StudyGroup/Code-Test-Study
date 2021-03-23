#include <iostream>
using namespace std;
#define MAX_N 10

int n, m, turn = 1e9;

void array_copy (char from[][MAX_N], char to[][MAX_N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            to[i][j] = from[i][j];
        }
    }
}

void simulate(int index, char arr[][MAX_N], int dir) {
    char copy[MAX_N][MAX_N];
    array_copy(arr, copy);
    
    if (index == 10) return;
    bool blueEnter = false, redEnter = false;
    if (dir == 0) {                                         //왼쪽으로 기울일 때
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (copy[i][j] == 'B' || copy[i][j] == 'R') {
                    char now = copy[i][j];
                    for (int k = j; k > 0; k--) {
                        if (copy[i][k-1] == '.') {
                            swap(copy[i][k], copy[i][k-1]);
                            continue;
                        }
                        else if (copy[i][k-1] == 'O') {
                            if (now == 'B') blueEnter = true;
                            else if (now == 'R') redEnter = true;
                            copy[i][k] = '.';
                            break;
                        }
                        else break;
                    }
                }
            }
        }
    }
    else if (dir == 1) {                                    //오른쪽으로 기울일 때
        for (int i = 0; i < n; i++) {
            for (int j = m-2; j >= 0; j--) {
                if (copy[i][j] == 'B' || copy[i][j] == 'R') {
                    char now = copy[i][j];
                    for (int k = j; k < m; k++) {
                        if (copy[i][k+1] == 'O') {
                            if (now == 'B') blueEnter = true;
                            else if (now == 'R') redEnter = true;
                            copy[i][k] = '.';
                            break;
                        }
                        else if (copy[i][k+1] == '.') {
                            swap(copy[i][k], copy[i][k+1]);
                            continue;
                        }
                        else break;
                    }
                }
            }
        }
    }
    else if (dir == 2) {                                    //위쪽으로 기울일 때
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                if (copy[i][j] == 'B' || copy[i][j] == 'R') {
                    char now = copy[i][j];
                    for (int k = i; k > 0; k--) {
                        if (copy[k-1][j] == '.') {
                            swap(copy[k][j], copy[k-1][j]);
                            continue;
                        }
                        else if (copy[k-1][j] == 'O') {
                            if (now == 'B') blueEnter = true;
                            else if (now == 'R') redEnter = true;
                            copy[k][j] = '.';
                            break;
                        }
                        else break;
                    }
                }
            }
        }
    }
    else if (dir == 3) {                                    //아래쪽으로 기울일 때
        for (int j = 0; j < m; j++) {
            for (int i = n-2; i >= 0; i--) {
                if (copy[i][j] == 'B' || copy[i][j] == 'R') {
                    char now = copy[i][j];
                    for (int k = i; k < n; k++) {
                        if (copy[k+1][j] == 'O') {
                            if (now == 'B') blueEnter = true;
                            else if (now == 'R') redEnter = true;
                            copy[k][j] = '.';
                            break;
                        }
                        else if (copy[k+1][j] == '.') {
                            swap(copy[k][j], copy[k+1][j]);
                            continue;
                        }
                        else break;
                    }
                }
            }
        }
    }

    if (redEnter && !blueEnter) {
        turn = min(turn, index + 1);
        return;
    }
    else if (blueEnter) return;
    
    for (int nextDir = 0; nextDir < 4; nextDir++) {
        if (dir == nextDir) continue;
        simulate(index+1, copy, nextDir);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    char board[MAX_N][MAX_N];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {                           //세로
        for (int j = 0; j < m; j++) {                       //가로
            cin >> board[i][j];
        }
    }
    
    for (int dir = 0; dir < 4; dir++) {
        simulate(0, board, dir);
    }
    
    if (turn == 1e9) cout << -1;
    else cout << turn;
    return 0;
}
