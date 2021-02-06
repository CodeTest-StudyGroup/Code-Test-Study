#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int H, W, input;
vector<int> height;

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> H >> W; // 세로, 가로
	for (int i = 0; i < W; i++) {
		cin >> input;
		height.push_back(input);
	}
	int result = 0;
	
	// 양 끝쪽은 좌우를 살펴볼 필요가 없음
	for (int i = 1; i < W - 1; i++) {
		// 왼쪽, 오른쪽 살펴보기
		int left = 0, right = 0;
		for (int L = i-1; L >= 0; L--) 
			left = max(left, height[L]);
		for (int R = i + 1; R < W; R++) 
			right = max(right, height[R]);

		int target = min(left, right); // 작은 것 선택
		int current = height[i]; // 현재 높이
		result = result + max(0, target - current);
	}

	cout << result;

	return 0;
}