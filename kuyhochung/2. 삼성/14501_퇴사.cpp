#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 16

int N;
int T[MAX_N] = {0, };
int P[MAX_N] = {0, };
int answer = 0;

int main() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }
    
    for (int i = N; i > 0; i--) {
        if (i + T[i] > N + 1)                       //어차피 접근할 수 없는 날
            P[i] = P[i+1];
        else {
            P[i] = max(P[i+1], P[i] + P[i+T[i]]);
            answer = max(answer, P[i]);
        }
    }
    cout << answer;
    return 0;
}
