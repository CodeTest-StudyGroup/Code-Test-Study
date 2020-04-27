#define _CRT_SECURE_NO_WARNINGS
#define NumOfMagnet 4
#define NumOfBlades 8

#define M_INF -100
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int arr[10][10]; // 원래 인풋으로 받는 배열
int assignment[10][10]; // 계단을 배정하는 배열
int simul[10][10]; // 시뮬레이션을 진행하는 배열
int stair[10];
int time;
int MinTime = 1000001;
int peopleCnt;
bool allMINF;

vector<pair<int, int>> stairIdx;
vector<int> stairOne;
vector<int> stairTwo;

bool compare(int a, int b) {
	return a > b;
}

void dfs(int cnt) {

	// 기저 사례. 이 케이스에 대하여 시뮬레이션 진행
	if (cnt == peopleCnt) {
		int idx = 0;
		time = 0; // 새로 시작
		// simul 에 사람별로 계단 배정 후 거리를 표시하기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1) 
					assignment[i][j] = stair[idx++];

				if (assignment[i][j] == 1) // 1번 계단일 경우의 거리 계산				
					simul[i][j] = abs(i - stairIdx[0].first) + abs(j - stairIdx[0].second);
				
				else if (assignment[i][j] == 2) // 2번 계단일 경우의 거리 계산				
					simul[i][j] = abs(i - stairIdx[1].first) + abs(j - stairIdx[1].second);
				
			}
		}

		// 1분씩 시간이 흐른다. 계단 입구에 도착 시, 1분 뒤부터 계단을 내려갈 수 있다.
		time = 1; // 시작
		while (1) {

			// 1분의 시간이 흐를 때 배정된 거리가 일괄적으로 -1 감소하는 작업.
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (simul[i][j] != M_INF && simul[i][j] != -1) {
						// 이미 -1인 사람들은 내려가기를 대기해야 하므로 감소시키지 않는다.
						simul[i][j] -= 1;
					}
				}
			}

			// 계단 내려가는 벡터가 비어 있지 않을 경우, 내부의 원소들을 일괄적으로 1 감소시키는 작업
			// 0이 되면 그 벡터에서 지운다. 빼기 용이하도록 내림차순 정렬하여 0이 맨 끝에 오도록 유도한다.
			sort(stairOne.begin(), stairOne.end(), compare);
			sort(stairTwo.begin(), stairTwo.end(), compare);

			if (stairOne.size() != 0) {
				for (int i = stairOne.size() -1 ; i >= 0; i--) {
					stairOne[i] -= 1;
					if (stairOne[i] == 0) {
						stairOne.erase(stairOne.begin() + i);
					}
				}				
			}
			if (stairTwo.size() != 0) {
				for (int i = stairTwo.size() - 1; i >= 0; i--) {
					stairTwo[i] -= 1;
					if (stairTwo[i] == 0) {
						stairTwo.erase(stairTwo.begin() + i);
					}
				}
			}


			// -1이 된 사람들을 계단을 내려가는 중인 벡터에 넣는 작업.
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (simul[i][j] == -1 && assignment[i][j] == 1
						&& stairOne.size() < 3) { // queue에 넣어 둔다.
						stairOne.push_back(arr[stairIdx[0].first][stairIdx[0].second]);
						simul[i][j] = M_INF; // 이미 들어간 것이므로 없애버린다.
					}
					else if (simul[i][j] == -1 && assignment[i][j] == 2
						&& stairTwo.size() < 3) { // queue에 넣어 둔다.
						stairTwo.push_back(arr[stairIdx[1].first][stairIdx[1].second]);
						simul[i][j] = M_INF; // 이미 들어간 것이므로 없애버린다.
					}
				}
			}

			// 모든 simul 내의 벡터가 M_INF가 되었으며 stairOne, Two 벡터에도 더 이상 내려가는 사람이 없을 경우
			// while문을 종료한다.
			allMINF = true;
			for (int i = 0; i < N; i++){
				for (int j = 0; j < N; j++) {
					if (simul[i][j] != M_INF) {
						allMINF = false;
					}
				}
			}
			if (allMINF && stairOne.empty() && stairTwo.empty())
				break;		
			
			// 아니면 시간이 1분 증가한다.
			time += 1;
		}	

		return;
	}

	// stair Num으로만 표현
	for (int i = 1; i <= 2; i++) {
		stair[cnt] = i;
		dfs(cnt + 1);

		if (MinTime > time)		
			MinTime = time;
		
		stair[cnt] = 0;
	}

}

int main() {

	int T;
	FILE* fp = fopen("input.txt", "r");

	fscanf(fp, "%d", &T);

	for (int t = 1; t <= t; t++) {
		fscanf(fp, "%d", &N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				fscanf(fp, "%d", &arr[i][j]);
				if (arr[i][j] == 1) {
					peopleCnt += 1;
				}
				if (arr[i][j] != 0 && arr[i][j] != 1) {
					stairIdx.push_back({ i,j });
				}
				simul[i][j] = M_INF;
				assignment[i][j] = 0;
			}
		}


		dfs(0);

		printf("#%d %d\n",t, MinTime);

		MinTime = 1000001;
		peopleCnt = 0;
		stairIdx.clear();
		time = 0;
		stairOne.clear();
		stairTwo.clear();
	}
}