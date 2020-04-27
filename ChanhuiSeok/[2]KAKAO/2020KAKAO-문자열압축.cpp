#include <string>
#include <vector>

using namespace std;

int solution(string s) {

	vector <string> partial;
	string tempStr;
	string resultStr = "";
	int answer = 0, width = 0, sameCount = 0;
	int startIdx, minLength = 1000001;

	startIdx = 0;
	minLength = s.length();

	for (int width = 1; width < s.length(); width++) {
		// width 별로 분리하기
		while (startIdx + width <= s.length()) {
			tempStr = s.substr(startIdx, width);
			partial.push_back(tempStr);
			startIdx += width;

			if (startIdx + width > s.length()
				&& startIdx < s.length()) {
				tempStr = s.substr(startIdx);
				partial.push_back(tempStr);
			}
		}
		// 여기까지 진행하면 width 만큼씩 문자열 분리되어 벡터에 저장됨

		// 이후, partial 벡터에서 서로 같은 것이 있는지 차례로 비교함
		startIdx = 0;
		while (startIdx < partial.size()) {
			for (int j = startIdx; j < partial.size() - 1; j++) {
				if (partial[startIdx] == partial[j + 1])
					sameCount += 1;
				else
					break;
			}
			if (sameCount != 0) {
				resultStr += to_string(sameCount + 1) + partial[startIdx];
				startIdx = startIdx + sameCount + 1;
				sameCount = 0;
			}
			else {
				resultStr += partial[startIdx];
				startIdx = startIdx + sameCount + 1;
				sameCount = 0;
			}
		}

		if (minLength >= resultStr.length())
			minLength = resultStr.length();

		// 다른 케이스를 위한 초기화
		tempStr = ""; resultStr = "";
		partial.clear(); startIdx = 0;
	}

	return minLength;
}