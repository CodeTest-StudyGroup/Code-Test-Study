#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

string gears[5];
vector <pair <int, int> > rotation;

string clockwise(string input) {
	string result = "";
	int last = (int)input.size() - 1;
	result += input[last];
	result += input.substr(0, last);

	return result;
}

string counterclockwise(string input) {
	string result = "";
	int last = (int)input.size() - 1;
	char front = input[0];
	result += input.substr(1);
	result += front;

	return result;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i <= 4; i++) {
		cin >> gears[i];
	}

	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int gearNo, direction;
		cin >> gearNo >> direction;
		rotation.push_back({ gearNo, direction });
	}

	for (int i = 0; i < n; i++) {
		int gearNo = rotation[i].first;
		int direction = rotation[i].second;

		int visited[5] = { 0, };
		queue<pair <int, int> > q;
		q.push({ gearNo, direction });
		visited[gearNo] = 1;


		while (!q.empty()) {
			int currentGear = q.front().first;
			int currentDir = q.front().second;
			q.pop();

			if (((currentGear + 1) <= 4) && (gears[currentGear][2] != gears[currentGear + 1][6]) && visited[currentGear + 1] == 0) {
				visited[currentGear + 1] = 1;
				q.push({ (currentGear + 1), (currentDir * -1)});
			}
			if (((currentGear -1 ) >= 1) && (gears[currentGear][6] != gears[currentGear - 1][2]) && visited[currentGear - 1] == 0) {
				visited[currentGear - 1] = 1;
				q.push({ (currentGear - 1), (currentDir * -1)});
			}

			if (currentDir == 1) {
				gears[currentGear] = clockwise(gears[currentGear]);
			}
			if (currentDir == -1) {
				gears[currentGear] = counterclockwise(gears[currentGear]);
			}
		}
	}

	int score = 0;
	for (int i = 1; i <= 4; i++) {
		if (gears[i][0] == '1')
			score += pow(2, i-1);
	}
	cout << score << endl;
}