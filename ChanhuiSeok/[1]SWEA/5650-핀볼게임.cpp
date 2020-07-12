#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

using namespace std;

int board[104][104];
vector <pair<int, int>> worm[11];

int direction[4] = { UP,DOWN,LEFT,RIGHT };

typedef struct {
	int dir;
	int y;
	int x;
}pinball;
pinball pin;


pair<int, int> getWorm(int num, int y, int x) {

	int ty, tx;
	if (worm[num][0].first != y || worm[num][0].second != x) {
		ty = worm[num][0].first;
		tx = worm[num][0].second;
	}
	else {
		ty = worm[num][1].first;
		tx = worm[num][1].second;
	}

	return make_pair(ty, tx);
}

int changeDir(int target, int myDir) {

	int retDir = myDir;

	switch (target) {
	case 1:
		if (myDir == UP) retDir = DOWN;
		else if (myDir == DOWN) retDir = RIGHT;
		else if (myDir == LEFT) retDir = UP;
		else if (myDir == RIGHT) retDir = LEFT;
		break;
	case 2:
		if (myDir == UP) retDir = RIGHT;
		else if (myDir == DOWN) retDir = UP;
		else if (myDir == LEFT) retDir = DOWN;
		else if (myDir == RIGHT) retDir = LEFT;
		break;
	case 3:
		if (myDir == UP) retDir = LEFT;
		else if (myDir == DOWN) retDir = UP;
		else if (myDir == LEFT) retDir = RIGHT;
		else if (myDir == RIGHT) retDir = DOWN;
		break;
	case 4:
		if (myDir == UP) retDir = DOWN;
		else if (myDir == DOWN) retDir = LEFT;
		else if (myDir == LEFT) retDir = RIGHT;
		else if (myDir == RIGHT) retDir = UP;
		break;
	case 5:
		if (myDir == UP) retDir = DOWN;
		else if (myDir == DOWN) retDir = UP;
		else if (myDir == LEFT) retDir = RIGHT;
		else if (myDir == RIGHT) retDir = LEFT;
		break;
	default:
		retDir = myDir;
	}

	return retDir;
}

int game(int i, int j, int dir) {

	/* 핀볼 정보 정의 */
	int curScore = 0;
	pin.y = i; pin.x = j; pin.dir = dir;

	int startY = i, startX = j;

	/* 핀볼 움직이기 */
	while (1) {
		// 움직이기
		if (pin.dir == UP) pin.y -= 1;		
		else if (pin.dir == DOWN) pin.y += 1;		
		else if (pin.dir == LEFT) pin.x -= 1;		
		else if (pin.dir == RIGHT) pin.x += 1;
		
		// 핀볼이 처음 위치일 경우 반복문을 빠져나온다.
		if (pin.y == startY && pin.x == startX)
			break;

		// 다음 갈 곳이 블랙홀이었을 경우, 반복문을 빠져나온다.
		if (board[pin.y][pin.x] == -1) {
			break;
		}

		// 다음 갈 곳이 1~5 블록이었을 경우, 방향을 바꿔준다.
		// 또한, 블록에 부딪혔으므로 점수가 증가된다.
		if (board[pin.y][pin.x] >= 1 && board[pin.y][pin.x] <= 5) {
			pin.dir = changeDir(board[pin.y][pin.x], pin.dir);
			curScore += 1;
		}

		// 다음 갈 곳이 웜홀이었을 경우, 핀볼의 위치를 다른 웜홀이 있는 곳으로 바꿔준다.
		else if (board[pin.y][pin.x] >= 6 && board[pin.y][pin.x] <= 10) {
			pair<int, int> temp;
			temp = getWorm(board[pin.y][pin.x], pin.y, pin.x);
			pin.y = temp.first;
			pin.x = temp.second;
		}			
	}

	return curScore;
}


int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int maxScore = 0;
	int T, N;
	cin >> T;

	// -1은 블랙홀, 0은 빈공간, 1~5는 블록, 6~10은 웜홀
	// 블랙홀이나 처음 위치로 도달하면 게임 종료, 점수는 벽이나 블록에 부딪힌 회수

	for (int t = 0; t < T; t++) {
		cin >> N; // N * N 게임판
		int score = 0;

		// 벽면 블록으로 처리
		for (int i = 0; i <= N + 1; i++) {
			for (int j = 0; j <= N + 1; j++) {
				board[i][j] = 5;
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> board[i][j];
				// 웜홀일 경우 쌍을 알아야 하므로 따로 저장
				if (board[i][j] >= 6 && board[i][j] <= 10) {
					worm[board[i][j]].push_back({ i,j });
				}
			}
		}
	
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				// 빈 공간일 경우 출발
				if (board[i][j] == 0) {

					for (int k = 0; k < 4; k++) {
						score = game(i, j, direction[k]);
						maxScore = max(maxScore, score);
					}
				}
			}
		}
		cout << "#" << t + 1 << " " << maxScore << '\n';
		maxScore = -100;
		
		for (int i = 6; i <= 10; i++) 
			worm[i].clear();		
	}

	return 0;
}