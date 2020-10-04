#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

int board[9][9];

// 가로 행 검사하는 함수
bool rowCheck(int rowNum) {
	int cnt[10];
	for (int i = 0; i < 10; i++) 
		cnt[i] = 0;
	
	for (int i = 0; i < 9; i++) {
		if (board[rowNum][i] != 0)
			cnt[board[rowNum][i]] += 1;
		if (cnt[board[rowNum][i]] >= 2) return false;
	}
	return true;
}

// 세로 열 검사하는 함수
bool colCheck(int colNum) {
	int cnt[10];
	for (int i = 0; i < 10; i++) 
		cnt[i] = 0;
	
	for (int i = 0; i < 9; i++) {
		if (board[i][colNum] != 0)
			cnt[board[i][colNum]] += 1;
		if (cnt[board[i][colNum]] >= 2) return false;
	}
	return true;
}

// 특정 칸이 몇 번째 단위정사각형에 포함되는지 반환
pair<int,int> squNum(int rowNum, int colNum) {
	if (rowNum >= 0 && rowNum <= 2) {
		if (0 <= colNum && colNum <= 2) {
			return { 0,0 };
		}
		else if (3 <= colNum && colNum <= 5) {
			return { 0,3 };
		}
		else if (6 <= colNum && colNum <= 8) {
			return { 0,6 };
		}
	}
	else if (rowNum >= 3 && rowNum <= 5) {
		if (0 <= colNum && colNum <= 2) {
			return { 3,0 };
		}
		else if (3 <= colNum && colNum <= 5) {
			return { 3,3 };
		}
		else if (6 <= colNum && colNum <= 8) {
			return { 3,6 };
		}
	}
	else if (rowNum >= 6 && rowNum <= 8) {
		if (0 <= colNum && colNum <= 2) {
			return { 6,0 };
		}
		else if (3 <= colNum && colNum <= 5) {
			return { 6,3 };
		}
		else if (6 <= colNum && colNum <= 8) {
			return { 6,6 };
		}
	}
}

// 특정 칸의 단위 정사각형 9칸을 검사하는 함수
bool squCheck(int rowNum, int colNum) {
	int cnt[10];
	for (int i = 0; i < 10; i++)
		cnt[i] = 0;

	pair<int, int> square_num = squNum(rowNum, colNum);
	int row = square_num.first;
	int col = square_num.second;

	for (int i = row; i < row + 3; i++) {
		for (int j = col; j < col + 3; j++) {
			if(board[i][j] != 0)
				cnt[board[i][j]] += 1;
			if (cnt[board[i][j]] >= 2) return false;
		}
	}
	return true;
}

void simulation(int row, int col) {

	// 칸을 다 채웠을 경우 출력 후 종료
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			// 빈 칸에 대해서 검사
			if (board[i][j] == 0) {

				//1부터 9까지 빈 칸에 대입해 본다.
				for (int k = 1; k <= 9; k++) {
					board[i][j] = k;
					// 모든 체크에 통과 시
					if (rowCheck(i) && colCheck(j) && squCheck(i, j)) {
						simulation(i, j);
					}
					board[i][j] = 0;
				}
				return;
			}

			if (i == 8 && j == 8) {
				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 9; j++) {
						if (board[i][j] == 0) {
							return;
						}
					}
				}
				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 9; j++) {
						cout << board[i][j] << ' ';
					}
					cout << '\n';
				}
				exit(0);
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
		}
	}
	simulation(0,0);
	return 0;
}