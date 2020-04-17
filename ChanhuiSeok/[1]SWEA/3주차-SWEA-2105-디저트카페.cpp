#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

/*

문제를 정확하게 보는 습관을 꼭꼭 들이자..
너무 엄한 시간을 버렸다...

배열의 번호들은 단지 디저트의 종류를 뜻할 뿐이다..

이거는 디저트를 최대한 많이 먹었을 때 그 갯수를 출력하는건데

나는 배열에 나오는 번호들을 디저트의 갯수로 잘못 오해하고
그 합들이 최대가 될 때의 테두리 칸의 갯수를 출력하니까 자꾸 틀렸다..
.
.
.
...
.
..%^%^^

*/


using namespace std;
int N;

// 오른쪽 아래는 0번, 오른쪽 위는 1번, 왼쪽 아래는 2번, 왼쪽 위는 3번
int dy[4] = { 1,-1,1,-1 };
int dx[4] = { 1,1,-1,-1 };
int dessert[101];
int maxCnt = -100, sum = 0, maxSum = -100;
int arr[21][21];
// prev_dir 값이 :
// 0이면 이전 위치가 왼쪽 위에서 온것,// 1이면 오른쪽 위에서 온 것,
// 2면 오른쪽 아래에서 온 것,// 3이면 왼쪽 아래에서 온 것이다.
void dfs(int prev_dir, int start_y, int start_x, int y, int x, int path, int sum, int corner) {
	if (corner >= 5)
		return;

	if (prev_dir == 0) { // 왼쪽 위에서 왔을 때
		dessert[arr[y][x]] = 1;

		// 오른쪽 아래로 가거나, 왼쪽 아래로 갈 수 있다.
		for (int i = 0; i < 4; i = i + 2) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// 다음 갈 곳이 처음 위치와 동일하면 종료
			if ((ty == start_y && tx == start_x && (corner == 2 && path >= 3)) ||
				(ty == start_y && tx == start_x && (corner == 3 && path >= 3))) {
				sum += arr[start_y][start_x];
				if (maxCnt < path) {
					maxCnt = path;
				}
				return;
			}

			// 허용 범위 내에 있고, 다음에 갈 값이 기존 path 경로에 없을 때만 추가하기
			if (ty <= N && ty >= 1 && tx <= N && tx >= 1 && dessert[arr[ty][tx]] == 0) {

				if (i == 0) { // 왼쪽 위에서 왔을 때 오른쪽 아래로 향했다면,
					dessert[arr[ty][tx]] = 1;
					dfs(0, start_y, start_x, ty, tx, path + 1, sum + arr[ty][tx], corner); // 다음 위치 입장에서는 왼쪽 위이다.
					dessert[arr[ty][tx]] = 0;
				}
				else if (i == 2) { // 왼쪽 위에서 왔을 때 왼쪽 아래로 향했다면,
					// 현재 이 위치가 오른쪽 모서리이다.
					dessert[arr[ty][tx]] = 1;
					dfs(1, start_y, start_x, ty, tx, path + 1, sum + arr[ty][tx], corner + 1); // 다음 위치 입장에서는 오른쪽 위이다.
					dessert[arr[ty][tx]] = 0;
				}
			}
		}
		dessert[arr[y][x]] = 0;
	}

	else if (prev_dir == 1) { // 오른쪽 위에서 왔을 때
		dessert[arr[y][x]] = 1;

		// 왼쪽 위 혹은 왼쪽 아래로 갈 수 있다.
		for (int i = 2; i < 4; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// 다음 갈 곳이 처음 위치와 동일하면 종료
			if ((ty == start_y && tx == start_x && (corner == 2 && path >= 3)) ||
				(ty == start_y && tx == start_x && (corner == 3 && path >= 3))) {
				sum += arr[start_y][start_x];
				if (maxCnt < path) {
					maxCnt = path;
				}
				return;
			}

			// 허용 범위 내에 있고, 다음에 갈 값이 기존 path 경로에 없을 때만 추가하기
			if (ty <= N && ty >= 1 && tx <= N && tx >= 1 && dessert[arr[ty][tx]] == 0) {

				if (i == 2) { // 오른쪽 위에서 와서 왼쪽 아래로 향했다면, 다음 위치 입장에서는 오른쪽 위이다.
					dessert[arr[ty][tx]] = 1;
					dfs(1, start_y, start_x, ty, tx, path + 1, sum + arr[ty][tx], corner);
					dessert[arr[ty][tx]] = 0;
				}
				else if (i == 3) { // 오른쪽 위에서 와서 왼쪽 위로 향했다면, 현재 이 위치가 아래쪽 모서리이다.
					// 다음 위치 입장에서는 오른쪽 아래이다.
					dessert[arr[ty][tx]] = 1;
					dfs(2, start_y, start_x, ty, tx, path + 1, sum + arr[ty][tx], corner + 1);
					dessert[arr[ty][tx]] = 0;
				}
			}
		}
		dessert[arr[y][x]] = 0;
	}

	else if (prev_dir == 2) { // 오른쪽 아래에서 왔을 때
		dessert[arr[y][x]] = 1;

		// 왼쪽 위 혹은 오른쪽 위로 갈 수 있다.
		for (int i = 1; i < 4; i = i + 2) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// 다음 갈 곳이 처음 위치와 동일하면 종료
			if ((ty == start_y && tx == start_x && (corner == 2 && path >= 3)) ||
				(ty == start_y && tx == start_x && (corner == 3 && path >= 3))) {
				sum += arr[start_y][start_x];
				if (maxCnt < path) {
					maxCnt = path;
				}
				return;
			}

			// 허용 범위 내에 있고, 다음에 갈 값이 기존 path 경로에 없을 때만 추가하기
			if (ty <= N && ty >= 1 && tx <= N && tx >= 1 && dessert[arr[ty][tx]] == 0) {

				if (i == 1) { // 오른쪽 아래에서 왔을 때 오른쪽 위로 가면, 다음 위치 입장에서 왼쪽 아래이다.
					// 그리고 코너가 된다.
					dessert[arr[ty][tx]] = 1;
					dfs(3, start_y, start_x, ty, tx, path + 1, sum + arr[ty][tx], corner + 1);
					dessert[arr[ty][tx]] = 0;
				}
				else if (i == 3) { // 오른쪽 아래에서 왔을 때 왼쪽 위로 가면, 다음 위치 입장에서 오른쪽 아래이다.
					dessert[arr[ty][tx]] = 1;
					dfs(2, start_y, start_x, ty, tx, path + 1, sum + arr[ty][tx], corner);
					dessert[arr[ty][tx]] = 0;
				}
			}
		}
		dessert[arr[y][x]] = 0;
	}

	else if (prev_dir == 3) { // 왼쪽 아래에서 왔을 때
		dessert[arr[y][x]] = 1;

		// 오른쪽 위 혹은 오른쪽 아래로 갈 수 있다.
		for (int i = 0; i < 2; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// 다음 갈 곳이 처음 위치와 동일하면 종료
			if ((ty == start_y && tx == start_x && (corner == 2 && path >= 3)) ||
				(ty == start_y && tx == start_x && (corner == 3 && path >= 3))) {
				sum += arr[start_y][start_x];
				if (maxCnt < path) {
					maxCnt = path;
				}
				return;
			}

			// 허용 범위 내에 있고, 다음에 갈 값이 기존 path 경로에 없을 때만 추가하기
			if (ty <= N && ty >= 1 && tx <= N && tx >= 1 && dessert[arr[ty][tx]] == 0) {

				if (i == 0) { // 왼쪽 아래에서 와서 오른쪽 아래로 향했다면, 현재 이 위치가 모서리이다. 다음 위치 입장에서는 왼쪽 위이다.
					dessert[arr[ty][tx]] = 1;
					dfs(0, start_y, start_x, ty, tx, path + 1, sum + arr[ty][tx], corner + 1);
					dessert[arr[ty][tx]] = 0;
				}
				else if (i == 1) { // 왼쪽 아래에서 와서 오른쪽 위로 향했다면, 다음 위치 입장에서는 왼쪽 아래이다.
					dessert[arr[ty][tx]] = 1;
					dfs(3, start_y, start_x, ty, tx, path + 1, sum + arr[ty][tx], corner);
					dessert[arr[ty][tx]] = 0;
				}
			}
		}
		dessert[arr[y][x]] = 0;
	}

}

int main() {

	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		for (int j = 1; j <= N - 2; j++) { // 내려갈 수 있는 행번호
			for (int k = 2; k <= N - 1; k++) { // 옆으로 갈 수 있는 열번호
				dfs(0, j, k, j, k, 0, 0, 0);
			}
		}

		if (maxCnt != -100)
			printf("#%d %d\n", t, maxCnt + 1);

		else
			printf("#%d -1\n", t);

		maxCnt = -100;
		maxSum = -100;
	}

}