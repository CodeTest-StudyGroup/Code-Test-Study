#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define MAX_N 10
#define MAX_P 20

int n, k;
int a[MAX_N][MAX_N];
vector<vector<int> > will_play;
int kyunghee[MAX_P];
int minho[MAX_P];
bool can_win = false;

void dfs(set<int> played, vector<int> score, int i, int j, vector<int> others) {
    if (can_win) return;
    for (int s = 0; s < score.size(); s++) {
        if (score[s] == k) {
            //지우가 가장 먼저 k점을 달성했다면
            if (s == 0) can_win = true;
            return;
        }
    }
    if (i > j) swap(i, j);
    
    //경희와 민호가 승부하는 경우
    if (i == 1 && j == 2) {
        int kyunghee_play = will_play[1][others[1]], minho_play = will_play[2][others[2]];
        //경희(1)가 이기는 경우
        others[i]++; others[j]++;
        if (a[kyunghee_play][minho_play] == 2) {
            score[i]++;
            dfs(played, score, 0, 1, others);
        }
        //비기거나 민호(2)가 이기는 경우
        else {
            score[j]++;
            dfs(played, score, 0, 2, others);
        }
        return;
    }
    //지우가 승부하는 경우
    else {
        bool not_used_exists = false;
        for (int s = 1; s <= n; s++) {
            //이미 냈던 손동작은 다시 낼 수 없다.
            if (played.find(s) != played.end()) continue;
            //지우가 이기는 경우
            not_used_exists = true;
            if (a[s][will_play[j][others[j]]] == 2) {
                played.insert(s);
                score[0]++;
                others[j]++;
                if (j == 2) {
                    dfs(played, score, 0, 1, others);
                }
                else if (j == 1) {
                    dfs(played, score, 0, 2, others);
                }
                played.erase(s);
                score[0]--;
                others[j]--;
            }
            //지우가 비기거나 지는 경우
            else {
                played.insert(s);
                score[j]++;
                others[j]++;
                dfs(played, score, 1, 2, others);
                played.erase(s);
                score[j]--;
                others[j]--;
            }
        }
        if (!not_used_exists) return;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //손동작의 종류 n, 우승을 위해 필요한 승수 k
    cin >> n >> k;
    //상성; A(i,j)가 2: i번 손동작이 j번 손동작을 이긴다.
    //1: i번 손동작이 j번 손동작과 비긴다.
    //0: i번 손동작이 j번 손동작에게 진다.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    //예외 처리
    if (n < k) {
        cout << 0;
        return 0;
    }
    //경희와 민호가 앞으로 20경기에서 낼 손동작
    vector<int> temp; temp.clear();
    
    will_play.push_back(temp);
    temp.clear();
    for (int i = 0; i < MAX_P; i++) {
        int input; cin >> input; temp.push_back(input);
    }
    will_play.push_back(temp);
    temp.clear();
    for (int i = 0; i < MAX_P; i++) {
        int input; cin >> input; temp.push_back(input);
    }
    will_play.push_back(temp);
    
    set<int> played;
    vector<int> score(3);
    vector<int> played_index(3);
    played_index[1] = 1;
    //지우, 경희, 민호
    for (int i = 1; i <= n; i++) {
        //지우가 이기는 경우
        if (a[i][will_play[1][0]] == 2) {
            played.insert(i);
            score[0]++;
            dfs(played, score, 0, 2, played_index);
            played.erase(i);
            score[0]--;
        }
        //비기는 경우 또는 지는 경우
        else {
            played.insert(i);
            score[1]++;
            dfs(played, score, 1, 2, played_index);
            played.erase(i);
            score[1]--;
        }
    }
    
    if (can_win) cout << 1;
    else cout << 0;
    return 0;
}
