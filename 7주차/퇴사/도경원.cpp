#include <iostream>
#include <algorithm>

using namespace std;

int t[15], p[15], ans[15];
int main() {
	int n; cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> t[i] >> p[i];
	}
	
	for (int i = n-1; i >= 0; i--)
	{
		if (t[i] > n - i) ans[i] = ans[i + 1];// 남은 날보다 필요한 날이 더 많다면 못쓰니 값을 그대로 가져옴
		else ans[i] = max(p[i] + ans[i + t[i]], ans[i + 1]); // ans[i+1] : 진전에 계산한 max값
															 // 현재가격 + 현재필요한 시간 뒤에 있는 친구의 최대값
	}
	cout << ans[0];
}