#include <iostream>

using namespace std;

int main(){

	int N;
	cin >> N; // N <= 100,000

	int a, b, x, y, sum = 0;

	cin >> x >> y;
	a = x; b = y;

	// 초기 기준 범위 : [a, b] (맨 처음 입력받은 범위)

	for (int i = 0; i < N-1; i++) {
		cin >> x >> y; // 다음 (x, y)
		
		// 기준 범위 [a, b] 안에 들어갈 경우
		if (x >= a && y <= b) {
			continue;
		}

		// (x,y)의 시작점 x가 기준 범위 [a, b]에 속하지만 끝점 y는 바깥일 경우
		else if (x >= a && x < b && y > b) {
			// 기준 범위의 끝점을 y로 갱신
			b = y;
		}

		// (x, y)가 기준 범위 [a, b] 에 속하지 않을 경우
		else if (x >= b) {
			// 현재 범위를 sum에 더하고, 범위값 [a, b]를 새로 갱신
			sum += b - a;
			a = x; b = y;
		}
	}

	// 더해지지 않은 마지막 계산된 값(b-a)을 sum에 더한다.
	cout << sum + (b - a);
	return 0;
}