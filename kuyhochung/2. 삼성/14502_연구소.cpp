#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 8

int area[MAX_N][MAX_N];
int area_copy[MAX_N][MAX_N];
int result = 0;
int N, M;
int moveX[4] = {1, 0, -1, 0};
int moveY[4] = {0, 1, 0, -1};

void areacopy(int (*to)[MAX_N], int (*from)[MAX_N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            to[i][j] = from[i][j];
        }
    }
}

void virus() {
    int area_spread[MAX_N][MAX_N];
    areacopy(area_spread, area_copy);
    queue<pair <int, int> > q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (area_spread[i][j] == 2)
                q.push(make_pair(i, j));
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dx = x + moveX[i];
            int dy = y + moveY[i];
            if (0 <= dx && dx < N && 0 <= dy && dy < M) {
                if (area_spread[dx][dy] == 0) {
                    area_spread[dx][dy] = 2;
                    q.push(make_pair(dx,dy));
                }
            }
        }
    }
    int safe = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (area_spread[i][j] == 0)
                safe++;
        }
    }
    result = max(result, safe);
}

void wall(int count) {
    if (count == 3) {
        virus();
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (area_copy[i][j] == 0) {
                area_copy[i][j] = 1;
                wall(count+1);
                area_copy[i][j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> area[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(area[i][j] == 0) {
                areacopy(area_copy, area);
                area_copy[i][j] = 1;
                wall(1);
                area_copy[i][j] = 0;
            }
        }
    }

    cout << result;
    return 0;
}