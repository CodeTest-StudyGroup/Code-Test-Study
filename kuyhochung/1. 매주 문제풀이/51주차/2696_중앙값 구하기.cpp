#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int T;
priority_queue<int, vector<int>, less<int> > min_pq;
priority_queue<int, vector<int>, greater<int> > max_pq;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	//테스트 케이스의 수 T만큼 반복한다.
	cin >> T;
	for (int a = 0; a < T; a++) {
		//이번 케이스에서 수열의 크기 m을 입력받고, 각 원소를 numbers에 담는다.
		int m;
		vector<int> numbers;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int temp;
			cin >> temp;
			numbers.push_back(temp);
		}

		//홀수 숫자를 읽을 때의 결과를 담을 배열
		queue<int> answers;

		//배열을 차례로 읽으며, 홀수번째 원소를 읽을 때마다 중앙값을 answers에 넣음.
		priority_queue<int, vector<int>, greater<int> > min_pq;
		priority_queue<int, vector<int>, less<int> > max_pq;
		for (int i = 0; i < numbers.size(); i++) {
			
			//두 pq가 모두 비었을 경우, max_pq에 값을 넣는다.
			if (min_pq.empty() && max_pq.empty()) {
				max_pq.push(numbers[i]);
			}
			else if (max_pq.size() > min_pq.size()) {
				if (numbers[i] < max_pq.top()) {
					min_pq.push(max_pq.top());
					max_pq.pop();
					max_pq.push(numbers[i]);
				}
				else {
					min_pq.push(numbers[i]);
				}
			}
			else if (min_pq.size() == max_pq.size()) {
				if (numbers[i] > max_pq.top()) {
					min_pq.push(numbers[i]);
					max_pq.push(min_pq.top());
					min_pq.pop();
				}
				else {
					max_pq.push(numbers[i]);
				}
			}

			//홀수번째 값을 읽을 때의 중앙값을 기록함
			if (i % 2 == 0) {
				answers.push(max_pq.top());
			}
		}

		//중앙값을 차례로 공백으로 구분하여 출력
		//한 줄에 최대 10개씩 출력한다.
		cout << answers.size() << endl;
		while (answers.size() > 10) {
			for (int i = 0; i < 10; i++) {
				cout << answers.front() << " ";
				answers.pop();
			}
			cout << endl;
		}
		while (!answers.empty()) {
			cout << answers.front() << " ";
			answers.pop();
		}
	}
	return 0;
}