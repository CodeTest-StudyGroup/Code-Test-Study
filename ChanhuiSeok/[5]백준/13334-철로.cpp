#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
// 블로그에 포스팅해서 정리할 만한 문제인 것 같다.
// 참고로 라인 스위핑은 priority_queue를 많이 사용한다고 한다.

#define pii pair<int, int>

vector<pair<int, int>> input;

int n, d;

struct comp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		/* priority_queue는 comp를 정의 시, 일반적인 sort에서 comp함수 정의때와
		정반대로 쓰면 된다. 오름차순을 아래처럼 작성했다. */
		if (a.second == b.second) {
			return a.first > b.first;
		}
		return a.second > b.second;
	}
};

priority_queue<pii, vector<pii>, comp> inputQ;
priority_queue<int, vector<int>, greater<int>> pq;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else if (a.second == b.second) {
		return a.first < b.first;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int h, o;
		cin >> h >> o;
		if (h > o)inputQ.push({ o,h });
		else inputQ.push({ h,o });
	}
	cin >> d;

	int maxSize = 0;

	// n개만큼 살펴본다.
	while (!inputQ.empty()) {
		int iR = inputQ.top().second;
		int iL = inputQ.top().first;
		inputQ.pop();

		// iR-iL 사이즈가 d보다 작으면 일단 가능한 후보니까 그 왼쪽 끝점을 넣는다.
		if (iR - iL <= d) {
			pq.push(iL);
		}

		while (!pq.empty()) {
			// 가능한 왼쪽 시작점 후보들이 있는 pq 에서 하나를 뽑아서
			// 현재 살펴보고 있는 n번째 인풋의 오른쪽 끝값과의 거리를 계산하고
			// 그 거리가 d 이하이면 나가서 다른 인풋을 계속 보며
			// d 보다 큰 거리이면 가능한 왼쪽 시작점 후보에서 그것을 빼버린다.
			int tmp = pq.top();
			if (iR - tmp <= d) break;
			else 
				pq.pop();		
		}
		maxSize = max(maxSize, (int)pq.size());
	}

	cout << maxSize;

	return 0;
}