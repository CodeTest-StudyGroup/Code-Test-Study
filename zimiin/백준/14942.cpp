// 14942번 개미

#include <cstdio> 
#include <vector>
#include <queue>
using namespace std;

#define MAX 100000
#define INF 2000000000

struct Info {
	int node;
	int dist;
	
	Info() { }
	
	Info(int node, int dist) {
		this->node = node;
		this->dist = dist;
	}
};

int n, energy[MAX + 1];
vector<Info> tree[MAX + 1];
Info ancestor[MAX + 1][17];
bool visited[MAX + 1];
queue<int> q;

int main() {
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &energy[i]);
	}
	
	for (int i = 1; i < n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		
		tree[a].push_back(Info(b, c));
		tree[b].push_back(Info(a, c));
	}
	
	// initailize
	for (int i = 0; i < 17; i++) {
		ancestor[1][i].node = 1;
		ancestor[1][i].dist = 0;
	}
	
	// get ancestor node and distance to the node
	q.push(1);
	visited[1] = true;
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for (int i = 1; i < 17; i *= 2) {
			Info firstBefore = ancestor[cur][i / 2];
			Info secondBefore = ancestor[firstBefore.node][i / 2];
			
			ancestor[cur][i].node = secondBefore.node;
			ancestor[cur][i].dist = firstBefore.dist + secondBefore.dist;
		}
		
		for (int i = 0; i < tree[cur].size(); i++) {
			int nxt = tree[cur][i].node;
			int dist = tree[cur][i].dist;
			
			if (!visited[nxt]) {
				visited[nxt] = true;
				ancestor[nxt][0].node = cur;
				ancestor[nxt][0].dist = dist;
				q.push(nxt);
			}
		}
	}
	
	// 1번 노드와 가장 가까운 노드 구하기
	for (int i = 1; i <= n; i++) {
		int curEnergy = energy[i];
		int curNode = i;
		
		while (true) {
			bool can_go = false;
			
			for (int i = 16; i > 0; i /= 2) {
				if (ancestor[curNode][i].dist > curEnergy) {
					continue;
				}
				
				can_go = true;
				curEnergy -= ancestor[curNode][i].dist;
				curNode = ancestor[curNode][i].node;
				break;
			}
			
			// parent
			if (!can_go && ancestor[curNode][0].dist <= curEnergy) {
				can_go = true;
				curEnergy -= ancestor[curNode][0].dist;
				curNode = ancestor[curNode][0].node;
			}
			
			if (!can_go || curNode == 1) break;
		}
		
		printf("%d\n", curNode);
	} 
	
	return 0;
}
