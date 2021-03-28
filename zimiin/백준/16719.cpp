// 16719¹ø ZOAC

#include <cstdio> 
using namespace std;

char str[101];
bool show[100];

void print() {
	for (int i = 0; str[i]; i++) {
		if (show[i]) printf("%c", str[i]);
	}
	printf("\n");
}

void answer(int s) {
	if (!str[s]) return;
	
	while (!show[s]) {
		
		int min = s;
		
		for (int i = s; !show[i] && str[i]; i++) {
			if (str[min] > str[i]) min = i;
		}
		
		show[min] = true;
		print();
		answer(min + 1);
	}
}

int main() {
	scanf("%s", str);
	answer(0);
	return 0;
}
