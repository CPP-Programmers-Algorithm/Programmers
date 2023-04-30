#include <iostream>
#define MAX 1001
using namespace std;

int n;
int arr[MAX];
int dp[MAX]; // 앞에서부터 찾는 최장수열
int r_dp[MAX]; // 뒤에서부터 찾는 최장수열

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)// 수열저장
		cin >> arr[i];
	
	// 앞의 최장순열
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	// arr의 값을 비교하는 이유는 이전 dp정보를 쓸 수 있는지 없는지 판단하는 것이다
	
	// 뒤의 최장순열
	for (int i = n; i >= 1; i--)
	{
		r_dp[i] = 1;
		for (int j = n; j >= i; j--)
		{
			if (arr[i] > arr[j] && r_dp[i] < r_dp[j] + 1) {
				r_dp[i] = r_dp[j] + 1;
			}
		}
	}

	// 정답도출
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		if (ans < dp[i] + r_dp[i] - 1) ans = dp[i] + r_dp[i] - 1;
	}
	cout << ans << "\n";
}




//https://yabmoons.tistory.com/143