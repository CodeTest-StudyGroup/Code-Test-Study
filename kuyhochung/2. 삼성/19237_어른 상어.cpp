#include <iostream>
using namespace std;
#define MAX_N 21

struct SHARK {
    int x, y, direction;
    bool is_active;
    int next_dir[5][4];
};

int n, m, k;
SHARK shark[401];
pair<int, int> smell[MAX_N][MAX_N];                 //남은 시간, 상어 번호
int ocean[MAX_N][MAX_N];
int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, -1, 1};

bool in_boundary(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < n) return true;
    else return false;
}

void move_sharks() {
    for (int shark_now = 1; shark_now <= m; shark_now++) {
        if (!shark[shark_now].is_active) continue;
        int dir = shark[shark_now].direction;
        int x = shark[shark_now].x;
        int y = shark[shark_now].y;
        
        bool moved = false;
        
        for (int i = 0; i < 4; i++) {
            int now_dir = shark[shark_now].next_dir[dir][i];
            int nx = x + dx[now_dir];
            int ny = y + dy[now_dir];
            
            if (in_boundary(nx, ny) && smell[ny][nx].first == 0) {
                if (ocean[ny][nx] != 0) {
                    if (ocean[ny][nx] > shark_now) {
                        ocean[y][x] = 0;
                        ocean[ny][nx] = shark_now;
                        shark[shark_now].x = nx;
                        shark[shark_now].y = ny;
                        shark[ocean[ny][nx]].is_active = false;
                        moved = true;
                        shark[shark_now].direction = now_dir;
                    }
                    else if (ocean[ny][nx] < shark_now) {
                        ocean[y][x] = 0;
                        shark[shark_now].is_active = false;
                        moved = true;
                        break;
                    }
                }
                else {
                    ocean[y][x] = 0;
                    ocean[ny][nx] = shark_now;
                    shark[shark_now].x = nx;
                    shark[shark_now].y = ny;
                    moved = true;
                    shark[shark_now].direction = now_dir;
                }
                break;
            }
            
        }
        if (!moved) {
            for (int i = 0; i < 4; i++) {
                int now_dir = shark[shark_now].next_dir[dir][i];
                int nx = x + dx[now_dir];
                int ny = y + dy[now_dir];
                
                if (in_boundary(nx, ny) && smell[ny][nx].second == shark_now) {
                    ocean[y][x] = 0;
                    ocean[ny][nx] = shark_now;
                    shark[shark_now].x = nx;
                    shark[shark_now].y = ny;
                    shark[shark_now].direction = now_dir;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (shark[i].is_active) {
            int x = shark[i].x;
            int y = shark[i].y;
            smell[y][x] = {k, i};
        }
    }
}

void remove_smell() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ocean[i][j] == 0 && smell[i][j].first > 0) {
                smell[i][j].first--;
                if (smell[i][j].first == 0)
                    smell[i][j].second = 0;
            }
        }
    }
}

int remaining_sharks() {
    int shark_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ocean[i][j] != 0) shark_count++;
        }
    }
    return shark_count;
}

void view_ocean() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ocean[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void smell_init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ocean[i][j] != 0)
                smell[i][j] = {k, ocean[i][j]};
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ocean[i][j];
            if (ocean[i][j] != 0) {
                shark[ocean[i][j]].y = i;
                shark[ocean[i][j]].x = j;
                shark[ocean[i][j]].is_active = true;
            }
        }
    }
    
    for (int i = 1; i <= m; i++) {
        int temp;
        cin >> temp;
        shark[i].direction = temp;
    }
    
    for (int sh = 1; sh <= m; sh++) {
        for (int i = 1; i <= 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> shark[sh].next_dir[i][j];
            }
        }
    }
    smell_init();
    
    int round;
    for (round = 0; round < 1000; round++) {
        move_sharks();
        remove_smell();
        //view_ocean();
        if (remaining_sharks() == 1) break;
    }
    
    if (round == 1000) cout << -1;
    else cout << round + 1;
    return 0;
}
