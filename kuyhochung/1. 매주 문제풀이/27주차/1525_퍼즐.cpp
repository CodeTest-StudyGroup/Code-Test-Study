#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool in_boundary(int x, int y) {
    if (x >= 0 && x < 3 && y >= 0 && y < 3) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int start = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int temp;
            cin >> temp;
            if (temp == 0) temp = 9;
            start = start*10 + temp;
        }
    }
    
    if (start == 123456789) {
        cout << 0;
        return 0;
    }
    
    map<int, int> distance;
    queue<int> q;
    distance[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int now_int = q.front();
        q.pop();
        string now = to_string(now_int);
        
        int z = now.find('9');
        int x = z / 3;
        int y = z % 3;
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (!in_boundary(nx, ny)) continue;
            string next = now;
            swap(next[x*3 + y], next[nx*3 + ny]);
            int next_int = stoi(next);
            
            if (distance.count(next_int) == 0) {
                distance[next_int] = distance[now_int] + 1;
                q.push(next_int);
            }
        }
    }
    
    if (distance[123456789] == 0) cout << -1;
    else cout << distance[123456789];
    return 0;
}
