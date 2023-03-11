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
using namespace std;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
unordered_map<string, int> string1;
unordered_map<string, int> string2;
unordered_map<string, bool> string1Visited;
int solution(string str1, string str2) {
	for (int i = 0; i < str1.size() - 1; i++) {
		string temp = "";
		if (str1[i] == ' ' || str1[i + 1] == ' ')
			continue;

		if ('A' <= str1[i] && str1[i] <= 'Z') {
			str1[i] += 32;
		}
		else if ('a' <= str1[i] && str1[i] <= 'z') {
		}
		else
			continue;

		if ('A' <= str1[i + 1] && str1[i + 1] <= 'Z') {
			str1[i + 1] += 32;
		}
		else if ('a' <= str1[i + 1] && str1[i + 1] <= 'z') {
		}
		else {
			i++;
			continue;
		}

		temp += str1[i];
		temp += str1[i + 1];
		string1[temp]++;
	}
	for (int i = 0; i < str2.size() - 1; i++) {
		string temp = "";
		if (str2[i] == ' ' || str2[i + 1] == ' ')
			continue;

		if ('A' <= str2[i] && str2[i] <= 'Z') {
			str2[i] += 32;
		}
		else if ('a' <= str2[i] && str2[i] <= 'z') {
		}
		else
			continue;

		if ('A' <= str2[i + 1] && str2[i + 1] <= 'Z') {
			str2[i + 1] += 32;
		}
		else if ('a' <= str2[i + 1] && str2[i + 1] <= 'z') {
		}
		else {
			i++;
			continue;
		}

		temp += str2[i];
		temp += str2[i + 1];
		string2[temp]++;

	}

	double hapCnt = 0;
	double kyoCnt = 0;
	for (auto iter : string2) {
		hapCnt += max(iter.second, string1[iter.first]);
		kyoCnt += min(iter.second, string1[iter.first]);
		string1Visited[iter.first] = true;
	}
	for (auto iter : string1) {
		if (string1Visited[iter.first])
			continue;
		hapCnt += iter.second;
	}

	if (kyoCnt == 0 && hapCnt == 0)
		return 65536;

	return (floor)((kyoCnt / hapCnt) * 65536);
}