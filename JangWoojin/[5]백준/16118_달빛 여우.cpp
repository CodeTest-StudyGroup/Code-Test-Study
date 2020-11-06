#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

const ll INF = 1e17;
const int MAX = 4001;

vector<pair<int, ll>> graph[MAX];
int n, m;

vector<ll> dijkstra(int start) {
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<int, ll>> pq;
    dist[start] = 0;
    pq.push({-dist[start], start});

    while (!pq.empty()) {
        ll d = -pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (d > dist[v]) continue;

        for (auto& next : graph[v]) {
            int nv = next.first;
            ll nd = next.second;
            if (dist[v] + nd < dist[nv]) {
                dist[nv] = dist[v] + nd;
                pq.push({-dist[nv], nv});
            }
        }
    }

    return dist;
}

vector<ll> dijkstra2(int start) {
    vector<vector<ll>> dist(2, vector<ll>(n + 1, INF));
    priority_queue<pair<ll, pair<int, bool>>> pq;
    dist[0][start] = 0;
    pq.push({-dist[0][start], {start, true}});

    while (!pq.empty()) {
        ll d = -pq.top().first;
        int v = pq.top().second.first;
        bool booster = pq.top().second.second;
        pq.pop();

        if (d != dist[!booster][v]) continue;

        for (auto& next : graph[v]) {
            int nv = next.first;
            ll nd = next.second;
            nd = booster ? nd / 2 : nd * 2;
            if (dist[!booster][v] + nd < dist[booster][nv]) {
                dist[booster][nv] = dist[!booster][v] + nd;
                pq.push({-dist[booster][nv], {nv, !booster}});
            }
        }
    }

    for (int i = 0; i < dist[0].size(); ++i)
        dist[0][i] = min(dist[0][i], dist[1][i]);

    return dist[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back({b, d * 2});
        graph[b].push_back({a, d * 2});
    }

    vector<ll> fox = dijkstra(1);
    vector<ll> wolf = dijkstra2(1);

    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (fox[i] < wolf[i]) cnt++;
    cout << cnt << endl;

    return 0;
}
