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
#define INF 0x3f3f3f3f/3
#define endl "\n"

using namespace std;

int dpCount[1001][1001];
int main(void)
{
	string str1, str2;
	cin >> str1 >> str2;
	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dpCount[i][j] = dpCount[i - 1][j - 1] + 1;
			}
			else {
				dpCount[i][j] = dpCount[i][j - 1] < dpCount[i - 1][j] ? dpCount[i - 1][j] : dpCount[i][j] = dpCount[i][j - 1];
			}
		}
	}
	cout << dpCount[str1.size()][str2.size()];
	if (dpCount[str1.size()][str2.size()] != 0) {
		cout << endl;
		string ans = "";
		int startX = str2.size();
		int startY = str1.size();
		while (startX >= 1 && startY >= 1) {
			if (str1[startY - 1] == str2[startX - 1]) {
				ans += str1[startY - 1];
				startY--; startX--;
			}
			else {
				dpCount[startY][startX - 1] > dpCount[startY - 1][startX] ? startX-- : startY--;
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans;
	}

}