#include <bits/stdc++.h>
using namespace std;


// 아직 실패



int coms[1000000] = { 0 };

int binarySearch(double target, int len) {
	int st = 0;
	int en = len - 1;
	int sum = 0;
	while (st <= en) {
		sum = 0;
		int mid = (st + en) / 2;

		for (int i = mid; i < len; i++) sum += coms[i];
		sum += mid * coms[mid];

		if (sum < target) { en = mid - 1; } // 범위증가
		else if (sum > target) { st = mid + 1; } // 범위감소
		else if (sum == target) { return mid; }
	}
	if (sum > target) return st;
	else return st - 1;
}

int main(void) {
	int N; cin >> N;
	int cCount = 0;

	for (int i = 0; i < N * N; i++) {
		cin >> coms[i];
		cCount += coms[i];
	}

	sort(coms, coms + N * N, greater<int>());
	if (cCount == 0) { cout << 0; }
	else cout << coms[binarySearch((double)cCount / 2, N * N)];

}