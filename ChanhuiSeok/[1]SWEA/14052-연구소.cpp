#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;
queue<pair<int, int>> virus_q;

int arr[10][10];
int visit[10][10];
int copy_arr[10][10]; // 초기 배열 형태를 복사

int MaxSafeZone = -1;

int N, M;

// 유효한 칸인지 판단하는 함수
bool isValid(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M || arr[y][x] == 1)
		return false;
	if (visit[y][x] == 1) return false;
	return true;
}


// 바이러스를 퍼뜨리는 함수
void bfs() {
	// 상, 하, 좌, 우 검사해서 빈칸이면 큐에 넣고 방문하며 2로 만든다.
	q = virus_q;

	while (!q.empty()) {
		int fy = q.front().first;
		int fx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = fy + dy[i];
			int tx = fx + dx[i];

			// 유효한 칸에 대해서만 큐에 넣는다.
			if (isValid(ty, tx)) {
				q.push({ ty,tx });
				visit[ty][tx] = 1;
				arr[ty][tx] = 2; // 바이러스 전파하기
			}
		}	
	}

	// 바이러스 전파 완료
	// 빈 칸의 갯수 세기
	int zeroCnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				zeroCnt += 1;
			}
		}
	}
	MaxSafeZone = max(MaxSafeZone, zeroCnt);
}

// 벽을 세우는 함수
void createWall(int cnt) {

	if (cnt == 3) // 3개를 세웠을 경우
	{
		// 복사
		memcpy(copy_arr, arr, sizeof(arr));
		bfs(); // 바이러스를 퍼뜨린다.
				
		// 되돌리기
		memcpy(arr, copy_arr, sizeof(arr));
		memset(visit, 0, sizeof(visit));

		cnt -= 1;
		return;
	}

	// 벽을 세운다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				createWall(cnt + 1);
				arr[i][j] = 0; // 다시 빈 칸으로 만든다.
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus_q.push({ i,j });
			}
		}
	}

	// 벽을 세운 다음 -> 바이러스 퍼뜨리기 -> 0의 갯수 세기
	// 다시 새로운 벽을 세우기 -> ... 반복
	createWall(0);

	cout << MaxSafeZone;

	return 0;
}