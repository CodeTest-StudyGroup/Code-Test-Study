#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> floors[101]; // 1~100번 엘리베이터에 연결된 층을 표시
vector<int> elevator[100001]; // 1~100000층에서 갈 수 있는 엘리베이터 번호를 표시
priority_queue<pair<int, int>> pq;

int ele_cnt[101];
int ele_parent[101];

int A, B, N, M; // N층, M대의 엘리베이터

void dijkstra() {

	// 시작 층과 연결된 모든 엘리베이터는 탄 횟수를 1로 초기화시킨다. (1번만 타도 갈 수 있다는 의미)
	for (int i = 0; i < elevator[A].size(); i++) {
		ele_cnt[elevator[A][i]] = 1;
		pq.push({ -1, elevator[A][i] });
	}

	while (!pq.empty()) {
		int eleNum = pq.top().second;
		int tempC = pq.top().first * -1;
		pq.pop();

		if (tempC <= ele_cnt[eleNum]) {
			// 큐에서 뽑은 엘리베이터 번호와 연결된 모든 층을 살펴본다.
			for (int i = 0; i < floors[eleNum].size(); i++) {
				int tempFloor = floors[eleNum][i];
				for (int j = 0; j < elevator[tempFloor].size(); j++) {
					int nextEle = elevator[tempFloor][j];
					// 연결된 층에서 탈 수 있는 다음 엘리베이터 번호

					// 다음 엘리베이터에 탄 횟수가 한 번도 없거나,
					// 다음 엘리베이터를 탄 횟수보다 tempC + 1이 더 작을 경우
					// 값을 그것으로 갱신해 준다.
					if (ele_cnt[nextEle] == 0 || tempC + 1 < ele_cnt[nextEle]) {
						ele_cnt[nextEle] = tempC + 1;
						ele_parent[nextEle] = eleNum; // 다음 엘리베이터 전에 탄 것은 eleNum으로 표시
						pq.push({ (tempC + 1) * -1, nextEle });
					}
				}
			}

		}
	}
}

void print(int num) {
	if (num == 0) return;
	print(ele_parent[num]);
	printf("%d\n", num);
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) { // 엘리베이터 갯수만큼 반복
		int X, Y;
		cin >> X >> Y;

		while (X <= N) {
			// 4, 3을 입력받을 경우 4층, 7층, 10층, .. 이 floor[i] 에 연결
			floors[i].push_back(X);
			elevator[X].push_back(i);
			X += Y;
		}
	}
	cin >> A >> B;

	dijkstra();

	int ans = 987654321;
	int last = 0;

	// B층과 연결된 엘리베이터들 에서 최솟값 찾기
	for (int i = 0; i < elevator[B].size(); i++) {
		if (ele_cnt[elevator[B][i]] < ans) {
			ans = ele_cnt[elevator[B][i]];
			last = elevator[B][i];
		}
	}

	if (ans == 987654321 || ans == 0) printf("-1\n");
	else {
		printf("%d\n", ans);
		print(last);
	}



	return 0;
}