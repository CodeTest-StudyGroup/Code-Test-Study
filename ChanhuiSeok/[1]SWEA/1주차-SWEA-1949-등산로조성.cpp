#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

//상,하,좌,우
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int visit[9][9];
int arr[9][9];
int cnt;
int maxCnt = -1;
int K;
int cutINF;

void findPath(int y, int x, int N) {

	visit[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ty = dy[i] + y;
		int tx = dx[i] + x;

		// 상,하,좌,우 중 갈 수 있는 case
		if (ty >= 0 && ty < N && tx >= 0 && tx < N) {

			if (visit[ty][tx] == 0 && arr[y][x] > arr[ty][tx])
			{
				visit[ty][tx] = 1; cnt += 1;
				findPath(ty, tx, N);

				if (maxCnt <= cnt) 
					maxCnt = cnt;
				
				cnt -= 1;
				visit[ty][tx] = 0;
			}

			else{
				for (int mk = 1; mk <= K; mk++) {
					if (visit[ty][tx] == 0 && arr[y][x] > (arr[ty][tx]) - mk && cutINF == 0) {
						
						cutINF = 1; visit[ty][tx] = 1; cnt += 1;
						arr[ty][tx] = arr[ty][tx] - mk;
						findPath(ty, tx, N);

						if (maxCnt <= cnt) 
							maxCnt = cnt;

						cnt -= 1; cutINF = 0;
						arr[ty][tx] = arr[ty][tx] + mk;
						visit[ty][tx] = 0;
					}
				}//end inner for
			}//end inner else
			
		}//end outer if
	} //end outer for
}//end function

int main() {

	int T;
	int N, input;
	int maxPath = -1;
	int maxValue = -1;
	
	vector <pair<int, int>> maxElements;

	scanf("%d", &T);
	for (int t = 0; t < T; t++) {

		scanf("%d %d", &N, &K);

		// N * N input 입력받기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &input);
				arr[i][j] = input;

				if (input >= maxValue)
					maxValue = input;
			}
		}

		// maxValue를 가지는 위치 저장
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == maxValue)
					maxElements.push_back({ i,j });
			}
		}

		// 시작
		for (int i = 0; i < maxElements.size(); i++) {
			findPath(maxElements[i].first, maxElements[i].second, N);

			for (int j = 0; j < 9; j++) {
				for (int k = 0; k < 9; k++) {
					visit[j][k] = 0;
				}
			}
			cnt = 0;
		}

		printf("#%d %d", t, maxCnt);
		maxCnt = -1;
		maxElements.clear();
		maxValue = -1;
	}

}
