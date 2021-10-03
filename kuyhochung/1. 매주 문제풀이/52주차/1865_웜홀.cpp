#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 501
#define INF 1e8

int testCase;
int n, m, w;
int s, e, t;
int dist[MAX_N];

bool bellman_ford (int n, vector <vector <pair <int, int> > > &nodes) {
    for (int i = 2; i <= n; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < nodes.size(); j++) {
            for (int k = 0; k < nodes[j].size(); k++) {
                //from: j
                //to: nodes[j][k].first
                //time: nodes[j][k].second
                if (dist[nodes[j][k].first] > dist[j] + nodes[j][k].second) {
                    dist[nodes[j][k].first] = dist[j] + nodes[j][k].second;
                }
            }
        }
    }
    
    for (int j = 0; j < nodes.size(); j++) {
        for (int k = 0; k < nodes[j].size(); k++) {
            //from: j
            //to: nodes[j][k].first
            //time: nodes[j][k].second
            if (dist[nodes[j][k].first] > dist[j] + nodes[j][k].second) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testCase;
    
    while(testCase--) {
        //지점의 수, 도로의 개수, 웜홀의 개수
        cin >> n >> m >> w;
        
        vector<vector<pair <int, int> > > nodes(n+1);
        
        //노드 간 도로 및 웜홀에 대한 정보 입력
        for (int i = 0; i < m; i++) {
            cin >> s >> e >> t;
            nodes[s].push_back({e, t});
            nodes[e].push_back({s, t});
        }
        for (int i = 0; i < w; i++) {
            cin >> s >> e >> t;
            nodes[s].push_back({e, -t});
        }
        
        if (bellman_ford(n, nodes)) cout << "YES\n"; else cout << "NO\n";
    }
    
    return 0;
}