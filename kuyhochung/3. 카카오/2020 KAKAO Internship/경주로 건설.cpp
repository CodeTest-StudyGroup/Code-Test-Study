#include <string>
#include <vector>
#include <queue>

using namespace std;
#define MAX_N 26
#define INF 1e9

int cost[MAX_N][MAX_N];
int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, -1, 0, 1};

int solution(vector<vector<int>> board) {
    int n = (int)board.size() - 1;
    
    queue <pair < pair <int, int>, pair <int, bool> > > q;
    //x, y, cost, updown
    
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            cost[i][j] = INF;
        }
    }
    
    cost[0][0] = 0;
    if (board[0][1] != 1){
        q.push({{0, 1}, {100, false}});
        cost[0][1] = 100;
    }
    if (board[1][0] != 1){
        q.push({{1, 0}, {100, true}});
        cost[1][0] = 100;
    }
    
    while(!q.empty()){
        int ox = q.front().first.first;
        int oy = q.front().first.second;
        int nowCost = q.front().second.first;
        bool facing = q.front().second.second;
        q.pop();

        if(cost[ox][oy] != nowCost)
            continue;
        
        for (int i = 0; i < 4; i++){
            int x = ox + dx[i]; int y = oy + dy[i];
            if (x >= 0 && x < n+1 && y >= 0 && y < n+1 && board[x][y] != 1){
                if (facing){
                    if (ox == x) {
                        q.push({{x, y}, {nowCost + 600, false}});
                        if (cost[x][y] > nowCost + 600)
                            cost[x][y] = nowCost + 600;
                    }
                    else {
                        q.push({{x, y}, {nowCost + 100, true}});
                        if (cost[x][y] > nowCost + 100)
                            cost[x][y] = nowCost + 100;
                    }
                }
                else {
                    if (oy == y){
                        q.push({{x, y}, {nowCost + 600, true}});
                        if(cost[x][y] > nowCost + 600)
                            cost[x][y] = nowCost + 600;
                    }
                    else {
                        q.push({{x, y}, {nowCost + 100, false}});
                        if (cost[x][y] > nowCost + 100)
                            cost[x][y] = nowCost + 100;
                    }
                }
            }
        }
    }
    return cost[n][n];
}