#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
ll N;
vector<char> symbol;

int main() {
    cin >> N;
    while (N) {
        if (N & 1) {
            N *= 2;
            symbol.push_back('/');
        }
        else if (N & 2) {
            N -= 2;
            symbol.push_back('+');
        }
        else {
            N /= 2;
            symbol.push_back('*');
        }
    }
    
    if (symbol.size() > 99)
        cout << -1;
    else {
        cout << symbol.size() << '\n';
        while (!symbol.empty()) {
            cout << "[" << symbol.back() << "] ";
            symbol.pop_back();
        }
    }
    
    return 0;
}
