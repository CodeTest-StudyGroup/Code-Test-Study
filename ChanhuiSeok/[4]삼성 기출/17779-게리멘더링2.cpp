#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define pii pair<int, int> 

/* 18405번 */
using namespace std;

int N;
int arr[21][21]; // 인구 수가 있는 곳
int board[21][21]; // 5구역을 나누는 곳
int visit[21][21]; // 방문배열

int res_min = 987654321;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

// 경계 길이 설정 가능 여부
bool isBoundary(int x, int y, int d1, int d2) {
	if (x + d1 + d2 <= N && y - d1 >= 1 && y + d2 <= N) {
		return true;
	}
	return false;
}

void simulation() {

	for (int i = 1; i <= N - 2; i++) {
		for (int j = 2; j <= N - 1; j++) {

			for (int d1 = 1; d1 <= N - 1; d1++) {
				for (int d2 = 1; d2 <= N - 1; d2++) {

					// 가능한 경계 길이인지 판단 및 꼭지점 판단 후 5번 경계선 만들기
					if (isBoundary(i, j, d1, d2)) {
						// 가능한 경계길이일 경우
						for (int k = 0; k <= d2; k++) {
							board[i + d1 + k][j - d1 + k] = 5;
							board[i + k][j + k] = 5;
						}
						for (int k = 0; k <= d1; k++) {
							board[i + k][j - k] = 5;
							board[i + d2 + k][j + d2 - k] = 5;
						}

						// 5번 테두리를 세웠으니 1,2,3,4 를 BFS 해 본다.
						queue<pair<int, int>> q;

						q.push({ 1,1 }); board[1][1] = 1; visit[1][1] = 1;
						q.push({ 1,N }); board[1][N] = 2; visit[1][N] = 1;
						q.push({ N,1 }); board[N][1] = 3; visit[N][1] = 1;
						q.push({ N,N }); board[N][N] = 4; visit[N][N] = 1;

						while (!q.empty()) {
							int r = q.front().first;
							int c = q.front().second;
							q.pop();

							for (int k = 0; k < 4;k++) {
								int tr = r + dy[k];
								int tc = c + dx[k];

								if (tr <= 0 || tc <= 0 || tr > N || tc > N ||
									visit[tr][tc] == 1 || board[tr][tc] == 5) 
									continue;
								
								if (1 <= tr && tr < i + d1 && 1 <= tc && tc <= j) {
										board[tr][tc] = 1;
										visit[tr][tc] = 1;
										q.push({ tr,tc });
								}

								else if (1 <= tr && tr <= i + d2 && j < tc && tc <= N) {
										board[tr][tc] = 2;
										visit[tr][tc] = 1;
										q.push({ tr,tc });
								}

								else if (i + d1 <= tr && tr <= N && 1 <= tc && tc < j - d1 + d2) {
										board[tr][tc] = 3;
										visit[tr][tc] = 1;
										q.push({ tr,tc });
								}

								else if (i + d2 < tr && tr <= N && j - d1 + d2 <= tc && tc <= N) {
										board[tr][tc] = 4;
										visit[tr][tc] = 1;
										q.push({ tr,tc });
								}
							}
						}
						// 나머지 5번도 채운다.
						for (int i = 1; i <= N; i++) {
							for (int j = 1; j <= N; j++) {
								if (board[i][j] == 0) {
									board[i][j] = 5;
								}
								visit[i][j] = 0;
							}
						}

						// 각 구역별 배열에 인구수를 더한다.
						int sumArr[5] = { 0,0,0,0,0 };
						for (int i = 1; i <= N; i++) {
							for (int j = 1; j <= N; j++) {
								sumArr[board[i][j] - 1] += arr[i][j];
							}
						}
						sort(sumArr, sumArr + 5);
						res_min = min(res_min, sumArr[4]-sumArr[0]);

					// 다른 케이스를 위해 초기화한다.
						for (int i = 1; i <= N; i++) {
							for (int j = 1; j <= N; j++) {
								board[i][j] = 0;
								visit[i][j] = 0;
							}
						}
					}
					// 5번 만들 수 없을 경우 다른 경계선 길이로 넘어가기
					else {
						continue;
					}
				}
			} // end inner for
		}
	} // end outer for
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	simulation();
	cout << res_min;
	return 0;
}