#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n,k;

int main() {
	cin >> n >> k;
    vector<int> arr;
    vector<int> per;
    for(int i=0 ; i<n ; i++) {
        int a;
        cin >> a;
        per.push_back(i);
        arr.push_back(a);
    }
    int cnt=0;
    do {
        int sum = 500;
        bool check = true;
        for(int i=0 ; i<n ; i++) {
            sum += arr[per[i]]-k;
            if(sum<500) {
                check = false;
                break;
            }
        }
        if(check) cnt++;
    }while(next_permutation(per.begin(), per.end()));
    cout << cnt;

	return 0;
}
