import java.util.*;
class Solution {

	/*
	 * 균형잡힌 괄호: (와 ) 갯수가 같을 때, 올바른 괄호:(와 ) 짝이 맞을 때
	 */

	public String solution(String p) {

		if (p.length() == 0) { // 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
			return p;
		}

		if (isValid(p)) {
			return p;
		}

		int length = p.length();

		String u = "";
		String v = "";

		int sum = 0;

		if (p.charAt(0) == '(') {
			sum += 1;
		} else {
			sum -= 1;
		}

		for (int i = 1; i < length; i++) {
			// 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며,
			// v는 빈 문자열이 될 수 있습니다.
			if (p.charAt(i) == '(') {
				sum += 1;
			} else {
				sum -= 1;
			}

			if (sum == 0) {

				u = p.substring(0, i + 1);
				if (i < length) {
					v = p.substring(i + 1);
				}

				if (!isValid(u)) { // 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
					StringBuffer newString = new StringBuffer("("); // 빈 문자열에 첫 번째 문자로 '('를 붙입니다.

					newString.append(solution(v)); // 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
					newString.append(")"); // ')'를 다시 붙입니다.
					for (int j = 1; j < u.length() - 1; j++) { // u의 첫번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
						if (u.charAt(j) == '(') {
							newString.append(')');
						} else {
							newString.append('(');
						}
					}
					return newString.toString(); // 생성된 문자열을 반환합니다.
				} else { // 문자열 u가 "올바른 괄호 문자열"이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
					StringBuffer newString = new StringBuffer(u);
					newString.append(solution(v)); // 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
					return newString.toString();
				}
			}

		}

		StringBuffer newString = new StringBuffer("("); // 빈 문자열에 첫 번째 문자로 '('를 붙입니다.

		newString.append(solution(v)); // 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
		newString.append(")"); // ')'를 다시 붙입니다.
		for (int j = 1; j < u.length() - 1; j++) { // u의 첫번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
			if (u.charAt(j) == '(') {
				newString.append(')');
			} else {
				newString.append('(');
			}
		}
		return newString.toString(); // 생성된 문자열을 반환합니다.

	}

	public boolean isValid(String str) {

		if (str.length() == 0) {
			return true;
		}

		Stack<Character> stack = new Stack<Character>();

		stack.push(str.charAt(0));

		for (int i = 1; i < str.length(); i++) {
			if (str.charAt(i) == '(') {
				stack.push(str.charAt(i));
			} else {
				if (stack.isEmpty()) {
					return false;
				}

				stack.pop();
			}
		}

		if (!stack.isEmpty()) {
			return false;
		}

		return true;
	}
}
