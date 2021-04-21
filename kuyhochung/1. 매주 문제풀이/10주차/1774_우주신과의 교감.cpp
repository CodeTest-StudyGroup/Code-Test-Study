#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_N 1001

struct info {                           //시작 노드와 끝 노드의
    int start, end;                     //거리를 담을 struct 정의
    double dist;
};
struct cmp {                            //pq의 우선순위를 할당할 struct 정의
    bool operator() (info &a, info &b) {
        return a.dist > b.dist;
    }
};
double result = 0;
int N, M;
double x[MAX_N], y[MAX_N];              //각 node의 x, y좌표를 담는 배열
int parent[MAX_N];                      //x의 부모를 담는 array

double distance(int p, int q) {         //거리를 반환하는 함수
    double result = sqrt(pow(x[p]-x[q], 2) + pow(y[p]-y[q], 2));
    return result;
}

int find_parent(int x) {                //부모 찾기 - parent[x] = x일 때까지 재귀적 접근
    if (parent[x] == x)
        return x;
    return parent[x] = find_parent(parent[x]);
}

void make_union(int a, int b) {         //두 노드 사이에 엣지를 만드는 경우
    a = find_parent(a);                 //각각의 부모를 찾아서,
    b = find_parent(b);
    if (a > b)                          //더 큰 노드의 부모를 더 작은 부모의 노드로 대체한다.
        parent[a] = b;
    else if (b > a)
        parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    int a, b;
    priority_queue<info, vector<info> , cmp> pq;    //info 형태의 pq
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {      //i의 parent = i로 초기화
        parent[i] = i;
    }
    for (int i = 1; i <= N; i++) {      //node 입력
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < M; i++) {       //이미 건설된 edge 입력
        cin >> a >> b;
        make_union(a, b);
    }
    
    for (int i = 1; i < N; i++) {       //queue에 push해 주는 작업
        for (int j = i + 1; j <= N; j++) { //좌표를 중복해서 넣지 않는다.
            info temp;
            temp.start = i;
            temp.end = j;
            temp.dist = distance(i, j);
            pq.push(temp);
        }
    }
    while (!pq.empty()) {               //kruskal algorithm
        int start = pq.top().start;
        int end = pq.top().end;
        double dist = pq.top().dist;
        pq.pop();
        int parent_start = find_parent(start);
        int parent_end = find_parent(end);
        if (parent_start == parent_end)
            continue;
        make_union(start, end);
        result += dist;
    }
    
    cout << fixed;
    cout.precision(2);
    cout << result;
    return 0;
}
