#include <iostream>
using namespace std;

long long fibo[90] = { 0,1 }; // 첫번째 두번째만 초기화가 된다

int main() {
	// n번째 피보나치 구하기
	int n; cin >> n;

	for (int i = 2; i <= n; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	cout << fibo[n];
}