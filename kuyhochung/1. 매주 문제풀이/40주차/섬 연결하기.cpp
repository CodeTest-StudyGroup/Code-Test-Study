#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_N 101

int parent[MAX_N];

int get_parent(int x) {
    if (parent[x] != x) parent[x] = get_parent(parent[x]);
    return parent[x];
}

void make_union(int x, int y) {
    x = get_parent(x);
    y = get_parent(y);
    
    if (y > x)
        parent[y] = x;
    else parent[x] = y;
}

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    sort(costs.begin(), costs.end(), cmp);
    
    for (int i = 0; i < costs.size(); i++) {
        int node_a = costs[i][0];
        int node_b = costs[i][1];
        int cost = costs[i][2];
        
        if (get_parent(node_a) != get_parent(node_b)) {
            make_union(node_a, node_b);
            answer += cost;
        }
    }
    
    return answer;
}