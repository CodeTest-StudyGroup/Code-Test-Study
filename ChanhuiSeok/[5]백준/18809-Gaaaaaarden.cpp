#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

#define HOSU 0
#define UNABLE 1
#define ABLE 2

#define GREEN 10
#define RED 20
#define FLOWER 1000

#define GREEN_NOW 60
#define RED_NOW 70

int N, M, G, R;
int arr[51][51];
bool visit[51][51];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

vector<pair<int, int>> candi;
vector<int> ind;
vector<int> color;

int maxFlower = -987654321;

/* 배양액을 뿌릴 땅을 조합을 이용하여 모든 경우의 수를 본다. */
/* 그 뿌려질 땅에 G 혹은 R이 오는 경우의 수를 순열을 이용하여 모든 경우의 수를 본다. */

void simulation() {

	int copyArr[51][51];
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			copyArr[i][j] = arr[i][j];
		
	// G, R 개수에 따른 순열로 각 칸에 뿌리기
	// 배양액을 뿌릴 칸을 조합으로 고르기
	do { /* 땅 조합 */
		vector<pair<int, int>> p_land; // 배양액 뿌릴 땅 리스트	
		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1) {
				p_land.push_back(candi[i]);
			}
		}

		do { /* 배양액 색상 순열 */

			int flower = 0;
			queue<pair<int, int>> q;

			// 배양액을 처음에 떨어뜨릴 p_land에, color 순서대로 배양액을 뿌린다.
			for (int i = 0; i < p_land.size(); i++) {
				pair<int, int> p = p_land[i];
				arr[p.first][p.second] = color[i];

				visit[p.first][p.second] = true;
				q.push({ p.first, p.second });
			}

			while (1) {
				vector<pair<int, int>> now; // 방금 뿌려진 초록색 혹은 빨간색 배양액의 위치
				bool flag = false;

				// 사방으로 퍼뜨려 본다.
				while (!q.empty()) {
					int y, x, curColor;
					y = q.front().first;
					x = q.front().second;
					curColor = arr[y][x];

					q.pop();

					for (int i = 0; i < 4; i++) {
						int ty = y + dy[i];
						int tx = x + dx[i];

						// 호수가 아니고, 꽃이 아닌 곳에 배양액 뿌리기
						if (ty >= 0 && tx >= 0 && ty < N && tx < M &&
							!visit[ty][tx] && arr[ty][tx] != HOSU && arr[ty][tx] != FLOWER) {

							// 다음에 갈 곳이, 방금 뿌려진 배양액이며 다른 색상이었을 경우
							// 그 칸은 꽃으로 만든다.
							if ((arr[y][x] == RED && arr[ty][tx] == GREEN_NOW) ||
								(arr[y][x] == GREEN && arr[ty][tx] == RED_NOW)) {
								arr[ty][tx] = FLOWER;
								flower++;
							}
							else { // 아닐 경우, 그냥 흩뿌린다.
								flag = true;
								arr[ty][tx] = arr[y][x] + 50; // NOW로 뿌린다.
								now.push_back({ ty,tx });
							}
						}
					}
				}

				// 만약 위에서 더 이상 배양액이 퍼뜨려진 적이 없었을 경우
				if (!flag) {
					maxFlower = max(maxFlower, flower); // 값 갱신
					break;
				}

				// now에 있는 칸들을 조사하고 다음을 위해 큐에 넣는다.
				for (int k = 0; k < now.size(); k++) {
					int y = now[k].first;
					int x = now[k].second;
					visit[y][x] = true;

					if (arr[y][x] != FLOWER &&
						(arr[y][x] == GREEN_NOW || arr[y][x] == RED_NOW)) {
						arr[y][x] = arr[y][x] - 50;
						q.push({ y,x });
					}
				}
			}

			// 땅 초기화
			for (int i = 0; i < N; i++) 
				for (int j = 0; j < M; j++) {
					arr[i][j] = copyArr[i][j];
					visit[i][j] = false;
				}

		} while (next_permutation(color.begin(), color.end()));
	} while (next_permutation(ind.begin(), ind.end()));
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> G >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == ABLE) {
				candi.push_back({ i,j });
			}
		}
	}

	// R+G 개수만큼 1을 넣고
	for (int i = 0; i < R + G; i++)
		ind.push_back(1);
	for (int i = 0; i < candi.size() - (R + G); i++)
		ind.push_back(0);
	sort(ind.begin(), ind.end());

	for (int i = 0; i < R; i++)
		color.push_back(RED);
	for (int i = 0; i < G; i++)
		color.push_back(GREEN);
	sort(color.begin(), color.end());

	// 모든 칸에 대해 배양액 뿌리기를 안했을 때 종료

	simulation();
	cout << maxFlower;

	return 0;
}