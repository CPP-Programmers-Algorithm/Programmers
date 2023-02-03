#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<deque>
#include<map>
#include<vector>
#include<cmath>
#include<climits>
#include<set>
#include<queue>
#include<list>
#include<stack>
#include<math.h>
#include<memory>
#include<sstream>
using namespace std;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	init();
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		long long bridges[31][31];
		memset(bridges, 0, sizeof(bridges));
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			bridges[1][i] = i;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 2; j <= m; j++) {
				if (i > j)
					continue;

				if (i == j)
					bridges[i][j] += 1;

				bridges[i][j] = bridges[i][j - 1] + bridges[i - 1][j - 1];
			}
		}
		cout << bridges[n][m] << "\n";
	}
}