#include <iostream>
using namespace std;
#define MAX_ENTRY 1000003

long long classes[MAX_ENTRY];
int N, B, C;

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> classes[i];
	}
	cin >> B >> C;

	long long result = 0;

	for (int i = 0; i < N; i++) {
		classes[i] -= B;
		result++;

		if (classes[i] > 0) {
			result += classes[i] / C;
			if (classes[i] % C > 0)
				result++;
		}
	}

	cout << result;

	return 0;
}
