#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define INF 987654321
#define MAX_N 1001

int n, m;
int d[MAX_N];
vector < vector <pair <int, int> > > roads(MAX_N);
int lowest = INF;

void initialize() {
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }
}

bool should_skip(int x, int y, int skipX, int skipY) {
    if (x == skipX && y == skipY) return true;
    if (x == skipY && y == skipX) return true;
    return false;
}

void dijkstra(int skipFrom, int skipTo) {

    initialize();
    priority_queue<pair <int, int> > pq;
    d[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (cost > d[now]) continue;

        for (int i = 0; i < roads[now].size(); i++) {
            int next = roads[now][i].first;
            int nextCost = roads[now][i].second;

            if (should_skip(now, next, skipFrom, skipTo)) continue;

            if (d[next] > cost + nextCost) {
                d[next] = cost + nextCost;
                pq.push({ -(cost + nextCost), next });
            }
        }
    }
}

vector <pair <int, int> > bfs() {
    int visited[MAX_N];
    for (int i = 1; i <= n; i++) {
        visited[i] = INF;
    }
    visited[1] = 0;

    vector <pair <int, int> > answer;
    queue < pair <int, vector <pair <int, int> > > > q;
    q.push({ 1, answer });

    while (!q.empty()) {
        int now = q.front().first;
        vector <pair <int, int> > list = q.front().second;
        q.pop();

        for (int i = 0; i < roads[now].size(); i++) {
            int next = roads[now][i].first;
            int nextCost = roads[now][i].second;

            if (visited[next] > visited[now] + nextCost) {
                visited[next] = visited[now] + nextCost;
                vector <pair <int, int> > nextList = list;

                if (next == n && visited[next] == lowest) {
                    answer = list;
                    answer.push_back({ now, next });
                }
                else {
                    nextList.push_back({ now, next });
                    q.push({ next, nextList });
                }
            }
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        roads[a].push_back({ b, c });
        roads[b].push_back({ a, c });
    }

    vector <pair <int, int> > skipRoads;
    vector<int> candidates;

    dijkstra(-1, -1);
    lowest = d[n];

    skipRoads = bfs();
    for (int i = 0; i < skipRoads.size(); i++) {
        int skipFrom = skipRoads[i].first;
        int skipTo = skipRoads[i].second;
        dijkstra(skipFrom, skipTo);
        candidates.push_back(d[n]);
    }

    sort(candidates.begin(), candidates.end());
    if (candidates.back() == INF) cout << -1;
    else cout << candidates.back() - lowest;
}