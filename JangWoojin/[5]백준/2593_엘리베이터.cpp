#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
struct Elevator {
    int x, y;
};

const int INF = 1e9;
const int MAX = 101;

Elevator elev[MAX];
vector<int> graph[MAX];
int cnts[MAX], parent[MAX];
int n, m, a, b;

bool transfer(int u, int v) {
    int d = elev[u].x - elev[v].x;
    if (d == 0) return true;
    for (int i = 0; elev[u].x + elev[u].y * i <= n; ++i) {
        int temp = elev[u].y * i + d;
        if (temp > 0 && temp % elev[v].y == 0) return true;
    }
    return false;
}

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 1; i <= m; ++i) {
        int temp = a - elev[i].x;
        if (temp >= 0 && temp % elev[i].y == 0) {
            cnts[i] = 1;
            pq.push({cnts[i], i});
        }
    }
    while (!pq.empty()) {
        int cnt = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (cnt > cnts[cur]) continue;
        for (auto next : graph[cur]) {
            if (cnts[next] == 0 || cnts[next] > cnt + 1) {
                cnts[next] = cnt + 1;
                parent[next] = cur;
                pq.push({cnts[next], next});
            }
        }
    }
}

void print(int x) {
    if (x == 0) return;
    print(parent[x]);
    cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> elev[i].x >> elev[i].y;
        for (int j = 1; j < i; ++j) {
            if (transfer(i, j)) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    cin >> a >> b;

    dijkstra();

    int answer = INF, idx = 0;
    for (int i = 1; i <= m; ++i) {
        int temp = b - elev[i].x;
        if (temp >= 0 && temp % elev[i].y == 0 && cnts[i] < answer) {
            answer = cnts[i];
            idx = i;
        }
    }

    if (answer == INF || answer == 0)
        cout << "-1" << endl;
    else {
        cout << answer << endl;
        print(idx);
    }

    return 0;
}
