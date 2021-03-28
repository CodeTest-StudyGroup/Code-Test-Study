#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 100000

int n, m;
vector<int> broken;
int result = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		broken.push_back(temp);
	}
	result = abs(n - 100);
	for (int i = 0; i < 1000001; i++) {
		bool available = true;
		string temp = to_string(i);
		for (int k = 0; k < temp.size(); k++) {
			for (int j = 0; j < m; j++) {
				if (temp[k] - '0' == broken[j]) {
					available = false;
					break;
				}
			}
		}
		if (!available) continue;
		int numLength = temp.size();
		result = min(result, abs(n - i) + numLength);
	}
	cout << result;
	return 0;
}