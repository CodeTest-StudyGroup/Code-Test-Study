/* 강한 연결 요소(SCC, 코사라주 알고리즘) */
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 100;

int cost[MAX];
bool visited[MAX];
vector<int> graph[MAX];
vector<int> reverse_graph[MAX];
stack<int> st;

void visit(int u) {
    visited[u] = true;
    for (auto adj : graph[u])
        if (!visited[adj]) visit(adj);
    st.push(u);
}

int assign(int u) {
    int ret = cost[u];
    visited[u] = true;
    for (auto adj : reverse_graph[u])
        if (!visited[adj]) ret = min(ret, assign(adj));
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> cost[i];

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                graph[i].push_back(j);
                reverse_graph[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (!visited[i]) visit(i);

    memset(visited, false, sizeof(visited));

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) ans += assign(u);
    }

    cout << ans << endl;
    return 0;
}

/* 플로이드 와샬 */
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100;

int cost[MAX];
bool route[MAX][MAX];
bool visited[MAX];

int dfs(int u, int n) {
    int ret = cost[u];
    visited[u] = true;
    for (int i = 0; i < n; i++)
        if (!visited[i] && route[u][i] && route[i][u])
            ret = min(ret, dfs(i, n));
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> cost[i];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
            if (s[j] == '1') route[i][j] = 1;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (route[i][k] && route[k][j]) route[i][j] = 1;

    for (int i = 0; i < n; i++)
        if (!visited[i]) ans += dfs(i, n);

    cout << ans << endl;
    return 0;
}