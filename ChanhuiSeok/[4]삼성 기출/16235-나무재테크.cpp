#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#include <string>
#include <deque>

using namespace std;

int N, M, K;

int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };

typedef struct tree {
	int age;
	bool isDead;
}Tree;

int board[12][12];
int A[12][12]; // 추가되는 양분값

deque<int> info[12][12];
queue<int> dead[12][12];

bool valid(int y, int x) {

	if (y < 1 || y > N || x < 1 || x > N)
		return false;
	return true;
}

void simulation(int K) {

	while (K > 0) {
		// 봄
		// 나무가 자신의 나이만큼 양분을 먹고, 나이 1 증가, 각 칸에 있는 양분만 먹기 가능
		// 하나의 칸에 여러 개 나무가 있으면, 나이가 어린 나무부터 양분 획득
		// 땅에 양분이 부족해서 자신의 나이만큼 양분 못 먹으면 그 나무는 즉시 죽음

		// 땅에 있는 모든 나무들에 대하여
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {

				int size = info[i][j].size();
				// 그 칸의 큐를 확인한다.
				for (int k = 0; k < size; k++) {

					// 나이가 어린 나무부터
					int age = info[i][j].front();
					info[i][j].pop_front();

					// 자신의 나이만큼 양분 먹기
					if (board[i][j] >= age) {
						board[i][j] -= age;

						// 나이 1 증가시키기
						info[i][j].push_back(age + 1);
					}
					// 자신의 나이만큼 양분을 못 먹을 경우 죽인다.
					else {
						// dead 큐에 넣는다.
						dead[i][j].push(age);
					}
				}
			}
		}


		// 여름
		// 봄에 죽은 나무가 양분으로 변한다.
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				// 그 칸의 죽은 큐를 확인한다.			
				while (!dead[i][j].empty()) {
					int age = dead[i][j].front();
					dead[i][j].pop();
					board[i][j] += age / 2;
				}
			}
		}


		// 가을
		// 나무가 번식한다. 번식하는 나무는 나이가 5배수여야 하고 인접 8개 칸에 나이가 1인 나무가 생기며
		// 땅 벗어난 칸에는 나무가 생기지 않는다.
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {

				int size = info[i][j].size();
				for (int k = 0; k < size; k++) {
					// 8방향 조사
					int age = info[i][j][k];

					if (age % 5 == 0) {
						for (int m = 0; m < 8; m++) {
							int ty = i + dy[m];
							int tx = j + dx[m];

							if (valid(ty, tx)) {
								info[ty][tx].push_front(1); // 나이 1인 나무를 앞에 추가
							}
						}
					}
				}
			}
		}


		// 겨울
		// 땅 한 칸씩 돌아다니면서 A[r][c]만큼 양분을 추가시킨다.
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				board[i][j] = board[i][j] + A[i][j];
			}
		}

		K -= 1;
	}

}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			board[i][j] = 5;
		}
	}


	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;

		info[x][y].push_back(z);
	}

	// 나무정보 입력받기 완료

	simulation(K);


	// 죽지 않은 나무들의 개수 세기
	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cnt += info[i][j].size();
		}
	}

	cout << cnt;
	return 0;
}