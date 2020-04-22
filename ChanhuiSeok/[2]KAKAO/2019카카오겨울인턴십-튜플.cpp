#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

/* C++은 이런 string 다루는 문제가 나오면 헷갈릴 것 같다. */
/* split 함수, eraseAll 등을 짜는 연습을 많이 해야겠다!!! */

using namespace std;
int usage[100001];
int visit[100001];

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

void eraseAllString(string& s, char target) {
	s.erase(remove(s.begin(), s.end(), target), s.end());
}

bool compare(vector<int> v1, vector<int> v2) {
	return v1.size() < v2.size();
}

vector<int> solution(string s) {
	vector<string> origin;
	vector< vector<int> > origin_intV;
	vector<int> answer;

	int maxIdx = -1;
	int i, j, Idx = 0, isFind = 0, maxValue = -1;
	int ori_Idx = 0;
	string temp_str = "";

	eraseAllString(s, '{');
	origin = split(s, '}');

	// 숫자가 한 개만 있었을 때는 예외
	if (origin.size() == 1) {
		answer.push_back(stoi(origin[0]));
		return answer;
	}

	// 문자열 처리. 이 반복문을 끝내면, { } 로 구분됫 숫자 묶음이 차례대로 벡터에 들어간다.
	for (i = 0; i < origin.size() - 1; i++) {
		vector<int> origin_temp;

		for (j = 0; j < origin[i].size(); j++) {
			if (origin[i][j] != ',' && origin[i][j] != ' ') {
				temp_str += to_string(origin[i][j] - 48);
			}
			else if (j != 0 && origin[i][j] == ',') {
				origin_temp.push_back(stoi(temp_str));

				if (stoi(temp_str) > maxValue)
					maxValue = stoi(temp_str);

				usage[stoi(temp_str)] = 1;
				temp_str = "";
			}
		}
		if (j == origin[i].size()) {
			origin_temp.push_back(stoi(temp_str));
			usage[stoi(temp_str)] = 1;

			if (stoi(temp_str) > maxValue)
				maxValue = stoi(temp_str);

			temp_str = "";
		}

		origin_intV.push_back(origin_temp);
		ori_Idx += 1;
	}

	// 하나씩 경우의 수를 해 보기. 먼저, 숫자 묶음의 길이 순서대로 정렬해 놓는다.
	Idx = 0;
	sort(origin_intV.begin(), origin_intV.end(), compare);

	// ex : {2}, {2,1}, {2,1,3}, {2,1,3,4} 로 정렬된 것들만큼 반복한다.
	for (int i = 0; i < origin_intV.size(); i++) {
		for (int j = 1; j <= maxValue; j++) {

			if (usage[j] == 1 && visit[j] != 1) {

				answer.push_back(j);

				if (find(origin_intV[i].begin(), origin_intV[i].end(), j)
					== origin_intV[i].end()) {
					answer.pop_back();
				}
				else {
					visit[j] = 1;
					break;
				}

			}
		}
	}
	return answer;

}