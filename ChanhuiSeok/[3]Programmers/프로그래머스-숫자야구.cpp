#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int strike = 0;
    int ball = 0;
    int find = 1;
    int findSuccess = 0;
    int ballCheck = 0;

    for (int num = 123; num <= 987; num++) {

        find = 1;

        if (to_string(num)[0] == '0' ||
            to_string(num)[1] == '0' ||
            to_string(num)[2] == '0')
            continue;

        if (to_string(num)[0] == to_string(num)[1] ||
            to_string(num)[1] == to_string(num)[2] ||
            to_string(num)[0] == to_string(num)[2])
            continue;


        // 반복문 도는 num이랑 벡터에 있는 숫자의 자릿수 비교
        for (int i = 0; i < baseball.size(); i++) {
            strike = 0; ball = 0;

            /* 벡터 내 숫자 하나와 일단 비교*/
            for (int m = 0; m < 3; m++) {
                for (int n = 0; n < 3; n++) {
                    if (to_string(num)[m] == to_string(baseball[i][0])[n] && m == n)
                    {
                        strike++; // 스트라이크
                        continue;
                    }
                    // 스트라이크가 아니였다면, 볼 체크
                    if (to_string(num)[m] == to_string(baseball[i][0])[n] && m != n)
                    {
                        ball++; // ball
                    }
                }
            }

            // 만약 스트라이크와 볼 수가 일치하지 않았으면 다음 num으로 이동
            if (baseball[i][1] != strike
                || baseball[i][2] != ball) {
                find = 0;
                break;
            }
        }
        // 벡터에 있는 모든 원소가 일치했을 경우
        if (find == 1) {
            findSuccess++;
        }
    }

    return findSuccess;
}