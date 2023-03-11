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
#include<unordered_map>
#define INF 0x3f3f3f3f
#define endl "\n"

#define MOD 1000000007
using namespace std;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
long long tree[(1000001 << 2)];
long long nodes[1000001];

long long initTree(int node, int start, int end) {
	if (start == end) return tree[node] = nodes[start];
	int mid = (start + end) / 2;
	return tree[node] = (initTree(node * 2, start, mid) *
		initTree(node * 2 + 1, mid + 1, end)) % MOD;
}
long long query(int node, int start, int end, int left, int right) {
	if (end < left || start > right) return 1;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return (query(node * 2, start, mid, left, right) *
		query(node * 2 + 1, mid + 1, end, left, right)) % MOD;
}

void Update(int node, int start, int end, long long value, int idx) {
	if (start > idx || end < idx) return;

	if (start == end) {
		tree[node] = value % MOD;
		return;
	}

	int mid = (start + end) / 2;
	Update(node * 2, start, mid, value, idx);
	Update(node * 2 + 1, mid + 1, end, value, idx);
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
}

int main(void) {
	init();
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> nodes[i];
	}
	initTree(1, 0, n - 1);
	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		switch (a)
		{
		case 1:
			Update(1, 0, n - 1, c, b - 1);
			break;
		case 2:
			cout << query(1, 0, n - 1, b - 1, c - 1) << endl;
			break;
		default:
			break;
		}
	}
}