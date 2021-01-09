#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int arr[101][101];

#define INF 987654321

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (r == c) arr[r][c] = 0;
			else arr[r][c] = 987654321;
		}
	}

	// 갈 수 있는 길
	for (int i = 0; i < M; i++) {
		int s, r;
		cin >> s >> r;
		arr[s][r] = 1; // 갈 수 있음
	}

	for (int k = 1; k <= N; k++) {
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				arr[r][c] = min(arr[r][c], arr[r][k] + arr[k][c]);
			}
		}
	}

	// r->c 혹은 c->r 로 가는 길이 없으면 카운트한다.
	for (int r = 1; r <= N; r++) {
		int unable = 0;
		for (int c = 1; c <= N; c++) {
			if (r == c) continue;
			if (arr[r][c] == INF && arr[c][r] == INF) {
				unable += 1;
			}
		}
		cout << unable << '\n';
	}
	
	return 0;
}
