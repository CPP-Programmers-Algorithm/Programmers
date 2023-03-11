#include <iostream>
#include <algorithm>
using namespace std;

int price[100000] = {0};
int road[100000]  = {0};
int ans = 0;



int main(void) {
	int n; cin >> n;
	for (int i = 1; i < n; i++) { cin >> road[i];  }
	for (int i = 0; i < n; i++) { cin >> price[i]; }

	ans += price[0] * road[1]; // ù��°�� ����
	
	int l_price;				// ���� ���� ����
	l_price = price[0];			// �� ���� ������ ���� ��츸 ����� ���� ����

	for (int i = 1; i < n; i++)
	{
		if (l_price < price[i]) {
			ans += l_price * road[i + 1];
		}
		else {
			l_price = price[i]; // ���� ������ �������� ���� �̰ɷ� ������
			ans += l_price * road[i + 1];
		}
	}

	cout << ans;
}