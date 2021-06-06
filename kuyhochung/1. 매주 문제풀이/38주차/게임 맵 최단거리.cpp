#include <vector>
#include <queue>
using namespace std;

#define INF 10001

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[101][101];
queue <pair <int, int> > q;

bool in_boundary(int x, int y, int maxX, int maxY) {
    if (0 <= x && x < maxX && 0 <= y && y < maxY) return true;
    else return false;
}

int solution(vector<vector<int> > maps)
{
    int maxX = maps.size();
    int maxY = maps[0].size();
    
    for (int i = 0; i < maxX; i++) {
        for (int j = 0; j < maxY; j++) {
            visited[i][j] = INF;
        }
    }
    visited[0][0] = 1;
    
    q.push({0, 0});
    
    while(!q.empty()) {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = nowX + dx[dir];
            int ny = nowY + dy[dir];
            
            if (!in_boundary(nx, ny, maxX, maxY)) continue;
            if (maps[nx][ny] == 0) continue;
            if (visited[nx][ny] <= visited[nowX][nowY] + 1) continue;
            
            visited[nx][ny] = visited[nowX][nowY] + 1;
            q.push({nx, ny});

        }
    }
    
    if (visited[maxX-1][maxY-1] == INF) return -1;
    else return visited[maxX-1][maxY-1];
}
