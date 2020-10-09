#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <string>
#include <map>
#include <cstring>

using namespace std;

#define pii pair<int,int>

int parent[100001];
int sizes[100001];

vector<pair<long long, pii>> node;

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);

	parent[b] = a;
	sizes[a] += sizes[b];
}

bool cmp(const pair<int, pii>& a, const pair<int, pii>& b) {
	return a.first > b.first;
}

int N, M;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		long long x, y, w;
		cin >> x >> y >> w;
		node.push_back({ w, { x,y } }); // x-y 사이 가중치 w
	}

	// 부모 배열 및 크기 초기화
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		sizes[i] = 1;
	}

	// u-v 로 갈 수 있으면, 그래프의 최소 간선부터 지우면서
	// 계속 u-v로 갈 수 있는지 파악한다.

	// 가중치 내림차순 정렬
	sort(node.begin(), node.end(), cmp);

	// 1개부터 n개 간선까지의 가중치 합 저장
	long long sum_all = 0;
	for (int i = 0; i < node.size(); i++) {
		sum_all += node[i].first;
	}

	// 간선을 한개씩 선택하면서 계산
	// 선택된 간선의 가중치는 누적해 놓는다.
	long long result = 0;
	long long selected = 0;
	for (int k = 0; k < node.size(); k++) {

		long long a = node[k].second.first;
		long long b = node[k].second.second;
		long long w = node[k].first;

		// a와 b 합집합하기
		// 단, a와 b가 다른 집합이었을 경우에만
		if (find(a) != find(b)) {
			// 값 계산하기
			// 합치기 전 (a 집합 사이즈) * (b 집합 사이즈) * (가중치 총합 - 이미 선택된 가중치 합) 계산
			long long a_size = sizes[parent[a]];
			long long b_size = sizes[parent[b]];
			result += (((a_size * b_size) % 1000000000) * (sum_all - selected)) % 1000000000;

			unite(a, b);
		}
		selected += w;
	}

	cout << result % 1000000000;

	return 0;
}