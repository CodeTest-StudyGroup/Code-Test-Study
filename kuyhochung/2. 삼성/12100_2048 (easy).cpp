#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define MAX_N 20

int n;
int board[MAX_N][MAX_N];
int maxValue = 0;

void array_copy(int from[][MAX_N], int to[][MAX_N]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			to[i][j] = from[i][j];
		}
	}
}

int get_max_value(int matrix[][MAX_N]) {
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result = max(result, matrix[i][j]);
		}
	}
	return result;
}

void matrix_shift(int dir, int round, int matrix[][MAX_N]) {
	if (round == 5) return;
	int current_max = 0;
	int board_copy[MAX_N][MAX_N];
	array_copy(matrix, board_copy);

	if (dir == 0) {						//왼쪽으로 모으기
		for (int i = 0; i < n; i++) {
			queue<int> q;
			stack<int> s;
			for (int j = n-1; j >= 0; j--) {
				int now = board_copy[i][j];
				if (now != 0) s.push(now);
			}
			for (int j = 0; j < n; j++) {
				board_copy[i][j] = 0;
			}
			while (!s.empty()) {
				int first = s.top();
				s.pop();
				if (s.empty()) {
					q.push(first);
				}
				else {
					int second = s.top();
					s.pop();
					if (first == second)
						q.push(first + second);
					else {
						q.push(first);
						s.push(second);
					}
				}
			}
			int j = 0;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				board_copy[i][j] = now;
				j++;
			}
		}
	}
	else if (dir == 1) {						//오른쪽으로 모으기
		for (int i = 0; i < n; i++) {
			queue<int> q;
			stack<int> s;
			for (int j = 0; j < n; j++) {
				int now = board_copy[i][j];
				if (now != 0) s.push(now);
			}
			for (int j = 0; j < n; j++) {
				board_copy[i][j] = 0;
			}
			while (!s.empty()) {
				int first = s.top();
				s.pop();
				if (s.empty()) {
					q.push(first);
				}
				else {
					int second = s.top();
					s.pop();
					if (first == second)
						q.push(first + second);
					else {
						q.push(first);
						s.push(second);
					}
				}
			}
			int j = n-1;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				board_copy[i][j] = now;
				j--;
			}
		}
	}
	else if (dir == 2) {						//왼쪽으로 모으기
		for (int j = 0; j < n; j++) {
			queue<int> q;
			stack<int> s;
			for (int i = n - 1; i >= 0; i--) {
				int now = board_copy[i][j];
				if (now != 0) s.push(now);
			}
			for (int i = 0; i < n; i++) {
				board_copy[i][j] = 0;
			}
			while (!s.empty()) {
				int first = s.top();
				s.pop();
				if (s.empty()) {
					q.push(first);
				}
				else {
					int second = s.top();
					s.pop();
					if (first == second)
						q.push(first + second);
					else {
						q.push(first);
						s.push(second);
					}
				}
			}
			int i = 0;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				board_copy[i][j] = now;
				i++;
			}
		}
	}
	else if (dir == 3) {
		for (int j = 0; j < n; j++) {
			queue<int> q;
			stack<int> s;
			for (int i = 0; i < n; i++) {
				int now = board_copy[i][j];
				if (now != 0) s.push(now);
			}
			for (int i = 0; i < n; i++) {
				board_copy[i][j] = 0;
			}
			while (!s.empty()) {
				int first = s.top();
				s.pop();
				if (s.empty()) {
					q.push(first);
				}
				else {
					int second = s.top();
					s.pop();
					if (first == second)
						q.push(first + second);
					else {
						q.push(first);
						s.push(second);
					}
				}
			}
			int i = n - 1;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				board_copy[i][j] = now;
				i--;
			}
		}

	}

	maxValue = max(maxValue, get_max_value(board_copy));
	for (int a = 0; a < 4; a++) {
		matrix_shift(a, round + 1, board_copy);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			board[i][j] = temp;
		}
	}

	for (int i = 0; i < 4; i++) {
		matrix_shift(i, 0, board);
	}
	cout << maxValue;
	return 0;
}