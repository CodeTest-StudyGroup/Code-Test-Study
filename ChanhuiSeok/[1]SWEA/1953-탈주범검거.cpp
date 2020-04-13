#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int arr[51][51];
int visit[51][51];
int place[51][51];
int N, M, R, C, L;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 }; // 상하좌우
int place_cnt = 0;
int L_cnt = 0;

void findPath(int y, int x) {

	visit[y][x] = 1;

	//상,하,좌,우 모두 가능. 단, 다음 칸들이 연결되지 못하면 실패
	if (arr[y][x] == 1) {
		for (int i = 0; i < 4; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// 위나 아래로 가려 할 때 막혀있지 않을 때만 가능
			if ((i == 0 && arr[ty][tx] != 3 && arr[ty][tx] != 4 && arr[ty][tx] != 7 && arr[ty][tx] != 0) ||
				(i == 1 && arr[ty][tx] != 3 && arr[ty][tx] != 5 && arr[ty][tx] != 6 && arr[ty][tx] != 0)) {
				// 허용 가능한 범위이며 방문하지 않았다면
				if (ty < N && ty >= 0 && tx < M && tx >= 0
					&& visit[ty][tx] != 1 && L_cnt < L-1) {

					visit[ty][tx] = 1; // 방문 표시 설정
					place[ty][tx] = 1;
					L_cnt += 1; // 이동 후 한시간 증가

					findPath(ty, tx);

					visit[ty][tx] = 0; // 복귀
					L_cnt -= 1; // 복귀
				}
			}

			// 좌 우로 가려할 때 막혀있지 않을 때만 가능
			if ((i == 2 && arr[ty][tx] != 2 && arr[ty][tx] != 6 && arr[ty][tx] != 7 && arr[ty][tx] != 0) ||
				(i == 3 && arr[ty][tx] != 2 && arr[ty][tx] != 4 && arr[ty][tx] != 5 && arr[ty][tx] != 0)) {
				// 허용 가능한 범위이며 방문하지 않았다면
				if (ty < N && ty >= 0 && tx < M && tx >= 0
					&& visit[ty][tx] != 1 && L_cnt < L-1) {

					visit[ty][tx] = 1; // 방문 표시 설정
					place[ty][tx] = 1;
					L_cnt += 1; // 이동 후 한시간 증가

					findPath(ty, tx);

					visit[ty][tx] = 0; // 복귀
					L_cnt -= 1; // 복귀
				}
			}

		}
	}
	// 상, 하만 가능
	else if (arr[y][x] == 2) {
		for (int i = 0; i < 2; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// 상, 하 파이프 다음에 좌, 우 파이프가 오면 실패
			if ((i == 0 && arr[ty][tx] != 3 && arr[ty][tx] != 4 && arr[ty][tx] != 7 && arr[ty][tx] != 0)||
				(i == 1 && arr[ty][tx] != 3 && arr[ty][tx] != 5 && arr[ty][tx] != 6 && arr[ty][tx] != 0)){
				// 허용 가능한 범위이며 방문하지 않았다면
				if (ty < N && ty >= 0 && tx < M && tx >= 0
					&& visit[ty][tx] != 1 && L_cnt < L-1) {

					visit[ty][tx] = 1; // 방문 표시 설정
					place[ty][tx] = 1;
					L_cnt += 1; // 이동 후 한시간 증가

					findPath(ty, tx);

					visit[ty][tx] = 0; // 복귀
					L_cnt -= 1; // 복귀
				}
			}
		}
	}
	// 좌, 우 가능
	else if (arr[y][x] == 3) {

		for (int i = 2; i < 4; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// 좌, 우 파이프 다음에 상, 하 파이프가 오면 실패
			if ((i == 2 && arr[ty][tx] != 2 && arr[ty][tx] != 6 && arr[ty][tx] != 7 && arr[ty][tx] != 0)||
				(i == 3 && arr[ty][tx] != 2 && arr[ty][tx] != 5 && arr[ty][tx] != 4 && arr[ty][tx] != 0)){
				// 허용 가능한 범위이며 방문하지 않았다면
				if (ty < N && ty >= 0 && tx < M && tx >= 0
					&& visit[ty][tx] != 1 && L_cnt < L-1) {

					visit[ty][tx] = 1; // 방문 표시 설정
					place[ty][tx] = 1;
					L_cnt += 1; // 이동 후 한시간 증가

					findPath(ty, tx);

					visit[ty][tx] = 0; // 복귀
					L_cnt -= 1; // 복귀
				}
			}
		}

	}
	// 상, 우 가능
	else if (arr[y][x] == 4) {

		for (int i = 0; i < 4; i = i + 3) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// 위로갈 수 있을 때 가로로 막혀 있으면 안됨
			// 혹은 오른쪽으로 갈 수 있을 때 세로로 막혀있으면 안 됨
			if ((i == 0 && arr[ty][tx] != 3 && arr[ty][tx] != 4 && arr[ty][tx] != 7 && arr[ty][tx] != 0) ||
				(i == 3 && arr[ty][tx] != 2 && arr[ty][tx] != 5 && arr[ty][tx] != 4 && arr[ty][tx] != 0)) {
				// 허용 가능한 범위이며 방문하지 않았다면
				if (ty < N && ty >= 0 && tx < M && tx >= 0
					&& visit[ty][tx] != 1 && L_cnt < L-1) {

					visit[ty][tx] = 1; // 방문 표시 설정
					place[ty][tx] = 1;
					L_cnt += 1; // 이동 후 한시간 증가

					findPath(ty, tx);

					visit[ty][tx] = 0; // 복귀
					L_cnt -= 1; // 복귀
				}
			}
		}

	}
	// 하, 우 가능
	else if (arr[y][x] == 5) {

		for (int i = 1; i < 4; i = i + 2) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// 아래로갈 수 있을 때 가로로 막혀 있으면 안됨
			// 혹은 오른쪽으로 갈 수 있을 때 세로로 막혀있으면 안 됨
			if ((i == 1 && arr[ty][tx] != 3 && arr[ty][tx] != 5 && arr[ty][tx] != 6 && arr[ty][tx] != 0) ||
				(i == 3 && arr[ty][tx] != 2 && arr[ty][tx] != 4 && arr[ty][tx] != 5 && arr[ty][tx] != 0)) {
				// 허용 가능한 범위이며 방문하지 않았다면
				if (ty < N && ty >= 0 && tx < M && tx >= 0
					&& visit[ty][tx] != 1 && L_cnt < L-1) {

					visit[ty][tx] = 1; // 방문 표시 설정
					place[ty][tx] = 1;
					L_cnt += 1; // 이동 후 한시간 증가

					findPath(ty, tx);

					visit[ty][tx] = 0; // 복귀
					L_cnt -= 1; // 복귀
				}
			}
		}

	}
	// 하, 좌 가능
	else if (arr[y][x] == 6) {

		for (int i = 1; i < 3; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// 아래로갈 수 있을 때 가로로 막혀 있으면 안됨
			// 혹은 왼쪽으로 갈 수 있을 때 세로로 막혀있으면 안 됨
			if ((i == 1 && arr[ty][tx] != 3 && arr[ty][tx] != 5 && arr[ty][tx] != 6 && arr[ty][tx] != 0) ||
				(i == 2 && arr[ty][tx] != 2 && arr[ty][tx] != 6 && arr[ty][tx] != 7 && arr[ty][tx] != 0)) {
				// 허용 가능한 범위이며 방문하지 않았다면
				if (ty < N && ty >= 0 && tx < M && tx >= 0
					&& visit[ty][tx] != 1 && L_cnt < L-1) {

					visit[ty][tx] = 1; // 방문 표시 설정
					place[ty][tx] = 1;
					L_cnt += 1; // 이동 후 한시간 증가

					findPath(ty, tx);

					visit[ty][tx] = 0; // 복귀
					L_cnt -= 1; // 복귀
				}
			}
		}

	}
	// 상, 좌 가능
	else if (arr[y][x] == 7) {

		for (int i = 0; i < 4; i=i+2) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// 위로갈 수 있을 때 가로로 막혀 있으면 안됨
			// 혹은 왼쪽으로 갈 수 있을 때 세로로 막혀있으면 안 됨
			if ((i == 0 && arr[ty][tx] != 3 && arr[ty][tx] != 4 && arr[ty][tx] != 7 && arr[ty][tx] != 0) ||
				(i == 2 && arr[ty][tx] != 2 && arr[ty][tx] != 6 && arr[ty][tx] != 7 && arr[ty][tx] != 0)) {
				// 허용 가능한 범위이며 방문하지 않았다면
				if (ty < N && ty >= 0 && tx < M && tx >= 0
					&& visit[ty][tx] != 1 && L_cnt < L-1) {

					visit[ty][tx] = 1; // 방문 표시 설정
					place[ty][tx] = 1;
					L_cnt += 1; // 이동 후 한시간 증가

					findPath(ty, tx);

					visit[ty][tx] = 0; // 복귀
					L_cnt -= 1; // 복귀
				}
			}
		}
	}


}


int main() {

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {

		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &arr[i][j]);
			}
		}


		findPath(R, C);
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (place[i][j] == 1) {
					place_cnt += 1;
					place[i][j] = 0;
				}
			}
		}


		printf("#%d %d", t, place_cnt+1);

		place_cnt = 0;
		visit[R][C] = 0;
		L_cnt = 0;
	}

}