#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
const int MAX = 1000;
vector<vector<pii>> graph;
int parent[MAX];
int costs[MAX];
bool visited[MAX];
int n, k, minCost, maxCost;

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    if (u < v) swap(u, v);
    parent[u] = v;
}

void bfs(int start) {
    bool visited[MAX];
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;
    while (!q.empty()) {
        int cur = q.front().first;
        int total = q.front().second;
        q.pop();
        for (auto& adj : graph[cur]) {
            int next = adj.first;
            int cost = adj.second;
            if (visited[next]) continue;
            visited[next] = true;
            maxCost = max(maxCost, total + cost);
            q.push({next, total + cost});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    minCost = maxCost = 0;
    cin >> n >> k;
    graph.resize(n);
    for (int i = 0; i < n; ++i) parent[i] = i;
    vector<pipii> v;
    for (int i = 0; i < k; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        int a = v[i].second.first;
        int b = v[i].second.second;
        int c = v[i].first;
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) continue;
        merge(pa, pb);
        minCost += c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    visited[0] = true;
    for (int i = 0; i < n; ++i) bfs(i);
    cout << minCost << endl << maxCost << endl;
    return 0;
}