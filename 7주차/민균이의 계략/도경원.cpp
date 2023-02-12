#include <iostream>
#include <algorithm>

using namespace std;

int n;
int card[1001];
int dp[1001];

int main() { // ¾î·Æ´Ù
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> card[i];
	}
	for (int i = 0; i < n; i++)

	{
		dp[i] = 1;
		for (int j = 0; j <= i; j++)
		{
			if (card[j] < card[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}

	cout << *max_element(dp, dp + n);
}



//https://shoark7.github.io/programming/algorithm/3-LIS-algorithms
//https://jason9319.tistory.com/113