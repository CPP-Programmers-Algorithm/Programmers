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
int toIndex(char ch) { return ch - '0'; }
struct TrieNode {
	TrieNode* children[11];
	bool isEnd;

	TrieNode() :children(), isEnd(false) {}

	void Insert(string& key, int index) {
		if (index == key.length())
			isEnd = true;
		else {
			int childIndex = toIndex(key[index]);
			if (children[childIndex] == nullptr)
				children[childIndex] = new TrieNode;
			children[childIndex]->Insert(key, index + 1);
		}
	}
	//접두사로서 검색 되더라도 true를 리턴하게끔 한 함수
	bool Find_1(string& key, int depth) {
		if (depth == key.length())
			return true;
		int childIndex = toIndex(key[depth]);
		if (children[childIndex] == nullptr)
			return false;
		return children[childIndex]->Find_1(key, depth + 1);
	}
	//완전히 일치하는 단어 단위로만 찾고 true를 리턴하게끔 한 함수
	bool Find_2(string& key, int depth) {
		if (depth == key.length() && isEnd)
			return true;
		if (depth == key.length() && !isEnd)
			return false;
		int childIndex = toIndex(key[depth]);
		if (children[childIndex] == nullptr)
			return false;
		return children[childIndex]->Find_2(key, depth + 1);

	}
};
bool cmp(string& str1, string& str2) {
	return str1.length() > str2.length();
}
int main(void) {
	init();
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int n;
		cin >> n;
		TrieNode root;
		bool isYES = true;
		vector<string> strVec;
		for (int i = 0; i < n; i++) {
			string phone;
			cin >> phone;
			strVec.push_back(phone);
		}
		sort(strVec.begin(), strVec.end(), cmp);
		root.Insert(strVec[0], 0);
		for (int i = 1; i < strVec.size(); i++) {
			if (root.Find_1(strVec[i], 0)) {
				isYES = false;
				break;
			}
			root.Insert(strVec[i], 0);
		}
		if (isYES)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}