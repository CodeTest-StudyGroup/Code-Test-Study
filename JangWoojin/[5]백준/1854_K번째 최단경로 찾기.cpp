#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 1001;
vector<pair<int, int>> graph[MAX];
priority_queue<int> dist[MAX];
int n, m, k;

void dijkstra(int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start].push(0);
    pq.push({0, start});
    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        for (auto& next : graph[v]) {
            int nv = next.first;
            int nd = d + next.second;
            if (dist[nv].size() < k) {
                dist[nv].push(nd);
                pq.push({nd, nv});
            } else if (dist[nv].top() > nd) {
                dist[nv].pop();
                dist[nv].push(nd);
                pq.push({nd, nv});
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
    }
    dijkstra(1);
    for (int i = 1; i <= n; ++i)
        printf("%d\n", dist[i].size() == k ? dist[i].top() : -1);
    return 0;
}
