#define pb push_back
#define pillar 0
#define beam 1
#define setup 1
#define INF 1000000

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[110][110][2]; // 격자판

bool check(int n, int y, int x) {

	bool flag = true;
	// 기둥 확인
	if (arr[y][x][pillar] == setup) {

		// 내 아래에 기둥이 있거나, 한 쪽에 보가 있을 경우 기둥 유효함
		if (y == 0 || arr[y - 1][x][pillar] == 1 || arr[y][x][beam] == 1 ||
			(x > 0 && arr[y][x - 1][beam] == 1)) {
			flag = true;
		}

		else
			return false;
	}

	// 보 확인
	if (arr[y][x][beam] == setup) {

		// 보 설치 시 양쪽 중 하나 밑에 기둥이 있으면 유효함
		// 혹은 양 옆에 보가 있어도 유효함
		if ((y > 0 && arr[y - 1][x][pillar] == 1) || (y > 0 && arr[y - 1][x + 1][pillar] == 1)
			|| (x > 0 && x < n && arr[y][x - 1][beam] == 1 && arr[y][x + 1][beam] == 1)) {
			flag = true;
		}
		else
			return false;
	}
	return true;

}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	vector<int> temp;

	// 처음에 격자판을 모두 -로 초기화
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			arr[i][j][0] = -INF;
			arr[i][j][1] = -INF;
		}
	}

	for (int i = 0; i < build_frame.size(); i++) {
		int x = build_frame[i][0];
		int y = build_frame[i][1];
		int category = build_frame[i][2];
		int crtORdel = build_frame[i][3];

		// 설치
		if (crtORdel == 1) {
			// 기둥일 경우
			if (category == pillar) {
				arr[y][x][pillar] = setup; // 일단 설치 후 검증
				if (check(n, y, x) == false) {
					arr[y][x][pillar] = -INF;
				}
			}

			// 보일 경우
			else {
				arr[y][x][beam] = setup; // 일단 설치 후 검증
				if (check(n, y, x) == false) {
					arr[y][x][beam] = -INF;
				}
			}
		}

		// 삭제
		else {
			// 기둥일 경우
			if (category == pillar) {
				if (arr[y][x][pillar] == setup) {
					arr[y][x][pillar] = -INF; // 일단 삭제 후 검증
					// 기둥이 삭제될 경우 0. 그 자리 검사
					// 1. 그 위에 있던 기둥의 유효성 검증
					// 2. 그 기둥으로 서있을 수 있었던 보의 위치 검사
					if (!(check(n, y, x) && check(n, y + 1, x) && check(n, y + 1, x - 1))) {
						arr[y][x][pillar] = setup;
					}
				}
			}

			// 보일 경우
			else {
				if (arr[y][x][beam] == setup) {
					arr[y][x][beam] = -INF; // 일단 삭제 후 검증
					// 보가 삭제될 경우
					// 1. 그 좌표 뿐만 아니라 그 옆에 있던 보들도 유효성 검사
					if (!(check(n, y, x) && check(n, y, x - 1) && check(n, y, x + 1))) {
						arr[y][x][beam] = setup;
					}
				}
			}
		}
	}

	vector<int> answer_temp;

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (arr[i][j][pillar] == setup) {
				answer_temp.pb(j);
				answer_temp.pb(i);
				answer_temp.pb(pillar);

				answer.pb(answer_temp);
				answer_temp.clear();
			}
			if (arr[i][j][beam] == setup) {
				answer_temp.pb(j);
				answer_temp.pb(i);
				answer_temp.pb(beam);

				answer.pb(answer_temp);
				answer_temp.clear();
			}
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}