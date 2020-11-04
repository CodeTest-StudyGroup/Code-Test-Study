#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<pair<int, int>> flower;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int m1, d1, m2, d2;
		cin >> m1 >> d1 >> m2 >> d2;
		flower.push_back(make_pair(m1 * 100 + d1, m2 * 100 + d2));
	}

	sort(flower.begin(), flower.end());

	int startTime = 301, endTime = 1130;
	int time = startTime;
	bool flag = true;
	int idx = -1, result = 0, tmpTime = 0;

	while (time <= endTime) {
		if (idx >= (int)flower.size()) break;

		flag = false;
		idx += 1;

		// time을 포함하고, 길이가 가장 긴 꽃 선택
		for (int k = idx; k < flower.size(); k++) {
			// 현재 날짜가, 다음 꽃의 범위에 들어올 수 없는 경우
			if (time < flower[k].first) break;

			// 끝 범위 옮기기
			if (time >= flower[k].first && tmpTime < flower[k].second) {
				tmpTime = flower[k].second;
				flag = true;
				idx = k;
			}
		}

		// 선택할 수 있는 꽃이 있었을 경우
		if (flag) {
			time = tmpTime; // 현재 날짜를 그 꽃이 끝나는 날짜로 변경
			result++;
		}
		// 선택할 수 있는 꽃이 없었을 경우 꽃 사이에 빈 날짜가 있다.
		else {
			cout << 0;
			return 0;
		}
	}

	cout << result;
	return 0;
}
