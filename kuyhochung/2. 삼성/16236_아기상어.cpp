#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 21

int N;
int fish[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int shark = 2;
int min_d, minX, minY;
int result = 0;
int eatcount = 0;
pair <int, int> location;
int moveX[4] = {1, 0, -1, 0};
int moveY[4] = {0, 1, 0, -1};


void bfs_init() {
    min_d = MAX_N * MAX_N;
    minX = MAX_N;
    minY = MAX_N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            visited[i][j] = -1;
        }
    }
}

void bfs(int sharkX, int sharkY) {
    queue<pair<int ,int> > q;
    visited[sharkX][sharkY] = 0;
    q.push(make_pair(sharkX, sharkY));
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int dx = x + moveX[i];
            int dy = y + moveY[i];
            
            if (dx < 1 || dx > N || dy < 1 || dy > N)
                continue;
            if (visited[dx][dy] != -1 || fish[dx][dy] > shark)
                continue;
            
            visited[dx][dy] = visited[x][y] + 1;
            
            if (fish[dx][dy] != 0 && fish[dx][dy] < shark) {
                if (min_d > visited[dx][dy]) {
                    minX = dx;
                    minY = dy;
                    min_d = visited[dx][dy];
                }
                else if (min_d == visited[dx][dy]) {
                    if (minX == dx) {
                        if (minY > dy) {
                            minX = dx;
                            minY = dy;
                        }
                    } else if (minX > dx) {
                        minX = dx;
                        minY = dy;
                    }
                }
            }
            
            q.push(make_pair(dx, dy));
        }
        
    }
}


int main() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> fish[i][j];
            if (fish[i][j] == 9) {
                fish[i][j] = 0;
                location.first = i;
                location.second = j;
            }
        }
    }
    
    while(1) {
        bfs_init();
        bfs(location.first, location.second);
        
        if(minX != MAX_N && minY != MAX_N) {
            result += visited[minX][minY];
            eatcount++;
            
            if (shark == eatcount) {
                shark++;
                eatcount = 0;
            }
            
            fish[minX][minY] = 0;
            location.first = minX;
            location.second = minY;
        }
        else
            break;
    }
    
    cout << result;
    return 0;
}
