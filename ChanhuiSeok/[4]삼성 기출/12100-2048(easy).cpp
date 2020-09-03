#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

/* 2048(Easy) 문제 */

int N;
int maxValue;
vector<string> seq;

int arr[25][25];

// 보드판에서 가장 큰 블록을 찾는 함수
int maxBlock() {
	int temp = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (temp < arr[i][j])
				temp = arr[i][j];
		}
	}
	return temp;
}

// 테스트용 출력 함수
void printArr() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void simul(int cnt) {

	if (cnt == 5) {
		maxValue = max(maxValue, maxBlock());
		return;
	}

	// 원래 값 복사해 두기
	int cpArr[25][25];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cpArr[i][j] = arr[i][j];
		}
	}

	//4가지 방향
	for (int dir = 0; dir < 4; dir++) {

		// 위
		if (dir == 0) {
			// 먼저 위로 다 옮겨놓기
			for (int col = 0; col < N; col++) {
				for (int row = 1; row < N; row++) {
					int tRow = row;
					while (tRow - 1 >= 0 && arr[tRow - 1][col] == 0) {
						arr[tRow - 1][col] = arr[tRow][col];
						arr[tRow][col] = 0;
						tRow -= 1;
					}
				}
			}

			// 합칠 수 있는 건 위쪽으로 합치고 다른 것은 0으로 바꾸기
			for (int col = 0; col < N; col++) {
				for (int row = 0; row < N; row++) {
					if (arr[row][col] == arr[row + 1][col]) {
						arr[row][col] *= 2;
						arr[row + 1][col] = 0;
					}
				}
			}

			// 다시 위로 다 옮기기
			for (int col = 0; col < N; col++) {
				for (int row = 1; row < N; row++) {
					int tRow = row;
					while (tRow - 1 >= 0 && arr[tRow - 1][col] == 0) {
						arr[tRow - 1][col] = arr[tRow][col];
						arr[tRow][col] = 0;
						tRow -= 1;
					}
				}
			}

			maxValue = max(maxValue, maxBlock());
			// simul 재귀 진행
			simul(cnt + 1);

			// 원래로 값 바꾸기
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					arr[i][j] = cpArr[i][j];
				}
			}
		}

		// 아래
		else if (dir == 1) {
			// 먼저 아래로 다 옮겨놓기
			for (int col = 0; col < N; col++) {
				for (int row = N - 2; row >= 0; row--) {
					int tRow = row;
					while (tRow + 1 < N && arr[tRow + 1][col] == 0) {
						arr[tRow + 1][col] = arr[tRow][col];
						arr[tRow][col] = 0;
						tRow += 1;
					}
				}
			}

			// 합칠 수 있는 건 아래쪽으로 합치고 다른 것은 0으로 바꾸기
			for (int col = 0; col < N; col++) {
				for (int row = N - 1; row > 0; row--) {
					if (arr[row][col] == arr[row - 1][col]) {
						arr[row][col] *= 2;
						arr[row - 1][col] = 0;
					}
				}
			}

			// 다시 아래로 다 옮기기
			for (int col = 0; col < N; col++) {
				for (int row = N - 2; row >= 0; row--) {
					int tRow = row;
					while (tRow + 1 < N && arr[tRow + 1][col] == 0) {
						arr[tRow + 1][col] = arr[tRow][col];
						arr[tRow][col] = 0;
						tRow += 1;
					}
				}
			}

			maxValue = max(maxValue, maxBlock());
			simul(cnt + 1);

			// 원래로 값 바꾸기
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					arr[i][j] = cpArr[i][j];
				}
			}

		}
		// 왼쪽
		else if (dir == 2) {
			// 먼저 왼쪽으로 다 옮겨놓기
			for (int row = 0; row < N; row++) {
				for (int col = 1; col < N; col++) {
					int tCol = col;
					while (tCol - 1 >= 0 && arr[row][tCol - 1] == 0) {
						arr[row][tCol - 1] = arr[row][tCol];
						arr[row][tCol] = 0;
						tCol -= 1;
					}
				}
			}

			// 합칠 수 있는건 왼쪽으로 합치기
			for (int row = 0; row < N; row++) {
				for (int col = 0; col < N; col++) {
					if (arr[row][col] == arr[row][col + 1]) {
						arr[row][col] *= 2;
						arr[row][col + 1] = 0;
					}
				}
			}

			for (int row = 0; row < N; row++) {
				for (int col = 1; col < N; col++) {
					int tCol = col;
					while (tCol - 1 >= 0 && arr[row][tCol - 1] == 0) {
						arr[row][tCol - 1] = arr[row][tCol];
						arr[row][tCol] = 0;
						tCol -= 1;
					}
				}
			}

			maxValue = max(maxValue, maxBlock());
			simul(cnt + 1);

			// 원래로 값 바꾸기
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					arr[i][j] = cpArr[i][j];
				}
			}
		}
		// 오른쪽
		else if (dir == 3) {

			// 먼저 오른쪽으로 다 옮겨놓기
			for (int row = 0; row < N; row++) {
				for (int col = N-2; col >= 0; col--) {
					int tCol = col;
					while (tCol + 1 < N && arr[row][tCol + 1] == 0) {
						arr[row][tCol + 1] = arr[row][tCol];
						arr[row][tCol] = 0;
						tCol += 1;
					}
				}
			}

			// 합칠 수 있는건 오른쪽으로 합치기
			for (int row = 0; row < N; row++) {
				for (int col = N-1; col > 0; col--) {
					if (arr[row][col] == arr[row][col - 1]) {
						arr[row][col] *= 2;
						arr[row][col - 1] = 0;
					}
				}
			}

			for (int row = 0; row < N; row++) {
				for (int col = N - 2; col >= 0; col--) {
					int tCol = col;
					while (tCol + 1 < N && arr[row][tCol + 1] == 0) {
						arr[row][tCol + 1] = arr[row][tCol];
						arr[row][tCol] = 0;
						tCol += 1;
					}
				}
			}
			
			maxValue = max(maxValue, maxBlock());
			simul(cnt + 1);

			// 원래로 값 바꾸기
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					arr[i][j] = cpArr[i][j];
				}
			}
		}
	}
}


int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	//최대 5번의 이동
	simul(0);

	cout << maxValue;

	return 0;
}