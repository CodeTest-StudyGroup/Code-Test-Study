#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

#define blank 0

int N, M, T;
deque<int> circle[51];
deque<int> cp_circle[51];
vector<int> cmd[51];

void rotate(int x_i, int d_i, int k_i) {
	int tmp;

	for (int i = 1; i <= N; i++) {
		if (i % x_i == 0) {

			if (d_i == 0) {
				for (int k = 0; k < k_i; k++) {
					/* 1회 시계방향 회전 */
					tmp = circle[i].back();
					circle[i].pop_back();
					circle[i].push_front(tmp);
				}
			}
			else if (d_i == 1) {
				for (int k = 0; k < k_i; k++) {
					/* 1회 반시계방향 회전 */
					tmp = circle[i].front();
					circle[i].pop_front();
					circle[i].push_back(tmp);
				}
			}

		}
	}
}

void eraser() {

	for (int i = 1; i <= 50; i++)
		cp_circle[i] = circle[i];

	bool flag = false;

	// 원래 원판을 보면서...
	for (int i = 1; i <= N; i++) {

		if (circle[i][0] != blank && circle[i][0] == circle[i][1]) {
			cp_circle[i][0] = blank;
			cp_circle[i][1] = blank;
			flag = true;
		}
		if (circle[i][0] != blank && circle[i][0] == circle[i][M - 1]) {
			cp_circle[i][0] = blank;
			cp_circle[i][M - 1] = blank;
			flag = true;
		}
		if (circle[i][M - 1] != blank && circle[i][M - 1] == circle[i][M - 2]) {
			cp_circle[i][M - 1] = blank;
			cp_circle[i][M - 2] = blank;
			flag = true;
		}
		if (circle[i][M - 1] != blank && circle[i][M - 1] == circle[i][0]) {
			cp_circle[i][M - 1] = blank;
			cp_circle[i][0] = blank;
			flag = true;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M - 2; j++) {
			if (circle[i][j] != blank && circle[i][j] == circle[i][j - 1]) {
				cp_circle[i][j] = blank;
				cp_circle[i][j - 1] = blank;
				flag = true;
			}
			if (circle[i][j] != blank && circle[i][j] == circle[i][j + 1]) {
				cp_circle[i][j] = blank;
				cp_circle[i][j + 1] = blank;
				flag = true;
			}
		}
	}

	for (int j = 0; j < M; j++) {
		if (circle[1][j] != blank && circle[1][j] == circle[2][j]) {
			cp_circle[1][j] = blank;
			cp_circle[2][j] = blank;
			flag = true;
		}
	}

	for (int j = 0; j < M; j++) {
		if (circle[N][j] != blank && circle[N][j] == circle[N - 1][j]) {
			cp_circle[N][j] = blank;
			cp_circle[N - 1][j] = blank;
			flag = true;
		}
	}

	for (int i = 2; i <= N-1; i++){
		for (int j = 0; j < M; j++) {
			if (circle[i][j] != blank && circle[i][j] == circle[i - 1][j]) {
				cp_circle[i][j] = blank;
				cp_circle[i - 1][j] = blank;
				flag = true;
			}
			if (circle[i][j] != blank && circle[i][j] == circle[i + 1][j]) {
				cp_circle[i][j] = blank;
				cp_circle[i + 1][j] = blank;
				flag = true;
			}
		}
	}

	// 지우기 완료, cp_circle을 복사
	for (int i = 1; i <= 50; i++)
		circle[i] = cp_circle[i];

	int sum = 0;
	// 합 미리 구하기
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			sum += circle[i][j];
		}
	}

	if (!flag) {
		// 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수는 1을 빼고, 작은 수는 1을 더한다.
		// 단, 모든 수가 0이었을 때에는 평균을 구하지 않도록 한다.
		double ave = 0;
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				if (circle[i][j] > blank) {
					cnt += 1;
				}
			}
		}
		// 총합 sum 구하기 완료
		ave = (double)sum / cnt;

		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				if (circle[i][j] > blank && circle[i][j] < ave) {
					circle[i][j] += 1;
				}
				else if (circle[i][j] > blank && circle[i][j] > ave) {
					circle[i][j] -= 1;
				}
			}
		}
	}
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			int input;
			cin >> input;
			circle[i].push_back(input);
		}
	}

	for (int i = 0; i < T; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		cmd[i] = { a,b,c };
	}

	// 먼저 명령대로 회전시켜 본다.
	for (int i = 0; i < T; i++) {
		rotate(cmd[i][0], cmd[i][1], cmd[i][2]);
		eraser();
	}

	// 원판의 모든 숫자 합 출력
	int res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (circle[i][j] != blank)
				res += circle[i][j];
		}
	}

	cout << res;

	return 0;
}