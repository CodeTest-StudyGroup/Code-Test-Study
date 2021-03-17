#include <iostream>
using namespace std;

struct fish {
    int x, y, direction;
    bool is_dead;
};

int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void copy_map(int to[4][4], int from[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            to[i][j] = from[i][j];
        }
    }
}

void copy_fish(fish to[17], fish from[17]) {
    for (int i = 1; i <= 16; i++) {
        to[i] = from[i];
    }
}

int dfs(int map_origin[][4], int x, int y, int dir, fish fish_origin[17]) {
    int map_copy[4][4];
    fish fish_copy[17];
    copy_map(map_copy, map_origin);
    copy_fish(fish_copy, fish_origin);
    
    int eat = map_copy[x][y];
    dir = fish_copy[map_copy[x][y]].direction;
    fish_copy[map_copy[x][y]].x = -1;
    fish_copy[map_copy[x][y]].y = -1;
    fish_copy[map_copy[x][y]].is_dead = true;
    map_copy[x][y] = 0;
    
    int answer = 0;
    
    for (int i = 1; i <= 16; i++) {
        if (fish_copy[i].is_dead) continue;
        
        int now_x = fish_copy[i].x;
        int now_y = fish_copy[i].y;
        
        for (int d = 0; d < 8; d++) {
            int nx = now_x + dx[fish_copy[i].direction];
            int ny = now_y + dy[fish_copy[i].direction];
            
            if (nx == x && ny == y) {
                fish_copy[i].direction = (fish_copy[i].direction + 1) % 8;
                continue;
            }
            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
                fish_copy[i].direction = (fish_copy[i].direction + 1) % 8;
                continue;
            }
            
            now_x = nx;
            now_y = ny;
            break;
        }
        
        if (map_copy[now_x][now_y] == 0) {
            map_copy[fish_copy[i].x][fish_copy[i].y] = 0;
            map_copy[now_x][now_y] = i;
            fish_copy[i].x = now_x;
            fish_copy[i].y = now_y;
        }
        else {
            int temp_x, temp_y;
            temp_x = fish_copy[i].x;
            temp_y = fish_copy[i].y;
            fish_copy[i].x = now_x;
            fish_copy[i].y = now_y;
            fish_copy[map_copy[now_x][now_y]].x = temp_x;
            fish_copy[map_copy[now_x][now_y]].y = temp_y;
            
            map_copy[temp_x][temp_y] = map_copy[now_x][now_y];
            map_copy[now_x][now_y] = i;
        }
    }
    
    int cx = x + dx[dir];
    int cy = y + dy[dir];
    
    while(!(cx < 0 || cx >= 4 || cy < 0 || cy >= 4)) {
        if (map_copy[cx][cy] != 0)
            answer = max(answer, dfs(map_copy, cx, cy, dir, fish_copy));
        cx += dx[dir];
        cy += dy[dir];
    }
    
    return answer + eat;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int map[4][4];
    fish fish[17];
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int a, b;
            cin >> a >> b;
            fish[a].x = i;
            fish[a].y = j;
            fish[a].is_dead = false;
            fish[a].direction = b-1;
            map[i][j] = a;
        }
    }
    cout << dfs(map, 0, 0, 0, fish);
    return 0;
}
