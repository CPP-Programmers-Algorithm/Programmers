#include <iostream>
using namespace std;

long long fibo[90] = { 0,1 }; // ù��° �ι�°�� �ʱ�ȭ�� �ȴ�

int main() {
	// n��° �Ǻ���ġ ���ϱ�
	int n; cin >> n;

	for (int i = 2; i <= n; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	cout << fibo[n];
}