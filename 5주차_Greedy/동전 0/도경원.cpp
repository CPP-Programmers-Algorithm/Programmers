#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k, ans = 0;
	cin >> n >> k;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	sort(v.begin(), v.end(), greater<int>()); // 역순으로 안 돌기 위해서 내림차순으로 정리
	
	for (int i = 0; i < n; i++) {
		while (k - v[i] >= 0) { // 나눗셈이 아닌 빼기로 구현 
			ans++;				// 빼서 0보다 작으면 더이상 나눌 수 없기 때문에 다음 작은 수로 넘어감
			k -= v[i];			
		}
	}
	cout << ans << '\n';
}




// ref : https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=namjs1540&logNo=221578707970