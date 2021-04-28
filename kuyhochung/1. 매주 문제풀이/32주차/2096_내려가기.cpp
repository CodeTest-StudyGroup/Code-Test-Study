#include <iostream>
using namespace std;
#define MAX_N 100000

int n;
int maxDP[3] = { 0, };
int minDP[3] = { 0, };
int numbers[3];
int temp0, temp2;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < 3; i++) {
		cin >> maxDP[i];
		minDP[i] = maxDP[i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> numbers[j];
		}

		temp0 = maxDP[0];
		temp2 = maxDP[2];
		maxDP[0] = max(maxDP[0], maxDP[1]) + numbers[0];
		maxDP[2] = max(maxDP[2], maxDP[1]) + numbers[2];
		maxDP[1] = max(max(temp0, maxDP[1]), temp2) + numbers[1];

		temp0 = minDP[0];
		temp2 = minDP[2];
		minDP[0] = min(minDP[0], minDP[1]) + numbers[0];
		minDP[2] = min(minDP[2], minDP[1]) + numbers[2];
		minDP[1] = min(min(temp0, minDP[1]), temp2) + numbers[1];
	}

	cout << max(max(maxDP[0], maxDP[1]), maxDP[2]) << " " << 
		min(min(minDP[0], minDP[1]), minDP[2]);
	return 0;
}