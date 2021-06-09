#include <string>
#include <vector>

using namespace std;

bool path[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            path[i][j] = false;
        }
    }
    
    for (int i = 0; i < results.size(); i++) {
        path[results[i][0]][results[i][1]] = true;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (path[i][k] && path[k][j])
                    path[i][j] = true;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int paths = 0;
        for (int j = 1; j <= n; j++) {
            if (path[i][j] || path[j][i]) paths++;
        }
        if (paths == n-1) answer++;
    }
    
    return answer;
}