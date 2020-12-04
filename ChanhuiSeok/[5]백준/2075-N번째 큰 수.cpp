#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	/* 큐에 N개만 들어가게 한다. */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp; cin >> temp;
			
			if (pq.size() < N) 
				pq.push(temp);
			
			else if (pq.size() == N) {
				int top = pq.top();
				// 큐에서 가장 작은 값을 뺀다.
				if (temp > top) {
					pq.pop(); pq.push(temp);
				}
			}
		}
	}
	cout << pq.top();
	return 0;
}