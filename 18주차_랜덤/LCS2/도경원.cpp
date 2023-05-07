#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

//선언
void init();
pair<int,string> LCS(string& shortWord, string& longWord);
//메인
int main() {
	init();
	
	string a,b;
	pair<int, string> ans;
	cin >> a >> b;
	ans = LCS(a, b);
	
	cout << ans.first << '\n' << ans.second;

}

//구현부
void init() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
}

pair<int, string> LCS(string& a, string& b) {
	string shortWord;
	string longWord;

	pair<int, string> lcs;

	if (a.length() < b.length()) { shortWord = a; longWord = b; }
	else { shortWord = b; longWord = a; }

	int wordGap = longWord.length() - shortWord.length();
	int sliding = wordGap;
	int maxCnt = 0;
	int lcsIdx = 0;
	do {
		int cnt = 0;
		if (shortWord[0] == longWord[sliding]) cnt++;
		for (int i = 1; i < shortWord.length(); i++){
			bool pre = shortWord[i - 1] == longWord[i - 1 + sliding];
			bool cur = shortWord[i] == longWord[i + sliding-1];
			if (pre && cur) cnt++;
		}
		if (cnt > maxCnt) {
			lcs.first = cnt;
			lcsIdx = wordGap - sliding;
		}
	} while (sliding--);
	lcs.second = shortWord.substr(lcsIdx, maxCnt);
	return lcs;
}