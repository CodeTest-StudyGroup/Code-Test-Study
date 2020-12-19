#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>

#define pii pair<int, int>

using namespace std;

vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;

vector<pair<int, pii>> info;
int parent[100001];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		X.push_back({ x,i });
		Y.push_back({ y,i });
		Z.push_back({ z,i });
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for (int i = 0; i < N - 1; i++) {
		info.push_back({ X[i + 1].first - X[i].first , {X[i].second, X[i + 1].second} });
		info.push_back({ Y[i + 1].first - Y[i].first , {Y[i].second, Y[i + 1].second} });
		info.push_back({ Z[i + 1].first - Z[i].first , {Z[i].second, Z[i + 1].second} });
	}

	sort(info.begin(), info.end());

	int cnt = 0;
	int total = 0;

	for (int i = 0; i < info.size(); i++) {
		int a = info[i].second.first;
		int b = info[i].second.second;
		int val = info[i].first;

		if (find(a) != find(b)) {
			unite(a, b);
			total += val;
		}
	}

	cout << total;

	return 0;
}