#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 51
#define INF 1e9

int n, m;
vector<string> maze;
int startX = -1, startY = -1;
vector<pair<int, int> > nodes;
vector<int> parent;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

//벽을 지나갈 수 없도록 판별하는 함수
bool is_reachable(int x, int y) {
	if (maze[x][y] == '1') return false;
	else return true;
}

//union-find 알고리즘을 위한 두 함수
int get_parent(int x) {
	if (parent[x] != x) parent[x] = get_parent(parent[x]);
	return parent[x];
}

void make_union(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);

	if (x > y) parent[x] = y;
	else parent[y] = x;
}

//bfs를 통해 시작점부터 도착점까지의 최단 거리를 구한다.
int bfs(int startX, int startY, int endX, int endY) {
	vector<vector<int> > d;
	vector<int> temp;
	queue<pair<int, int> > q;

	for (int i = 0; i < n; i++) temp.push_back(INF);
	for (int i = 0; i < n; i++) d.push_back(temp);
	d[startX][startY] = 0;
	q.push({ startX, startY });

	while (!q.empty()) {
		int currentX = q.front().first;
		int currentY = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = currentX + dx[dir];
			int ny = currentY + dy[dir];

			if (!is_reachable(nx, ny)) continue;
			if (d[currentX][currentY] + 1 < d[nx][ny]) {
				d[nx][ny] = d[currentX][currentY] + 1;
				q.push({ nx, ny });
			}
		}
	}
	
	return d[endX][endY];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	//주어진 입력을 받는다.
	cin >> n >> m;
	//1은 미로의 벽, 0은 지나다닐 수 있는 길, S는 로봇의 출발 위치, K는 열쇠의 위치
	//로봇의 출발 위치와 열쇠의 위치 (node)를 기록한다.
	//출발 지점 노드는 0번, 열쇠 노드는 1번부터 시작
	nodes.push_back({ -1, -1 });
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		maze.push_back(temp);
		for (int j = 0; j < n; j++) {
			if (temp[j] == 'K') {
				nodes.push_back({ i, j });
			}
			else if (temp[j] == 'S') {
				nodes[0] = { i, j };
			}
		}
	}

	//모든 노드끼리의 거리를 구하여, {거리, {x, y} } 의 형태로 담는다.
	//이후 노드의 크기를 기준으로 오름차순으로 정렬한다.
	vector<pair <int, pair<int, int> > > node_dist;
	for (int i = 0; i < nodes.size(); i++) {
		for (int j = i+1; j < nodes.size(); j++) {
			int dist = bfs(nodes[i].first, nodes[i].second, nodes[j].first, nodes[j].second);
			if (dist == INF) continue;
			node_dist.push_back({ dist, {i, j} });
		}
	}
	sort(node_dist.begin(), node_dist.end());

	//크루스칼 알고리즘
	//부모를 기록한 배열 초기화
	for (int i = 0; i < nodes.size(); i++) {
		parent.push_back(i);
	}
	int answer = 0;
	for (auto& next : node_dist) {
		if (get_parent(next.second.first) != get_parent(next.second.second)) {
			make_union(next.second.first, next.second.second);
			answer += next.first;
		}
	}

	//모든 노드가 연결되어 있는지 확인한다. 그렇지 않은 경우 -1을 출력.
	bool reach_all = true;
	for (auto next : parent) {
		if (next != 0) {
			cout << -1;
			reach_all = false;
			break;
		}
	}
	if (reach_all) cout << answer;

	return 0;
}