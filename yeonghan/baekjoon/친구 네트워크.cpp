#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
int t;
int parent[200001];
int netSize[200001];

int Find(int node) {
    if(node == parent[node]) return node;

    return parent[node] = Find(parent[node]);
}

void Union(int node1, int node2) {
    node1 = Find(node1);
    node2 = Find(node2);

    if(node1 != node2) {
        if(netSize[node1]<netSize[node2]) swap(node1, node2);

        parent[node2] = node1;
        netSize[node1] += netSize[node2];
        netSize[node2] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<string, int> m;
        int index=0;
        for(int i=0 ; i<200001 ; i++) {
            parent[i] = i;
            netSize[i] = 1;
        }

        for(int i=0 ; i<n ; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if(m.find(s1) == m.end()) m[s1] = index++;
            if(m.find(s2) == m.end()) m[s2] = index++;

            int test1 = Find(m[s1]);
            int test2 = Find(m[s2]);

            if(test1 == test2) { // 같은 네트워크
                cout << max(netSize[test1], netSize[test2]) << "\n";
            }
            else { // 다른 네트워크
                Union(test1, test2); // 합치고
                cout << max(netSize[test1], netSize[test2]) << "\n";
            }
        }
    }
    
    return 0;
}