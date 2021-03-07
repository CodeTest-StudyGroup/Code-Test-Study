#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum = 0, sub = 0, mul = 0, divi = 0;
int calc[4] = {0, 1, 2, 3};
int n;
vector<int> numbers;
int minimum = 1e9, maximum = -1e9;

void dfs (int number_used, int now) {
    if (number_used == n) {
        minimum = min(minimum, now);
        maximum = max(maximum, now);
    }
    
    if (sum > 0) {
        sum--;
        dfs(number_used + 1, now + numbers[number_used]);
        sum++;
    }
    if (sub > 0) {
        sub--;
        dfs(number_used + 1, now - numbers[number_used]);
        sub++;
    }
    if (mul > 0) {
        mul--;
        dfs(number_used + 1, now * numbers[number_used]);
        mul++;
    }
    if (divi > 0) {
        divi--;
        dfs(number_used + 1, now / numbers[number_used]);
        divi++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    
    cin >> sum >> sub >> mul >> divi;
    dfs(1, numbers[0]);
    
    cout << maximum << '\n' << minimum;
    return 0;
}
