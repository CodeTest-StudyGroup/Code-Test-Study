#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int N, int number) {
	int answer = 0;
	int powN = 0;
	string cont_n = "";
	vector<vector<int>> NVector;
	NVector.resize(9);

	// 첫번째 열에는 N, NN, NNN, NNNN 과 같은 숫자가 들어간다.
	/*
	for (int i = 0; i < 8; i++) {
		powN = powN + (pow(10, i) * N);
		NVector[i+1].push_back(powN);
	}*/
	for (int i = 1; i <= 8; i++) {
		cont_n += to_string(N);
		NVector[i].push_back(stoi(cont_n));
	}


	// 2열부터는, 즉 2행 55의 2열부터는 5+5, 5*5, 5-5, 5/5가 들어가야 한다.
	// 이 말은, 2행은 1행의 모든 숫자와 1행의 모든 숫자들의 사칙연산 값이 들어간다.
	// 3행은, 1행의 모든 숫자와 2행의 모든 숫자들의 사칙연산의 값과,
	// 2행의 모든 숫자와 1행의 모든 숫자들의 사칙연산 값이 들어간다.
	// 이렇게 값을 채워나간다..

	// 전체 8개의 행에 대하여 진행
	for (int i = 2; i <= 8; i++) {
		// j+k 의 합이 i와 같을 때, 모든 사칙연산을 진행한다.
		// 즉, 5행은 1+4, 2+3, 3+2, 4+1 행에 대한 사칙연산을 진행한다.
		for (int j = 1; j <= 8; j++) {
			for (int k = 1; k <= 8; k++) {
				if (j + k == i) {

					for (int m = 0; m < NVector[j].size(); m++) {
						for (int p = 0; p < NVector[k].size(); p++) {
							NVector[i].push_back(NVector[j][m] + NVector[k][p]);
							NVector[i].push_back(NVector[j][m] * NVector[k][p]);
							NVector[i].push_back(NVector[j][m] - NVector[k][p]);
							if (NVector[k][p] != 0)
								NVector[i].push_back(NVector[j][m] / NVector[k][p]);
						}
					}

				}
			}
		}

		for (int q = 0; q < NVector[i].size(); q++) {
			if (NVector[i][q] == number)
			{
				int answer = i;
				return answer;
			}
		}
	}

	answer = -1;
	return answer;
}