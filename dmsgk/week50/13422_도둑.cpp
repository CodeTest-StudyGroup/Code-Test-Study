//
//  13422_도둑.cpp
//  AlgorithmCpp
//
//  Created by Johyeon Yoon on 2021/09/02.
//

#include <iostream>
#include <queue>
using namespace std;

int t;
int money[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    for (int i=0; i<t; i++){
        int n, m, k;
        cin >> n >> m >> k;
            
        for (int j=0; j<n; j++){
            cin >> money[j];
        }
        
        int cnt = 0, robbed_sum = 0;
        queue<int> q;
        for (int k = 0; k<m; k++){
            q.push(money[k]);
            robbed_sum += money[k];
        }
                
        if (robbed_sum < k) {
            cnt ++;
        }
        
        if (n!=m){
            for (int i=1; i<n; i++){
                int prev = q.front();
                int now = money[(i+m-1)%n];
                robbed_sum += (now - prev);
                q.pop();
                q.push(now);
                
                if (robbed_sum < k){
                    cnt += 1;
                }
            }
        }
        cout << cnt << "\n";
    }
    
    return 0;
}
