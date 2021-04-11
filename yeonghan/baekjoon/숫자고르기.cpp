#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int n;
int arr[101];
bool visit[101];

bool go(int num, int result) {
    if(arr[num] == result) {
        visit[num] = true;
        return true;
    } else {
        if (!visit[num]) {
            visit[num] = true;
            if(go(arr[num], result)) {
                return true;
            } else {
                visit[num] = false;
                return false;
            }
        } else {
            return false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        cin >> arr[i];
    }
    for(int i=1 ; i<=n ; i++) {
        go(i, i);
    }
    int cnt=0;
    for(int i=1 ; i<=n ; i++) {
        if (visit[i]) cnt++;
    }
    cout << cnt << "\n";
    for(int i=1 ; i<=n ; i++) {
        if(visit[i]) cout << i << "\n";
    }
}
