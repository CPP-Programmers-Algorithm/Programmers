#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Trie {
private: 
	bool isEnd = false;
	Trie* child[10];

public:
	//Trie(): child(){}

	void Insert(string phnum) {
		Trie* now = this; // 루트에서 시작
		for (int i = 0; i < phnum.length(); ++i)
		{
			if (now->child[phnum[i] - '0'] == nullptr)
				now->child[phnum[i] - '0'] = new Trie(); // 자식중에 해당요소가 없다면 생성
			now = now->child[phnum[i] - '0']; // 다음글자로 이동
			if (i == phnum.length() - 1) now->isEnd = true; // 문자열끝에 도달하면 true
		}
	}
	bool isTherePrefix(string phnum) {
		Trie* now = this; //루트에서 시작
		for (int i = 0; i < phnum.length(); ++i)
		{
			if (now->child[phnum[i] - '0'] != nullptr) {
				now = now->child[phnum[i] - '0']; // 다음글자로 이동
				if (now->isEnd) //다음글자가 있는 상태인데 end표시가 되어 있다면
					return true;
			}
			else
				return false;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++){
		cin >> n;
		vector<string> phnum_list(n);
		for (int j = 0; j < n; j++){
			cin >> phnum_list[j];
		}
		sort(phnum_list.begin(), phnum_list.end());
		Trie* trie = new Trie();
		bool ok = true;
		for (auto phnum : phnum_list) {
			if (trie->isTherePrefix(phnum)) { // prefix검사
				ok = false;
				break;
			}
			trie->Insert(phnum); // 번호 넣기
		}
		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}

//https://ansohxxn.github.io/boj/5052/