
#include <cstdio>
#include <vector>
using namespace std;

#define MAX 30001

int n, m, k;
int noCandies[MAX];
vector<int> adj[MAX];
bool visited[MAX];
int noGroups;
pair<int, int> noKidsCandies[MAX];
int knapsack[2][MAX], before, cur;

void input() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &noCandies[i]);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

void dfs(int group, int cur) {
	if (visited[cur]) {
		return;
	}
	
	visited[cur] = true;
	noKidsCandies[group].first++;
	noKidsCandies[group].second += noCandies[cur];
	
	int noAdjNodes = adj[cur].size();
	for (int i = 0; i < noAdjNodes; i++) {
		dfs(group, adj[cur][i]);
	}
}

void countCandiesOfGroup() {
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			noGroups++;
			dfs(noGroups, i);
		}
	}
}

int maxf(int a, int b) { 
	return a > b ? a : b; 
}

void swapf(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void dp() {
	before = 0;
	cur = 1;
	for (int group = 1; group <= noGroups; group++) {
		for (int kid = 1; kid < k; kid++) {
			int kidsInGroup = noKidsCandies[group].first;
			int candiesInGroup = noKidsCandies[group].second;

			int resultExcludingGroup = knapsack[before][kid];
			int resultIncludingGroup = knapsack[before][kid - kidsInGroup] + candiesInGroup;

			if (kidsInGroup > kid) {
				knapsack[cur][kid] = resultExcludingGroup;
			}
			else {
				knapsack[cur][kid] = maxf(resultIncludingGroup, resultExcludingGroup);
			}
		}
		swap(before, cur);
	}
}

int getAnswer() {
	dp();
	int answer = 0;
	for (int i = 1; i < k; i++) {
		answer = maxf(answer, knapsack[before][i]);
	}
	return answer;
}

int main() {
	input();
	countCandiesOfGroup();
	printf("%d", getAnswer());
	return 0;
}