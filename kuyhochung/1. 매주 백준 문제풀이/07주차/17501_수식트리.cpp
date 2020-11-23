#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//sym은 노드의 연산자, left, right는 자식 노드, count는 더하기/빼기 여부를 결정
struct tree_node {
    char sym;
    int left, right, count;
};

int N;                      //정수 N; 노드는 총 2N-1개가 존재한다.
int num[100001];            //숫자 입력이 담길 array
int sub[100001];
tree_node node[200001];     //노드 array
queue<tree_node> q;         //BFS 연산을 위해 사용할 queue
int answer = 0;             //정답값을 누적할 int형 변수

void bfs();                 //bfs함수 프로토타입

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    //입력
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> num[i];
    for (int i = N+1; i < 2*N; i++) {
        char temp;
        int left, right;
        cin >> temp >> left >> right;
        node[i] = {temp, left, right, 0};
    }
    q.push(node[2*N-1]);                        //제일 마지막으로 넣은 node를 enque
    
    bfs();
    int count = 0;                              //연산자 중 -의 수를 센다.
    for (int i = 1; i <= N; i++) {
        if (sub[i] % 2 == 1)
            count++;
    }
    sort(num+1, num+N+1);                       //피연산자를 오름차순으로 정렬.
    
    for (int i = 1; i <= N; i++) {
        if (i <= count)
            answer -= num[i];                   //-를 센 만큼 answer에서 값을 작은 순서대로 빼고,
        else
            answer += num[i];                   //나머지 횟수만큼 answer에 값을 더한다.
    }
    
    cout << answer;
    
    return 0;
}

void bfs() {
    while(!q.empty()) {
        tree_node front = q.front();
        q.pop();
        if (front.left <= N)
            sub[front.left] = front.count;
        else
            q.push({ node[front.left].sym, node[front.left].left, node[front.left].right, node[front.left].count + front.count});
        if (front.right <= N)
            sub[front.right] = front.count + (front.sym=='-');
        else
            q.push({ node[front.right].sym, node[front.right].left, node[front.right].right, node[front.right].count + front.count + (front.sym=='-')});
    }
}
