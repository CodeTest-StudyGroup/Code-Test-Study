#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

typedef struct shark {
	int r;
	int c;
	int dir;
	int speed;
	int size;
	bool isDead;
}Shark;

// 상어의 움직임에 따라 상어 번호를 남긴다.
int R, C, M;

int board[102][102];
int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,1,-1 };
// 위,아래,오른쪽,왼쪽

int sum_size = 0;

Shark shark[10001];

// 경계를 넘는지 확인하는 함수
bool valid(int r, int c) {
	if (r > R || r <= 0 || c > C || c <= 0)
		return false;
	return true;
}

// 방향을 반대로 바꿔주는 함수
int reverseDir(int dir) {
	if (dir == 1) return 2;
	if (dir == 2) return 1;
	if (dir == 3) return 4;
	if (dir == 4) return 3;
}

// 상어를 움직이는 함수
void moving() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			board[i][j] = 0;
		}
	}
	// board 배열에는 이동이 모두 끝나면 값이 전체적으로
	// 갱신되어 있을 것이다.

	// 모든 죽지 않은 상어에 대해서 움직이기
	for (int i = 1; i <= M; i++) {

		if (shark[i].isDead == false) {
			// 상어의 속력과 방향		
			int speed = shark[i].speed;
			int rev_speed = 0;

			// 세로 방향일 경우
			if (shark[i].dir == 1 || shark[i].dir == 2) {
				rev_speed = speed % (2 * (R - 1));
			}
			else if (shark[i].dir == 3 || shark[i].dir == 4) {
				rev_speed = speed % (2 * (C - 1));
			}

			// 속력만큼 반복문을 돌면서 1칸씩 이동시키기
			for (int k = 0; k < rev_speed; k++) {
				int r = shark[i].r;
				int c = shark[i].c;
				int dir = shark[i].dir;

				int ty, tx;

				// 경계를 넘지 않는 경우
				if (valid(r + dy[dir], c + dx[dir])) {
					ty = r + dy[dir];
					tx = c + dx[dir];
					// 그 방향 그대로 이동시킨다.
					shark[i].r = ty;
					shark[i].c = tx;
				}

				// 경계를 넘는 경우
				else {
					// 방향을 바꾼다.
					dir = reverseDir(dir);
					shark[i].dir = dir;
					ty = r + dy[dir];
					tx = c + dx[dir];

					// 그곳으로 이동시킨다.
					shark[i].r = ty;
					shark[i].c = tx;
				}
			}//end for

			// 최종 상어 위치
			int sy = shark[i].r;
			int sx = shark[i].c;

			// board에 아무 것도 없을 시
			if (board[sy][sx] == 0) {
				board[sy][sx] = i;
				// 상어 번호를 남긴다.
			}
			// 만약 가려는 칸에 나보다 크기가 작은 상어가 있었을 시,
			// 그 상어를 죽이고 내가 그곳으로 간다.
			else if (board[sy][sx] != 0 &&
				shark[board[sy][sx]].size < shark[i].size) {
				shark[board[sy][sx]].isDead = true;
				board[sy][sx] = i;
			}
			// 만약 가려는 칸에 나보다 크기가 큰 상어가 있을 시,
			// 나 자신을 dead 표기한다.
			else if (board[sy][sx] != 0 &&
				shark[board[sy][sx]].size > shark[i].size) {
				shark[i].isDead = true;
			}
		}
	}
}

// 시뮬레이션 함수
void simulation() {

	// 낚시왕이 오른쪽으로 한 칸 이동
	for (int i = 1; i <= C; i++) {

		// 낚시왕이 가장 가까운 상어를 잡음
		for (int j = 1; j <= R; j++) {

			if (board[j][i] != 0) {
				int num = board[j][i];
				int shark_size = shark[num].size;
				sum_size += shark_size;
				shark[num].isDead = true;
				board[j][i] = 0;

				break;
			}
		}

		// 상어 이동
		moving();
	}

}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> M;

	int r, c, s, d, z;
	for (int i = 1; i <= M; i++) {
		cin >> r >> c >> s >> d >> z;
		shark[i].r = r;
		shark[i].c = c;
		shark[i].dir = d;
		shark[i].speed = s;
		shark[i].isDead = false;
		shark[i].size = z;
	}

	// 상어의 수만큼 board에 상어의 번호를 표시한다.
	for (int i = 1; i <= M; i++) {
		int r = shark[i].r;
		int c = shark[i].c;
		board[r][c] = i;
	}

	// 시뮬레이션 시작
	simulation();

	cout << sum_size;

	return 0;
}