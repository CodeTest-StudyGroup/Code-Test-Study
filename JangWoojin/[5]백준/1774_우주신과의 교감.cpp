#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Pos {
    int x, y;
};

const int MAX = 1001;
Pos pos[MAX];
vector<pair<double, pair<int, int>>> edges;
int parent[MAX];
int n, m;

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    parent[v] = u;
}

double getDistance(Pos& a, Pos& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> pos[i].x >> pos[i].y;
        parent[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (find(u) != find(v)) merge(u, v);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            edges.push_back({getDistance(pos[i], pos[j]), {i, j}});

    sort(edges.begin(), edges.end());

    double answer = 0;
    for (int i = 0; i < edges.size(); ++i) {
        double d = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if (find(u) != find(v)) {
            merge(u, v);
            answer += d;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << answer << endl;
    return 0;
}
