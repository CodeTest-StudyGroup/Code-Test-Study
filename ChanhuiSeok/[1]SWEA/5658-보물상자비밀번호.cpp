#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <functional>
#include <cstring>

using namespace std;

int output[1001];
int hex2dec(string hex)
{
	int len = hex.size();
	int base = 1, ret = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (hex[i] >= '0' && hex[i] <= '9') ret += (hex[i] - 48) * base;
		else if (hex[i] >= 'A' && hex[i] <= 'F') ret += (hex[i] - 55) * base;
		base *= 16; // 다음 자리 넘어가기
	}
	return ret;
}

int main() {
	string input;
	int N, T, K, rotate_cnt;

	cin >> T;
	set<int, greater<int>> data; // 데이터가 내림차순으로 들어가게 함
	set<int, greater<int>>::iterator iter;

	for (int t = 0; t < T; t++) {
		cin >> N >> K; // 숫자의 갯수 N(4의 배수, 8~28)과 크기 순서 K
		cin >> input;
		rotate_cnt = N / 4;
		int hexToDec = 0;

		//rotate 횟수만큼 돌아본다.
		for (int k = 0; k < rotate_cnt; k++) {
			string changed_temp;
			char last_str = input[input.size() - 1];

			for (int j = 0; j < N; j = j + rotate_cnt) {
				string temp = input.substr(j, rotate_cnt);
				hexToDec = hex2dec(temp);
				data.insert(hexToDec);
			}
			// 한 회전 당 추출한 16진수 10진수 변환 완료, 이후 시계 방향으로 회전시키기
			input.pop_back();
			changed_temp = last_str + input;
			input = changed_temp;
		}

		// 모두 다 돌고 나면 set에 데이터가 저장되어 있다. set의 데이터를 차례대로 배열에 넣어 본다.
		int idx = 0;
		for (iter = data.begin(); iter != data.end(); iter++)
			output[idx++] = *iter;
		cout << "#" << t + 1 << " " << output[K - 1] << '\n';
		data.clear();
	}
}