#include <string>
#include <vector>

using namespace std;

vector <vector <int> > RotateMatrixBy90Degree (vector <vector <int> > a) {
    int n = a.size();
    int m = a[0].size();
    vector <vector <int> > result(n, vector <int> (m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = a[m-j-1][i];
        }
    }
    return result;
}

bool check (vector <vector <int> > newlock) {
    
    int lock_length = newlock.size() / 3; 
    
    for (int i = lock_length; i < lock_length*2; i++) {
        for (int j = lock_length; j < lock_length*2; j++)
            if (newlock[i][j] != 1)
                return false;
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    int n = lock.size();
    int m = key.size();
    vector <vector <int> > newlock(n*3, vector <int> (n*3));
    
    //기존 자물쇠보다 가로, 세로가 각각 3배 큰 배열을 만듭니다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            newlock[n+i][n+j] = lock[i][j];
    }
    
    //열쇠의 4개 방향을 모두 확인해 봅니다.
    for (int rotation = 0; rotation < 4; rotation++) {
        
        key = RotateMatrixBy90Degree(key);
        
        for (int i = 0; i < n*2; i++) {
            for (int j = 0; j < n*2; j++) {
                
                //열쇠를 자물쇠에 장착해 봅니다.
                for (int x = 0; x < m; x++) {
                    for (int y = 0; y < m; y++) {
                        newlock[i+x][j+y] += key[x][y];
                    }
                }
                if (check(newlock)) return true;
                //열쇠를 자물쇠에서 뺍니다.
                for (int x = 0; x < m; x++) {
                    for (int y = 0; y < m; y++) {
                        newlock[i+x][j+y] -= key[x][y];
                    }
                }
            }
        }
    }
    return false;
}