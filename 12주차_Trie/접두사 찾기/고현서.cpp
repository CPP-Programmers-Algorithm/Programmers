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
int toIndex(char ch) { return ch - 'a'; }
struct TrieNode {
	TrieNode* children[26];
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
	int n, m;
	cin >> n >> m;
	TrieNode root;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		root.Insert(str, 0);
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (root.Find_1(str, 0))
			ans++;
	}
	cout << ans;
}