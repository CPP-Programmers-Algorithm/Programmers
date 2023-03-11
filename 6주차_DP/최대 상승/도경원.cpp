#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v;

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	int maxv = -1;
	int ans = 0;
	for (int i = v.size()-1; i >= 0; i--) // �� ������ �ι��� max �񱳰� �ִ�
	{
		if (v[i] > maxv) {				  // 1. ù��° �߰��� �� �� �ְ���
			maxv = v[i];
		}
		ans = max(ans, maxv - v[i]);	  // 2. �߰����� �� �Ǹ��� �ְ� ����
	}
	cout << ans;
}

// �ڿ������� max ã�� ���簪 ��
// �� �� �� ū �� ��


// ref : https://dkswnkk.tistory.com/664