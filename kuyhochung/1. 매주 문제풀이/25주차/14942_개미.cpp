#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 100001
#define SPARSE 17

int n;
int antEnergy[MAX_N] = {0, };
vector <pair <int, int > > graph[MAX_N];
bool visited[MAX_N];
int ant[MAX_N][SPARSE];
int dist[MAX_N][SPARSE];
queue<int> q;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill(visited, visited+MAX_N, false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> antEnergy[i];
    }
    for (int i = 0; i < n-1; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        int na = min(a, b);
        int nb = max(a, b);
        graph[na].push_back({nb, d});
        graph[nb].push_back({na, d});
    }
    
    //희소 배열 초기화
    q.push(1);
    visited[1] = true;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        for (auto p: graph[now]) {
            int next = p.first;
            int cost = p.second;
            
            if (visited[next]) continue;
            visited[next] = true;
            ant[next][0] = now;
            dist[next][0] = cost;
            q.push(next);
        }
    }
    for (int j = 1; j < SPARSE; j++) {
        for (int i = 1; i <= n; i++) {
            ant[i][j] = ant[ant[i][j-1]][j-1];
            dist[i][j] = dist[i][j-1] + dist[ant[i][j-1]][j-1];
        }
    }
    
    //각 개미굴별로 확인
    for (int i = 1; i <= n; i++) {
        int tmpEnergy = antEnergy[i];
        int now = i;
        for (int j = SPARSE-1; j >= 0; j --) {
            if (tmpEnergy <= 0) break;
            if (tmpEnergy >= dist[now][j] && ant[now][j] != 0) {
                tmpEnergy -= dist[now][j];
                now = ant[now][j];
            }
        }
        cout << now << '\n';
    }
    return 0;
}

//https://aruz.tistory.com/8
//https://hyperflow.dev/BOJ/14942
