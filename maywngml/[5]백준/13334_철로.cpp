#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
//도착지점 오름차순으로 정렬, 도착지점 같으면 출발지점 오름차순으로 정렬
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)
			return a.first > b.first;
		else
			return a.second > b.second;
	}
};

int main() {
	int n, d, x, y;
	int answer = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	//오름차순으로 정렬된 임시큐
	priority_queue<int, vector<int>, greater<int>> temp;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x > y)
			swap(x, y);
		pq.push({ x, y });
	}
	cin >> d;
	
	while (!pq.empty()) {
		int start = pq.top().first;
		int end = pq.top().second;
		pq.pop();
		//출발지점과 도착지점이 철로안에 들어갈 시 출발지점 임시큐에 넣음
		if (end - start <= d)
			temp.push(start);
		while (!temp.empty()) {
			//임시큐내 모든 원소의 출발지점이 철로안에 들어가면 반복문 종료
			//오름차순으로 정렬되었기에 앞의 원소만 확인
			if (end - temp.top() <= d)
				break;
			//출발지점이 철로안에 들어가지 못할 시 임시큐에서 제거함
			else
				temp.pop();
		}
		//최대값 갱신
		answer = max(answer, int(temp.size()));
	}

	cout << answer;
}
