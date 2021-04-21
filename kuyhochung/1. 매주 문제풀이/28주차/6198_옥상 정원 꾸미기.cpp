#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<int> buildings;
stack<int> s;
long long answer = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        buildings.push_back(temp);
    }
    
    for (int i = 0; i < n; i++) {
        while(!s.empty() && s.top() <= buildings[i]) s.pop();
        answer += s.size();
        s.push(buildings[i]);
    }
    cout << answer;
    return 0;
}
