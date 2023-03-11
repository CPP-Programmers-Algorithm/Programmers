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

	ans += price[0] * road[1]; // 첫번째는 전진
	
	int l_price;				// 낮은 가격 갱신
	l_price = price[0];			// 더 낮은 가격이 나온 경우만 계산할 가격 갱신

	for (int i = 1; i < n; i++)
	{
		if (l_price < price[i]) {
			ans += l_price * road[i + 1];
		}
		else {
			l_price = price[i]; // 낮은 가격이 나왔으니 이제 이걸로 갈꺼야
			ans += l_price * road[i + 1];
		}
	}

	cout << ans;
}