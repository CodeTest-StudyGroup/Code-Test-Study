//
//  1300_k번째수.cpp
//  AlgorithmCpp
//
//  Created by Johyeon Yoon on 2021/08/31.
//

// 1300 k번째 수
#include <iostream>
using namespace std;

long long n, k;


long long find_cnt(long long mid){
    long long cnt = 0;
    for (long long i = 1; i < n+1; i ++) {
        cnt += min(n, mid/i); 
    }
    return cnt;
}


int main(){
    cin >> n;
    cin >> k;
    
    long long left = 1;
    long long right = n * n;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (find_cnt(mid) >= k){
            right = mid -1;
        }
        else {
            left = mid + 1;
        }
    }
    cout << left;
    
    return 0;

}
