#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_N 500
#define INF 1e9

int n, m;
vector<pair<int, int>> edges[MAX_N];                                //각 노드 사이의 거리를 담는 배열
vector<pair<int, int>> trace[MAX_N];                                //BFS의 역추적을 위한 배열
bool visited[MAX_N][MAX_N];

void init () {
    memset(visited, false, sizeof(visited));
    memset(trace, 0, sizeof(trace));
    for (int i = 0; i < MAX_N; i++) {
        edges[i].clear();
    }
}

vector<int> dijkstra(int start, int nodes) {
    //dijkstra 알고리즘을 위한 거리 배열 - 시작점은 0, 그 외 무한으로 거리 초기화
    vector<int> distance(nodes, INF);
    distance[start] = 0;

    priority_queue<pair<int, int>> pq; //-cost, node 번호
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (distance[currentNode] < cost) continue;
        
        for (int i = 0; i < edges[currentNode].size(); i++) {
            int nextNode = edges[currentNode][i].first;
            int nextCost = cost + edges[currentNode][i].second;
            
            //삭제된 edge 무시
            if (edges[currentNode][i].second == -1) continue;

            if (distance[nextNode] > nextCost) {
                distance[nextNode] = nextCost;
                pq.push(make_pair(-nextCost, nextNode));

                //trace 갱신
                trace[nextNode].clear();
                trace[nextNode].push_back(make_pair(currentNode, nextCost));
            }

            //최단 거리 찾을 때마다 trace update
            else if (distance[nextNode] == nextCost)
                trace[nextNode].push_back(make_pair(currentNode, nextCost));
            }
        }
    return distance;
}

void BFS(int destination) {
    //queue를 이용하여 trace에 해당하는 정점들을 모두 지울 준비를 한다
    queue<int> q;
    bool visitedNode[MAX_N];
    for (int i = 0; i < n; i++) visitedNode[i] = false;
    q.push(destination);
    visitedNode[destination] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        
        for (int i = 0; i < trace[currentNode].size(); i++) {
            int nextNode = trace[currentNode][i].first;
            if (visited[currentNode][nextNode]) continue;
            
            //역순으로 접근하므로 nextNode 기준으로 접근
            for (int i = 0; i < edges[nextNode].size(); i++) {
                if (edges[nextNode][i].first == currentNode)
                    edges[nextNode][i].second = -1;
            }
            if (!visitedNode[nextNode]) {
                q.push(nextNode);
                visitedNode[nextNode] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    while (1) {
        init();

        cin >> n >> m;
        if (n == 0 && m == 0) break;

        int start, goal;
        cin >> start >> goal;

        for (int i = 0; i < m; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            edges[from].push_back({to, cost});
        }
        
        dijkstra(start, n);
        BFS(goal);
        vector<int> result = dijkstra(start, n);

        if (result[goal] == INF) cout << -1 << '\n';
        else cout << result[goal] << '\n';
    }
    return 0;
}
