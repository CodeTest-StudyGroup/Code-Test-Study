#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <set>

using namespace std;
#define MAX 1000000

int n, m;
int dist[1001]; // 최단 거리
int parent[1001]; // 경로를 담을 배열
typedef pair<int, int> p;
vector<p> arr[1001];
set<string> s;

void Dijkstra(int start) {
    memset(dist, MAX, sizeof(dist));
    priority_queue<p, vector<p>, greater<p> > pq;
    pq.push(p(0, start));
    dist[start] = 0;
    
    parent[start] = 0;

    while(!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();

        for(int i=0 ; i<arr[cur].size() ; i++) {
            int next = arr[cur][i].first;
            if(dist[next] > dist[cur] + arr[cur][i].second) {
                dist[next] = dist[cur] + arr[cur][i].second;
                pq.push(p(dist[next], next));
                parent[next] = cur; // 도착 경로를 계속 갱신(next에 오는 최단경로는 cur이므로)
            }
        }
    }

    // 경로를 거슬러 올라가면서 set에 경로를 넣어준다(중복 제거)
    for(int i=2 ; i<=n ; i++) {
        int now = i;
        while(parent[now] != 0) {
            string temp = to_string(now) + " " + to_string(parent[now]);
            s.insert(temp); // 출력은 임의의 순서
            now = parent[now];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    for(int i=0 ; i<m ; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        arr[a].push_back(p(b, c));
        arr[b].push_back(p(a, c));
    }

    Dijkstra(1);
    
    set<string>::iterator it;
    cout << s.size() << "\n";
    for(it=s.begin() ; it!=s.end() ; it++) {
        cout << *it << "\n";
    }
    
    return 0;
}