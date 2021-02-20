#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int check[51];

int main() {
    int n,ans=1000000;
    vector<int> can;
    cin >> n;
    vector<int> arr[n+1];
    while(true) {
        int a,b;
        cin >> a >> b;
        if(a==-1 && b==-1) break;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i=1 ; i<=n ; i++) {
        queue<int> q;
        q.push(i);
        memset(check, -1, sizeof(check));
        check[i] = 0;

        while(!q.empty()) {
            int x = q.front();
            q.pop();

            for(int j=0 ; j<arr[x].size() ; j++) {
                int next = arr[x][j];
                if(check[next] == -1 || check[next]>check[x]+1) {
                    check[next] = check[x]+1;
                    q.push(next);
                }
            }
        }
        int num=0;
        for(int j=1 ; j<=n ; j++) {
            num = max(num, check[j]);
        }
        // i랑 num이 후보
        if(ans>num) {
            can.clear();
            can.push_back(i);
            ans = num;
        }
        else if(ans==num) {
            can.push_back(i);
        }
    }
    cout << ans << " " << can.size() << "\n";
    for(int i=0 ; i<can.size() ; i++) {
        cout << can[i] << " ";
    }
    cout << "\n";

    return 0;
}