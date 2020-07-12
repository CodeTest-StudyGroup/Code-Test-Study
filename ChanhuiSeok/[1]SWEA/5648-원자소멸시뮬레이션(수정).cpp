#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Atomic{
	int x;
	int y;
	int dir;
	int K;
	bool disCharge;
}atomic;

int arr[2002][2002];
int collide[2002][2002];
int collEntry[1001];
atomic atomic_list[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, N, inX, inY, inD, inK;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		for (int i = 1; i < 1001; i++) collEntry[i] = 0;

		// arr 배열 초기화
		for (int k = 0; k < 2002; k++)
			for (int j = 0; j < 2002; j++) 
				arr[k][j] = 0;
					
		cin >> N; //원자의 갯수

		for (int i = 1; i <= N; i++) {
			cin >> inX >> inY >> inD >> inK;
			atomic_list[i].x = inX + 1000;
			atomic_list[i].y = inY + 1000;

			if (inD == 0) atomic_list[i].dir = 1;
			else if (inD == 1) atomic_list[i].dir = -1;
			else if (inD == 2) atomic_list[i].dir = 2;
			else if (inD == 3) atomic_list[i].dir = -2;

			atomic_list[i].K = inK;
			atomic_list[i].disCharge = false;
			arr[inY + 1000][inX + 1000] = i;
		}

		int ty, tx, tD, tK;
		int time = 0, t_Energy = 0;

		// 시간 흐름 시작
		while (1) {
			time += 1;
			if (time > 2001) break; // -1000~1000 까지 이동에 2000초, 그 이상일 경우 모두 다 바깥으로..

			// [1] '두 지점'이 서로 맞붙어 있어서 0.5초에 부딪힐 것이 있는지 사전 확인
			for (int j = 1; j <= N; j++) {
				if (atomic_list[j].disCharge == true) continue; // 이미 방출된 원자는 패스

				ty = atomic_list[j].y; tx = atomic_list[j].x;
				tD = atomic_list[j].dir; tK = atomic_list[j].K;

				// 옮기기 전에 이전 좌표 저장
				int beforeX = tx, beforeY = ty;

				// 차례대로 상(y 증가 방향), 하, 좌, 우로 이동시켜 본다.
				if (tD == 1) ty += 1; else if (tD == -1) ty -= 1;
				else if (tD == 2) tx -= 1; else tx += 1;

				// 바로 다음 칸이 허용 가능한 칸이면서, 다른 원자가 있을 경우
				if (ty >= 0 && tx >= 0 && ty < 2002 && tx < 2002 && arr[ty][tx] != -1) {

					// 그 다음칸에 기록된 원자가 방출된 원자가 아닐 경우에만 시행
					if (atomic_list[arr[ty][tx]].disCharge != true) {
						int nextDir = atomic_list[arr[ty][tx]].dir;

						// 0.5초에서 부딪힐 상황이 될 경우, 방출 및 초기화 진행
						if (nextDir * -1 == tD) {
							collEntry[arr[ty][tx]] = 1; collEntry[j] = 1;
							arr[beforeY][beforeX] = 0; // 이전 내 자리 초기화
							atomic_list[j].disCharge = true; // 방출
							atomic_list[arr[ty][tx]].disCharge = true; // 방출
							arr[ty][tx] = 0; // 충돌 지점 초기화
						}
					}
				}	
			}

			// [2] 맞붙은 칸 처리 완료 -> 1초 동안 일어나는 일
			for (int j = 1; j <= N; j++) {
				if (atomic_list[j].disCharge == true) continue; // 이미 방출된 원자는 패스

				ty = atomic_list[j].y; tx = atomic_list[j].x;
				tD = atomic_list[j].dir; tK = atomic_list[j].K;

				// 옮기기 전에 이전 좌표 저장
				int beforeX = tx, beforeY = ty;

				// 차례대로 상(y 증가 방향), 하, 좌, 우로 이동시켜 본다.
				if (tD == 1) ty += 1; else if (tD == -1) ty -= 1;
				else if (tD == 2) tx -= 1; else tx += 1;
					
				// 앞으로 이동해야 할 곳에 아무것도 없을 경우, 옮긴다.
				if (ty >= 0 && ty < 2002 && tx >= 0 && tx < 2002 && collide[ty][tx] == 0) {
					arr[ty][tx] = j;
					atomic_list[j].y = ty; atomic_list[j].x = tx;
					collide[ty][tx] = tK; // 이동한 칸에 에너지량 기입
				}

				else if (ty >= 0 && ty < 2002 && tx >= 0 && tx < 2002 && collide[ty][tx] != 0) {
					collEntry[arr[beforeY][beforeX]] = 1;
					collEntry[arr[ty][tx]] = 1;

					if(arr[ty][tx] != 0) atomic_list[arr[ty][tx]].disCharge = true; // 기존 원자 방출
					atomic_list[j].disCharge = true; // 충돌 예정 원자 방출

					arr[beforeY][beforeX] = 0; // 이전 내 자리 초기화
					arr[ty][tx] = 0; // 충돌 지점 초기화			
				}
				else arr[beforeY][beforeX] = 0; // 허용 범위 벗어난 경우 이전 내 자리 초기화				
			}

			// [4] collide 배열 초기화
			for (int k = 1; k<=N; k++) {
				int tx = atomic_list[k].x;
				int ty = atomic_list[k].y;
				collide[ty][tx] = 0;
			}
		}
		for (int i = 1; i <= N; i++) {
			if (collEntry[i] == 1) t_Energy += atomic_list[i].K;		
		}
		cout << "#" << t + 1 << " " << t_Energy << '\n';
	}
	return 0;
}