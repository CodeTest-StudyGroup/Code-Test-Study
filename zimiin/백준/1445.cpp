// 1445 일요일 아침의 데이트

#include <cstdio> 
#include <queue>
using namespace std;

#define MAX 100000000

struct Info {
	int x;
	int y;
	int dist;
	
	Info(int x, int y, int dist) {
		this->x = x;
		this->y = y;
		this->dist = dist;
	}
};

class cmp {
public:
	bool operator()(Info a, Info b) {
		return a.dist > b.dist;
	}
};

int n, m, map[50][50], fx, fy, dist[50][50];
priority_queue<Info, vector<Info>, cmp > pq;

int ax[] = {0, 1, 0, -1};
int ay[] = {-1, 0, 1, 0};

bool in_range(int x, int y) {
	if (x >= 0 && x < m && y >= 0 && y < n) return true;
	else return false;
}

int main() {
	// initialize
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j< 50; j++) {
			dist[i][j] = MAX;
		}
	}
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		
		char in[51];
		scanf("%s", in);
		
		for (int j = 0; j < m; j++) {
			// 쓰레기 
			if (in[j] == 'g') {
				map[i][j] = 5000; 
				for (int k = 0; k < 4; k++) {
					int nx = j + ax[k];
					int ny = i + ay[k];
					
					if (in_range(nx, ny) && map[ny][nx] == 0) {
						map[ny][nx] = 1;
					}
				}
			}
			// 도착지 
			else if (in[j] == 'F') {
				fx = j;
				fy = i;
			}
			// 출발지 
			else if (in[j] == 'S') {
				pq.push(Info(j, i, 0));
			}
		}
	}
	map[fy][fx] = 0;
	
	while (!pq.empty()) {
		int cx = pq.top().x;
		int cy = pq.top().y;
		int cdist = pq.top().dist;
		pq.pop();
		
		if (dist[cy][cx] > cdist) {
			dist[cy][cx] = cdist;
			
			if (cx == fx && cy == fy) continue;
			
			for (int i = 0; i < 4; i++) {
				int nx = cx + ax[i];
				int ny = cy + ay[i];
				
				if (in_range(nx, ny)) {
					pq.push(Info(nx, ny, cdist + map[ny][nx]));
				}
			}
		}
	}
	
	printf("%d %d", dist[fy][fx] / 5000, dist[fy][fx] % 5000);
	
	return 0;
}
