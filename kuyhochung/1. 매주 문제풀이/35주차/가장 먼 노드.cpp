#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 20001
#define INF 987654321

vector < vector <int> > edges(MAX_N);
int d[MAX_N];

void bfs(int n) {
    
    for (int i = 2; i <= n; i++) {
        d[i] = INF;
    }
    d[1] = 0;
    
    queue<int> q;
    q.push(1);
    
    while(!q.empty()) {
        int now = q.front();
        int cost = 1;
        q.pop();
        
        for (int i = 0; i < edges[now].size(); i++) {
            int next = edges[now][i];
            if (d[now] + 1 < d[next]) {
                d[next] = d[now] + 1;
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i][0];
        int b = edge[i][1];
        
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    bfs(n);
    
    int maximum = 0;
    for (int i = 1; i <= n; i++) {
        maximum = max(maximum, d[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        if (d[i] == maximum) answer++;
    }
    
    return answer;
}