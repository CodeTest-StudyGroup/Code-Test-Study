#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;

int N;
int arr[500001];
int lis[500001];
int back[500001];

pair<int, int> answer[500001];
set<int> sets;

int binarySearch(int end, int target) {
	int idx = lower_bound(lis, lis + end, target) - lis;
	return idx;
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	vector<pair<int, int>> input;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		input.push_back({ a,b });
	}

	// A 전봇대의 번호들을 대상으로 LIS를 구해야 하므로!
	sort(input.begin(), input.end(), cmp);

	for (int i = 1; i <= N; i++) {	
		arr[i] = input[i-1].first;
	}

	lis[1] = arr[1];
	int j = 1;

	answer[1].first = 1;
	answer[1].second = arr[1];

	// arr에 담긴 숫자들로 LIS 진행
	for (int i = 2; i <= N; i++) {

		// 맨 뒤의 값보다 크면 맨 뒤에 넣기
		if (lis[j] < arr[i]) {
			lis[j + 1] = arr[i];
			j++;
			answer[i].first = j; // arr[i]가 들어간 위치
			answer[i].second = arr[i]; // arr[i]가 들어간 값
		}

		// 아니면 위치를 찾기
		else {
			int idx = binarySearch(j, arr[i]);
			lis[idx] = arr[i];
			answer[i].first = idx;
			answer[i].second = arr[i];
		}
	}

	int size = N - j;
	cout << size <<'\n';

	// 원래 LIS 이루는 것 추적하기
	vector<int> ans;
	int tmp = j;
	for (int k = N; k >= 1; k--) {
		if (answer[k].first == tmp) {
			sets.insert(answer[k].second);
			tmp--;
		}
		if (tmp <= 0) break;
	}

	for (int i = 0; i < N; i++) {
		// input을 보면서 set에 없는 것 골라내기
		if (sets.find(input[i].first)==sets.end()) 
			ans.push_back(input[i].first);	
	}
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) 
		cout << ans[i] << '\n';
	
	return 0;
}