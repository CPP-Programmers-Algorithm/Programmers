#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<iostream>

#define pii pair<int,int>
using namespace std;

// value ���� ���ϴ� �Լ�
bool cmp(const pii& a, const pii& b) {
	if (a.second == b.second) return a.first > b.first;		// second�� value
	return a.second > b.second;								// value�� �ٸ��ٸ� �񱳰�� ��ȯ
}


vector <int> solution(string s) {
	vector<int> answer;
	map<int, int> m;									 // key value �� �����

	string tmp;
	for (int i = 1; i < s.length() - 1; i++)
	{
		if (s[i] != '{' && s[i] != '}' && s[i] != ',')	 // ������ ���
		{
			tmp += s[i];
			if (s[i + 1] == ',' || s[i + 1] == '}') {
				m[stoi(tmp)]++;							  // ī���� : �ش� Ű�� value ����
			}
			else continue;								  // ��ȣ�� ������ �ʾҴٸ� tmp�� ��� ����
		}
		tmp = "";
	}

	// ������� �ϸ� 
	// map key   : tuple�� ���
	// map value : ��Ұ� ������ Ƚ��

	// value ��� ����
	vector<pii> vec(m.begin(), m.end());	// map ��� vec ����
	sort(vec.begin(), vec.end(), cmp);		// cmp���� value�񱳸� �־����� vector�� value�������� ���ĵ�

	for (auto num : vec) {
		answer.push_back(num.first);		//emplace_back�� �ᵵ ��;
	}
	
	return answer;
}

int main() {
	string input;
	cin >> input;
	solution(input);
}