#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

int sizes[100002];
int link[100002];
int arr[201][201];
vector<int> plan;

int finds(int x) {
	if (link[x] == x) return x;
	return link[x] = finds(link[x]);
}

void unite(int a, int b) {
	a = finds(a);
	b = finds(b);

	if (a != b) {
		if (sizes[a] < sizes[b]) swap(a, b);
		sizes[a] += sizes[b];
		link[b] = a;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, input;
	cin >> N; // 전체 도시의 수
	cin >> M; // 여행 계획해 속한 도시들의 수

	for (int i = 1; i <= N; i++) {
		link[i] = i;
		sizes[i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				// i와 j를 union
				unite(i, j);
			}
		}
	}

	// 여행 계획

	for (int i = 0; i < M; i++) {
		cin >> input;
		plan.push_back(input);
	}

	// 대푯값이 모두 같은지 파악
	int temp = link[plan[0]];
	bool flag = true;
	for (int i = 0; i < M; i++) {
		if (temp != link[plan[i]]) {
			flag = false;
			break;
		}
	}

	if (flag) cout << "YES";
	else cout << "NO";

	return 0;
}