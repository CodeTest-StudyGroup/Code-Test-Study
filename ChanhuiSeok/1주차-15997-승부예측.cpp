#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;
vector <pair<string, double>> v;
vector <double> result(4); // 나중에 최종 확률 출력값

string t1, t2, t3, t4;
int reName(string str) {
    if (str == t1) {
        return 0;
    }
    else if (str == t2) {
        return 1;
    }
    else if (str == t3) {
        return 2;
    }
    else if (str == t4) {
        return 3;
    }
}

int n;
double percentage = 1;

typedef struct cases {
    string A;
    string B;
    double W;
    double D;
    double L;
}Case;

Case cases[6];

// desc order 
bool compare(const pair<string,double> &a, const pair<string, double>& b) {
    return a.second > b.second;
}

void dfs(int n) {

    if (percentage == 0)
        return;

    if (n == 6) {
        vector <pair<string, double>> rank; // 각 케이스별 랭크값 저장
        for (int i = 0; i < 4; i++) {
            rank.push_back({ v[i].first, v[i].second });
        }
        sort(rank.begin(), rank.end(), compare);

        // 모든 팀의 점수가 같을 때
        if (rank[0].second == rank[1].second && rank[1].second == rank[2].second &&
            rank[2].second == rank[3].second) {
            result[reName(rank[0].first)] += 0.5 * percentage;
            result[reName(rank[1].first)] += 0.5 * percentage;
            result[reName(rank[2].first)] += 0.5 * percentage;
            result[reName(rank[3].first)] += 0.5 * percentage;
        }

        // 상위 1팀은 명확하고, 중간 2, 3등의 등수가 같고, 4등도 명확할 때
        else if (rank[0].second > rank[1].second &&
            rank[1].second == rank[2].second && rank[2].second > rank[3].second) {
            result[reName(rank[0].first)] += percentage;
            result[reName(rank[1].first)] += 0.5 * percentage;
            result[reName(rank[2].first)] += 0.5 * percentage;
        }

        // 상위 1팀은 명확하고, 2,3,4 등의 점수가 같을 때
        else if (rank[0].second > rank[1].second &&
            rank[1].second == rank[2].second && rank[2].second == rank[3].second) {
            result[reName(rank[0].first)] += percentage;
            result[reName(rank[1].first)] += percentage * 1.0 / 3.0;
            result[reName(rank[2].first)] += percentage * 1.0 / 3.0;
            result[reName(rank[3].first)] += percentage * 1.0 / 3.0;
        }

        // 상위 1,2,3 등이 점수가 같고, 4등은 명확할 때
        else if (rank[0].second == rank[1].second && rank[1].second == rank[2].second
            && rank[2].second > rank[3].second) {
            result[reName(rank[0].first)] += percentage * 2.0 / 3.0;
            result[reName(rank[1].first)] += percentage * 2.0 / 3.0;
            result[reName(rank[2].first)] += percentage * 2.0 / 3.0;
        }

        // 상위 1, 2팀이 명확하게 구분될 때
        else if (rank[0].second > rank[1].second && rank[1].second > rank[2].second
            || (rank[0].second == rank[1].second && rank[1].second > rank[2].second)) {
            result[reName(rank[0].first)] += percentage;
            result[reName(rank[1].first)] += percentage;
        }

        return;
    }


    for (int i = 0; i < 4; i++) {
        if (cases[n].A == v[i].first) { // cases n번째 줄의 A가 반복문 i에서의 팀명과 같을 때           
            for (int j = 0; j < 4; j++) {
                if (cases[n].B == v[j].first) { // cases n번째 줄의 B가 반복문 j에서의 팀명과 같을 때
                 
                    for (int c = 0; c < 3; c++) {
                        double tempPercent = percentage;

                        // case 0. A가 이길 때
                        if (c == 0) {
                            v[i].second += 3;
                            percentage = percentage * cases[n].W;
                            dfs(n + 1);
                            v[i].second -= 3;
                        }

                        // case 1. A와 B가 비길 때
                        else if (c == 1) {
                            v[i].second += 1;
                            v[j].second += 1;
                            percentage = percentage * cases[n].D;
                            dfs(n + 1);
                            v[i].second -= 1;
                            v[j].second -= 1;
                        }

                        // case 2. A가 질 때 (즉, B가 이길 때)
                        else if (c == 2) {
                            v[j].second += 3;
                            percentage = percentage * cases[n].L;
                            dfs(n + 1);
                            v[j].second -= 3;
                        }

                        percentage = tempPercent;
                    }

                }
            }
        }
    }
    
    
}

int main()
{
    string team;
    for (int i = 0; i < 4; i++)
    {
        cin >> team;
        v.push_back({ team, 0 });
    }
    
    t1 = v[0].first;
    t2 = v[1].first;
    t3 = v[2].first;
    t4 = v[3].first;

    // 아래 6줄에 대하여 모든 경우의 수를 파악한다.
    // 즉, 한 줄당 이겼을 때 , 비겼을 때, 졌을 때의 3가지 경우가 나오고,
    // 3*3*3*3*3*3 = 3^6 가지의 경우의 수를 모두 본다는 의미가 된다!!
    // KOREA CCC 0.3 0.4 0.3
    // AAA BBB 0.428 0.144 0.428
    // AAA KOREA 0.0 0.0 1.0
    // CCC BBB 0.0 0.0 1.0
    // KOREA BBB 1.0 0.0 0.0
    // CCC AAA 0.0 0.0 1.0
    // 이었다면,
    // (1번째 줄) KOREA가 CCC를 이겼을 때 (확률 0.3)
    // (2) AAA가 이겼을 때 -> (3) AAA가 이겼을 때 -> (4) CCC가 이겼을 때 -> (5) KOREA가 이겼을 때
    // -> (6) CCC가 이겼을 때 -> (5) Korea가 이겼을 때로 백트래킹 -> (6) CCC와 AAA가 비겼을 때
    // -> (5) Korea가 이겼을 때로 백트래킹 -> (6) CCC가 AAA에게 졌을 때
    // -> (5) Korea와 BBB가 비겼을 때 -> (6) CCC가 이겼을 때 -> .... 반복 하면 3^6 가지 경우의 수를
    // 모두 볼 수 있다. 이 때, 확률 곱을 저장해 두면서 dfs로 판단해 준다.
    // 6줄을 모두 다 보았을 시, 승점이 매겨질 것이고, 이를 토대로 랭크를 만들어 준다.
    // 랭크 유형별로 확률 곱을 저장해 두면서 값을 result에 저장해 준다.


    for (int i = 0; i < 6; i++) {
        string A, B;
        double W, D, L;

        cin >> A >> B >> W >> D >> L;
        cases[i].A = A; cases[i].B = B; cases[i].W = W;
        cases[i].D = D; cases[i].L = L;
    }

    dfs(0);


    for (int i = 0; i < 4; i++) {
        printf("%.6lf\n", result[i]);
    }
    

}
