#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
#define MAX_N 1001
#define INF 1e9

int n, m;
int a, b, k, g;
int travel[MAX_N];
vector<pair <int, int> > graph[MAX_N];
int bridge[MAX_N][MAX_N];
pair<int, int> forbid[MAX_N][MAX_N];
int dist[MAX_N];
priority_queue < pair <int, int> , vector <pair <int, int> >, greater <pair <int ,int> > > pq;
bool visited[MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //입력을 받는다.
    cin >> n >> m;
    cin >> a >> b >> k >> g;
    for (int i = 0; i < g; i++) {
        cin >> travel[i];
    }
    //각 교차로의 이동 시간은 접근 편의성을 위해 graph와 bridge에 각각 받는다.
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        graph[u].push_back({v,l});
        graph[v].push_back({u,l});
        bridge[u][v] = l;
        bridge[v][u] = l;
    }
    
    //국왕의 방문 시간대를 저장한다.
    int start = 0;
    for (int i = 0; i < g-1; i++) {
        forbid[travel[i]][travel[i+1]] = {start, start+ bridge[travel[i]][travel[i+1]]};
        forbid[travel[i+1]][travel[i]] = {start, start+ bridge[travel[i+1]][travel[i]]};
        start += bridge[travel[i]][travel[i+1]];
    }
    
    //Dijkstra 알고리즘을 이용
    fill(dist+1, dist+n+1, INF);
    dist[a] = k;
    pq.push({k, a});
    while(!pq.empty()) {
        int currentDist = pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if (visited[current]) continue;
        visited[current] = true;
        for (auto pp: graph[current]) {
            int next = pp.first;
            int weight = pp.second;
            auto F = forbid[current][next];
            //이동하려는 다음 교차로에 국왕이 이미 있는 경우
            if (F.first <= currentDist && currentDist <= F.second)
                weight += F.second - currentDist;
            if (dist[next] > currentDist + weight) {
                dist[next] = currentDist + weight;
                pq.push({dist[next],next});
            }
        }
    }
    cout << dist[b]-k;
    return 0;
}

//참고한 코드: https://ioqoo.tistory.com/45
