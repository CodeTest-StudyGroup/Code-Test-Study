#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

/* vector를 사용하면 일반 array를 사용할 때보다 탐색 및 연산에서
	속도가 더 느리다고 한다

	나중에 array 써서 시간 단축해보기!!!
*/

using namespace std;

int N, K, T, M;
int arr[101][101];

bool isMetChemical(int y, int x) {
	if (y == 0 || y >= N - 1 || x == 0 || x >= N - 1)
		return true;
	else
		return false;
}

void MetFunc(int dir, int idx, vector<vector<int>> &v) {
	if (dir == 1) {
		v[idx][2] = v[idx][2] / 2;
		v[idx][3] = 2;
	}
	else if (dir == 2) {
		v[idx][2] = v[idx][2] / 2;
		v[idx][3] = 1;
	}
	
	else if (dir == 3) {
		v[idx][2] = v[idx][2] / 2;
		v[idx][3] = 4;
	}
	
	else if (dir == 4) {
		v[idx][2] = v[idx][2] / 2;
		v[idx][3] = 3;
	}
}


int main() {

	// N은 셀의 한 변의 길이, // K는 총 군집의 갯수, // M시간동안 군집 격리 유지
	int sero, garo, nums, dir;
	bool isMet;
	int SameSum = 0, maxX, maxY;
	int resultSum = 0, idx = 0;

	vector <vector<int>> v;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {

		scanf("%d %d %d", &N, &M, &K);
		v.resize(K);
		v.reserve(K);

		// dir 값이 1,2,3,4 각각 상,하,좌,우
		// 군집의 모든 데이터 받아오기
		for (int i = 0; i < K; i++) {
			scanf("%d %d %d %d", &sero, &garo, &nums, &dir);
			v[i].reserve(4);
			v[i].push_back(sero);
			v[i].push_back(garo);
			v[i].push_back(nums);
			v[i].push_back(dir);
		}
		
		// 시뮬레이션 시작 (M시간까지)
		for (int t = 1; t <= M; t++) {

			// 모든 군집 데이터들에 대하여 시행
			for (int idx = 0; idx < v.size(); idx++) {

				/* 일단 이동부터 일괄적으로 해 놓기 */
				if (v[idx][3] == 1)  // 상
					v[idx][0] = v[idx][0] - 1;
				
				else if (v[idx][3] == 2)  // 하
					v[idx][0] = v[idx][0] + 1;
				
				else if (v[idx][3] == 3)  // 좌
					v[idx][1] = v[idx][1] - 1;
				
				else if (v[idx][3] == 4)  // 우
					v[idx][1] = v[idx][1] + 1;
				////////////////////////////////
			}

			// 이동이 끝난 군집들에 대하여 sorting //
			sort(v.begin(), v.end());

			idx = 0;
			while (idx <= v.size() - 1) {
				SameSum = 0; // 초기화

				// CASE 1. 약품과 만났는가? // 약품과 만났으면, 모여서 합치는 과정 등이 존재하지 않는다.
				isMet = isMetChemical(v[idx][0], v[idx][1]);
				if (isMet) {
					MetFunc(v[idx][3], idx, v);

					// 미생물 수가 0이 되면 그 벡터 삭제
					if (v[idx][2] == 0) {
						v.erase(v.begin() + idx);
					}
					else
						idx++;
				}
				// CASE 2. 약품과 만나진 않았으나,
				// 지금 보는 좌표가 벡터의 끝일 경우, 그 다음것과 비교할 필요가 없으므로 빠져나가는 조건을 준다.
				else if (!isMet && idx == v.size() - 1) {
					idx++;
				}
				// CASE 3. 약품과 만나지 않았고, 다음 벡터에 자기와 같은 좌표 군집이 없을 경우
				// 그냥 이동할 수 있으므로 다음으로만 넘어간다.
				else if (!isMet &&
					(v[idx][0] != v[idx + 1][0] || v[idx][1] != v[idx + 1][1])) {
					idx++;
				}
				// CASE 4. 약품과 만나지 않았고, 다음 벡터에 자기와 같은 좌표 군집이 있을 경우
				else if (!isMet &&
					(v[idx][0] == v[idx + 1][0] && v[idx][1] == v[idx + 1][1])) {

					while (1) {
						if (idx == v.size() - 1) { // 이미 마지막이면 						
							v[idx][2] += SameSum;
							idx++;
							break;
						}

						else if (v[idx][0] == v[idx + 1][0] && v[idx][1] == v[idx + 1][1]) {
							// 미생물 수의 합을 더한다.
							// 그리고 도달한 좌표는 같지만 미생물 수는 더 적은 행이었으니 이 벡터는 삭제한다.
							SameSum = SameSum + v[idx][2];
							v.erase(v.begin() + idx);
						}

						else {
							// 같은 좌표에 도달한 군집들 중 제일 큰 군집이므로,
							// 삭제하지 않고 합만 더한 뒤 나간다.
							SameSum += v[idx][2];
							v[idx][2] = SameSum;
							idx++;
							break;
						}
					}
				}
			}
		}


		// 모든 미생물들의 합 구하기
		for (int i = 0; i < v.size(); i++) 
			resultSum += v[i][2];
		
		printf("#%d %d\n",t,resultSum);

		// 새로운 테스트케이스를 위한 초기화
		resultSum = 0;
		v.clear();
	}


}