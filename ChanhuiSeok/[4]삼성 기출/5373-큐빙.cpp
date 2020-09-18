#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#include <string>

using namespace std;

#define U 0
#define D 1
#define F 2
#define B 3
#define L 4
#define R 5

string cube[6][3][3];
// U D F B L R
string color[6] = { "w","y","r","o","g","b" };

int n;

void rotate2(char side, char dir) {

	// 얼마나 회전시킬 것인지 판단
	// 시계 방향이면 1번만, 반시계 방향이면 시계 방향으로 3번
	int cnt;
	if (dir == '+') cnt = 1;
	else if (dir == '-') cnt = 3;

	// cnt번 만큼 회전시켜 본다.
	for (int i = 1; i <= cnt; i++) {
		string temp[6][3][3]; // 복사용
		int idx = 0;

		// 임시 배열에 복사 (회전할 때 기존것 참조용)
		for (int k = 0; k < 6; k++) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[k][i][j] = cube[k][i][j];
				}
			}
		}

		// 각 면에 따른 인덱스 지정(map 대신)
		if (side == 'U') idx = 0;
		else if (side == 'D') idx = 1;
		else if (side == 'F') idx = 2;
		else if (side == 'B') idx = 3;
		else if (side == 'L') idx = 4;
		else if (side == 'R') idx = 5;

		// 먼저 돌리고자 하는 면 자체를 회전시킨다.
		cube[idx][0][0] = temp[idx][2][0];
		cube[idx][0][1] = temp[idx][1][0];
		cube[idx][0][2] = temp[idx][0][0];
		cube[idx][1][0] = temp[idx][2][1];
		cube[idx][1][2] = temp[idx][0][1];
		cube[idx][2][0] = temp[idx][2][2];
		cube[idx][2][1] = temp[idx][1][2];
		cube[idx][2][2] = temp[idx][0][2];

		// 돌리려는 면과 연관된 위,아래,왼,옆 면들을 돌린다.
		if (side == 'U') {

			cube[B][0][0] = temp[L][0][0];
			cube[B][0][1] = temp[L][0][1];
			cube[B][0][2] = temp[L][0][2];

			cube[R][0][2] = temp[B][0][2];
			cube[R][0][1] = temp[B][0][1];
			cube[R][0][0] = temp[B][0][0];

			cube[F][0][0] = temp[R][0][0];
			cube[F][0][1] = temp[R][0][1];
			cube[F][0][2] = temp[R][0][2];

			cube[L][0][0] = temp[F][0][0];
			cube[L][0][1] = temp[F][0][1];
			cube[L][0][2] = temp[F][0][2];
		}
		else if (side == 'D') {
			
			cube[F][2][2] = temp[L][2][2];
			cube[F][2][1] = temp[L][2][1];
			cube[F][2][0] = temp[L][2][0];

			cube[R][2][0] = temp[F][2][0];
			cube[R][2][1] = temp[F][2][1];
			cube[R][2][2] = temp[F][2][2];

			cube[B][2][2] = temp[R][2][2];
			cube[B][2][1] = temp[R][2][1];
			cube[B][2][0] = temp[R][2][0];

			cube[L][2][2] = temp[B][2][2];
			cube[L][2][1] = temp[B][2][1];
			cube[L][2][0] = temp[B][2][0];

		}
		else if (side == 'F') {
			
			cube[U][2][2] = temp[L][0][2];
			cube[U][2][1] = temp[L][1][2];
			cube[U][2][0] = temp[L][2][2];

			cube[R][0][0] = temp[U][2][0];
			cube[R][1][0] = temp[U][2][1];
			cube[R][2][0] = temp[U][2][2];

			cube[D][0][0] = temp[R][2][0];
			cube[D][0][1] = temp[R][1][0];
			cube[D][0][2] = temp[R][0][0];

			cube[L][0][2] = temp[D][0][0];
			cube[L][1][2] = temp[D][0][1];
			cube[L][2][2] = temp[D][0][2];

		}
		else if (side == 'B') {
			
			cube[U][0][0] = temp[R][0][2];
			cube[U][0][1] = temp[R][1][2];
			cube[U][0][2] = temp[R][2][2];

			cube[L][0][0] = temp[U][0][2];
			cube[L][1][0] = temp[U][0][1];
			cube[L][2][0] = temp[U][0][0];

			cube[D][2][2] = temp[L][2][0];
			cube[D][2][1] = temp[L][1][0];
			cube[D][2][0] = temp[L][0][0];

			cube[R][0][2] = temp[D][2][2];
			cube[R][1][2] = temp[D][2][1];
			cube[R][2][2] = temp[D][2][0];

		}
		else if (side == 'R') {
			
			cube[U][0][2] = temp[F][0][2];
			cube[U][1][2] = temp[F][1][2];
			cube[U][2][2] = temp[F][2][2];

			cube[B][0][0] = temp[U][2][2];
			cube[B][1][0] = temp[U][1][2];
			cube[B][2][0] = temp[U][0][2];

			cube[D][0][2] = temp[B][2][0];
			cube[D][1][2] = temp[B][1][0];
			cube[D][2][2] = temp[B][0][0];

			cube[F][0][2] = temp[D][0][2];
			cube[F][1][2] = temp[D][1][2];
			cube[F][2][2] = temp[D][2][2];

		}
		else if (side == 'L') {
			
			cube[U][2][0] = temp[B][0][2];
			cube[U][1][0] = temp[B][1][2];
			cube[U][0][0] = temp[B][2][2];

			cube[F][0][0] = temp[U][0][0];
			cube[F][1][0] = temp[U][1][0];
			cube[F][2][0] = temp[U][2][0];

			cube[D][2][0] = temp[F][2][0];
			cube[D][1][0] = temp[F][1][0];
			cube[D][0][0] = temp[F][0][0];

			cube[B][0][2] = temp[D][2][0];
			cube[B][1][2] = temp[D][1][0];
			cube[B][2][2] = temp[D][0][0];
		}

	}


}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int T = 0; T < t; T++) {
		// 큐브 색깔 초기화
		for (int k = 0; k < 6; k++) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cube[k][i][j] = color[k];
				}
			}
		}

		cin >> n;
		for (int i = 0; i < n; i++) {
			string input;
			cin >> input;

			rotate2(input[0], input[1]);
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[U][i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}