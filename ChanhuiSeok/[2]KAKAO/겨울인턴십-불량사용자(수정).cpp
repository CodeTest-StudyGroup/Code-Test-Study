#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> visit;
vector<vector<string>> result;

bool compare(string a, string b) {
	return a < b;
}

bool isCorrect(string user_id, string banned_id) {
	bool flag = true;
	for (int i = 0; i < banned_id.size(); i++) {
		if (user_id.size() != banned_id.size()) {
			flag = false;
			break;
		}
		if (banned_id[i] == '*')
			continue;
		if (banned_id[i] != user_id[i]) {
			flag = false;
			break;
		}
	}
	return flag;
}

void dfs(int idx, vector<vector<string>>& possible_id) {

	// banned_id와의 매칭이 모두 완료되었을 경우
	if (idx >= possible_id.size()) {
		vector<string> temp;
		temp.resize(possible_id.size());
		copy(visit.begin(), visit.end(), temp.begin());
		// 소팅하여 나중의 중복을 막아줄 수 있다.
		sort(temp.begin(), temp.end(), compare);

		if (find(result.begin(), result.end(), temp) == result.end())
			result.push_back(temp);
		temp.clear();
		return;
	}

	for (int i = 0; i < possible_id[idx].size(); i++) {

		// possible_id[idx][i]가 방문한 배열에 없으면?
		if (find(visit.begin(), visit.end(), possible_id[idx][i]) == visit.end()) {

			visit.push_back(possible_id[idx][i]);
			dfs(idx + 1, possible_id);
			visit.pop_back();

		}
	}

}

int solution(vector<string> user_id, vector<string> banned_id) {

	vector< vector<string>> possible_id;
	vector<string> temp_possible;
	vector<int> ind;
	int k = 0, cnt = 0;

	for (int i = 0; i < banned_id.size(); i++) {
		for (int j = 0; j < user_id.size(); j++) {
			if (isCorrect(user_id[j], banned_id[i]))
				temp_possible.push_back(user_id[j]);
		}
		possible_id.push_back(temp_possible);
		temp_possible.clear();
	}

	// 위에까지 하면, 각 banned_id마다 가능한 user_id들의 목록이
	// possible_id에 만들어졌다.
	dfs(0, possible_id);

	return result.size();

}