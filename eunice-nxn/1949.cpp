
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10001

using namespace std;

int town[MAX];
vector<int> map[MAX];
bool visit[MAX];
int N = 0;
int dp[MAX][2];
// dp[i][0] = 우수마을 아닐 때 주민 수
// dp[i][1] = 우수마을일 때 주민 수

void dfs(int now_){

	visit[now_] = true;
	dp[now_][0] = 0;
	dp[now_][1] = town[now_];

	// 인접한 마을 찾기
	for(int i = 0 ; i < map[now_].size(); i++){
		int next = map[now_][i];
		if(!visit[next]){
				dfs(next);
				dp[now_][0] += max(dp[next][0], dp[next][1]); // 우수마을이 아닐 때, 인접 마을은 우수마을이거나 아닐 수 있음
				dp[now_][1] += dp[next][0]; // 우수마을 일 때, 인접 마을은 우수마을이 될 수 없음
		}
	}



}

void draw_map(){

	cin >> N;
	for(int i = 1 ; i <= N ; i++){
		cin >> town[i] ;
		visit[i] = false;
	}

	for(int i = 1 ; i < N ; i++){
		int u = 0, v = 0;
		cin >> u >> v ;
		map[u].push_back(v);
		map[v].push_back(u);
	}


}
int main(){
	draw_map();
	dfs(1);
	cout << max(dp[1][0], dp[1][1]) << endl;
}
