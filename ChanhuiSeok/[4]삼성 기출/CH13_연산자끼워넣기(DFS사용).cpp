#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int oper[4];
int A[11];
int N;

int maxV = -987654321;
int minV = 987654321;

// 연산자 사용 갯수와, 결과값이 각각 인자로..
void dfs(int cnt, int res) {

	// 연산자를 다 썼을 경우
	if (cnt == N) {
		maxV = max(maxV, res);
		minV = min(minV, res);
		return;
	}

	else {
		// 덧셈
		if (oper[0] > 0) {	
			oper[0] -= 1;
			dfs(cnt + 1, res + A[cnt]);
			oper[0] += 1;
		}
		if (oper[1] > 0) {
			oper[1] -= 1;
			dfs(cnt + 1, res - A[cnt]);
			oper[1] += 1;
		}
		if (oper[2] > 0) {
			oper[2] -= 1;
			dfs(cnt + 1, res * A[cnt]);
			oper[2] += 1;
		}
		if (oper[3] > 0) {
			oper[3] -= 1;
			dfs(cnt + 1, res / A[cnt]);
			oper[3] += 1;
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int input;
	int tempA[11];

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i]; // 각 연산자의 갯수
	}

	dfs(1, A[0]);

	cout << maxV << '\n';
	cout << minV;

	return 0;
}