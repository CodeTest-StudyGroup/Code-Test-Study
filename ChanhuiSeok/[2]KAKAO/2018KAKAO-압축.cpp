#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

unordered_map<string, int> maps;
string arr[27];

vector<int> solution(string msg) {
	vector<int> answer;

	string target;
	string copymsg = msg;
	string tmp = msg;
	int idx = 1;
	int endIdx = 27;
	int index = 0;

	while (!tmp.empty()) {
		// 사전에서 현재 입력과 일치하는 가장 긴 문자열 w 찾기
		while (idx <= tmp.length()) {
			// 현재 문자에서 1, 2, 3,... 으로 계속 찾아보기
			target = tmp.substr(0, idx);
			if (maps.count(target)) {
				index = maps[target];
				idx++;
				continue;
			}
			// 사전에서 찾을 수 없는 경우
			else {
				// 가장 긴 문자열의 색인 번호 저장
				break;
			}
		}

		// 가장 긴 문자열의 색인 번호가 index에 저장되어 있음
		answer.push_back(index);

		// 입력에서 w 제거
		tmp = tmp.substr(idx - 1);

		// 입력에서 처리되지 않은 글자가 남아 있으면 사전에 저장
		maps.insert({ target, endIdx++ });

		// idx 초기화
		idx = 1;
	}

	return answer;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	// maps 초기화
	for (int i = 1; i <= 26; i++) {
		arr[i] = 'A' + i - 1;
		maps[arr[i]] = i;
	}

	vector<int> answer = solution("ABABABABABABABAB");

	return 0;
}