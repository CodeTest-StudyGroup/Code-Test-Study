#define pb push_back

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 0;
	int min_answer = 999999999;

	vector<int> li_origin; // 원형의 취약 지점들을 하나씩 펼치는 벡터
	vector<int> li_reverse; // 원형의 취약 지점들을 하나씩 펼치는 벡터
	vector<int> ind; // permutation 사용 위한 벡터
	set<int> visit;

	sort(dist.begin(), dist.end());

	for (int i = 0; i < weak.size(); i++) {

		for (int p = i; p < weak.size(); p++) {
			li_origin.pb(weak[p]);
		}
		for (int p = 0; p < i; p++) {
			li_reverse.pb(weak[p] + n);
		}
		li_origin.insert(li_origin.end(), li_reverse.begin(), li_reverse.end());
		// {1,5,6,10} -> {5,6,10,13} -> ...

		for (int j = 1; j <= dist.size(); j++) {

			// 조합이 아니라 순열을 사용하자.
			// dist 배열의 permutation을 위함
			// 먼저 사용할 친구들을 뽑아내기 위한 1, 0 ind 벡터를 만든다.
			for (int k = 0; k < j; k++)  // j 만큼만 선택
				ind.pb(1);
			for (int m = 0; m < dist.size() - j; m++)
				ind.pb(0);
			sort(ind.begin(), ind.end());

			do {
				vector<int> vec;
				for (int i = 0; i < ind.size(); i++) {
					if (ind[i] == 1) {
						vec.push_back(dist[i]);
					}
				}
				sort(vec.begin(), vec.end());
				// vec에는 예를 들면 dist{3,5,7} 이면 {3, 5} 가 들어가 있다.
				// 이제 이 vec를 가지고 다시 순열을 만든다.
				do {

					int endIdx = 0;
					bool iterFlag = false;
					bool possibleFlag = false; // 점검 완료할 경우

					for (int i = 0; i < vec.size(); i++) {
						// 점검하기
						for (int j = endIdx; j < weak.size(); j++) {
							for (int k = j; k < weak.size(); k++) {

								if (k == j && li_origin[k] <= vec[i]) {
									visit.insert(li_origin[k]);
									possibleFlag = true;
								}

								else if (li_origin[k] - li_origin[j] <= vec[i]) {
									// 점검 가능
									if (k + 1 <= weak.size() - 1) {
										visit.insert(li_origin[k]);
										visit.insert(li_origin[j]);
										endIdx = k + 1;
									}
									else {
										visit.insert(li_origin[k]);
										visit.insert(li_origin[j]);
										endIdx = weak.size();
									}
									possibleFlag = true;
								}
								else {
									// 점검 불가 시 더 살펴볼 필요가 없음
									iterFlag = true;
									break;
								}
							}
							if (iterFlag)
								break;
						}

						if (possibleFlag)
							answer += 1;
					}

					if (visit.size() == weak.size()) {
						min_answer = min(min_answer, answer);
					}

					visit.clear();
					answer = 0;

				} while (next_permutation(vec.begin(), vec.end()));
				vec.clear();
			} while (next_permutation(ind.begin(), ind.end()));
			ind.clear();
		}

		li_origin.clear();
		li_reverse.clear();
	}

	if (min_answer != 999999999)
		return min_answer;
	else
		return -1;
}