#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
#define MAX 100
// 지도 크기 변수
int N, M;
// 시간과 전체 치즈 개수 저장하는 변수
int day = 0, cheeseCnt = 0;
// 지도 정보를 표시하는 배열
int MAP[MAX][MAX];
// 외부 공기의 위치를 표시하는 배열
bool outsideAir[MAX][MAX];
int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0, -1, 0, 1 };
// 외부 공기와 2변 이상 접촉한 치즈를 녹이는 함수
void cheeseMelt(int x, int y) {
	int outsideAirCnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dirX[i];
		int ny = y + dirY[i];
        // 외부공기와 접촉했을 경우 outsideAirCnt를 1 증가시킴
		if (outsideAir[nx][ny]) {
			outsideAirCnt++;
		}
	}
    // 외부공기와 2변 이상 접촉했다면 배열값을 0으로 변경하고 치즈 개수를 감소시킴
	if (outsideAirCnt >= 2) {
		MAP[x][y] = 0;
		cheeseCnt--;
	}
}
// 외부 공기를 표시하는 함수 (BFS를 이용하여 탐색)
void checkOutsideAir(int x, int y) {
	queue<pair<int, int>> needVisit;
	needVisit.push({ x, y });
	while (!needVisit.empty()) {
        // 현재위치 저장
		int curx = needVisit.front().first;
		int cury = needVisit.front().second;
		needVisit.pop();
        // 현재 위치로부터 상하좌우 확인
		for (int i = 0; i < 4; i++) {
            // 다음 탐색위치 저장
			int nx = curx + dirX[i];
			int ny = cury + dirY[i];
            // 지도 범위를 벗어날 경우 continue
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
            // 탐색할 위치에 치즈가 있거나 이미 방문했다면 continue
			if (MAP[nx][ny] != 0 || outsideAir[nx][ny])
				continue;
            // 탐색할 위치를 큐에 push
			needVisit.push({ nx, ny });
            // 해당 위치가 외부 공기임을 표시함
			outsideAir[nx][ny] = true;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
            // 전체 치즈의 개수를 미리 세어놓음
			if (MAP[i][j] == 1) {
				cheeseCnt++;
			}
		}
	}
    // 치즈가 모두 녹을때까지 반복문 진행
	while (cheeseCnt > 0) {
        // 가장자리에는 치즈가 놓여져 있지 않으므로 (0, 0)부터 외부 공기 표시
		outsideAir[0][0] = true;
		checkOutsideAir(0, 0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
                // 치즈가 녹는지 안녹는지 확인
				if (MAP[i][j] == 1) {
					cheeseMelt(i, j);
				}
			}
		}
        // 시간을 증가시킴
		day++;
		memset(outsideAir, 0, sizeof(outsideAir));
	}

	cout << day;
}