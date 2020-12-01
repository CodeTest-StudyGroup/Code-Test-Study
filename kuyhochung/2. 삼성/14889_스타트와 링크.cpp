#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_N 21

int N;
bool is_used[MAX_N];
int players[MAX_N][MAX_N];
int answer = 1e10;

void dfs(int curr_player, int cnt) {
    
    if (cnt == N / 2) {
        vector<int> start;
        vector<int> link;

        for (int i = 0; i < N; i++) {
            if (is_used[i])
                start.push_back(i);
            else
                link.push_back(i);
        }

        int stat_start = 0, stat_link = 0;
        for (int i = 0; i < start.size(); i++) {
            for (int j = i+1; j < start.size(); j++) {
                int start_x = start[i], start_y = start[j];
                int link_x = link[i], link_y = link[j];
                stat_start += players[start_x][start_y] + players[start_y][start_x];
                stat_link += players[link_x][link_y] + players[link_y][link_x];
            }
        }

        answer = min(answer, abs(stat_start - stat_link));
        return;
    }

    for (int i = curr_player+1; i < N; i++) {
        if (is_used[i] == false) {
            is_used[i] = true;
            dfs(i, cnt + 1);
            is_used[i] = false;
        }
    }

}


int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> players[i][j];
        }
    }

    dfs(0,0);
    cout << answer << "\n";

    return 0;
}
