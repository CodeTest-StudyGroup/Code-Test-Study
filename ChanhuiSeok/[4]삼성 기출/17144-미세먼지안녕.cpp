#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int board[52][52];
int visit[52][52];
int m_board[52][52];
int cp_board[52][52];

int R, C, T;

vector<pair<int, int>> purifier;

void purify() {

	memset(m_board, 0, sizeof(m_board));

	// 복사 배열 만들기
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cp_board[i][j] = board[i][j];
		}
	}

	// 첫 번째 공기청정기는 반시계방향
	int fy = purifier[0].first;
	int fx = purifier[0].second;

	// 공기청정기가 위치한 행, 다음 오른쪽 칸부터 차례대로 순환 시작
	int ty = fy, tx = fx;

	// 공기청정기 표시
	m_board[fy][fx] = -1;

	/* ------------> 방향 */
	for (int i = tx + 1; i <= C - 1; i++) 
		m_board[ty][i + 1] = cp_board[ty][i];
	
	/* |위 방향 */
	for (int i = ty; i >= 2; i--) 
		m_board[i - 1][C] = cp_board[i][C];
	
	/* <------------ 방향 */
	for (int i = C; i >= 2; i--) 
		m_board[1][i - 1] = cp_board[1][i];
	
	/* |아래 방향 */
	for (int i = 1; i < fy - 1; i++) 
		m_board[i + 1][1] = cp_board[i][1];
	
	// 이동 안 한 나머지 칸도 기록하기
	// 2행부터 ~ fy-1 행까지, fx+1열부터 ~ C - 1열까지
	for (int i = 2; i <= fy - 1; i++) {
		for (int j = fx+1; j <= C - 1; j++) {
			m_board[i][j] = board[i][j];
		}
	}

	// 두 번째 공기청정기는 시계방향
	int sy = purifier[1].first;
	int sx = purifier[1].second;

	// 공기청정기가 위치한 행, 다음 오른쪽 칸부터 차례대로 시계 방향 순환 시작
	ty = sy, tx = sx;

	// 공기청정기 표시
	m_board[sy][sx] = -1;
	
	/* ----------> 방향 */
	for (int i = tx + 1; i <= C - 1; i++) 
		m_board[ty][i + 1] = cp_board[ty][i];
	
	/* | 아래 방향 */
	for (int i = sy; i <= R - 1; i++) 
		m_board[i + 1][C] = cp_board[i][C];	

	/* <------- 방향 */
	for (int i = C; i >= 2; i--) 
		m_board[R][i - 1] = cp_board[R][i];

	/* | 위 방향 */
	for (int i = R; i > sy + 1; i--) 
		m_board[i - 1][1] = cp_board[i][1];
	

	// 이동 안 한 나머지 칸도 기록하기
	// sy + 1행부터 ~ R-1 행까지, sx+1열부터 ~ C - 1열까지
	for (int i = sy+1; i <= R - 1; i++) {
		for (int j = sx + 1; j <= C - 1; j++) {
			m_board[i][j] = board[i][j];
		}
	}
	
	// 이후, 새로운 미세먼지 칸에 다시 visit 표기
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			// 미세먼지일 경우 확산 대상임을 먼저 표시
			if (m_board[i][j] != 0 && m_board[i][j] != -1) {
				visit[i][j] = m_board[i][j];
			}
		}
	}
	
	// board판 갱신
	for (int i = 1; i <= R; i++) 
		for (int j = 1; j <= C; j++) 
			board[i][j] = m_board[i][j];
			
}

void diffusion() {

	// 1초 동안, [1]미세먼지의 확산 이후 [2]공기청정기가 작동한다.
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {

			// 확산 대상일 경우
			if (visit[i][j] != 0) {
				int cnt = 0; // 몇 칸이나 확산했는지 여부
				int val = visit[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int ty = i + dy[k];
					int tx = j + dx[k];

					// 가능한 칸일 경우에만
					if (ty > 0 && tx > 0 && ty <= R && tx <= C
						&& board[ty][tx] != -1) {
						cnt += 1;
						board[ty][tx] = board[ty][tx] + val;
					}
				}
				board[i][j] = board[i][j] - (val * cnt);
			}
		}
	}

	// 다음 시간에서 새로운 미세먼지 칸을 위해 일단 초기화
	memset(visit, 0, sizeof(visit));

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> T;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> board[i][j];
			// 미세먼지일 경우 확산 대상임을 먼저 표시
			if (board[i][j] != 0 && board[i][j] != -1) {
				visit[i][j] = board[i][j];
			}
			// 공기청정기일 경우 좌표값 저장
			else if (board[i][j] == -1)
				purifier.push_back({ i,j });
		}
	}

	while (T > 0) {
		/* 확산 */
		diffusion();

		/* 청정 */
		purify();

		T--;
	}

	int res = 0;

	// 남아있는 미세먼지 양 더하기
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (board[i][j] != -1 && board[i][j] != 0) {
				res += board[i][j];
			}
		}
	}

	cout << res;

	return 0;
}