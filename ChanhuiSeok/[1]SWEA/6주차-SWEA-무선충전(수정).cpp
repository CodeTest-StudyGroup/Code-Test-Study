#define pb push_back
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct bc {
    int y, x, C, P;
}BC;

bool isPermit(int y, int x) {
    bool flag = true;
    if (y < 1 || y > 10 || x < 1 || x > 10)
        flag = false;
    return flag;
}

pair<int, int> moving(int y, int x, int dir) {
    // 이동 정보의 0:이동X, 1:상, 2:우, 3:하, 4:좌
    bool flag;
    if (dir == 0) return { y, x };
    if (dir == 1) { // 상
        flag = isPermit(y - 1, x);
        if (flag) return { y - 1,x };
    }
    if (dir == 2) { // 우
        flag = isPermit(y, x + 1);
        if (flag) return { y,x + 1 };
    }
    if (dir == 3) { // 하
        flag = isPermit(y + 1, x);
        if (flag) return { y + 1,x };
    }
    if (dir == 4) { // 좌
        flag = isPermit(y, x - 1);
        if (flag) return { y,x - 1 };
    }
}

// 특정 BC의 중심의 좌표와, 사용자의 지점 좌표간의 거리를 구하는 함수
int cal_path(int my, int mx, int y, int x) {
    return abs(my - y) + abs(mx - x);
}

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

int main() {

    int T, input, M, A;
    vector<int> A_path, B_path, A_sum, B_sum;
    pair<int, int>cur_A, cur_B;
    vector<BC> BC_info;

    scanf("%d", &T);
    // 사용자는 초기 위치(즉, 0초)부터 충전할 수 있다.
    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &M, &A); // M은 총 이동시간, A는 BC의 갯수
        for (int i = 0; i < M; i++) {
            scanf("%d", &input);
            A_path.pb(input);
        }
        for (int i = 0; i < M; i++) {
            scanf("%d", &input);
            B_path.pb(input);
        }
        for (int i = 0; i < A; i++) {
            int x, y, c, p; // 이 문제의 지도 좌표는 (x,y)(즉 (열,행)) 으로 되어있다
            scanf("%d %d %d %d", &x, &y, &c, &p);
            BC_info.pb({ y,x,c,p });
        }
        cur_A = { 1, 1 }; // y=1, x=1
        cur_B = { 10, 10 }; // y=10, x=10

        // 사용자를 총 이동시간 만큼 움직여 본다.
        for (int i = 0; i < M + 1; i++) {
            vector<pair<int, int>> tempA, tempB; // 각 pair -> BC의 번호와, 들어간 충전량
            int dirA, dirB;
            if (i == 0) { // 맨 처음 시작일 경우
                int max_A = 0, max_B = 0;
                for (int j = 0; j < A; j++) {
                    int pathA = cal_path(BC_info[j].y, BC_info[j].x, cur_A.first, cur_A.second);
                    int pathB = cal_path(BC_info[j].y, BC_info[j].x, cur_B.first, cur_B.second);

                    if (pathA <= BC_info[j].C)
                        max_A = max(max_A, BC_info[j].P);
                    if (pathB <= BC_info[j].C)
                        max_B = max(max_B, BC_info[j].P);
                }
                A_sum.push_back(max_A); B_sum.push_back(max_B);
                continue;
            }
            ////////////////////// case 1. A 사용자
            dirA = A_path[i - 1];
            cur_A = moving(cur_A.first, cur_A.second, dirA);
            for (int i = 0; i < A; i++) {
                int path = cal_path(BC_info[i].y, BC_info[i].x, cur_A.first, cur_A.second);
                if (path <= BC_info[i].C)
                    tempA.push_back({ i, BC_info[i].P });
            }
            sort(tempA.begin(), tempA.end(), compare); // 맨 앞에 가장 성능 좋은 것이 들어가게끔 정렬

            //////////////////////  case 2. B 사용자
            dirB = B_path[i - 1];
            cur_B = moving(cur_B.first, cur_B.second, dirB);
            for (int i = 0; i < A; i++) {
                int path = cal_path(BC_info[i].y, BC_info[i].x, cur_B.first, cur_B.second);
                if (path <= BC_info[i].C)
                    tempB.push_back({ i, BC_info[i].P });
            }
            sort(tempB.begin(), tempB.end(), compare);

            // tempA, tempB에 각각 가능한 BC들의 목록이 1개 이상 들어가 있을 경우 조건에 맞는 처리
            if (tempA.size() >= 1 && tempB.size() >= 1) {
                int valA, valB, max_BC_A, max_BC_B, max_tempA, max_tempB;
                max_BC_A = tempA[0].first; // A 사용자의 현재 가능한 BC들 중, 최대 충전량의 BC 번호
                max_BC_B = tempB[0].first; // B 사용자의 현재 가능한 BC들 중, 최대 충전량의 BC 번호

                // A와 B 사용자의 최대 충전량 갖는 BC가, 같은 번호의 BC일 경우, 조건에 의해 선택해야 한다.
                // 즉, 충전량은 같지만 번호는 다른 BC면 조건을 따질 필요가 없고, 이 조건문에서 나가게 된다.
                if (max_BC_A == max_BC_B) {
                    max_tempA = tempA[0].second; // A의 최대 충전량
                    max_tempB = tempB[0].second; // B의 최대 충전량
                    valA = max_tempA / 2; // 균등분배하여 놓는다.

                    // BC가 같고 A와 B 모두 1개씩 있으면 균등 분배
                    if (tempA.size() == 1 && tempB.size() == 1) {
                        A_sum.push_back(valA); B_sum.push_back(valA);
                    }
                    // A는 가능한 BC가 단 한개 뿐이고, B는 2개 이상일 경우
                    else if (tempA.size() == 1) {
                        max_tempA = tempA[0].second; // A의 최대 충전량
                        max_tempB = tempB[0].second; // B의 최대 충전량
                        if (max_tempA > max_tempA + tempB[1].second) { // 균등분배한 A와 B의 합이 더 클 경우
                            A_sum.push_back(max_tempA);
                            B_sum.push_back(max_tempA);
                        }
                        else { // A가 최댓값 가지게 하고, B는 그 다음 값을 선택한 뒤 더한 A와 B의 합이 더 클 경우
                            A_sum.push_back(tempA[0].second);
                            B_sum.push_back(tempB[1].second);
                        }
                    }
                    // B는 가능한 BC가 단 한개 뿐이고, A는 2개 이상일 경우
                    else if (tempB.size() == 1) {
                        max_tempA = tempA[0].second; // A의 최대 충전량
                        max_tempB = tempB[0].second; // B의 최대 충전량
                        if (max_tempA > max_tempB + tempA[1].second) { // 균등분배한 A와 B의 합이 더 클 경우
                            A_sum.push_back(max_tempA);
                            B_sum.push_back(max_tempA);
                        }
                        else { // B가 최댓값 가지게 하고, A는 그 다음 값을 선택한 뒤 더한 A와 B의 합이 더 클 경우
                            A_sum.push_back(tempA[1].second);
                            B_sum.push_back(tempB[0].second);
                        }
                    }
                    // A, B 모두 가능한 BC가 2개 이상인 경우
                    else {
                        max_tempA = tempA[0].second; // A의 최대 충전량
                        max_tempB = tempB[0].second; // B의 최대 충전량
                        if (max_tempA > max_tempA + tempB[1].second
                            && max_tempA > max_tempB + tempA[1].second) { // 균등분배한 합이 더 크면 그냥 이걸 선택
                            A_sum.push_back(max_tempA);
                            B_sum.push_back(max_tempA);
                        }
                        else if (max_tempA + tempB[1].second > max_tempA
                            && max_tempA + tempB[1].second > max_tempB + tempA[1].second) { // case 2
                            A_sum.push_back(tempA[0].second);
                            B_sum.push_back(tempB[1].second);
                        }
                        else { // case 3
                            A_sum.push_back(tempA[1].second);
                            B_sum.push_back(tempB[0].second);
                        }
                    }
                }
                // 같은 BC가 아니라서 조건을 따질 필요가 없으므로, 그대로 최댓값을 넣어준다.
                else {
                    A_sum.push_back(tempA[0].second);
                    B_sum.push_back(tempB[0].second);
                }
            }
            // A는 가능한 BC가 없었고 B만 있었을 경우, B에만 최댓값을 넣어준다.
            else if (tempA.size() == 0 && tempB.size() > 0)
                B_sum.push_back(tempB[0].second);

            // B는 가능한 BC가 없었고 A만 있었을 경우, A에만 최댓값을 넣어준다.
            else if (tempB.size() == 0 && tempA.size() > 0)
                A_sum.push_back(tempA[0].second);
        }
        int sum_A = 0, sum_B = 0;
        for (int i = 0; i < A_sum.size(); i++) sum_A += A_sum[i];
        for (int i = 0; i < B_sum.size(); i++) sum_B += B_sum[i];
        printf("#%d %d\n", t, sum_A + sum_B);
        A_path.clear(); B_path.clear(), BC_info.clear();
        A_sum.clear(); B_sum.clear();
    }

    return 0;
}