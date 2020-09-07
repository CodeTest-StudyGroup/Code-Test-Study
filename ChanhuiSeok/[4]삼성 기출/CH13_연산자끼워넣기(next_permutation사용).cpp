#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int oper[4];
int A[11];
vector<int> operList;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, input;
	int tempA[11];

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) 
		tempA[i] = A[i];
	
	for (int i = 0; i < 4; i++) {
		cin >> input;
		while (input > 0) {
			operList.push_back(i);
			input -= 1;
		}
	}

	sort(operList.begin(), operList.end());

	int minV = 987654321;
	int maxV = -987654321;

	do {	
		int operIdx = 0;
		for (int i = 0; i < N - 1; i++) {
			int a = A[i];
			int b = A[i + 1];
			int oper = operList[operIdx];

			if (oper == 0) { // +
				A[i + 1] = a + b;
			}
			else if (oper == 1) { // -
				A[i + 1] = a - b;
			}
			else if (oper == 2) { // *
				A[i + 1] = a * b;
			}
			else { // 나누기
				A[i + 1] = a / b;
			}
			operIdx++;
		}

		minV = min(minV, A[N - 1]);
		maxV = max(maxV, A[N - 1]);

		// A 원상복귀
		for (int i = 0; i < N; i++)
			A[i] = tempA[i];

	} while (next_permutation(operList.begin(), operList.end()));

	cout << maxV << '\n';
	cout << minV;

	return 0;
}