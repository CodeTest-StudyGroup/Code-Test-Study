//盔件捞客 富 1600锅

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;


int arr[200][200];
//int visited[200][200][32];

int dx[8] = { -1,-2,1,2,2,1,-2 ,- 1 };
int dy[8] = { -2,-1,-2,-1,1,2,1,2 };
int dx2[4] = { 1,-1,0,0 };
int dy2[4] = { 0,0,-1,1 };


typedef struct Point {
	int x;
	int y;
	int k;
}Point;
Point p, p2;
queue<Point> q;

int main() {
	int k=0;
	int w=0;
	int	h=0;
	
	scanf("%d", &k);
	scanf("%d %d", &w, &h);
	
	

	//vector<vector<int>> arr(h, vector<int>(w, 0));
	vector<vector<vector<int>>> visited(h+1, vector<vector<int>>(w+1, vector<int>(k+1, 0)));
	visited[0][0][0] = 1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &arr[i][j]);
		}
	}


	p.x = 0;
	p.y = 0;
	p.k = 0;
	q.push(p);

	while (!q.empty()) {
		p = q.front();
		q.pop();
		if ( (p.x == h - 1) && (p.y == w - 1) ) {
			printf("%d", visited[p.x][p.y][p.k] - 1);
			return 0;
		}
		int x1=0, y1=0, k1=0;
		if (p.k < k) { //富
			for (int i = 0; i < 8; i++) {
				x1 = p.x + dx[i];
				y1 = p.y + dy[i];
				k1 = p.k + 1;
				if (x1 >= 0 && x1 < h && y1 >= 0 && y1 < w) {
					if ( (visited[x1][y1][k1] == 0) && (arr[x1][y1] == 0) ) {
						p2.x = x1;
						p2.y = y1;
						p2.k = k1;
						visited[x1][y1][k1] = visited[p.x][p.y][p.k] + 1;
						q.push(p2);
					}
				}
			}
		}

		for (int i = 0; i < 4; i++) { // 盔件捞
			x1 = p.x + dx2[i];
			y1 = p.y + dy2[i];
			k1 = p.k;
			if (x1 >= 0 && x1 < h && y1 >= 0 && y1 < w) {
				if ( (visited[x1][y1][k1] == 0) && (arr[x1][y1] == 0) ) {
					p2.x = x1;
					p2.y = y1;
					p2.k = k1;
					visited[x1][y1][k1] = visited[p.x][p.y][p.k] + 1;
					q.push(p2);
				}
			}
		}
	}

	printf("%d",-1);
	return 0;
}