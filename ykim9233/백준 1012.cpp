//백준  1012 유기농배추

 
#include<bits/stdc++.h>

using namespace std;

int m, n,p;

int nx[4] = { 1,-1,0,0 };
int ny[4] = { 0,0,1,-1 };

int arr[101][101];
int visited[101][101];

void dfs(int x, int y) {
	int nxtx, nxty;
	for (int i = 0; i < 4; i++) {
		nxtx = x + nx[i];
		nxty = y + ny[i];

		if (nxtx < 0 || nxty < 0 || nxtx >= n || nxty >= m) continue;

		if (arr[nxtx][nxty] == 1 && visited[nxtx][nxty] != 1){
			visited[nxtx][nxty] = 1;
			dfs(nxtx, nxty);
		}
	}



}

int main() {
	cin >> m >> n>> p;
	int cnt = 0;



	for (int i = 0; i < p; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b]=1; 
	}


	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (arr[i][j] == 1 && visited[i][j]!=1) {
				cnt++;
				visited[i][j] = 1;
				dfs(i, j);
			}
		
		}
	}

	cout << cnt;

	return 0;
}






