#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 500;
const int INF = 987654321;
vector<int> trace[MAX];
int g[MAX][MAX];
int n, m, s, d;

vector<int> dijkstra() {
    vector<int> dist(n, INF);
    priority_queue<pii, vector<pii>, greater<>> pq;

    dist[s] = 0;
    pq.push({dist[s], s});

    while (!pq.empty()) {
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < d) continue;

        for (int next = 0; next < n; next++) {
            if (g[cur][next] == -1) continue;

            int nd = d + g[cur][next];
            if (nd < dist[next]) {
                dist[next] = nd;
                pq.push({nd, next});

                trace[next].clear();
            }
            if (nd <= dist[next]) {
                trace[next].push_back(cur);
            }
        }
    }

    return dist;
}

void removeShortestPath(int v) {
    for (auto u : trace[v]) {
        if (g[u][v] == -1) continue;
        g[u][v] = -1;
        removeShortestPath(u);
    }
}

int main() {
    while (1) {
        for (int i = 0; i < MAX; i++) {
            memset(g[i], -1, sizeof(g[i]));
            trace[i].clear();
        }

        scanf("%d %d", &n, &m);

        if (n == 0 && m == 0) {
            break;
        }

        scanf("%d %d", &s, &d);

        for (int i = 0, u, v, p; i < m; i++) {
            scanf("%d %d %d", &u, &v, &p);
            g[u][v] = p;
        }

        dijkstra();

        removeShortestPath(d);

        vector<int> dist = dijkstra();

        printf("%d\n", dist[d] == INF ? -1 : dist[d]);
    }

    return 0;
}