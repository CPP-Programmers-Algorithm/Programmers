#include<iostream>
using namespace std;

int solution(int n) {
	int ans = 0;
	while (n > 0) {
		if (n % 2 == 0) n /= 2; // 2�� �������ٸ� 2�� ������
		else {
			n -= 1; // 2�� �������� �ʴ´ٸ� 2�� ������ ������ ���� 
			ans++;  // 2����� �����̴� �� �����Ƿ� 2����� �ɶ������� �������� ���� �����ϴ� ��
		}
	}
	return ans;
}