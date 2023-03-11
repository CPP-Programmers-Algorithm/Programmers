#include <iostream>
#include <algorithm>
#include<string.h>
#include <queue>
using namespace std;

const int MAX = 114;
int visit[50001];
string List[] = { "h", "li", "na", "k", "rb", "cs", "fr", "be", "mg", "ca", "sr", "ba", "ra", "sc", "y", "ti", "zr", "hf", "rf", "la", "ac",
				  "v", "nb", "ta", "db", "ce", "th", "cr", "mo", "w", "sg", "pr", "pa", "mn", "tc", "re", "bh", "nd", "u", "fe", "ru", "os",
				  "hs", "pm", "np", "co", "rh", "ir", "mt", "sm", "pu", "ni", "pd", "pt", "ds", "eu", "am", "cu", "ag" ,"au", "rg", "gd", "cm",
				  "zn", "cd", "hg", "cn", "tb", "bk", "b", "al", "ga", "in", "tl", "dy", "cf", "c", "si", "ge", "sn", "pb", "fl", "ho", "es",
				  "n", "p", "as", "sb", "bi", "er", "fm", "o", "s", "se", "te", "po", "lv", "tm", "md", "f", "cl", "br", "i", "at", "yb", "no",
				  "he", "ne", "ar", "kr", "xe", "rn","lu", "lr" };


int main() {
	int t; cin >> t;
	while (t--) {
		memset(visit, false, sizeof(visit));

		string s;
		cin >> s;
		bool success = false;
		int end = s.length();

		queue<int> q;
		q.push(0);
		visit[0] = true;


		while (!q.empty()) {
			int pos = q.front();
			q.pop();

			if (pos == end) {
				success = true;
				break;
			}
			for (int i = 0; i < MAX; i++) {
				if (List[i][0] == s[pos] && List[i].size() == 1 && !visit[pos + 1]) {
					visit[pos + 1] = true;
					q.push(pos + 1);
				}
				if (List[i][0] == s[pos] && List[i][1] == s[pos + 1] && List[i].size() == 2 && !visit[pos + 2]) {
					visit[pos + 2] = true;
					q.push(pos + 2);
				}
			}
		}
		// 다 썼는데도 없다면 이어나가지 못했다는 말
		// 방문했다면 그 뒤의 수들도 이미 계산해봤으니 더 계산할 필요가 없는 것
		// 원리 : 모든 경우릐 수를 깊이 없이 직렬로 저장한 다음에 하나씩 꺼내는 계산

		if (success) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}

	}
}