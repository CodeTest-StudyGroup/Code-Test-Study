#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<string, int>& a, pair<string, int>& b) {
	return a.second < b.second;
}

bool solution(vector<string> phone_book) {
	vector<pair<string, int>> vec;
	vector<pair<string, int>>::iterator iter;
	vector<pair<string, int>>::iterator iter2;

	int sameFlag = 0, size = 0;
	bool answer = true;
	string tempStr1;
	for (int i = 0; i < phone_book.size(); i++) {
		vec.push_back(make_pair(phone_book[i], phone_book[i].size()));
	}

	sort(vec.begin(), vec.end(), compare);

	iter = vec.begin();
	while (iter != vec.end()) {
		size = iter->second;
		for (iter2 = vec.begin(); iter2 != vec.end(); iter2++) {
			if (*iter != *iter2) {
				tempStr1 = iter2->first.substr(0, size);
				if (tempStr1 == iter->first) {
					return false;
				}
			}
		}
		iter++;
	}
	return true;
}