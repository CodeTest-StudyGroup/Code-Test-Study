#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y, z, idx;
};

struct Edge {
    int dist, u, v;
    bool operator<(const Edge& e) { return dist < e.dist; }
};

vector<Point> v;
vector<Edge> edges;
vector<int> parent;
int n;

void createEdges() {
    sort(v.begin(), v.end(),
         [](const Point& a, const Point& b) { return a.x < b.x; });
    for (int i = 0; i < v.size() - 1; i++) {
        edges.push_back({abs(v[i].x - v[i + 1].x), v[i].idx, v[i + 1].idx});
    }

    sort(v.begin(), v.end(),
         [](const Point& a, const Point& b) { return a.y < b.y; });
    for (int i = 0; i < v.size() - 1; i++) {
        edges.push_back({abs(v[i].y - v[i + 1].y), v[i].idx, v[i + 1].idx});
    }

    sort(v.begin(), v.end(),
         [](const Point& a, const Point& b) { return a.z < b.z; });
    for (int i = 0; i < v.size() - 1; i++) {
        edges.push_back({abs(v[i].z - v[i + 1].z), v[i].idx, v[i + 1].idx});
    }
}

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    parent.resize(n);

    for (int i = 0, x, y, z; i < n; i++) {
        cin >> x >> y >> z;
        v.push_back({x, y, z, i});
        parent[i] = i;
    }

    createEdges();

    sort(edges.begin(), edges.end());

    int cnt = 0, ans = 0;
    for (auto& e : edges) {
        int u = find(e.u);
        int v = find(e.v);
        if (u == v) continue;
        parent[u] = v;
        ans += e.dist;
        if (++cnt == n - 1) break;
    }

    cout << ans << endl;

    return 0;
}