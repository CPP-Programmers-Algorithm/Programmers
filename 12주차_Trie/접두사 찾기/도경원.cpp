#include <iostream>
using namespace std;

struct Trie {
	Trie* node[26];

	Trie() {
		for (int i = 0; i < 26; i++) node[i] = NULL;//노드초기화
	}

	void insert(string& str, int idx) {
		if (idx == str.size())	// 종료조건 : 사이즈와 같아지면 그만
			return;

		if (node[str[idx] - 'a'] == NULL)
			node[str[idx] - 'a'] = new Trie(); //없으면 새로만든다

		node[str[idx] - 'a']->insert(str, idx + 1);// 재귀로 다음 자식으로 가기
	}

	bool find(string& str, int idx) {
		if (idx == str.size())	//끝에 도달했다면 성공
			return true;

		if (node[str[idx] - 'a'] == NULL)	// null 이 나온다면 false ->앞쪽에서부터 검색하니 똑같아야 함
			return false;

		return node[str[idx] - 'a']->find(str, idx + 1);//재귀를 통해 다음 노드탐색
	}

	void clear() {
		for (int i = 0; i < 26; i++){
			if (node[i] != NULL) {
				node[i]->clear(); // 재귀를 타고 가며 모든 자식 삭제
				delete node[i];
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	Trie* root = new Trie();

	for (int i = 0; i < n; i++){// 넣기
		string str;
		cin >> str;
		root->insert(str, 0);
	}

	int ans = 0;
	for (int i = 0; i < m; i++){//찾기
		string str;
		cin >> str;
		if (root->find(str, 0))
			ans++;
	}

	cout << ans << '\n';
	root->clear();
	delete root;
	return 0;
}



//https://intrepidgeeks.com/tutorial/c-baekjun-14426-find-prefix