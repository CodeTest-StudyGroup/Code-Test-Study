#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define INF 1e12                            //무한히 큰 수
#define MAX_ELEMENTS 200004                 //N*M의 최댓값은 200000
int N, M, D;                                //입력값 N, M, D
long long memo[MAX_ELEMENTS];               //memoization에 활용할 array; -INF로 초기화
long long input[MAX_ELEMENTS];              //입력값을 담을 array
long long answer = -INF;                    //답을 담을 long long형 변수

//array의 index 밖으로 나가는 것을 방지하기 위한 함수
bool isInBoundary(int curN, int curM) {
    return (0 <= curN && curN < N && 0 <= curM && curM < M);
}

long long memoization(int initM) {
    if (initM >= N*M)                       //범위 밖으로 나가는지 검사
        return -INF;
    int curN = initM / M;                   //현재 위치의 N값
    int curM = initM % M;                   //현재 위치의 M값
    if (curN == (N-1))
        return 0;                           //N번 행에 도달하였음
    if (memo[initM] != -INF)
        return memo[initM];                 //이미 탐색하였다면, 다시 탐색하지 않고 값을 반환한다.
    
    //curN은 아래로만 내려가고, curMM은 0부터 M 사이에 존재하므로, loop 조건을 아래와 같이 한다.
    for (int i = curN; i <= curN + D; i++) {
        for (int j = curM-D; j <= curM + D; j++) {
            //범위 내에 존재하고, 탐색하고자 하는 곳의 N이 시작점보다 크며, 이동 거리 가능한 범위 내에 존재하면,
            if (isInBoundary(i,j) && curN < i && (abs(i-curN) + abs(j-curM)) <= D)
                memo[initM] = max(memo[initM], input[initM]*input[i*M+j] + memoization(i*M+j));
            //메모이제이션 배열의 값은, 현재 값과 새로 계산된 값 (원소의 곱의 합산) 중 큰 것으로 한다.
        }
    }
    
    return memo[initM];
}


int main() {
    
    for (int i = 0; i < MAX_ELEMENTS; i++)
        memo[i] = -INF;
    cin >> N >> M >> D;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input[i*M+j];
        }
    }
    
    //맨 처음 시작점은 N = 0인 위치 중 어디에서나 가능하므로,
    for (int i = 0; i < M; i++)
        answer = max(answer, memoization(i));
    
    cout << answer;
    
    return 0;
}
