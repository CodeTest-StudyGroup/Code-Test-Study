#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 1001

int n, m, k;
vector<int> powerplants;
priority_queue<pair <int, pair <int, int> > > pq;
int parents[MAX_N];
int total = 0;

int get_parents(int x) {
    if (parents[x] != x)
        parents[x] = get_parents(parents[x]);
    return parents[x];
}

void make_union(int x, int y) {
    x = get_parents(x);
    y = get_parents(y);
    
    if (y > x) parents[y] = x;
    else parents[x] = y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i++) {
        parents[i] = i;
    }
    
    for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        powerplants.push_back(temp);
    }
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        pq.push({-cost, {from, to}});
    }
    
    for (int i = 0; i < powerplants.size() - 1; i++) {
        for (int j = i+1; j < powerplants.size(); j++) {
            make_union(powerplants[i], powerplants[j]);
        }
    }
    
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int from = pq.top().second.first;
        int to = pq.top().second.second;
        pq.pop();
        
        if (get_parents(from) != get_parents(to)) {
            make_union(from, to);
            total += cost;
        }
    }
    cout << total;
    return 0;
}
