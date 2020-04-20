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

bool isMetChemical(int y, int x) {
	if (y == 0 || y >= N - 1 || x == 0 || x >= N - 1)
		return true;
	else
		return false;
}

void MetFunc(int dir, int idx, vector<vector<int>> &v) {
	if (dir == 1) {
		v[idx][2] = v[idx][2] / 2; v[idx][3] = 2;
	}
	else if (dir == 2) {
		v[idx][2] = v[idx][2] / 2; v[idx][3] = 1;
	}
	
	else if (dir == 3) {
		v[idx][2] = v[idx][2] / 2; v[idx][3] = 4;
	}
	
	else if (dir == 4) {
		v[idx][2] = v[idx][2] / 2; v[idx][3] = 3;
	}
}

int main() {
	int sero, garo, nums, dir;
	int SameSum = 0, resultSum = 0, idx = 0, maxX, maxY;
	bool isMet;
	vector <vector<int>> v;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {

		scanf("%d %d %d", &N, &M, &K);
		v.resize(K); v.reserve(K);

		for (int i = 0; i < K; i++) {
			scanf("%d %d %d %d", &sero, &garo, &nums, &dir);
			v[i].reserve(4);
			v[i].push_back(sero); v[i].push_back(garo);
			v[i].push_back(nums); v[i].push_back(dir);
		}
		
		// 시뮬레이션 시작 (M시간까지)
		for (int t = 1; t <= M; t++) {
			for (int idx = 0; idx < v.size(); idx++) {				
				if (v[idx][3] == 1)  // 상
					v[idx][0] = v[idx][0] - 1;				
				else if (v[idx][3] == 2)  // 하
					v[idx][0] = v[idx][0] + 1;				
				else if (v[idx][3] == 3)  // 좌
					v[idx][1] = v[idx][1] - 1;				
				else if (v[idx][3] == 4)  // 우
					v[idx][1] = v[idx][1] + 1;
			}
			sort(v.begin(), v.end());
			idx = 0;

			while (idx <= v.size() - 1) {
				SameSum = 0; // 초기화
				isMet = isMetChemical(v[idx][0], v[idx][1]);
				if (isMet) {
					MetFunc(v[idx][3], idx, v);

					if (v[idx][2] == 0) {
						v.erase(v.begin() + idx);
					}
					else
						idx++;
				}
				else if (!isMet && idx == v.size() - 1) {
					idx++; //break;
				}
				else if (!isMet && (v[idx][0] != v[idx + 1][0] || v[idx][1] != v[idx + 1][1])) {
					idx++;
				}
				else if (!isMet && (v[idx][0] == v[idx + 1][0] && v[idx][1] == v[idx + 1][1])) {

					while (1) {
						if (idx == v.size() - 1) {					
							v[idx][2] += SameSum; idx++;
							break;
						}
						else if (v[idx][0] == v[idx + 1][0] && v[idx][1] == v[idx + 1][1]) {
							SameSum = SameSum + v[idx][2];
							v.erase(v.begin() + idx);
						}
						else {
							SameSum += v[idx][2];
							v[idx][2] = SameSum; idx++;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < v.size(); i++) 
			resultSum += v[i][2];
		
		printf("#%d %d\n",t,resultSum);
		resultSum = 0;
	}
}