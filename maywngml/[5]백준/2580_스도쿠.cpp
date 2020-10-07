#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
#define MAX 9
//빈칸 위치 저장
vector<pair<int, int>> need_visit;
int MAP[MAX][MAX];
int zero_cnt = 0;
//행별 숫자 저장
bool row[MAX][MAX+1];
//열별 숫자 저장
bool column[MAX][MAX+1];
//정사각형내 숫자 저장
bool square[MAX][MAX+1];
//스도쿠 성공 플래그
bool flag = false;

void sudoku(int cnt) {
	//빈칸을 모두 채웠을 경우 스도쿠 출력
	if (cnt == zero_cnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << MAP[i][j] << " ";
			}
			cout << '\n';
		}
		//성공 플래그 true로 바꿈
		flag = true;
		return;
	}
	//빈칸의 좌표 저장
	int x = need_visit[cnt].first;
	int y = need_visit[cnt].second;
	//스도쿠에 채울 수 있는 숫자 모두 넣어가며 확인
	for (int i = 1; i <= 9; i++) {
		//해당 칸이 몇번째 정사각형안에 있는지 계산
		int temp = (x / 3) * 3 + (y / 3);
		//해당 숫자가 스도쿠 조건을 만족할 경우
		if (!row[x][i] && !column[y][i] && !square[temp][i]) {
			//빈칸 채움
			MAP[x][y] = i;
			//열, 행, 사각형 배열에 해당 숫자 저장
			row[x][i] = true;
			column[y][i] = true;
			square[temp][i] = true;
			//다음 빈칸 탐색
			sudoku(cnt + 1);
			//스도쿠를 모두 채웠다면 리턴
			if(flag)
				return;
			//스도쿠 조건이 맞지않아서 리턴됐을 경우
			//다시 빈칸으로 만듬
			MAP[x][y] = 0;
			//열, 행, 사각형 배열에 해당 숫자 false로 바꿈
			row[x][i] = false;
			column[y][i] = false;
			square[temp][i] = false;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> MAP[i][j];
			//해당 칸이 빈칸이 아닐 경우 
			if (MAP[i][j] != 0) {
				//해당 칸이 몇번째 정사각형안에 있는지 계산
				int temp = (i / 3) * 3 + (j / 3);
				//각 행, 열, 정사각형에 숫자 저장
				row[i][MAP[i][j]] = true;
				column[j][MAP[i][j]] = true;
				square[temp][MAP[i][j]] = true;
			}
			//해당 칸이 빈칸일 경우
			else {
				//방문할 지점 저장
				need_visit.push_back({ i, j });
				//빈칸 갯수 셈
				zero_cnt++;
			}
		}
	}

	sudoku(0);
}