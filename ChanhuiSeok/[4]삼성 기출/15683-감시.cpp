#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#include <string>
#include <cstring>

#define FULL 8

using namespace std;

int N, M;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int minV = 987654321;

bool valid(int y, int x, int board[][10]) {
	if (y <= 0 || x <= 0 || y > N || x > M || board[y][x] == 6) {
		return false;
	}
	return true;
}

void retarr(int target_boar[][10], int origin_board[][10]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			target_boar[i][j] = origin_board[i][j];
		}
	}
}

void UP(int board[][10], int i, int j) {
	int ty = i - 1;
	int tx = j;
	while (valid(ty, tx, board) && ty > 0) {
		// 0이나 6이 아닌 다른 숫자였을 경우 - 다른 CCTV
		if (board[ty][tx] != 0 && board[ty][tx] != 6) {
			ty -= 1;
			continue;
		}
		// 빈 칸이었을 경우
		else if (board[ty][tx] == 0) {
			board[ty][tx] = FULL;
			ty -= 1;
		}
	}
}

void DOWN(int board[][10], int i, int j) {
	int ty = i + 1, tx = j;
	while (valid(ty, tx, board) && ty <= N) {
		// 0이나 6이 아닌 다른 숫자였을 경우 - 다른 CCTV
		if (board[ty][tx] != 0 && board[ty][tx] != 6) {
			ty += 1;
			continue;
		}
		// 빈 칸이었을 경우
		else if (board[ty][tx] == 0) {
			board[ty][tx] = FULL;
			ty += 1;
		}
	}
}

void LEFT(int board[][10], int i, int j) {
	int ty = i, tx = j - 1;
	while (valid(ty, tx, board) && tx > 0) {
		// 0이나 6이 아닌 다른 숫자였을 경우 - 다른 CCTV
		if (board[ty][tx] != 0 && board[ty][tx] != 6) {
			tx -= 1;
			continue;
		}
		// 빈 칸이었을 경우
		else if (board[ty][tx] == 0) {
			board[ty][tx] = FULL;
			tx -= 1;
		}
	}
}

void RIGHT(int board[][10], int i, int j) {
	int ty = i, tx = j + 1;
	while (valid(ty, tx, board) && tx <= M) {
		// 0이나 6이 아닌 다른 숫자였을 경우 - 다른 CCTV
		if (board[ty][tx] != 0 && board[ty][tx] != 6) {
			tx += 1;
			continue;
		}
		// 빈 칸이었을 경우
		else if (board[ty][tx] == 0) {
			board[ty][tx] = FULL;
			tx += 1;
		}
	}
}

void dfs(int origin_board[][10], int origin_visit[][10]) {

	int cp_board[10][10];
	int board[10][10];
	int visit[10][10];

	// 복구용 배열 카피
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cp_board[i][j] = origin_board[i][j];
			board[i][j] = origin_board[i][j];
			visit[i][j] = origin_visit[i][j];
		}
	}

	// 지도를 돌면서 0과 6이 아닌 곳에서 숫자에 따라 길을 펼쳐본다.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {

			// 방문 안 한 CCTV일 경우
			if (board[i][j] != 0 && board[i][j] != 6
				&& board[i][j] != FULL && visit[i][j] != 1) {

				visit[i][j] = 1;

				if (board[i][j] == 1) {
					// 한쪽 방향만, 단 90도 회전 4번 가능
					// 위로만 갈 때
					UP(board, i, j);
					dfs(board, visit);
					// 복구
					retarr(board, cp_board);

					// 아래로만 갈 때
					DOWN(board, i, j);
					dfs(board, visit);
					retarr(board, cp_board);

					// 왼쪽으로만 갈 때
					LEFT(board, i, j);
					dfs(board, visit);
					retarr(board, cp_board);

					// 오른쪽으로만 갈 때
					RIGHT(board, i, j);
					dfs(board, visit);
					retarr(board, cp_board);

				}
				else if (board[i][j] == 2) {
					// 양방향 가능, 좌-우 혹은 상-하
					// 먼저 왼쪽으로 쭉, 그다음 오른쪽으로 쭉
					LEFT(board, i, j); RIGHT(board, i, j);
					dfs(board, visit);
					retarr(board, cp_board);

					// 다시 위로 쭉, 아래로 쭉
					UP(board, i, j); DOWN(board, i, j);
					dfs(board, visit);
					retarr(board, cp_board);

				}
				else if (board[i][j] == 3) {

					// 위-오른쪽 혹은 오른쪽-아래 혹은 아래-왼쪽 혹은 왼쪽-위 가능
					UP(board, i, j); RIGHT(board, i, j);
					dfs(board, visit);
					retarr(board, cp_board);

					RIGHT(board, i, j); DOWN(board, i, j);
					dfs(board, visit);
					retarr(board, cp_board);

					DOWN(board, i, j); LEFT(board, i, j);
					dfs(board, visit);
					retarr(board, cp_board);

					LEFT(board, i, j); UP(board, i, j);
					dfs(board, visit);
					retarr(board, cp_board);

				}
				else if (board[i][j] == 4) {

					// 위-왼-오 , 위-오-아래, 왼,아래,오, 위-왼,아 가능
					UP(board, i, j); LEFT(board, i, j); RIGHT(board, i, j);
					dfs(board, visit);
					retarr(board, cp_board);

					UP(board, i, j); RIGHT(board, i, j); DOWN(board, i, j);
					dfs(board, visit);
					retarr(board, cp_board);

					LEFT(board, i, j); DOWN(board, i, j); RIGHT(board, i, j);
					dfs(board, visit);
					retarr(board, cp_board);

					UP(board, i, j); LEFT(board, i, j); DOWN(board, i, j);
					dfs(board, visit);
					retarr(board, cp_board);
				}
				else if (board[i][j] == 5) {
					// 상 하 좌 우 한번만 가능
					UP(board, i, j); RIGHT(board, i, j);
					DOWN(board, i, j); LEFT(board, i, j);
					dfs(board, visit);
					retarr(board, cp_board);
				}
			}
		}
	}

	// 빈 칸인 값 세기
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] == 0) {
				cnt += 1;
			}
		}
	}
	minV = min(minV, cnt);
	return;

}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int board[10][10];
	int visit[10][10];

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			visit[i][j] = 0;
		}
	}

	dfs(board, visit);

	cout << minV;

	return 0;
}