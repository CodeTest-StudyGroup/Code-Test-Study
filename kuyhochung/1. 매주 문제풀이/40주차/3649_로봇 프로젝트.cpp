#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int x;
    
    while (cin >> x) {
        int n;
        cin >> n;
        x = x * 10000000;
        vector<int> blocks;
        
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            blocks.push_back(temp);
        }
        sort (blocks.begin(), blocks.end());
        
        int left = 0, right = n-1;
        
        bool hasFound = false;
        while (left < right) {
            int temp = blocks[left] + blocks[right];
            if (temp == x) {
                hasFound = true;
                cout << "yes " << blocks[left] << " " << blocks[right] << '\n';
                break;
            }
            else if (temp > x) right--;
            else if (temp < x) left++;
        }
        
        if (!hasFound) cout << "danger\n";
    }
    return 0;
}
