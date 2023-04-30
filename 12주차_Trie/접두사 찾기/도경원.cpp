#include <iostream>
using namespace std;

struct Trie {
	Trie* node[26];

	Trie() {
		for (int i = 0; i < 26; i++) node[i] = NULL;//����ʱ�ȭ
	}

	void insert(string& str, int idx) {
		if (idx == str.size())	// �������� : ������� �������� �׸�
			return;

		if (node[str[idx] - 'a'] == NULL)
			node[str[idx] - 'a'] = new Trie(); //������ ���θ����

		node[str[idx] - 'a']->insert(str, idx + 1);// ��ͷ� ���� �ڽ����� ����
	}

	bool find(string& str, int idx) {
		if (idx == str.size())	//���� �����ߴٸ� ����
			return true;

		if (node[str[idx] - 'a'] == NULL)	// null �� ���´ٸ� false ->���ʿ������� �˻��ϴ� �Ȱ��ƾ� ��
			return false;

		return node[str[idx] - 'a']->find(str, idx + 1);//��͸� ���� ���� ���Ž��
	}

	void clear() {
		for (int i = 0; i < 26; i++){
			if (node[i] != NULL) {
				node[i]->clear(); // ��͸� Ÿ�� ���� ��� �ڽ� ����
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

	for (int i = 0; i < n; i++){// �ֱ�
		string str;
		cin >> str;
		root->insert(str, 0);
	}

	int ans = 0;
	for (int i = 0; i < m; i++){//ã��
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