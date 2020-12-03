#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool bfs(int start, vector<vector<int>>& graph, vector<int>& color) {
    const int RED = 1;
    const int BLUE = 2;
    bool ret = true;
    queue<int> q;
    color[start] = RED;
    q.push(start);
    while (!q.empty() && ret) {
        int cur = q.front();
        int c = color[cur];
        q.pop();
        for (auto next : graph[cur]) {
            if (color[next] == 0) {
                color[next] = c == RED ? BLUE : RED;
                q.push(next);
            } else if (color[next] == c) {
                ret = false;
                break;
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int RED = 1, BLUE = 2;
    int k;
    cin >> k;
    while (k--) {
        int v, e;
        cin >> v >> e;
        vector<vector<int>> graph(v + 1);
        vector<int> color(v + 1, 0);
        for (int i = 0; i < e; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool bipartite = true;
        for (int i = 1; i <= v && bipartite; ++i)
            if (color[i] == 0) bipartite &= bfs(i, graph, color);
        if (bipartite)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}