#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

int main() {

	int brown;
	int red;
	int square, sero;
	int i = 0, j = 1;

	vector<int> answer;

	scanf("%d %d", &brown, &red);

	square = brown + red; // 48
	sero = 1;

	i = square;
	j = 1;

	while (i >= 1) {

		if ((i - 2) * (j - 2) == red)
		{
			answer.push_back(i);
			answer.push_back(j);

			return 0;
		}

		j = j + 1;
		i = square / j;
	}


	printf("dd");

}