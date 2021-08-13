#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define INF 1e9

int n, T;
int max_X = 0;
int max_Y = 0;
vector <pair <int, int> > location;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

bool in_range(int y1, int y2) {
	if (abs(y1 - y2) <= 2) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> T;
	vector <vector <pair <int, int> > > edges(n+1);

	location.push_back({ 0, 0 });
	for (int i = 0; i < n; i++) {
		int tempX, tempY;
		cin >> tempX >> tempY;
		max_Y = max(max_Y, tempY);
		location.push_back({ tempX, tempY });
	}
	
	sort(location.begin(), location.end(), cmp);
	max_X = location.back().first;

	//정렬된 좌표들에 대해 번호를 부여
	map< pair<int, int>, int> locationNo;
	for (int i = 0; i < location.size(); i++) {
		locationNo.insert({ {location[i].first, location[i].second}, i });
	}
	//좌표번호 -> 좌표값: location
	//좌표값 -> 좌표번호: locationNo;

	//각 좌표들 간에 접근 가능한 경우 간선을 만든다.
	for (int i = 0; i < location.size(); i++) {
		int currentX = location[i].first;
		int currentY = location[i].second;

		int lowX = 0, highX = 0;

		//x범위 기준 상하한을 정한다.
		//x기준 정렬되어 있으므로, currentX 기준 +- 2 이내의 범위를 찾는다.
		if (currentX <= 2) lowX = 0;
		else {
			for (int j = i; j >= 0; j--) {
				if (!in_range(currentX, location[j].first)) {
					lowX = j + 1;
					break;
				}
			}
		}

		if (in_range(currentX, max_X)) highX = n;
		else {
			for (int j = i; j <= n; j++) {
				if (!in_range(currentX, location[j].first)) {
					highX = j - 1;
					break;
				}
			}
		}

		//x범위 내에서 y가 범위에 있는 경우 간선을 만든다.
		for (int j = lowX; j <= highX; j++) {
			if (in_range(currentY, location[j].second)) {
				if (currentX == location[j].first && currentY == location[j].second) continue;
				edges[i].push_back({ location[j].first, location[j].second });
			}
		}
	}

	//만든 그래프를 이용한 BFS 탐색을 진행한다.
	vector<int> visited;
	for (int i = 0; i < location.size(); i++) {
		visited.push_back(INF);
	}

	queue<int> q;
	q.push(0);
	visited[0] = 0;

	while (!q.empty()) {
		int currentNo = q.front();
		q.pop();
		int currentX = location[currentNo].first;
		int currentY = location[currentNo].second;

		for (int j = 0; j < edges[currentNo].size(); j++) {
			int nextX = edges[currentNo][j].first;
			int nextY = edges[currentNo][j].second;
			int nextNo = locationNo[{nextX, nextY}];

			if (visited[currentNo] + 1 < visited[nextNo]) {
				visited[nextNo] = visited[currentNo] + 1;
				q.push(nextNo);
			}
		}

	}

	//y값이 가장 높은 경우의 visited값을 참고한다.
	int answer = INF;
	for (int i = 0; i < location.size(); i++) {
		if (location[i].second == max_Y) {
			answer = min(answer, visited[i]);
		}
	}

	if (answer == INF) cout << -1;
	else cout << answer;

	return 0;
}