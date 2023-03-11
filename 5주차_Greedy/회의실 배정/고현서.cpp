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
class Meeting {
public:
	int start;
	int end;
	Meeting(int s, int e) {
		this->start = s;
		this->end = e;
	}
	bool operator<(Meeting& m) {
		if (this->end == m.end) {
			return this->start < m.start;
		}
		return this->end < m.end;
	}
};
int main() {
	init();
	int n;
	cin >> n;
	vector<Meeting> meets;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		meets.push_back({ a, b });
	}
	sort(meets.begin(), meets.end());
	int cnt = 0;
	int endingTime = 0;
	for (int i = 0; i < n; i++) {
		if (meets[i].start >= endingTime) {
			endingTime = meets[i].end;
			cnt++;
		}
	}
	cout << cnt;
}