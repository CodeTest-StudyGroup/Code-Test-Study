//≈‰∏∂≈‰

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;
int m, n, h;

typedef struct Tomato {
	int h;
	int n;
	int m;
	int day;
}Tomato;

int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

map<int, int> m1;
int c = 0;
vector<vector<vector<int>>> v;
queue<Tomato> q;

int main() {
	scanf("%d %d %d", &m, &n, &h);
	for (int i = 0; i < h; i++) {
		vector<vector<int>> v1;
		for (int j = 0; j < n; j++) {
			int num;
			vector<int> v2;
			for (int k = 0; k < m; k++) {
				scanf("%d", &num);
				if (num == 1) {
					Tomato t;
					t.h = i;
					t.n = j;
					t.m = k;
					t.day = 0;
					q.push(t);
				}
				else if (num == 0) {
					c++;
				}
				v2.push_back(num);
				m1[num]++;
			}
			v1.push_back(v2);
		}
		v.push_back(v1);
	}

	if (m1[1] == 0) {
		printf("-1");
		return 0;
	}
	else if (m1[0] == 0) {
		printf("0");
		return 0;
	}

	while (!q.empty()) {
		Tomato t = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int z = t.h + dz[i];
			int x = t.n + dx[i];
			int y = t.m + dy[i];
			if (z >= 0 && z < h && x >= 0 && x < n && y >= 0 && y < m) {
				if (v[z][x][y] == 0) {
					Tomato t1;
					c--;
					if (c == 0) {
						printf("%d",t.day+1);
						return 0;
					}
					v[z][x][y] = 1;
					t1.h = z;
					t1.n = x;
					t1.m = y;
					t1.day = t.day + 1;
					q.push(t1);
				}
			}
		}
	}

	if (c != 0) {
		printf("-1");
	}
	return 0;

}