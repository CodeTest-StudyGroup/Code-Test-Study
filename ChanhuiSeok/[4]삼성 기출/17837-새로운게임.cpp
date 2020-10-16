#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <deque>

using namespace std;

#define WHITE 0
#define RED 1
#define BLUE 2

int N, K;
int board[14][14];

int dy[5] = { 0, 0, 0,-1,1 };
int dx[5] = { 0, 1,-1,0,0 };

typedef struct chess {
	int row;
	int col;
	int dir;
}Chess;

// 다른 말들이 쌓일 것을 대비한 deque 2차원 배열
deque<int> arr[14][14];

// 체스의 위치 및 방향 정보를 갱신하는 1차원 정보 배열
Chess chess[12];

// 체스 방향 바꿔주는 함수
int change(int dir) {
	if (dir == 1) return 2;
	if (dir == 2) return 1;
	if (dir == 3) return 4;
	if (dir == 4) return 3;
}

bool simulation() {

	// 모든 말들을 차례대로 살펴보기
	for (int i = 1; i <= K; i++) {
		int c_row = chess[i].row;
		int c_col = chess[i].col;
		int c_dir = chess[i].dir;

		// cur_dir 방향대로 움직여 보기
		int next_row = c_row + dy[c_dir];
		int next_col = c_col + dx[c_dir];

		// 흰색 칸이었을 경우
		if (board[next_row][next_col] == WHITE) {
			// 현재 i번째 말 포함 맨 위의 말들까지 그 칸으로 이동
			// i번째 말이 속한 칸의 정보로 확인
			deque<int> tmp; // 이동할 말 정보 담기
			
			// 덱의 맨 앞에서부터 i가 나올 때까지 확인
			int idx = 0;
			for (idx = 0; idx < arr[c_row][c_col].size(); idx++) {
				if (arr[c_row][c_col][idx] == i)
					break;
			}
			// idx부터 끝까지 담는다.
			int size = arr[c_row][c_col].size() - idx;
			for (int j = 0; j < size; j++) {
				tmp.push_front(arr[c_row][c_col].back());
				arr[c_row][c_col].pop_back();
			}

			// tmp에 담긴 정보를 다음 이동할 칸에 back으로 넣는다.
			for (int m = 0; m < tmp.size(); m++) {
				arr[next_row][next_col].push_back(tmp[m]);
				chess[tmp[m]].row = next_row;
				chess[tmp[m]].col = next_col;
			}
			if (arr[next_row][next_col].size() >= 4) {
				// 게임 종료
				return true;
			}
		}
		else if (board[next_row][next_col] == RED) {
			// 이동은 하는데 순서를 반대로 바꾸어서 쌓는다.
			deque<int> tmp; // 이동할 말 정보 담기

			// 덱의 맨 앞에서부터 i가 나올 때까지 확인
			int idx = 0;
			for (idx = 0; idx < arr[c_row][c_col].size(); idx++) {
				if (arr[c_row][c_col][idx] == i)
					break;
			}
			// idx부터 끝까지 담는다.
			int size = arr[c_row][c_col].size() - idx;
			for (int j = 0; j < size; j++) {
				tmp.push_back(arr[c_row][c_col].back());
				arr[c_row][c_col].pop_back();
			}

			// tmp에 담긴 정보를 다음 이동할 칸에 back으로 넣는다.
			for (int m = 0; m < tmp.size(); m++) {
				arr[next_row][next_col].push_back(tmp[m]);
				chess[tmp[m]].row = next_row;
				chess[tmp[m]].col = next_col;
			}

			if (arr[next_row][next_col].size() >= 4) {
				// 게임 종료
				return true;
			}
		}
		else if (board[next_row][next_col] == BLUE) {
			// 현재 말의 방향을 바꾼다.
			chess[i].dir = change(chess[i].dir);
			int n_row = c_row + dy[chess[i].dir];
			int n_col = c_col + dx[chess[i].dir];

			// BLUE가 아닐 경우 바뀐 방향으로 한 칸 이동한다. 한 말이 이동할 때는 위에 올려진
			// 말도 반드시 함께 이동하는 조건을 유의하자.
			if (board[n_row][n_col] == WHITE) {
				deque<int> tmp; // 이동할 말 정보 담기

				// 덱의 맨 앞에서부터 i가 나올 때까지 확인
				int idx = 0;
				for (idx = 0; idx < arr[c_row][c_col].size(); idx++) {
					if (arr[c_row][c_col][idx] == i)
						break;
				}
				// idx부터 끝까지 담는다.
				int size = arr[c_row][c_col].size() - idx;
				for (int j = 0; j < size; j++) {
					tmp.push_front(arr[c_row][c_col].back());
					arr[c_row][c_col].pop_back();
				}
				// tmp에 담긴 정보를 다음 이동할 칸에 back으로 넣는다.
				for (int m = 0; m < tmp.size(); m++) {
					arr[n_row][n_col].push_back(tmp[m]);
					chess[tmp[m]].row = n_row;
					chess[tmp[m]].col = n_col;
				}

				if (arr[n_row][n_col].size() >= 4) {
					// 게임 종료
					return true;
				}
			}
			else if (board[n_row][n_col] == RED) {
				// 이동은 하는데 순서를 반대로 바꾸어서 쌓는다.
				deque<int> tmp; // 이동할 말 정보 담기

				// 덱의 맨 앞에서부터 i가 나올 때까지 확인
				int idx = 0;
				for (idx = 0; idx < arr[c_row][c_col].size(); idx++) {
					if (arr[c_row][c_col][idx] == i)
						break;
				}
				// idx부터 끝까지 담는다.
				int size = arr[c_row][c_col].size() - idx;
				for (int j = 0; j < size; j++) {
					tmp.push_back(arr[c_row][c_col].back());
					arr[c_row][c_col].pop_back();
				}

				// tmp에 담긴 정보를 다음 이동할 칸에 back으로 넣는다.
				for (int m = 0; m < tmp.size(); m++) {
					arr[n_row][n_col].push_back(tmp[m]);
					chess[tmp[m]].row = n_row;
					chess[tmp[m]].col = n_col;
				}

				if (arr[n_row][n_col].size() >= 4) {
					// 게임 종료
					return true;
				}
			}
		} // end if
	}//end for

	return false;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	// 맨 바깥을 BLUE로 채워놓는다.
	for (int i = 0; i <= N+1; i++) {
		board[0][i] = BLUE;
		board[N + 1][i] = BLUE;
		board[i][0] = BLUE;
		board[i][N + 1] = BLUE;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int row, col, dir;
		cin >> row >> col >> dir;
		arr[row][col].push_back(i + 1);
		chess[i + 1].row = row;
		chess[i + 1].col = col;
		chess[i + 1].dir = dir;
	}

	bool flag = false;
	int i = 1;
	for (i = 1; i <= 1000; i++) {
		flag = simulation();
		if (flag) break;
	}

	if (flag == true)
		cout << i;
	else if (flag == false || i > 1000)
		cout << -1;

	return 0;
}