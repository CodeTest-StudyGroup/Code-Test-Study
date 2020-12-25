#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;
#define MAX_N 10000

int T, A, B;
bool visited[MAX_N];

string BFS (int start) {
    queue <pair <int, string> > q;
    q.push(make_pair(start, ""));
    visited[start] = true;
    
    while(!q.empty()) {
        int curNum = q.front().first;
        string curString = q.front().second;
        q.pop();
        
        if (curNum == B) return curString;
        
        int dx = (curNum * 2) % 10000;
        if (visited[dx] == false) {
            visited[dx] = true;
            q.push(make_pair(dx, curString + "D"));
        }
        
        dx = curNum - 1;
        if (curNum == 0) dx = 9999;
        if (visited[dx] == false) {
            visited[dx] = true;
            q.push(make_pair(dx, curString + "S"));
        }
        
        dx = (curNum % 1000) * 10 + (curNum / 1000);
        if (visited[dx] == false) {
            visited[dx] = true;
            q.push(make_pair(dx, curString + "L"));
        }
        
        dx = (curNum / 10) + (curNum % 10) * 1000;
        if (visited[dx] == false) {
            visited[dx] = true;
            q.push(make_pair(dx, curString + "R"));
        }
    }
    return "";
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        A = 0; B = 0;
        memset(visited, false, sizeof(visited));
        
        cin >> A >> B;
        cout << BFS(A) << '\n';
        
    }
    return 0;
}
