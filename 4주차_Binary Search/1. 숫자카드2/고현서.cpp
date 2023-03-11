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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
}
int CountArr[20000001];
int main() {
	init();
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		CountArr[s + 10000000]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int s;
		cin >> s;
		cout << CountArr[s + 10000000] << " ";
	}

}