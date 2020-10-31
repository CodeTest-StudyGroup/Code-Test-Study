#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define RED 1
#define BLUE 2
#define YELLOW 3

int N;
int arr[10001];
int maxVal = -1;

// 각 공마다 색상을 바꾸어 보고, 지워지는 갯수를 반환하는 함수
// 여기서 많이 지워질수록 좋은 것임
int bomber(int cur, int color) {

	int left = cur, right = cur;
	int origin_color = arr[cur];
	int ans = 0; // 지워지는 갯수 반환

	// 해당 칸 색상 변경
	arr[cur] = color;

	// 해당 칸 색상 변경 시, 해당 칸 기준으로 왼쪽을 계속 가면서
	// 그 색상과 같은 칸이 있을 때까지 움직이고

	// 해당 칸 색상 변경 시, 해당 칸 기준으로 오른쪽을 계속 가면서
	// 그 색상과 같은 칸이 있을 때까지 움직인다.

	bool flag = true;

	while (left >= 1 && right <= N && flag) {
		// 현재 칸의 색상 파악
		int cur_color = arr[left];
		int cnt = 0;

		// 왼쪽 움직이기
		while (left >= 1 && arr[left] == cur_color) {
			left -= 1;
			cnt++;
		}

		// 오른쪽 움직이기
		while (right <= N && arr[right] == cur_color) {
			right += 1;
			cnt++;
		}

		// 4개 이상 지워졌다면, 다른 칸들도 연쇄 폭발이 가능한지 봐야 하므로
		// flag 값을 true로 바꾸고, 터진 갯수에 더한다.
		if (cnt >= 4){ 
			ans += cnt;
			flag = true;
		}
		// 4개 이상 지워지지 못한다면, 다른 연쇄 폭발을 알아볼 필요가 없다.
		else {
			flag = false;
		}
	}

	// 해당 칸 색상 복구
	arr[cur] = origin_color;
	return ans - 1; // 맨 처음에는 같은데서 시작하므로 최초 1회 한번 더 더해지므로 -1을 함
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	// 입력받은 것들의 색상 변경해 보기
	for (int i = 1; i <= N; i++) {
		maxVal = max(maxVal, bomber(i, RED));
		maxVal = max(maxVal, bomber(i, BLUE));
		maxVal = max(maxVal, bomber(i, YELLOW));
	}

	cout << N - maxVal;
	return 0;
}