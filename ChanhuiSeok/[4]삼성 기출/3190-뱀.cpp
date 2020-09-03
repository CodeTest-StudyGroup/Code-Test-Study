#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define EMPTY 0
#define APPLE 1
#define SNAKE 2
#define WALL 5

#define UP 10
#define DOWN 11
#define LEFT 12
#define RIGHT 13

using namespace std;

typedef struct{
	int dir;
	int y;
	int x;
}snake;

int arr[102][102];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

string info[10001];
queue<snake> q;

bool moving(int dir) {
	snake temp;
	int ty = q.back().y;
	int tx = q.back().x;

	if (dir == UP) { ty += dy[0]; tx += dx[0]; }
	else if (dir == DOWN) { ty += dy[1]; tx += dx[1]; }
	else if (dir == LEFT) { ty += dy[2]; tx += dx[2]; }
	else if (dir == RIGHT) { ty += dy[3]; tx += dx[3]; }

	// 다음 칸이 벽이거나 자기 자신일 경우 바로 종료하기
	if (arr[ty][tx] == WALL || arr[ty][tx] == SNAKE) {
		return false;
	}

	// 다음 칸이 사과일 경우
	if (arr[ty][tx] == APPLE) {
		temp.y = ty; temp.x = tx; temp.dir = dir;
		q.push(temp);
		arr[ty][tx] = SNAKE; // 뱀으로 채우기
	}

	// 다음 칸이 사과가 아닐 경우
	else {
		temp.y = ty; temp.x = tx; temp.dir = dir;
		q.push(temp);
		arr[ty][tx] = SNAKE; // 뱀 몸통으로 채우기

		// 뱀의 꼬리 부분의 좌표값 얻기
		int tail_y = q.front().y;
		int tail_x = q.front().x;
		arr[tail_y][tail_x] = EMPTY; // 게임판에서 꼬리 부분 제거하기
		q.pop(); // 꼬리 제거
	}

	return true;
}

int changeDir_func(int originDir, string change) {

	int changedDir;

	if (change == "D") {
		if (originDir == UP) changedDir = RIGHT;
		else if (originDir == DOWN) changedDir = LEFT;
		else if (originDir == LEFT) changedDir = UP;
		else if (originDir == RIGHT) changedDir = DOWN;
	}

	else if (change == "L") {
		if (originDir == UP) changedDir = LEFT;
		else if (originDir == DOWN) changedDir = RIGHT;
		else if (originDir == LEFT) changedDir = DOWN;
		else if (originDir == RIGHT) changedDir = UP;
	}

	return changedDir;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	int row, col;
	int L, sec;
	string dir;

	// 뱀 초기화
	snake sna;
	sna.y = 1;  sna.x = 1; sna.dir = RIGHT;
	q.push(sna);

	// 게임판 초기화
	for (int i = 0; i < N + 2; i++) 
		for (int j = 0; j < N + 2; j++) 
			arr[i][j] = WALL;		
	
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			arr[i][j] = EMPTY;		
	
	for (int i = 0; i < K; i++) {
		cin >> row >> col;
		arr[row][col] = APPLE; // 1은 사과
	}

	// 뱀의 방향정보 입력
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> sec >> dir;
		info[sec] = dir;
	}

	// (1,1) 에서 시작. 뱀은 처음에 오른쪽을 향한다.
	int time = 0;

	while (1) {
		// 뱀 머리의 방향값 임시 저장
		int headDir = q.back().dir;
		int changeDir;

		// 매 초마다 이동, 뱀의 머리값 넘기기
		if (!moving(headDir)) 
			break;
			
		time += 1; // 시간 흐름

		// 매 초가 끝난 뒤 방향 전환 여부 파악
		if (info[time] == "D" || info[time] == "L") {

			// 머리 부분의 방향을 바꾸기
			changeDir = changeDir_func(headDir, info[time]);
			q.back().dir = changeDir;
		}

		/* 상황 출력 */
		/*
		for (int i = 0; i <= N+2; i++) {
			for (int j = 0; j <= N+2; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		*/
	}
	
	cout << time + 1;

	return 0;
}