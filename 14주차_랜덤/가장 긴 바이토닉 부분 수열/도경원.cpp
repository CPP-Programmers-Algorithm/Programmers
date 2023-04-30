#include <iostream>
#define MAX 1001
using namespace std;

int n;
int arr[MAX];
int dp[MAX]; // �տ������� ã�� �������
int r_dp[MAX]; // �ڿ������� ã�� �������

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)// ��������
		cin >> arr[i];
	
	// ���� �������
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
	// arr�� ���� ���ϴ� ������ ���� dp������ �� �� �ִ��� ������ �Ǵ��ϴ� ���̴�
	
	// ���� �������
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

	// ���䵵��
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		if (ans < dp[i] + r_dp[i] - 1) ans = dp[i] + r_dp[i] - 1;
	}
	cout << ans << "\n";
}




//https://yabmoons.tistory.com/143