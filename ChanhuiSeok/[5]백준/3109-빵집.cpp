#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
string arr[10001][501];
int visit[10001][501];

// 오른쪽 위 - 오른쪽 - 오른쪽 아래 순
int dy[3] = { -1, 0, 1 };
int dx[3] = { 1, 1, 1 };

bool valid(int y, int x) {
	if (y < 0 || x < 0 || y >= R || x >= C || arr[y][x] == "x") {
		return false;
	}
	return true;
}

bool iterFlag = false;

void simulation(int y, int x) {
	
	// 끝 열에 도달했을 경우
	if (x == C - 1) {
		iterFlag = true;
		return;
	}

	for (int i = 0; i < 3; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];

		// 유효한 칸이고 방문하지 않았을 때만 감
		if (valid(ty, tx) && !visit[ty][tx]) {
			visit[ty][tx] = 1;
			simulation(ty, tx);
			if (iterFlag)
				break;
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	
	string tmp;

	cin >> R >> C;

	// .는 빈 칸, x는 건물임. 처음과 마지막 열은 항상 비어있음.
	for (int i = 0; i < R; i++) {
		cin >> tmp;
		for (int j = 0; j < C; j++) {
			arr[i][j] = tmp[j];
		}
	}

	int cnt = 0;

	// 모든 왼쪽 열에 대해서 시행
	for (int row = 0; row < R; row++) {
		simulation(row, 0);
		if (iterFlag) 
			cnt += 1;
		iterFlag = false;
	}

	cout << cnt;

	return 0;
}