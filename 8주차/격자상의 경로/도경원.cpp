#include <iostream>
using namespace std;

int dp(int n, int m) {
	if (n == 1 || m == 1) {
		return 1;
	}

	return dp(n - 1, m) + dp(n, m - 1);
}


int main() {
	int n, m, k;
	cin >> n >> m >> k;
	if (k == 0) {
		cout<< dp(n, m);
	}
	else {
		int nn, mm;
		nn = k / m; // 6
		mm = k % m; // 11
		if (mm == 0) {
			mm = m;
		}
		else {
			nn++;
		}
		cout << dp(nn, mm) * dp(n - nn + 1, m - mm + 1);
	}
	

}