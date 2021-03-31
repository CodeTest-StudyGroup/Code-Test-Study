#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int n, k;
bool visited[26];
vector <string> words;
int result = 0;

void simulate(int alphabet, int cnt) {
    if (cnt == k) {
        int temp = 0;
        for (int i = 0; i < n; i++) {
            bool wordFlag = true;
            for (int j = 0; j < words[i].size(); j++) {
                if (!visited[words[i][j] - 'a']) {
                    wordFlag = false;
                    break;
                }
            }
            if (wordFlag) temp++;
        }
        result = max(result, temp);
        return;
    }
    
    for (int i = alphabet; i < 26; i++) {
        if (!visited[i]) {
            visited[i] = true;
            simulate(i, cnt+1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(visited, false, sizeof(visited));
    cin >> n >> k;
    if (k == 0) {
        cout << 0 << '\n';
        return 0;
    }
    if (k == 26) {
        cout << n << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        words.push_back(temp.substr(4, temp.length()));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            words[i].pop_back();
        }
    }
    visited[0] = true; visited['c'-'a'] = true; visited['i'-'a'] = true; visited['n'-'a'] = true; visited['t'-'a'] = true;
    simulate(0, 5);
    cout << result << '\n';
    return 0;
}
