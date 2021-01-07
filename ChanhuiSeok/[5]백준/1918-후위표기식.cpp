#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

stack<char> stk;

// �켱������ top�� ũ�ų� ������ true, top�� ������ false
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
			// '('�� ���� ������ ��� ����
			while (stk.top() != '(') {
				char tmp = stk.top();
				result += tmp;
				stk.pop();
			}
			stk.pop(); // '(' �� ���ֱ�
		}

		// operator
		else {
			// ������ ��� ���� ���
			if (stk.empty()) 
				stk.push(target);
			
			// ������� ���� ���
			else if (!stk.empty()) {
				// topCh�� target�� �켱���� ��
				char topCh = stk.top();
				
				// topCh�� target�� �켱������ ���ų�, topCh�� �� Ŭ ���
				// topCh�� ���ϰ� pop�Ѵ�. �� ������ ��ӵ� ������ �ݺ��Ѵ�.
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

	// stk�� �����ִ� ���ڰ� ������ ���ϱ�
	while (!stk.empty()) {
		char temp = stk.top();
		if(temp != '(')
			result += temp;
		stk.pop();
	}

	cout << result;
	return 0;
}