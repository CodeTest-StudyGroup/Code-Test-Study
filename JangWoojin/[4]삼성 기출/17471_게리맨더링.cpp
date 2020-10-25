#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int MAX = 10;
vector<int> graph[MAX];
int num[MAX];
int area[MAX];
int n, answer;

int calc(int t) {
    queue<int> q;
    int sum = 0;
    bool visited[MAX];
    memset(visited, false, sizeof(visited));
    bool flag = false;
    for (int i = 0; i < n; ++i)
        if (area[i] == t) sum += num[i];
    for (int i = 0; i < n; ++i) {
        if (area[i] == t) {
            if (!visited[i] && flag) return -1;
            flag = true;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (auto next : graph[cur]) {
                    if (area[next] == t && !visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
    }
    return sum;
}

void pick(int idx, int cnt, int m) {
    if (cnt == m) {
        int a = calc(0);
        int b = calc(1);
        if (a == -1 || b == -1) return;
        answer = min(answer, abs(a - b));
        return;
    }
    for (int i = idx; i < n; ++i) {
        area[i] = 1;
        pick(i+1, cnt+1, m);
        area[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> num[i];
    for (int i = 0; i < n; ++i) {
        int m; cin >> m;
        while (m--) {
            int j; cin >> j;
            graph[i].push_back(j - 1);
        }
    }
    
    answer = INF;
    for (int i = 1; i <= n / 2; ++i)
        pick(0, 0, i);
    
    if (answer == INF) answer = -1;
    cout << answer << endl;
    
    return 0;
}
