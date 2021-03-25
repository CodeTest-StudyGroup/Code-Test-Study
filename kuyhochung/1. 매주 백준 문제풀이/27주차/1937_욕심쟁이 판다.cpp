#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 500

int n, live_max = 0;
int matrix[MAX_N][MAX_N];
int visited[MAX_N][MAX_N] = {0, };
vector <pair <int, pair <int ,int > > > order;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool in_boundary(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < n) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            matrix[i][j] = temp;
            order.push_back({-temp, {i, j}});
        }
    }
    sort(order.begin(), order.end());

    for (int a = 0; a < order.size(); a++) {
        int x = order[a].second.first;
        int y = order[a].second.second;
        
        int temp_max = 1;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (!in_boundary(nx, ny)) continue;
            if (matrix[nx][ny] > matrix[x][y] && visited[nx][ny] != 0)
                temp_max = max(temp_max, visited[nx][ny] + 1);
        }
        visited[x][y] = temp_max;
        live_max = max(live_max, visited[x][y]);
    }
    
    cout << live_max;
    return 0;
}
