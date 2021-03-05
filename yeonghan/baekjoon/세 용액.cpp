#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<long long> arr;
long long ans[3];
bool check;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        long long a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    long long cnt=0;
    for(int i=0 ; i<n-2 ; i++) {
        long long left = i+1, right = n-1;

        while(left<right) {
            long long sum = arr[i] + arr[left] + arr[right];
            if(!check || (abs(cnt)>abs(sum))) {
                check = true;
                cnt = sum;
                ans[0] = arr[i];
                ans[1] = arr[left];
                ans[2] = arr[right];
            }
            if(sum>0) right--;
            else if(sum<0) left++;
            else {
                sort(ans, ans+3);
                for(int i=0 ; i<3 ; i++) {
                    cout << ans[i] << " ";
                }
                exit(0);
            }
        }
    }

    sort(ans, ans+3);
    for(int i=0 ; i<3 ; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}