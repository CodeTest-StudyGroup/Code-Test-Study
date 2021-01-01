#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

stack<char> stk;

// 우선순위가 top이 크거나 같으면 true, top이 작으면 false
bool ranks(char top, char target) {
	if ((top == '+' || top == '-') &&
		(target == '+' || target == '-')) {
		return true;
	}
	if ((top == '*' || top == '/') &&
		(target == '*' || target == '/')) {
		return true;
	}
	if ((top == '*' || top == '/') &&
		(target == '+' || target == '-')) {
		return true;
	}
	if ((top == '+' || top == '-') &&
		(target == '(')) {
		return true;
	}
	return false;
}

int main(){

	string input;
	cin >> input;
	
	string result = "";

	for (int i = 0; i < input.size(); i++) {
		char target = input[i];

		// operand
		if (target >= 'A' && target <= 'Z') 
			result += target;
		
		else if (target == '(')
			stk.push(target);
		
		else if (target == ')') {
			// '('가 나올 때까지 모두 더함
			while (stk.top() != '(') {
				char tmp = stk.top();
				result += tmp;
				stk.pop();
			}
			stk.pop(); // '(' 도 없애기
		}

		// operator
		else {
			// 스택이 비어 있을 경우
			if (stk.empty()) 
				stk.push(target);
			
			// 비어있지 않을 경우
			else if (!stk.empty()) {
				// topCh와 target의 우선순위 비교
				char topCh = stk.top();
				
				// topCh와 target의 우선순위가 같거나, topCh가 더 클 경우
				// topCh를 더하고 pop한다. 이 조건이 계속될 때까지 반복한다.
				while (ranks(topCh, target)) {
					result += topCh;
					stk.pop();

					if (stk.empty()) break;
					topCh = stk.top();
				}
				stk.push(target);
			}
		}
	}

	// stk에 남아있는 문자가 있으면 더하기
	while (!stk.empty()) {
		char temp = stk.top();
		if(temp != '(')
			result += temp;
		stk.pop();
	}

	cout << result;
	return 0;
}