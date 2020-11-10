#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

long long N, M;
vector<long long> time;

// 표를 그려서 확인해 보면, 특정 시간까지 탑승한 사람의 수를
// 아래와 같이 구할 수 있다.
long long calcul(long long times) {
	long long result = 0;
	for (int i = 0; i < M; i++) {
		result += times / time[i];
	}
	return result;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		long long tmp; cin >> tmp;
		time.push_back(tmp);
	}

	// 어린이들 수보다 놀이공원 수가 더 많다면 그냥 바로 출력
	if (N <= M) {
		cout << N;
		return 0;
	}

	long long mid;
	long long people = M; // 놀이기구에 모두 태우고 시작

	long long left = 0;

	// 놀이기구가 1개밖에 없고, 사람은 최대 수 만큼 있고, 놀이기구 운행시간도
	// 최대 30분짜리일 경우 가장 오래 걸리는 시간
	long long right = 2000000000LL * 30LL;

	long long findTime = 0; // 마지막 사람까지 탔을 때의 시간

	while (left <= right) {
		mid = (left + right) / 2;
		long long times = calcul(mid);

		// 찾고자 하는 것보다 클 경우 right 범위 좁히기
		// +M 한 이유는, 0분에는 처음에 모든 놀이기구에 학생들이 다 탑승하므로
		if (times + M >= N) {
			right = mid - 1;
			findTime = mid;
		}
		else {
			left = mid + 1;
		}
	}

	// findTime-1 분까지 탔었던 인원 구하기
	for (int i = 0; i < M; i++) {
		people += (findTime - 1) / time[i];
	}

	// 1분 전 인원 +1 명부터 N명이 될 때까지 넣어본다.
	long long answer = 0;
	for (int k = 0; k < M; k++) {
		long long tmp = findTime % time[k];	
		// 나누어 떨어질 경우
		if (tmp == 0) {
			people++;
			answer = k;
		}
		if (people >= N) break;
	}
	cout << answer + 1;

	return 0;
}