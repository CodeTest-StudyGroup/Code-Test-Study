#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define MAX 10000

int A, B;
bool visited[MAX];

string bfs() {
	int tempNum;
	queue<pair<int, string>> q;
	//큐에 n과 현재까지의 명령어를 저장
	q.push({ A, "" });
	visited[A] = true;

	while (!q.empty()) {
		int num = q.front().first;
		string str = q.front().second;
		q.pop();

		if (num == B)
			return str;

		//명령어가 D일 경우
		tempNum = (num * 2) % 10000;
		if (!visited[tempNum]) {
			q.push({ tempNum, str + "D" });
			visited[tempNum] = true;
		}
		//명령어가 S일 경우
		if (num == 0)
			tempNum = 9999;
		else
			tempNum = num - 1;
		if (!visited[tempNum]) {
			q.push({ tempNum, str + "S" });
			visited[tempNum] = true;
		}
		//명령어가 L일 경우
		tempNum = (num % 1000) * 10 + (num / 1000);
		if (!visited[tempNum]) {
			q.push({ tempNum, str + "L" });
			visited[tempNum] = true;
		}
		//명령어가 R일 경우
		tempNum = (num % 10) * 1000 + num / 10;
		if (!visited[tempNum]) {
			q.push({ tempNum, str + "R" });
			visited[tempNum] = true;
		}
	}
}

int main() {
	int T;
	vector<string> answer;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		answer.push_back(bfs());
		memset(visited, 0, sizeof(visited));
	}

	for (auto elem : answer) {
		cout << elem << '\n';
	}
}