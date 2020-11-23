#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<string> strs;
int dics[26];
set<char> dicset;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		strs.push_back(input);		

		for (int j = 0; j < input.size(); j++) {
			dicset.insert(input[j]);
		}
	}

	// 9 8 7 ... 로 매칭
	int num = 9;
	vector<int> ind;
	for (int i = 0; i < dicset.size(); i++) {
		ind.push_back(num--);
	}

	sort(ind.begin(), ind.end());
	int max_num = -987654321;

	do {
		int idx = 0;
		// ind를 dics에 차례로 저장
		for (auto iter = dicset.begin(); iter != dicset.end(); iter++) {
			dics[*iter - 'A'] = ind[idx++];
		}

		// 매칭된 알파벳에 맞게 숫자 만들어 보기
		int sums = 0;
		for (int k = 0; k < strs.size(); k++) {
			string cur = strs[k];
			int curInt = 0;
			for (int m = 0; m < cur.size(); m++) {
				curInt = curInt * 10 + dics[cur[m] - 'A'];
			}
			sums += curInt;
		}

		max_num = max(max_num, sums);	
	} while (next_permutation(ind.begin(), ind.end()));

	cout << max_num;

	return 0;
}
