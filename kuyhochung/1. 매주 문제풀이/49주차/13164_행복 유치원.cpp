#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;
vector<int> students;
vector<int> diff;
int answer = 0;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		students.push_back(temp);
	}
	for (int i = 1; i < n; i++) {
		diff.push_back(students[i] - students[i - 1]);
	}
	sort(diff.begin(), diff.end(), greater<int>());
	for (int i = k-1; i < diff.size(); i++) {
		answer += diff[i];
	}
	cout << answer;
	return 0;
}