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
	
	sort(v.begin(), v.end(), greater<int>()); // �������� �� ���� ���ؼ� ������������ ����
	
	for (int i = 0; i < n; i++) {
		while (k - v[i] >= 0) { // �������� �ƴ� ����� ���� 
			ans++;				// ���� 0���� ������ ���̻� ���� �� ���� ������ ���� ���� ���� �Ѿ
			k -= v[i];			
		}
	}
	cout << ans << '\n';
}




// ref : https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=namjs1540&logNo=221578707970