#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <map>
#include <stack>
#include <string>

using namespace std;

int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };

int board[21][21];
pair<int, int> smell[21][21];

typedef struct shark {
	int isDead;
	int dir;
	int y;
	int x;
	int rank[5][4];
}Shark;

Shark shark[401];
int N, M, k; // N은 격자 크기, M은 상어 수, k는 상어가 k번 이동하고 나면 냄새가 사라지는 수

bool valid(int y, int x) {

	if (y < 0 || x < 0 || y >= N || x >= N) {
		return false;
	}
	return true;
}

// 일괄적으로 모든 칸의 냄새를 1 감소시키는 함수
void remove_smell() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0 && smell[i][j].second > 0) {
				smell[i][j].second -= 1;

				if (smell[i][j].second == 0) {
					smell[i][j].first = 0;
				}
			}
		}
	}
}


// 모든 상어가 움직이는 함수
void moving() {
	// 1. 기본적으로 상어는 상,하,좌,우 중 인접한 칸으로 이동한다. 
	// 단, 이동하는 방향을 기준으로 아무 냄새가 없는 칸으로 이동한다.
	// 2. 상,하,좌,우 다 우선순위대로 둘러보면서 냄새가 없는 칸이 없었으면
	// 상,하,좌,우 중 자기 냄새가 있던 칸으로 이동한다.

	// 모든 상어에 대해서 이동시키기
	// 이 모든 과정을 진행하는 데 1초 소요된다고 가정
	for (int i = 1; i <= M; i++) {
		int dir = shark[i].dir; // i번 상어의 방향
		int y = shark[i].y;
		int x = shark[i].x;

		bool isFind = false;

		// 죽지 않은 상어들에 대해서만 진행
		if (shark[i].isDead == false) {
			// 보는 방향 기준 4가지 우선순위로 인접한 칸을 살펴본다.
			for (int j = 0; j < 4; j++) {
				int f_dir = shark[i].rank[dir][j]; // 보는 방향 기준 우선순위
				int ty = y + dy[f_dir];
				int tx = x + dx[f_dir];

				// 경계를 벗어나지 않았을 경우 && 냄새가 없었을 경우
				if (valid(ty, tx) && smell[ty][tx].second == 0) {
					// 아직 냄새는 새기지 말고, 그 자리에 상어를 이동시켜 본다.
					// 이 자리에 또 상어가 올 수 있으므로

					// 다른 상어가 있을 경우, 상어 번호를 비교한다.
					if (board[ty][tx] != 0) {

						// 가고자 했던 자리의 상어보다 내 번호가 작을 경우
						// 내 번호가 그 자리를 치고 들어간다.
						// 그리고 원래 그 자리에 있던 상어는 없애버린다.
						if (board[ty][tx] > i) {
							board[y][x] = 0; // 이동 전은 빈 칸으로 바꿈

							board[ty][tx] = i;
							shark[i].y = ty;
							shark[i].x = tx;
							shark[board[ty][tx]].isDead = true;
							isFind = true;

							// 이동한 상어의 보는 방향을 바꾼다.
							shark[i].dir = f_dir;
						}

						// 가고자 했던 자리의 상어보다 내 번호가 클 경우
						// 상어 나 자신을 죽게 한다.
						else if (board[ty][tx] < i) {
							board[y][x] = 0;
							shark[i].isDead = true;
							isFind = true;
							break;
						}
					}

					// 가려고 하는 칸에 아무 상어도 없었을 경우
					else {
						board[y][x] = 0; // 이동 전은 빈 칸으로 바꿈
						board[ty][tx] = i;
						shark[i].y = ty;
						shark[i].x = tx;
						isFind = true;

						// 이동한 상어의 보는 방향을 바꾼다.
						shark[i].dir = f_dir;
					}

					break; // 이동을 했으므로 다음 상어로 넘어간다.
				}
			}


			// 상,하,좌,우 모두 빈 칸은 없었을 경우, i번 상어의 냄새가 있는 곳으로 이동
			if (!isFind) {
				// 자신의 냄새가 있는 곳을 다시 찾는다.
				for (int j = 0; j < 4; j++) {
					int f_dir = shark[i].rank[dir][j]; // 보는 방향 기준 우선순위
					int ty = y + dy[f_dir];
					int tx = x + dx[f_dir];

					// 자신의 번호와 같을 경우
					if (valid(ty, tx) && smell[ty][tx].first == i) {
						board[y][x] = 0; // 이동 전은 빈 칸으로 바꿈
						board[ty][tx] = i;
						shark[i].y = ty;
						shark[i].x = tx;

						// 이동한 상어의 보는 방향을 바꾼다.
						shark[i].dir = f_dir;
						break;
					}
				}
			}
		}
	}

	// 이동이 모두 끝났으면, 새로 이동한 상어가 있는 지점에 냄새를 남긴다.
	for (int i = 1; i <= M; i++) {
		// 죽지 않은 상어들에 대해서만 시행한다.
		if (shark[i].isDead == false) {
			int y = shark[i].y;
			int x = shark[i].x;

			smell[y][x].first = i;
			smell[y][x].second = k;
		}
	}
}

int simulation() {

	int time = 0; // 0초에 시작

	while (time <= 1000) {

		// 격자에 1번 상어만 있는지 확인
		bool flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] != 0 && board[i][j] != 1) {
					flag = true; // 다른게 있다
					break;
				}
			}
		}
		if (!flag) break;

		// 상어를 이동시키고, 냄새를 남긴다.
		moving();

		// 상어가 없는 곳의 모든 냄새 1씩 제거
		
		remove_smell();

		// 여기까지가 1초 경과
		time += 1;	
	}

	if (time > 1000)
		return -1;
	
	return time;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) {
				shark[board[i][j]].y = i;
				shark[board[i][j]].x = j;
			}
		}
	}


	// 각 상어의 초기 방향	

	for (int i = 1; i <= M; i++) {
		int input;
		cin >> input;
		shark[i].dir = input;
	}

	// 상어의 번호는 1번부터
	for (int i = 1; i <= M; i++) {
		for (int k = 1; k <= 4; k++) {
			for (int j = 0; j < 4; j++) {
				cin >> shark[i].rank[k][j];
			}
		}
	}

	// 초기에 상어가 주어졌을 때 냄새가 있다고 가정
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 0) {
				smell[i][j] = make_pair(board[i][j], k);
			}
		}
	}

	int res = simulation();
	cout << res;

	return 0;
}