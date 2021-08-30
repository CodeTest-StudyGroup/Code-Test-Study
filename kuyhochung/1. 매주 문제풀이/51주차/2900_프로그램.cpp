#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define MAX 1000001

int N, K, Q;
long long a[MAX] = { 0, };
long long sum[MAX] = { 0, };
map<int, int> x_elements;

void something(int jump, int cnt) {
	int i = 0;
	while (i < N) {
		a[i] = a[i] + cnt;
		i = i + jump;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	//입력을 받는다.
	cin >> N >> K;
	//입력받는 x원소의 갯수를 map 자료구조를 이용하여 세어 준다.
	for (int i = 0; i < K; i++) {
		int temp;
		cin >> temp;
		x_elements[temp]++;
	}
	//체크한 x원소의 등장 횟수를 이용하여, something 함수를 실행할 때 x원소가 나온 횟수만큼 더해 준다.
	for (auto next : x_elements) {
		//jump: x원소의 값, cnt: x원소의 등장 횟수
		int jump = next.first;
		int cnt = next.second;
		something(jump, cnt);
	}

	//누적합 계산
	sum[0] = a[0];
	for (int i = 1; i < N; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int L, R;
		cin >> L >> R;
		cout << sum[R] - sum[L - 1] << '\n';
	}

	return 0;
}