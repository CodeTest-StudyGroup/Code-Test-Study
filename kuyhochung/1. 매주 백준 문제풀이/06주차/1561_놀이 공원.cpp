#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_M 10001

int N, M;
vector <long long> ride(MAX_M, 0);

long long binary_search() {
    long long low = 0, high = *(max_element(ride.begin(), ride.end())) * N, mid = 0;
    
    while(low + 1 < high) {
        mid = (low + high) / 2;
        long long temp = M;
        for (int i = 1; i <= M; i++) {
            temp += mid / ride[i];
        }
        if (temp < N)
            low = mid;
        else
            high = mid;
    }
    
    //k번째 시간까지 놀이기구를 탄 아이의 수를 전체 아이의 수에서 빼 줍니다.
    for (int i = 1; i <= M; i++)
        N -= low / ride[i];
    N -= M;
    
    return low;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> ride[i];
    }
    
    if (N <= M) {
        cout << N;
        return 0;
    }
    
    long long k = binary_search() + 1;              //k는 시간 t까지 놀이기구를 탑승한 아이들 수의 총합

    for (int i = 1; i <= M; i++) {
        if (k % ride[i] == 0) {
            N--;
            if (N == 0) {
                cout << i;
                return 0;
            }
        }
    }
    
    return 0;
}
