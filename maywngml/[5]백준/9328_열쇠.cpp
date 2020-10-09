#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <map>
using namespace std;
#define MAX 100
//지도의 높이와 너비(행, 열)
int h, w;
char MAP[MAX][MAX];
bool visited[MAX][MAX];
//상근이가 가진 열쇠 목록
bool key[26];
//열쇠가 없어서 못 여는 문의 문자와 위치를 임시 저장
map<char, vector<pair<int, int>>> temp_key;
int dir[4][2] = { {-1,0}, {0,-1}, {1,0}, {0,1} };

int bfs(queue<pair<int,int>> need_visit) {
	int cnt = 0;

	while (!need_visit.empty()) {
		int x = need_visit.front().first;
		int y = need_visit.front().second;
		int c = MAP[x][y];
		need_visit.pop();

		//문에 맞는 열쇠가 없을 경우 위치 임시 저장하고 다음 지점 탐색
		if ('A' <= c && c <= 'Z') {
			char ch = tolower(c);
			if (!key[ch - 'a']) {
				//소문자로 저장
				temp_key[ch].push_back({ x, y });
				continue;
			}
		}
		
		if (!visited[x][y]) {
			visited[x][y] = true;
			//방문 지점에 새로운 열쇠가 있으면 key벡터에 추가
			if ('a' <= c && c <= 'z') {
				if (!key[c - 'a']) {
					key[c - 'a'] = true;
					//새 열쇠로 열 수 있는 문이 있으면 해당 위치 큐에 저장
					if (temp_key[c].size() != 0) {
						for (int i = 0; i < temp_key[c].size(); i++)
							need_visit.push({ temp_key[c][i].first, temp_key[c][i].second });
						temp_key[c].clear();
					}
				}
			}
			//문서 찾으면 문서 개수에 1 더함
			if (c == '$') 
				cnt++;

			for (int i = 0; i < 4; i++) {
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
					continue;
				if (MAP[nx][ny] == '*' || visited[nx][ny])
					continue;
				need_visit.push({ nx, ny });
			}
		}
	}

	return cnt;
}

int main() {
	int tc;
	string key_ex;
	vector<int> answer;

	cin >> tc;

	for (int i = 0; i < tc; i++) {
		queue<pair<int, int>> need_visit;
		cin >> h >> w;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> MAP[i][j];
				//지도 가장자리가 벽이 아닐 경우
				if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
					//탐색할 지점에 해당 위치를 넣음
					if (MAP[i][j] != '*') {
						need_visit.push({ i, j });
					}
				}
			}
		}
		cin >> key_ex;

		if (key_ex != "0") {
			//열쇠 목록 저장
			for (int i = 0; i < key_ex.size(); i++)
				key[key_ex[i] - 'a'] = true;
		}
		
		answer.push_back(bfs(need_visit));
		//사용한 배열들과 맵 초기화
		memset(visited, false, sizeof(visited));
		memset(MAP, 0, sizeof(MAP));
		memset(key, false, sizeof(key));
		temp_key.clear();
	}

	for (auto elem : answer)
		cout << elem << '\n';
}
