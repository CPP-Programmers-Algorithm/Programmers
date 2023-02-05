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
	for (int i = v.size()-1; i >= 0; i--) // 이 문제는 두번의 max 비교가 있다
	{
		if (v[i] > maxv) {				  // 1. 첫번째 발견한 것 중 최고가격
			maxv = v[i];
		}
		ans = max(ans, maxv - v[i]);	  // 2. 발견했을 때 판매한 최고 가격
	}
	cout << ans;
}

// 뒤에서부터 max 찾고 현재값 뺌
// 그 중 젤 큰 게 답


// ref : https://dkswnkk.tistory.com/664