#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, X;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> X;
			// 큐의 사이즈가 N보다 작다면 X를 큐에 추가함
			if (pq.size() < N) {
				pq.push(X);
			}
			else {
				// 큐에서 제일 작은 값보다 X가 크다면
				if (pq.top() < X) {
					// 제일 작은 값을 제거하고 X를 추가
					pq.pop();
					pq.push(X);
				}
			}
		}
	}

	cout << pq.top();
}