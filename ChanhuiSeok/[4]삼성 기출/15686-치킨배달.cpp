#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

/* 치킨 배달 문제 (next_permutation 활용) */

int arr[51][51];
vector<pair<int, int>> store;
vector<pair<int, int>> house;
vector<int> ind;

int pathLength(int r1, int c1, int r2, int c2) {
	return abs((r1 - r2)) + abs((c1 - c2));
}

int main() {

	int N, M, res_sum_chicken = 1000001;
	cin >> N >> M;
	// N은 도시의 크기 N X N, M은 치킨집 최대 M개 고르기

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) store.push_back({ i,j });
			if (arr[i][j] == 1) house.push_back({ i,j });
		}
	}
	
	// 1개부터 ~ M개 폐업시키지 않을 때까지 모든 경우의 수를 따져서 구한다
	for (int k = 1; k <= M; k++) {

		int store_size = store.size();
		int house_size = house.size();

		for (int i = 0; i < k; i++)
			ind.push_back(1);
		for (int i = 0; i < store_size - k; i++)
			ind.push_back(0);

		sort(ind.begin(), ind.end());

		int tmp_sum = 0;
		int tmp_sum_chicken = 100001;
		
		// 최소 1개부터 최대 M개까지 선택할 것임
		do {
			// 모든 집에 대한 치킨거리 구하기
			for (int j = 0; j < house_size; j++) {
				int temp = 100001;
				// 폐업 대상인 치킨집이 아닐 경우, j번째 집과 치킨집과의 거리 구하기
				for (int i = 0; i < store_size; i++) {
					// 폐업시키지 않을 치킨집 고르기
					if (ind[i] == 1) {
						temp = min(temp, pathLength(house[j].first, house[j].second,
							store[i].first, store[i].second));
					}
				}
				tmp_sum += temp;
			}
			tmp_sum_chicken = min(tmp_sum_chicken, tmp_sum);
			tmp_sum = 0;

		} while (next_permutation(ind.begin(), ind.end()));

		res_sum_chicken = min(res_sum_chicken, tmp_sum_chicken);
		tmp_sum = 0;
		ind.clear(); // 새로운 케이스 위한 복구
	}

	cout << res_sum_chicken;

	return 0;
}