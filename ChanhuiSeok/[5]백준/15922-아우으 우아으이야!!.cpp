#include <iostream>

using namespace std;

int main(){

	int N;
	cin >> N; // N <= 100,000

	int a, b, x, y, sum = 0;

	cin >> x >> y;
	a = x; b = y;

	// �ʱ� ���� ���� : [a, b] (�� ó�� �Է¹��� ����)

	for (int i = 0; i < N-1; i++) {
		cin >> x >> y; // ���� (x, y)
		
		// ���� ���� [a, b] �ȿ� �� ���
		if (x >= a && y <= b) {
			continue;
		}

		// (x,y)�� ������ x�� ���� ���� [a, b]�� �������� ���� y�� �ٱ��� ���
		else if (x >= a && x < b && y > b) {
			// ���� ������ ������ y�� ����
			b = y;
		}

		// (x, y)�� ���� ���� [a, b] �� ������ ���� ���
		else if (x >= b) {
			// ���� ������ sum�� ���ϰ�, ������ [a, b]�� ���� ����
			sum += b - a;
			a = x; b = y;
		}
	}

	// �������� ���� ������ ���� ��(b-a)�� sum�� ���Ѵ�.
	cout << sum + (b - a);
	return 0;
}