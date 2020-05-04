
#include <string>
#include <vector>
#include <queue>

using namespace std;

enum states { garo, sero };
int N;
vector <vector<int>> map;

typedef struct robots {
	int y, x, state, time;
}Robot;

bool visit[102][102][2];

bool isRanged(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N)
		return false;
	if (map[y][x] == 1)
		return false;
	return true;
}

vector<Robot> isPossible(Robot& robot) {
	// 지금 이 로봇의 상,하,좌,우와 회전까지 고려한 칸들을 모두 보고 이동 가능하면 큐에 넣는다.
	// 로봇이 가로형일 때
	vector<Robot> temp;
	if (robot.state == garo) {
		// 1. 가로형을 유지하거나 위로 회전하면서 로봇의 [위쪽]으로 갈 수 있나?
		if (isRanged(robot.y - 1, robot.x) && isRanged(robot.y - 1, robot.x + 1)) {
			// 가능하면, 큐에 넣기 위한 준비를 한다.
			temp.push_back({ robot.y - 1, robot.x, sero, robot.time + 1 });
			temp.push_back({ robot.y - 1, robot.x + 1, sero, robot.time + 1 });
			temp.push_back({ robot.y - 1, robot.x, garo, robot.time + 1 });
		}
		// 2. 가로형을 유지하거나 아래로 회전하면서 로봇의 [아래쪽]으로 갈 수 있나?
		if (isRanged(robot.y + 1, robot.x) && isRanged(robot.y + 1, robot.x + 1)) {
			// 가능하면, 큐에 넣는다.
			temp.push_back({ robot.y, robot.x, sero, robot.time + 1 });
			temp.push_back({ robot.y, robot.x + 1, sero, robot.time + 1 });
			temp.push_back({ robot.y + 1, robot.x, garo, robot.time + 1 });
		}
		// 3. 가로형을 유지하면서 [오른쪽]으로 갈 수 있나?
		if (isRanged(robot.y, robot.x + 2)) {
			temp.push_back({ robot.y, robot.x + 1, garo, robot.time + 1 });
		}
		// 4. 가로형을 유지하면서 [왼쪽]으로 갈 수 있나?
		if (isRanged(robot.y, robot.x - 1)) {
			temp.push_back({ robot.y, robot.x - 1, garo, robot.time + 1 });
		}
	}
	else if (robot.state == sero) {
		// 1. 세로형을 유지하거나 오른쪽으로 회전하면서 [오른쪽]으로 갈 수 있나?
		if (isRanged(robot.y, robot.x + 1) && isRanged(robot.y + 1, robot.x + 1)) {
			// 가능하면, 큐에 넣기 위한 준비를 한다.
			temp.push_back({ robot.y, robot.x, garo, robot.time + 1 });
			temp.push_back({ robot.y + 1, robot.x, garo, robot.time + 1 });
			temp.push_back({ robot.y, robot.x + 1, sero, robot.time + 1 });
		}
		// 2. 세로형을 유지하거나 왼쪽으로 회전하면서 [왼쪽]으로 갈 수 있나?
		if (isRanged(robot.y, robot.x - 1) && isRanged(robot.y + 1, robot.x - 1)) {
			// 가능하면, 큐에 넣기 위한 준비를 한다.
			temp.push_back({ robot.y + 1, robot.x - 1, garo, robot.time + 1 });
			temp.push_back({ robot.y, robot.x - 1, garo, robot.time + 1 });
			temp.push_back({ robot.y, robot.x - 1, sero, robot.time + 1 });
		}
		// 3. 세로형을 유지하면서 [위쪽]으로 갈 수 있나?
		if (isRanged(robot.y - 1, robot.x)) {
			temp.push_back({ robot.y - 1, robot.x, sero, robot.time + 1 });
		}
		// 4. 세로형을 유지하면서 [아래쪽]으로 갈 수 있나?
		if (isRanged(robot.y + 2, robot.x)) {
			temp.push_back({ robot.y + 1, robot.x, sero, robot.time + 1 });
		}
	}

	return temp;
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	map = board;
	N = board.size();

	// (1) Robot Init
	queue<Robot> que;
	/////////////////////////////////////////////////
	// (2) start BFS
	que.push({ 0, 0, garo, 0 });

	while (!que.empty()) {
		Robot robot = que.front();
		que.pop();

		// 방문 표시
		// 이미 N, N 좌표에 왔을 경우
		if ((robot.y == N - 1 && robot.x == N - 2 && robot.state == garo) ||
			(robot.y == N - 2 && robot.x == N - 1 && robot.state == sero)) {
			return robot.time;
		}

		bool v = visit[robot.y][robot.x][robot.state];
		if (v) continue;
		else {
			visit[robot.y][robot.x][robot.state] = true;
		}

		auto temp = isPossible(robot);
		for (auto& newTemp : temp) {
			que.push(newTemp);
		}
	}
	return 0;
}