//
//  20057_마법사 상어와 토네이도.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/10/20.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos { int r, c; };

// 좌하우상
const int dr[] = {0, 1, 0, -1};
const int dc[] = {-1, 0, 1, 0};
const int MAX = 500;
int map[MAX][MAX];
int n;
int answer;

Pos coord(Pos& p, int d) {
	return { p.r + dr[d], p.c + dc[d] };
}

bool inRange(Pos& p) {
	return (0 <= p.r && p.r < n) && (0 <= p.c && p.c < n);
}

void flutter(Pos p, int d) {
	int sum = 0;
	vector<pair<Pos, double>> pos;
	Pos a = coord(p, (d + 3) % 4);
	Pos aa = coord(a, (d + 3) % 4);
	Pos aaa = coord(a, (d + 2) % 4);
	Pos b = coord(p, (d + 1) % 4);
	Pos bb = coord(b, (d + 1) % 4);
	Pos bbb = coord(b, (d + 2) % 4);
	pos.push_back({ a, 0.07 });
	pos.push_back({ b, 0.07 });
	pos.push_back({ aa, 0.02 });
	pos.push_back({ bb, 0.02 });
	pos.push_back({ aaa, 0.01 });
	pos.push_back({ bbb, 0.01 });
	pos.push_back({ coord(a, d), 0.10 });
	pos.push_back({ coord(b, d), 0.10 });
	Pos alpha = coord(p, d);
	pos.push_back({ coord(alpha, d), 0.05 });
	for (auto& a: pos) {
		int amount = int(map[p.r][p.c] * a.second);
		sum += amount;
		if (inRange(a.first))
			map[a.first.r][a.first.c] += amount;
		else
			answer += amount;
	}
	int remain = map[p.r][p.c] - sum;
	if (inRange(alpha))
		map[alpha.r][alpha.c] += remain;
	else
		answer += remain;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> map[i][j];
	answer = 0;
	Pos x = { n / 2, n / 2 };
	int d = 0;
	bool flag = false;
	for (int i = 1; i <= n && !flag; ++i) {
		for (int k = 0; k < 2 && !flag; ++k) {
			for (int j = 0; j < i && !flag; ++j) {
				Pos y = coord(x, d);
				flutter(y, d);
				x = y;
				if (x.r == 0 && x.c == 0)
					flag = true;
			}
			d = (d + 1) % 4;
		}
	}
	cout << answer << endl;
	return 0;
}
