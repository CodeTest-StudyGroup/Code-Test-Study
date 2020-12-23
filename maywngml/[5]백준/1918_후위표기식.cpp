#include <algorithm>
#include <string>
#include <stack>
#include <map>
#include <iostream>
using namespace std;
// 연산자별 우선순위 정보를 담을 맵
map<char, int> priority;
// 연산자를 임시로 저장할 스택
stack<char> sign;
// 연산자별 우선순위 저장 (숫자가 낮을수록 우선순위가 높은 것)
// 스택에는 우선순위가 낮은 연산자가 먼저 쌓여야 한다.
void init() {
	priority['('] = 1;
	priority[')'] = 1;
	priority['*'] = 2;
	priority['/'] = 2;
	priority['+'] = 3;
	priority['-'] = 3;
}
// flag가 true이면 current가 ')', false는 다른 연산자일 경우
void process(char current, bool flag) {
	while (!sign.empty()) {
        // 스택의 맨 위 원소를 변수에 저장
		char signTop = sign.top();
        // signTop가 '('가 아닐 경우
		if (signTop != '(') {
            // 1. current가 ')'라면 signTop이 ')'일때까지 스택 내 원소들 출력
            // 2. current가 ')'가 아니면 signTop이 현재 연산자보다 우선순위가 높을 경우에만 스택 내 원소들 출력
			if (flag || (!flag && priority[signTop] <= priority[current])) {
				cout << signTop;
				sign.pop();
			}
            // 위 조건에 어긋날 시 반복문 종료
			else {
				break;
			}
		}
        // signTop가 '('일 경우 반복문 종료
		else {
			break;
		}
	}
}

int main() {
	string input;

	init();
	cin >> input;

	for (auto elem : input) {
		bool check = isalpha(elem);
        // 현재 원소가 문자이면 무조건 출력
		if (check) {
			cout << elem;
		}
		else {
			switch (elem) {
                // 현재 원소가 '('이면 무조건 스택에 저장
				case '(':
					sign.push(elem);
					break;
                // 현재 원소가 ')'이면 process함수 호출
				case ')':
					process(elem, true);
                    // 스택의 맨 위 원소 제거(맨 위 원소는 '('이다)
					sign.pop();
					break;
                // 현재 원소가 다른 연산자일 경우
				default:
                    // 스택이 비어있지 않고 현재 원소의 우선순위가 맨 위 원소보다 낮다면 process 함수 호출
					if (!sign.empty() && priority[sign.top()] <= priority[elem]) {
						process(elem, false);
					}
                    // 스택에 현재원소 push
					sign.push(elem);
			}
		}
	}
    // 남아있는 연산자들 출력
	while (!sign.empty()) {
		cout << sign.top();
		sign.pop();
	}
}