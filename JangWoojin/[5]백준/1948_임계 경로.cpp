#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, s, e;
vector<vector<pair<int, int>>> adj;
vector<bool> chk;
vector<int> cost;

void get_cost(int x) {
	for (auto next : adj[x]) {
		int nx = next.first;
		int nc = next.second;
		if (cost[nx] == 0) get_cost(nx);
		cost[x] = max(cost[x], cost[nx] + nc);
	}
}

void get_cnt(int x, int &cnt) {
	if (chk[x]) return;
	chk[x] = 1;
	for (auto next : adj[x]) {
		int nx = next.first;
		int nc = next.second;
		if (cost[x] - nc == cost[nx])
			get_cnt(nx, ++cnt);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	adj.resize(n+1);
	cost.resize(n+1);
	chk.resize(n+1);
	while (m--) {
		int s, e, c;
		cin >> s >> e >> c;
		adj[s].push_back({ e, c });
	}
	cin >> s >> e;

	int cnt = 0;
	get_cost(s);
	get_cnt(s, cnt);

	cout << cost[s] << endl << cnt << endl;
	return 0;
}