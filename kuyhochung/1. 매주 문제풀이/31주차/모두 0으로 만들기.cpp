#include <string>
#include <vector>
#include <cmath>

using namespace std;
long long answer = 0, sum = 0;
vector <long long> a;
vector <int> newEdges[300001];

void find(int to, int p) {
    for (int i = 0; i < newEdges[to].size(); i++) {
        int from = newEdges[to][i];
        if (from == p) continue;
        if (newEdges[from].size() != 1)
            find (from, to);
        answer += abs(a[from]);
        a[to] += a[from];
        a[from] = 0;
    }
}

long long solution(vector<int> inputA, vector<vector<int>> edges) {
    bool isZero = true;
    for (int i = 0; i < inputA.size(); i++) {
        sum += inputA[i];
        if (inputA[i] != 0) isZero = false;
    }
    if (isZero) return 0;
    if (sum != 0) return -1;
    
    for (int i = 0; i < inputA.size(); i++) {
        a.push_back((long long)inputA[i]);
    }

    for (int i = 0; i < edges.size(); i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        newEdges[a].push_back(b);
        newEdges[b].push_back(a);
    }
    
    find(0,-1);
    return answer;
}