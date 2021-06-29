#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define MAX_N 1001

int n, m;
int board[MAX_N][MAX_N];


int answer = 0;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= m; j++) {
			board[i][j] = temp[j - 1] - '0';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 0) continue;
			board[i][j] = min(board[i - 1][j], min(board[i - 1][j - 1], board[i][j - 1])) + 1;
			answer = max(answer, board[i][j]);
		}
	}

	cout << answer * answer;
	return 0;
}