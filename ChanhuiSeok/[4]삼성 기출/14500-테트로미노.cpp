#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#include <string>

using namespace std;

int board[501][501];
int mode[5] = { 1,2,3,4,5 };
// 긴 가로, 긴 세로, 정사각형, 6칸 사각형 가로, 6칸 사각형 세로

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	// 크기가 N X M인 종이 위에 테트로미노 하나 놓기
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	// 테트로미노 하나를 적절히 놓아서 놓인 칸에 쓰여있는 수들의 합이
	// 최대가 되는 경우를 구한다.
	// 테트로미는 5가지 종류의 모양이 존재한다.


	// type은 크게 4가지로 본다
	int MODE, k = 0, maxV = -1;
	while (k<5) {
		MODE = mode[k++];

		// 가로로 긴 4칸
		if (MODE == 1) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M - 3; j++) {
					int a, b, c, d;
					a = board[i][j];
					b = board[i][j + 1];
					c = board[i][j + 2];
					d = board[i][j + 3];

					maxV = max(maxV, a + b + c + d);
				}
			}
		}

		// 세로로 긴 4칸
		else if (MODE == 2) {
			for (int i = 0; i < N - 3; i++) {
				for (int j = 0; j < M; j++) {
					int a, b, c, d;
					a = board[i][j];
					b = board[i + 1][j];
					c = board[i + 2][j];
					d = board[i + 3][j];
					maxV = max(maxV, a + b + c + d);
				}
			}
		}

		// 정사각형
		else if (MODE == 3) {
			for (int i = 0; i < N - 1; i++) {
				for (int j = 0; j < M - 1; j++) {
					int a, b, c, d;
					a = board[i][j];
					b = board[i + 1][j];
					c = board[i][j + 1];
					d = board[i + 1][j + 1];
					maxV = max(maxV, a + b + c + d);
				}
			}
		}

		// 가로 방향 6칸 사각형에서 가능한 2칸 빼기
		else if (MODE == 4) {
			for (int i = 0; i < N - 1; i++) {
				for (int j = 0; j < M - 2; j++) {
					int a, b, c, d, e, f;
					int s1, s2, s3, s4, s5, s6, s7, s8;

					a = board[i][j];
					b = board[i][j + 1];
					c = board[i][j + 2];
					d = board[i + 1][j];
					e = board[i + 1][j + 1];
					f = board[i + 1][j + 2];

					s1 = a + b + c + d;
					s2 = a + b + c + f;
					s3 = a + d + e + f;
					s4 = c + d + e + f;
					s5 = a + b + e + f;
					s6 = b + c + d + e;
					s7 = a + b + c + e;
					s8 = b + d + e + f;

					maxV = max(maxV, max(s1, max(s2, max(s3, max(s4,
						max(s5, max(s6, max(s7, s8))))))));
				}
			}
		}

		// 세로 방향 6칸 사각형에서 가능한 2칸 빼기
		else if (MODE == 5) {
			for (int i = 0; i < N - 2; i++) {
				for (int j = 0; j < M - 1; j++) {
					int a, b, c, d, e, f;
					int s1, s2, s3, s4, s5, s6, s7, s8;

					a = board[i][j];
					b = board[i][j + 1];
					c = board[i + 1][j];
					d = board[i + 1][j + 1];
					e = board[i + 2][j];
					f = board[i + 2][j + 1];

					s1 = a + c + e + f;
					s2 = b + d + e + f;
					s3 = a + b + c + e;
					s4 = a + b + d + f;
					s5 = a + c + d + f;
					s6 = b + c + d + e;
					s7 = b + c + d + f;
					s8 = a + c + d + e;

					maxV = max(maxV, max(s1, max(s2, max(s3, max(s4,
						max(s5, max(s6, max(s7, s8))))))));
				}
			}
		}
	}

	cout << maxV;

	return 0;
}