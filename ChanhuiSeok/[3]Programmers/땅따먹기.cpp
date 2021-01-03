#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int N = land.size();

    for (int i = 0; i < N - 1; i++) {
        land[i + 1][0] = land[i + 1][0] + max(land[i][1], max(land[i][2], land[i][3]));
        land[i + 1][1] = land[i + 1][1] + max(land[i][0], max(land[i][2], land[i][3]));
        land[i + 1][2] = land[i + 1][2] + max(land[i][0], max(land[i][1], land[i][3]));
        land[i + 1][3] = land[i + 1][3] + max(land[i][0], max(land[i][1], land[i][2]));
    }

    answer = max(land[N - 1][0], max(land[N - 1][1], max(land[N - 1][2], land[N - 1][3])));

    return answer;
}