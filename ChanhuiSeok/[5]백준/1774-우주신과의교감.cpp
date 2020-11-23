#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

int N, M;

vector<pii> node;
deque<pair<double, pii>> path;

int parent[1001];

int finds(int a) {
	if (parent[a] == a) return a;
	return parent[a] = finds(parent[a]);
}

void unite(int a, int b) {
	a = finds(a);
	b = finds(b);
	if (a == b) return;
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

double getDist(int x1, int y1, int x2, int y2) {
	double xs = pow((x2 - x1), 2);
	double ys = pow((y2 - y1), 2);
	return sqrt(xs + ys);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	node.resize(N + 1);

	// parent 초기화
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		node[i].first = a; node[i].second = b;
	}

	// 미리 연결해 놓기
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		if (finds(a) != finds(b)) unite(a, b);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {

			pair<int, int> a = node[i];
			pair<int, int> b = node[j];
			double dist = getDist(a.first, a.second, b.first, b.second);

			// i - j 연결 관계, dist 거리를 가짐
			path.push_back({ dist,{i, j} });
		}
	}

	// path를 거리순으로 정렬
	sort(path.begin(), path.end());
	
	double cost = 0;

	// path의 맨 앞부터 결합하면서 (최소) 신장 트리를 만든다.
	// 선택된 간선의 갯수가 정점의 갯수 -1이 된다.
	for (int i = 0; i < path.size(); i++) {
		int a = path[i].second.first;
		int b = path[i].second.second;
		double dist = path[i].first;

		// 부모가 다를 경우 합치기 가능
		if (finds(a) != finds(b)) {
			unite(a, b);
			cost += dist;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << cost;

	return 0;
}