#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <map>
#include <stack>
#include <string>

#define UP 1
#define LEFT_UP 2
#define LEFT 3
#define LEFT_DOWN 4
#define DOWN 5
#define RIGHT_DOWN 6
#define RIGHT 7
#define RIGHT_UP 8
#define EMPTY -1
#define SHARK_NUM 30

using namespace std;

int dy[] = {0, -1,-1,0,1,1,1,0,-1 };
int dx[] = {0, 0,-1,-1,-1,0,1,1,1 };

typedef struct fish {
	int y;
	int x;
	int dir;
	bool isDead;
}Fish;

int dfs(int origin_board[][4], Fish origin_fish[17], int y, int x, int dir) {

	// 원래값 복구용
	int board[4][4];
	Fish fish[17];

	int total = 0;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			board[i][j] = origin_board[i][j];

	for (int i = 0; i <= 16; i++)
		fish[i] = origin_fish[i];

	// 상어를 (y, x)에 놓을 것이며 이에 해당하는 (먹은) 번호 수 증가
	// 따라서 현재 상어의 위치는 y, x 이다.
	total = board[y][x];

	// 방향은 원래 그 자리에 있던 물고기의 방향을 그대로 따른다.
	dir = fish[board[y][x]].dir;

	// (y, x) 자리에 있던 물고기는 죽는다.
	fish[board[y][x]].isDead = true;
	fish[board[y][x]].y = -1;
	fish[board[y][x]].x = -1;

	// board에서 죽은 칸을 지운다.
	board[y][x] = 0;

	// 모든 물고기에 대해서 이동을 시켜본다.
	for (int i = 1; i <= 16; i++) {

		bool flag = false;
		// 죽지 않은 물고기에 대해서만 이동을 시켜본다.
		if (fish[i].isDead == false) {
			int ay, ax;
			// 물고기는 갈 수 없는 방향이 나오면 8방향 모두 돌아본다.
			for (int k = 0; k < 8; k++) {
				ay = fish[i].y + dy[fish[i].dir];
				ax = fish[i].x + dx[fish[i].dir];

				// 물고기가 가려고 하는 곳이 상어인 경우
				if (ay == y && ax == x) {
					// 다음 방향으로 가본다.
					fish[i].dir = (fish[i].dir) % 8 + 1;
					continue;
				}

				// 범위 바깥일 경우
				if (ay >= 4 || ay < 0 || ax >= 4 || ax < 0) {
					// 다음 방향으로 가본다.
					fish[i].dir = (fish[i].dir) % 8 + 1;
					continue;
				}

				// 갈 수 있을 경우
				flag = true;
				break;
			}

			// 8방향 모두 돌아보고 갈 수 있는 길이 있었을 경우
			if (flag) {

				// 가고자 하는 곳이 빈 칸이었을 경우
				// 그냥 그 자리에 물고기를 놓으면 된다.
				if (board[ay][ax] == 0) {
					board[fish[i].y][fish[i].x] = 0;
					fish[i].y = ay;
					fish[i].x = ax;
					board[ay][ax] = i;
				}

				// 가고자 하는 곳(ay, ax)에 물고기가 있었을 경우
				// 서로 자리를 바꿔 준다.
				else if (board[ay][ax] != 0) {
					int ty, tx, tDir, tmp;
					tx = fish[i].x;
					ty = fish[i].y;
					//tDir = fish[i].dir;

					fish[i].x = ax;
					fish[i].y = ay;

					fish[board[ay][ax]].x = tx;
					fish[board[ay][ax]].y = ty;
					//fish[board[ay][ax]].dir = tDir;

					board[ty][tx] = board[ay][ax];
					board[ay][ax] = i;

				}
			}
		}
	}

	// 모두 이동한 다음 상어를 이동시켜 본다.
	int sy = y + dy[dir];
	int sx = x + dx[dir];

	int ans = 0;

	// 그 방향으로 상어가 이동 가능할 때까지
	while (!(sy < 0 || sy >= 4 || sx < 0 || sx >= 4)) {
		// 상어가 이동할 다음 칸이 빈 칸이 아닐 경우
		if (board[sy][sx] != 0) {
			ans = max(ans, dfs(board, fish, sy, sx, dir));
		}
		sy = sy + dy[dir];
		sx = sx + dx[dir];
	}

	return total + ans;
}


int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	Fish fish[17];
	int board[4][4];
	int a, b;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a >> b; // a는 번호, b는 방향
			fish[a].dir = b;
			fish[a].y = i;
			fish[a].x = j;
			fish[a].isDead = false;
			board[i][j] = a;
		}
	}
	// 물고기 정보 완료

	int ans = dfs(board, fish, 0, 0, 0);

	cout << ans;

	return 0;
}