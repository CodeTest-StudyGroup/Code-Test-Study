#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;
#define MAX 700
// 애벌레의 사이즈와 애벌레가 자라게 될 크기를 저장하는 배열
long long larvaSize[MAX][MAX], growNum[2 * MAX - 1];
int M;
int dirX[3] = { 0, -1, -1 };
int dirY[3] = { -1, -1, 0 };
// 애벌레 사이즈 1로 초기화
void init() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			larvaSize[i][j] = 1;
		}
	}
}

void growLarva() {
	int rowIdx = M - 1, columnIdx = 1;
    // 제일 왼쪽 열과 위쪽 행의 애벌레들 크기 증가
	for (int i = 0; i < 2 * M - 1; i++) {
		if (i < M) {
            // 제일 왼쪽 열에 있는 애벌레들 정해진 값만큼 사이즈 증가시킴
			larvaSize[rowIdx][0] += growNum[i];
			rowIdx--;
		}
		else {
            // 제일 위쪽 행에 있는 애벌레들 정해진 값만큼 사이즈 증가시킴
			larvaSize[0][columnIdx] += growNum[i];
			columnIdx++;
		}
	}
    // 나머지 애벌레들 크기 증가
	for (int i = 1; i < M; i++) {
		for (int j = 1; j < M; j++) {
			long long sizeMax = 0;
			for (int k = 0; k < 3; k++) {
                // 현재 위치의 왼쪽, 왼쪽 위, 위쪽의 애벌레들 중 제일 사이즈가 큰 값을 저장
				sizeMax = max(sizeMax, larvaSize[i + dirX[k]][j + dirY[k]]);
			}
            // 최대값을 현재 위치의 애벌레 사이즈에 대입
			larvaSize[i][j] = sizeMax;
		}
	}
}

int main() {
	int N, zero, one, two;

	cin >> M >> N;

	init();
    // N년동안 제일 왼쪽 열과 위쪽 행의 애벌레들이 자라는 정도를 구함
	for (int i = 0; i < N; i++) {
        // 0, 1, 2의 개수 입력받음
		cin >> zero >> one >> two;
        // 0에 대한 계산은 건너뜀.
        // 1의 개수만큼 growNum의 현재 원소 1씩 증가시킴 
		for (int j = zero; j < zero + one; j++) {
			growNum[j]++;
		}
        // 2의 개수만큼 growNum 현재 원소 2씩 증가시킴 
		for (int j = zero + one; j < 2 * M - 1; j++) {
			growNum[j] += 2;
		}
	}
    // 애벌레 크기 증가시킴
	growLarva();
    // 애벌레 크기 출력
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << larvaSize[i][j] << " ";
		}
		cout << '\n';
	}
}