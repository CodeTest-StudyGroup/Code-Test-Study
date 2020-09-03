#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>

#define top 1
#define bottom 6

typedef long long ll;

using namespace std;

int N, M, x, y, K;
int board[21][21];
int cur_x, cur_y;

int dice[7];
int tempDice[7];

void rolling(int dir) {
	memcpy(tempDice, dice, sizeof(dice));
	if (dir == 1) {
		dice[1] = tempDice[4];
		dice[6] = tempDice[3];
		dice[3] = tempDice[1];
		dice[4] = tempDice[6];
	}
	else if (dir == 2) {
		dice[1] = tempDice[3];
		dice[6] = tempDice[4];
		dice[3] = tempDice[6];
		dice[4] = tempDice[1];
	}
	else if (dir == 3) {
		dice[1] = tempDice[5];
		dice[6] = tempDice[2];
		dice[2] = tempDice[1];
		dice[5] = tempDice[6];
	}
	else if (dir == 4) {
		dice[1] = tempDice[2];
		dice[6] = tempDice[5];
		dice[2] = tempDice[6];
		dice[5] = tempDice[1];
	}
}

bool isValid(int x, int y) {
	if (x >= N || y >= M || x < 0 || y < 0) 
		return false;
	return true;
}

int simul(int dir) {

	// [1] 위치 이동시키기
	if (dir == 1) {
		if (isValid(cur_x, cur_y + 1)) 
			cur_y += 1;
		else return -1;
	}
	else if (dir == 2) {
		if (isValid(cur_x, cur_y - 1)) 
			cur_y -= 1;
		else return -1;
	}
	else if (dir == 3) {
		if (isValid(cur_x - 1, cur_y))
			cur_x -= 1;
		else return -1;
	}
	else {
		if (isValid(cur_x + 1, cur_y))
			cur_x += 1;
		else return -1;
	}

	// [1.5] 주사위 굴리기
	rolling(dir);

	// [2] 이동시킨 뒤 값 판별하기
	// 2-1. 이동한 곳에 쓰여있는 수가 0일 경우
	if (board[cur_x][cur_y] == 0) {
		// 주사위 바닥면에 쓰여 있는 수가 칸에 복사된다.
		board[cur_x][cur_y] = dice[bottom];
	}
	// 2-2. 이동한 곳에 쓰여있는 수가 0이 아닐 경우
	else {
		// 칸에 쓰여 있는 수가 주사위 바닥면으로 복사되고
		// 칸에 쓰인 수는 0이 된다.
		dice[bottom] = board[cur_x][cur_y];
		board[cur_x][cur_y] = 0;
	}

	return dice[top];
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> x >> y >> K;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int ret, dir;
	cur_x = x; cur_y = y;

	// 시뮬레이션
	for (int i = 0; i < K; i++) {
		cin >> dir;
		ret = simul(dir);
		if (ret != -1) {
			cout << ret << '\n';
		}
	}
	
	return 0;
}