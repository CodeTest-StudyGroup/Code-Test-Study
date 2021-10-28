#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, temp;
    //양수: 자신보다 키가 큰 이성과 춤을 추고 싶다.
    //음수: 자신보다 키가 작은 이성과 춤을 추고 싶다.
    vector<int> male_pos;
    vector<int> male_neg;
    vector<int> female_pos;
    vector<int> female_neg;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp > 0) male_pos.push_back(temp);
        else male_neg.push_back(abs(temp));
    }
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp > 0) female_pos.push_back(temp);
        else female_neg.push_back(abs(temp));
    }
    
    sort(male_pos.begin(), male_pos.end(), greater<int>());
    sort(male_neg.begin(), male_neg.end(), greater<int>());
    sort(female_pos.begin(), female_pos.end(), greater<int>());
    sort(female_neg.begin(), female_neg.end(), greater<int>());
    
    int cnt = 0;
    int i = 0, j = 0;
    while (i < male_pos.size() && j < female_neg.size()) {
        if (male_pos[i] < female_neg[j]) {
            cnt++;
            i++;
            j++;
        }
        else {
            i++;
        }
    }
    i = 0; j = 0;
    while (i < female_pos.size() && j < male_neg.size()) {
        if (female_pos[i] < male_neg[j]) {
            cnt++;
            i++;
            j++;
        }
        else {
            i++;
        }
    }
    cout << cnt;
    return 0;
}
