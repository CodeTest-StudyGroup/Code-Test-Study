#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

#define EXPLODE 100

int N, W, H;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int minV = 987654321;

// 0이 아닌 칸을 세는 함수
int countAll(int board[][20]) {
	int res = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (board[i][j] != 0)
				res++;
		}
	}
	return res;
}

// 모든 칸을 아래로 내리는 함수
void forced(int board[][20]) {
	for (int j = 0; j < W; j++) { // 열
		for (int i = H - 2; i >= 0; i--) {
			int k = i;
			while (k <= H - 2 && board[k][j] != 0) {
				if (board[k + 1][j] == 0) {
					board[k + 1][j] = board[k][j];
					board[k][j] = 0;
				}
				k++;
			}
		}
	}
}

// EXPLODE를 0으로 바꾸는 함수
void blanked(int board[][20]) {
	for (int j = 0; j < W; j++) {
		for (int i = 0; i < H; i++) {
			if (board[i][j] == EXPLODE){
				board[i][j] = 0;
			}
		}
	}
}


// 폭발시키는 dfs
void burn(int board[][20], int burn_board[][20], int num, int y, int x) {

	if (burn_board[y][x] != EXPLODE) {
		burn_board[y][x] = EXPLODE;
	}
	if (num == 1) {		
		return;
	}

	//상
	for (int m = y - 1; m >= y - num + 1 && m >= 0; m--) {
		if(burn_board[m][x] != EXPLODE && burn_board[m][x] != 0)
			burn(board, burn_board, board[m][x], m, x);
	}

	//하
	for (int m = y + 1; m <= y + num -1 && m < H; m++) {
		if(burn_board[m][x] != EXPLODE && burn_board[m][x] != 0)
			burn(board, burn_board, board[m][x], m, x);
	}

	//좌
	for (int m = x - 1; m >= x - num + 1 && m >= 0; m--) {
		if(burn_board[y][m] != EXPLODE && burn_board[y][m] != 0)
			burn(board, burn_board, board[y][m], y, m);
	}

	//우
	for (int m = x + 1; m <= x + num - 1 && m < W; m++) {
		if(burn_board[y][m] != EXPLODE && burn_board[y][m] != 0)
			burn(board, burn_board, board[y][m], y, m);
	}

}


// 메인 dfs
void simulate(int cnt, int origin_board[][20]) {
	int burn_board[20][20];
	int board[20][20];
	int cp_board[20][20];

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			board[i][j] = origin_board[i][j];
			burn_board[i][j] = origin_board[i][j];
		}
	}

	if (cnt == N) {
		//printf("\nN번 선택 완료\n");
		int res = countAll(origin_board);
		minV = min(minV, res);
		return;
	}

	// col번째부터 구슬 떨어트리기
	for (int col = 0; col <= W - 1; col++) {
		//printf("%d번 열 선택 ", col);

		for (int row = 0; row <= H - 1; row++) {
			// 처음으로 0이 아닌 것이 나올 경우
			if (board[row][col] != 0) {
				burn(board, burn_board, board[row][col], row, col);
				break;
			}
		}
		// 처리 전 배열 복사
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cp_board[i][j] = board[i][j];
			}
		}

		// 이번 열 모두 처리
		blanked(burn_board);
		forced(burn_board);

		// board에 복사
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				board[i][j] = burn_board[i][j];
			}
		}

		
		// 처리 후 출력
		/*
		printf("처리 후 \n");
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				printf("%d ", board[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/

		simulate(cnt + 1, board);

		// 처리 전으로 되돌리기
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				board[i][j] = cp_board[i][j];
				burn_board[i][j] = cp_board[i][j];
			}
		}

	}

}

int main() {

	int T;
	int board[20][20];
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {

		scanf("%d %d %d", &N, &W, &H);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &board[i][j]);
			}
		}
		// 벽돌은 숫자 1 ~ 9로 표현된다.
		// 구슬은 좌, 우로만 움직일 수 있고 항상 맨 위에 있는 벽돌만 깨트릴 수 있다.
		// 구슬은 N번만 쏠 수 있다.
		simulate(0, board);

		printf("#%d %d\n", t+1, minV);
		minV = 987654321;
	}


	return 0;
}