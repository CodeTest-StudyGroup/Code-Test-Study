
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;
typedef pair<string, string> ps;

string tempStr = "";

ps split(string p) { // 균형잡힌 문자열로 분리하는 함수

	ps partial;
	string tempStr = "";
	int splitIdx = 0;
	stack <char> s;

	for (int i = 0; i < p.length(); i++) {
		if (!s.empty() && s.top() == '(' && p[i] == ')') {
			s.pop();
			tempStr += p[i];
			splitIdx = i;
		}
		else if (!s.empty() && s.top() == ')' && p[i] == '(') {
			s.pop();
			tempStr += p[i];
			splitIdx = i;
		}
		else if (p[i] == '(' || p[i] == ')') {
			s.push(p[i]);
			tempStr += p[i];
		}
		if (s.empty()) break;
	}

	partial.first = tempStr;
	partial.second = p.substr(splitIdx + 1);
	return partial;
}

bool isCorrect(string p) { // 올바른 괄호인지 판단하기

	bool flag = false;
	stack <char> s;

	if (p[0] != '(')
		return false;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(') s.push(p[i]);

		else if (!s.empty() && s.top() == '(' && p[i] == ')')
			s.pop();
	}
	if (s.empty())
		flag = true;
	return flag;
}


string recursion(string p) {

	ps originStr; // u, v가 포함되는 pair

	if (p == "")
		return p;

	originStr = split(p); // 여기에 들어온건 올바른 문자열은 아니란 것, p 문자열 분리

	if (isCorrect(originStr.first)) { // 3. u가 올바른 문자열이라면
		return originStr.first + recursion(originStr.second); // 3-1. v에 대해 다시 수행 후 u에 이어 붙인다.
	}

	else if (!isCorrect(originStr.first)) { // 4. u가 올바른 문자열이 아니라면
		string result = "";
		string temp = "";
		temp += "("; // 4-1. 빈 문자열에 ( 를 붙입니다.
		temp += recursion(originStr.second); // 4-2. v에 대해 다시 수행한 결과 문자열을 이어 붙입니다.
		temp += ")"; // 4-3. )를 다시 붙입니다.

		// u의 첫 번째 문자와 마지막 문자를 제거한 후
		// 남은 문자열의 괄호 방향을 뒤집고, temp 의 뒤에 붙입니다.
		result = originStr.first.substr(1, originStr.first.size() - 2);
		for (int i = 0; i < result.length(); i++) {
			if (result[i] == '(')
				result[i] = ')';
			else if (result[i] == ')')
				result[i] = '(';
		}
		temp += result;

		return temp;
	}

}

string solution(string p) {
	string result;
	bool flag;
	flag = isCorrect(p);

	if (flag) return p;
	result = recursion(p);
	return result;

}