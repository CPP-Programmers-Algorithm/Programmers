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
		if (t[i] > n - i) ans[i] = ans[i + 1];// ���� ������ �ʿ��� ���� �� ���ٸ� ������ ���� �״�� ������
		else ans[i] = max(p[i] + ans[i + t[i]], ans[i + 1]); // ans[i+1] : ������ ����� max��
															 // ���簡�� + �����ʿ��� �ð� �ڿ� �ִ� ģ���� �ִ밪
	}
	cout << ans[0];
}