#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N;
// 전위순회, 중위순회 결과를 저장할 벡터
vector<int> preorder, inorder;
// 후위순회를 진행하는 함수
void postorder(int start, int end, int parent) {
	for (int index = start; index <= end; index++) {
        // 중위순회 벡터에서 전위순회의 부모 노드의 위치를 찾음
		if (inorder[index] == preorder[parent]) {
            // 왼쪽 서브트리 탐색
			postorder(start, index - 1, parent + 1);
            // 오른쪽 서브트리 탐색
			postorder(index + 1, end, parent + index - start + 1);
            // 중위순회 결과 출력
			cout << preorder[parent] << " ";
		}
	}
}

int main() {
	int T, preNum, inNum, answerRow;
	vector<vector<int>> answer;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> preNum;
			preorder.push_back(preNum);
		}
		for (int i = 0; i < N; i++) {
			cin >> inNum;
			inorder.push_back(inNum);
		}
		postorder(0, N - 1, 0);
        // 벡터 초기화
		preorder.clear();
		inorder.clear();
		cout << '\n';
	}
}