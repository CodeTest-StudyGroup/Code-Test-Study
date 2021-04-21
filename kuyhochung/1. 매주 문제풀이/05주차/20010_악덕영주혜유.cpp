#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
#define MAX_N 1000001
#define MAX_T 1001
struct node {
    int start, end, weight;
};
struct cmp {
    bool operator() (node &a, node &b) {
        return a.weight > b.weight;
    }
};
int N, K;
int parent[MAX_N] = {0, };
bool check[MAX_T];
int min_cost = 0;
int max_distance = -1;
priority_queue<node, vector<node> , cmp> pq;
vector<int> v [MAX_T];
int cost[MAX_T][MAX_T];

int find_parent(int a) {
    if (parent[a] == a)
        return a;
    else
        return parent[a] = find_parent(parent[a]);
}

void make_union(int a, int  b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a > b)
        parent[a] = b;
    else if (b > a)
        parent[b] = a;
}

void kruskal() {
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
    priority_queue<node, vector<node>, cmp> node_list;
    node_list = pq;
    
    while (!node_list.empty()) {
        int start = node_list.top().start;
        int end = node_list.top().end;
        int weight = node_list.top().weight;
        node_list.pop();
        int parent_start = find_parent(start);
        int parent_end = find_parent(end);
        if (parent_start == parent_end)
            continue;
        make_union(start, end);
        min_cost += weight;
        v[start].push_back(end);
        v[end].push_back(start);
        cost[start][end] = weight;
        cost[end][start] = weight;
    }
}

void bfs(int start) {
    memset(check, false, sizeof(check));
    queue <pair <int,int> > q;
    q.push(make_pair(start, 0));
    check[start] = true;
    while(!q.empty()) {
        int now = q.front().first;
        int dist = q.front().second;
        q.pop();
        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            int pre_dist = dist + cost[now][next];
            if (check[next]) continue;
            check[next] = true;
            q.push(make_pair(next, pre_dist));
            max_distance = max(max_distance, pre_dist);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int a, b, w;
    cin >> N >> K;
    
    for (int i = 0; i < K; i++) {
        cin >> a >> b >> w;
        make_union(a, b);
        node temp;
        temp.start = a;
        temp.end = b;
        temp.weight = w;
        pq.push(temp);

    }
    
    kruskal();
    cout << min_cost << '\n';
    for (int i = 0; i < N; i++)
    bfs(i);
    cout << max_distance;
    
    return 0;
}
