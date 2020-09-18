#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <map>
#include <stack>
#include <string>

#define pii pair<int,int>
#define POINT 5

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

using namespace std;

int board[400][400];
vector<int> pxy[21];

void draw_curve(int sy, int sx, int sDir, int gen) {

	// 시작 좌표 (sy, sx) 에서 gen 세대까지
	for (int i = 0; i <= gen; i++) {
		// 0세대일 경우
		if (i == 0) 
			pxy[0].push_back(sDir); // 벡터에 넣기				
		else {		
			// 전 세대 정보를 그대로 넣고
			for (int k = 0; k < pxy[i - 1].size(); k++)
				pxy[i].push_back(pxy[i - 1][k]);

			// 뒤에 전 세대의 정보를 거꾸로 한 값 +1을 하여 차례대로 넣는다.
			for (int k = pxy[i - 1].size() - 1; k >= 0; k--) 
				pxy[i].push_back((pxy[i - 1][k] + 1) % 4);		
		}
	}

}


int main(){

	int N;
	cin >> N;

	vector<vector<int>> dragon;
	dragon.resize(N);

	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		// x, y는 드래곤 커브 시작점, d는 시작 방향, g는 세대

		dragon[i].push_back(x); dragon[i].push_back(y);
		dragon[i].push_back(d); dragon[i].push_back(g);
	}
	// 드래곤 커브 입력 완료

	// 시작 위치를 (100, 100) 이 원점이 되도록 맞춘다.
	// dragon[0] 부터 차례대로 격자판에 그림을 그려 본다.

	for (int i = 0; i < N; i++) {
		int y = dragon[i][1];
		int x = dragon[i][0];
		int dir = dragon[i][2];
		int gen = dragon[i][3];

		draw_curve(y, x, dir, gen);

		// 이제 각 세대마다 정해진 방향 순서대로 평면에 표시한다.
		int sY, sX, eY, eX;
		sY = y; sX = x;
		for (int k = 0; k <= gen; k++) {

			// k세대
			for (int j = pxy[k].size() / 2; j < pxy[k].size(); j++) {
				// 시작 지점에 표시
				//if(sY >= 0 && sY <=100 && sX >= 0 && sX <= 100)
					board[sY][sX] = POINT;

				eY = sY + dy[pxy[k][j]];
				eX = sX + dx[pxy[k][j]];
				// 끝 지점에 표시
				//if (eY >= 0 && eY <= 100 && eX >= 0 && eX <= 100)
					board[eY][eX] = POINT;

				// 이전 끝 지점이 시작지점이 되므로
				sY = eY; sX = eX;
			}

		}

		for (int k = 0; k <= gen; k++) {
			pxy[k].clear();
		}
	
	}
	

	int ans = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] == POINT &&
				board[i][j + 1] == POINT &&
				board[i + 1][j] == POINT &&
				board[i + 1][j + 1] == POINT) {
				ans += 1;
			}
		}
	}

	return 0;
}