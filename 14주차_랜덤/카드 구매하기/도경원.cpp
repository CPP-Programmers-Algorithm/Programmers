#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> p(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	vector<int> dp(n + 1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) { // n개의 카드를 구매하는 최대가격
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + p[j]);
		}
	}
	cout << dp[n] << "\n";
	return 0;
}





//https://novlog.tistory.com/entry/BOJ-11052-%EC%B9%B4%EB%93%9C-%EA%B5%AC%EB%A7%A4%ED%95%98%EA%B8%B0-%EB%AC%B8%EC%A0%9C-%ED%92%80%EC%9D%B4-%EC%86%8C%EC%8A%A4-%EC%BD%94%EB%93%9C-with-CC