#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> stk;
	int crashCount = 0;

	for (int i = 0; i < moves.size(); i++) {

		// N*N 판에서 열 단위로 파악해 본다.
		for (int j = 0; j < board.size(); j++) {
			// j번째 행, movse[i]번째 열
			// 한 번 넣었으면, 다음으로 이동한다.
			if (board[j][moves[i] - 1] != 0) {

				/* 스택에서 터지는 것 구현 */
				if (!stk.empty() && stk.top() == board[j][moves[i] - 1]) {
					stk.pop();
					crashCount += 2; // 2개 터짐					
				}
				else {
					stk.push(board[j][moves[i] - 1]);
				}
				board[j][moves[i] - 1] = 0;
				break;
			}
		}
	}

	return crashCount;
}