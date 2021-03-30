#include <iostream>
using namespace std;
#define MAX_N 50

int N, a, b;
int numbers[MAX_N];
int diff[MAX_N];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	for (int i = 0; i < N - 1; i++) {
		diff[i] = numbers[i + 1] - numbers[i];
	}
	//차이는 (a-1)x + b, a(a-1)x + ab, a^2(a-1)x + a^2b, a^3(a-1)x + a^3b ...
	//n과 n-1의 차이는 diff[n-1]에 저장된다.

	if (N == 1 || (N == 2 && numbers[0] != numbers[1])) {
		cout << "A";
		return 0;
	}

	if (N == 2) {
		cout << numbers[0];
		return 0;
	}

	if (numbers[0] == numbers[1]) {
		if (numbers[1] != numbers[2]) {
			cout << "B";
			return 0;
		}
		a = 1;
		b = 0;
	}
	else {
		if (diff[1] % diff[0]) {
			cout << "B";
			return 0;
		}
		a = diff[1] / diff[0];
		b = numbers[1] - a * numbers[0];
	}

	int i = 0;
	int answer = a * numbers[N - 1] + b;
	for (i = 3; i < N; ++i) {
		if (numbers[i] != a * numbers[i - 1] + b)
		break;
	}
	if (i < N)
		cout << "B";
	else
		cout << answer;

	return 0;
}