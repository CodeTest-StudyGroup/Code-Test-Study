#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int N, M, H;
int minV = 987654321;
int board[34][34];

int ret = 987654321;

// i->i 가 가능한지 체크하는 함수
bool check() {
	// N개의 선
	for (int i = 1; i <= N; i++) {
		int startIdx = i; // startIdx번째 입구에서 사다리타기 시작
		
		// H 높이만큼 실행해 본다.
		for (int j = 1; j <= H; j++) {
			if (board[j][startIdx] == 1) {
				// 그 사다리를 타고 오른쪽으로 가본다.
				startIdx += 1;
			}
			// 왼쪽에 가로선이 있을 경우
			else if (board[j][startIdx - 1] == 1) {
				startIdx -= 1;
			}
		}

		// 사다리타기를 모두 완료했는데 다른 출구일 경우
		// 한 번이라도 다르면 답이 아니므로 바로 false 반환하고 종료
		if (startIdx != i) {
			return false;
		}
	}
	return true;
}

// dfs 함수
void dfs(int line, int cnt) {

	if (cnt > 3) return;
	// i->i가 모두 가능할 경우
	if (check() == true) {
		ret = min(ret, cnt);
		if (ret == 1) {
			printf("%d", ret);
			exit(0);
		}
		return;
	}

	for (int i = line; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			// 이미 설치되어 있을 경우 다른 칸 알아보기
			if (board[i][j - 1] == 1 || board[i][j + 1] == 1 || board[i][j] == 1) {
				continue;
			}
			// 아닐 경우 그 칸에 설치 후 설치 갯수 증가시키며 재귀함수 실행
			board[i][j] = 1;
			dfs(i, cnt + 1);
			board[i][j] = 0; // 복귀 - 설치 취소
		}
	}

}

int main() {

	int a, b;
	scanf("%d %d %d", &N, &M, &H);

	// board[a][b] : b와 b+1 선 사이에 a번째 가로선이 위치한 것
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		board[a][b] = 1;
	}

	if (check() == true) {
		cout << 0;
		return 0;
	}

	dfs(1, 0);
	if (ret != 987654321)
		printf("%d", ret);
	else
		printf("-1");

	return 0;
}