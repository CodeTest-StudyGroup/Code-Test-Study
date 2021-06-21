#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int a, b, c;
    Edge(int a, int b, int c) : a(a), b(b), c(c) {}
    bool operator<(const Edge& rhs) const {
        return c > rhs.c;
    }
};
vector<int> parent;
vector<Edge> edges;
int n, m, src, dest;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(Edge(a, b, c));
    }
    cin >> src >> dest;
}

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    parent[u] = v;
}

int calc() {
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;
    
    sort(edges.begin(), edges.end());
    for (auto &e : edges) {
        merge(e.a, e.b);
        if (find(src) == find(dest))
            return e.c;
    }
    return -1;
}

int main() {
    input();
    cout << calc() << endl;
    
    return 0;
}
