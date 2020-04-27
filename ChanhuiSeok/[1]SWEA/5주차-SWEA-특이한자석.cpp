#define _CRT_SECURE_NO_WARNINGS
#define NumOfMagnet 4
#define NumOfBlades 8
#include <iostream>
#include <vector>

using namespace std;

bool SameOrDiff[3];
int DoCycle[4];

void Clockwise(vector<int> &magnet) {	
	vector<int>::iterator iter;
	int temp;

	iter = magnet.begin();
	temp = magnet[magnet.size() - 1];
	magnet.pop_back();
	magnet.insert(iter, temp);
}

void ctr_Clockwise(vector<int> &magnet) {
	vector<int>::iterator iter;
	int temp;

	iter = magnet.begin();
	temp = *iter;
	magnet.erase(magnet.begin());
	magnet.push_back(temp);
}

int main() {

	int T, K, input, mNum, dir;
	int score = 0, twice = 1;
	vector<vector<int>> magnet;
	vector<pair<int, int>> cycle;
	
	scanf("%d", &T);
	
	for (int t = 1; t <= T; t++) {

		scanf("%d", &K);

		for (int i = 0; i < NumOfMagnet; i++) {
			vector<int> temp;
			for (int j = 0; j < NumOfBlades; j++) {
				scanf("%d", &input);
				temp.push_back(input);
			}
			magnet.push_back(temp);
		}

		for (int i = 0; i < K; i++) {
			scanf("%d %d", &mNum, &dir);
			cycle.push_back({ mNum, dir });
		}

		// margnet 인덱스 번호 in 0은 N극, 1은 S극 // 시계방향은 1, 반시계방향은 -1
		// 자석날이 같은지 아닌지 SameOrDiff에 처음 표기		
		for (int i = 0; i < NumOfMagnet - 1; i++) {
			if (magnet[i][2] == magnet[i + 1][6]) 
				SameOrDiff[i] = true;		
			else
				SameOrDiff[i] = false;
		}

		// 테스트 시작
		for (int i = 0; i < K; i++) {
			mNum = cycle[i].first; dir = cycle[i].second;
			DoCycle[mNum - 1] = dir;

			// mNum번 자석을 dir 방향으로 회전시킨다. mNum번 자석 회전시, 다른 자석들 영향 파악		
			if (mNum - 1 == 0) { // 0번 자석
				if (SameOrDiff[0] == false) 
					DoCycle[1] = DoCycle[mNum - 1] * -1;				
				if (SameOrDiff[1] == false) 
					DoCycle[2] = DoCycle[1] * -1;				
				if (SameOrDiff[2] == false) 
					DoCycle[3] = DoCycle[2] * -1;			
			}
			else if (mNum - 1 == 1) { // 1번 자석 - 0번과 2번과 연결
				if (SameOrDiff[0] == false) 
					DoCycle[0] = DoCycle[mNum - 1] * -1;
				if (SameOrDiff[1] == false) 
					DoCycle[2] = DoCycle[mNum - 1] * -1;
				if (SameOrDiff[2] == false) 
					DoCycle[3] = DoCycle[2] * -1;
			}
			else if (mNum - 1 == 2) {
				if (SameOrDiff[1] == false) 
					DoCycle[1] = DoCycle[mNum - 1] * -1;
				if (SameOrDiff[2] == false) 
					DoCycle[3] = DoCycle[mNum - 1] * -1;
				if (SameOrDiff[0] == false) 
					DoCycle[0] = DoCycle[1] * -1;
			}
			else if (mNum - 1 == 3) {
				if (SameOrDiff[2] == false) 
					DoCycle[2] = DoCycle[mNum - 1] * -1;
				if (SameOrDiff[1] == false) 
					DoCycle[1] = DoCycle[2] * -1;
				if (SameOrDiff[0] == false) 
					DoCycle[0] = DoCycle[1] * -1;
			}

			for (int i = 0; i < NumOfMagnet; i++) {
				if (DoCycle[i] == 1)  /* 시계 방향 회전 */
					Clockwise(magnet[i]);
				else if (DoCycle[i] == -1)  /* 반시계 방향 회전 */
					ctr_Clockwise(magnet[i]);
			}
			//DoCycle 다시 0으로 초기화
			for (int i = 0; i < NumOfMagnet; i++)
				DoCycle[i] = 0;

			// 회전된 뒤의 같은 날 여부를 다시 표기
			for (int i = 0; i < NumOfMagnet - 1; i++) {
				if (magnet[i][2] == magnet[i + 1][6]) 
					SameOrDiff[i] = true;			
				else
					SameOrDiff[i] = false;
			}
		}

		// 점수 계산하기
		twice = 1; score = 0;

		for (int i = 1; i <= NumOfMagnet; i++) {
			if (magnet[i - 1][0] == 0)
				score += 0;
			else if (magnet[i - 1][0] == 1)
				score += twice;
			twice*=2;
		}

		printf("#%d %d",t, score);

		// 복구
		magnet.clear();
		cycle.clear();
	}
}