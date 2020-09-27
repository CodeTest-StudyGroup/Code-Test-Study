#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
#include <cstring>
#include <string>

using namespace std;

int D(int num) {
	int tmp = num * 2 % 10000;
	return tmp;
}

int S(int num) {
	int tmp = num - 1;
	if (num == 0) tmp = 9999;
	return tmp;
}

int L(int num) {
	int tmp = (num % 1000) * 10 + num / 1000;
	return tmp;
}

int R(int num) {
	int tmp = (num / 10) + (num % 10) * 1000;
	return tmp;
}

string simulation(int origin, int target) {

	bool counts[10001];
	for (int i = 0; i < 10001; i++) {
		counts[i] = false;
	}

	queue<pair<int, string> > q;

	// origin ---> target 최소 횟수
	int reg = origin;
	counts[origin] = 1;
	q.push({ origin , "" });

	int num;
	string dir;

	while (!q.empty()) {
		num = q.front().first;
		dir = q.front().second;
		q.pop();

		// 목표값을 찾으면 바로 종료
		if (num == target) break;
		
		int d = D(num);
		int l = L(num);
		int s = S(num);
		int r = R(num);

		if (counts[d] == 0) {
			if (d == target) {
				dir = dir + "D";
				break;
			}
			q.push({ d, dir + "D" });
			counts[d] = 1;
		}

		if (counts[s] == 0) {
			if (s == target) {
				dir = dir + "S";
				break;
			}
			q.push({ s, dir + "S" });
			counts[s] = 1;
		}

		if (counts[l] == 0) {	
			if (l == target) {
				dir = dir + "L";
				break;
			}
			q.push({ l, dir + "L" });
			counts[l] = 1;
		}

		if (counts[r] == 0) {
			if (r == target) {
				dir = dir + "R";
				break;
			}
			q.push({ r, dir + "R" });
			counts[r] = 1;
		}
	}
	return dir;
}


int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K, T;
	int a, b;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> a >> b;
		// a는 레지스터 초기 값, b는 최종 값

		// simulation
		string res = simulation(a, b);
		cout << res << '\n';
	}

	return 0;
}