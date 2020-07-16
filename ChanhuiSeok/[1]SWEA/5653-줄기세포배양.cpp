#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>

#define DEAD -1000

using namespace std;

// 시간, 생명력, row, col
typedef pair<pair<int, int>, pair<int, int>> Pair;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int arr[1001][1001];
bool visit[1001][1001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;
	// 초기 상태에 줄기 세포 분포된 세로크기, 가로크기, 배양시간

	int T;
	cin >> T;

	int row, col;

	for (int t = 0; t < T; t++) {
		cin >> N >> M >> K;
		priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
		// 시간이 가장 최소인 값이 맨 앞으로 오게끔 하는 우선순위 큐 (오름차순)

		for (int i = 400; i < 400 + N; i++) {
			for (int j = 400; j < 400 + M; j++) {
				cin >> arr[i][j];
				
				if (arr[i][j] > 0) {
					visit[i][j] = true; // 방문 체크
					pq.push({ {arr[i][j], -arr[i][j]}, {i,j} });
				}
			}
		}

		int time = 1;
		// 배양 시간이 K일 때 까지
		while (time < K) {
			// 우선순위 큐가 비어있지 않고, 맨 앞의 cell이 현재 시간과 같을 경우
			while (!pq.empty() && pq.top().first.first == time) {
				int row = pq.top().second.first;
				int col = pq.top().second.second;
				int life = -pq.top().first.second;

				pq.pop(); // 활성화 pop

				// 해당 cell이 아래 번식 코드를 진행하지 못하게 한다.
				if (life == -DEAD)
					continue;

				// 활성화된 cell의 소멸 기한을 설정한다.
				// 즉, time + life - 1 초에 큐에서 아예 pop 되고 time + life 초에는 큐에 없게 한다.
				// 예를 들어, 맵에 맨 처음 생명력 2인 세포가 있었을 경우 time = 2초일 때 먼저 pop 된다.
				// 이후 이 세포는 2초 활성화 이후 죽어야 한다. 즉 time=4초일 때는 큐에 없어야 한다.
				// 따라서 3초에 pop을 하고, 4초에 없도록 아래와 같은 코드를 작성한다.

				pq.push({ {time + life - 1, DEAD}, {0,0} });

				for (int i = 0; i < 4; i++) {
					int ty = row + dy[i];
					int tx = col + dx[i];

					if (visit[ty][tx] == false) {
						visit[ty][tx] = true;
						pq.push({ { time+life+1, -life} ,  { ty, tx} });
					}

				}
			}
			time += 1;
		}

		cout << "#" << t+1 << " " << pq.size() << '\n';
		memset(visit, false, sizeof(visit));
		memset(arr, 0, sizeof(arr));
	}

	return 0;
}