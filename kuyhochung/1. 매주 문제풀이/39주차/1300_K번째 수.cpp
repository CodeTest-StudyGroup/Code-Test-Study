#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int result = -1;

int main () {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    
    int front = 1, end = k;
    while (front <= end) {
        int cnt = 0;
        int mid = (front + end) / 2;
        
        //mid 이하의 j의 개수를 구한다.
        //i * j  <= mid이므로, j <= (mid/i)
        for (int i = 1; i <= n; i++) {
            cnt += min (mid/i, n);
        }
        
        if (cnt < k) front = mid + 1;
        else {
            result = mid;
            end = mid - 1;
        }
    }
    cout << result;
    
    return 0;
}
