#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector <pair <int, int> > towns;
int n;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    long long total = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        towns.push_back({a, b});
        total += b;
    }
    sort(towns.begin(), towns.end());
    
    long long prefix_sum = 0;
    for (int i = 0; i < n; i++) {
        prefix_sum += towns[i].second;
        if (prefix_sum > ceil(total/2)) {
            cout << towns[i].first;
            break;
        }
    }
    return 0;
}
