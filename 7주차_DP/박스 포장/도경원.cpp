#include <iostream>
#include <algorithm>

using namespace std;

int n;
int box[5001];
int dp[5001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> box[i];
	}
	for (int i = 0; i < n; i++)

	{
		dp[i] = 1;
		for (int j = 0; j <= i; j++)
		{
			if (box[j] < box[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}

	cout << *max_element(dp, dp + n);
}

