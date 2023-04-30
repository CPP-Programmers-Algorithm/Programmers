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
		Trie* now = this; // ��Ʈ���� ����
		for (int i = 0; i < phnum.length(); ++i)
		{
			if (now->child[phnum[i] - '0'] == nullptr)
				now->child[phnum[i] - '0'] = new Trie(); // �ڽ��߿� �ش��Ұ� ���ٸ� ����
			now = now->child[phnum[i] - '0']; // �������ڷ� �̵�
			if (i == phnum.length() - 1) now->isEnd = true; // ���ڿ����� �����ϸ� true
		}
	}
	bool isTherePrefix(string phnum) {
		Trie* now = this; //��Ʈ���� ����
		for (int i = 0; i < phnum.length(); ++i)
		{
			if (now->child[phnum[i] - '0'] != nullptr) {
				now = now->child[phnum[i] - '0']; // �������ڷ� �̵�
				if (now->isEnd) //�������ڰ� �ִ� �����ε� endǥ�ð� �Ǿ� �ִٸ�
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
			if (trie->isTherePrefix(phnum)) { // prefix�˻�
				ok = false;
				break;
			}
			trie->Insert(phnum); // ��ȣ �ֱ�
		}
		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}

//https://ansohxxn.github.io/boj/5052/