#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


string a, b, ans;
vector<int> va, vb;

string fiboBig(string &a, string &b) {					// ���۷��� Ÿ������ �ҷ��� �����͸� �������� �ʴ´�
	string res = "";

	int diff_len = b.size() - a.size();				    // b�� ���� ������ ������ ũ�� ���̴�  b.s - a.s

	for (int i = 0; i < diff_len; i++)va.push_back(0);  // �ڸ��� ������ش� // ���ڸ����� idx �Ȱ��� ������ ����
	for (auto str : a)va.push_back(str - '0');			// int�� ��ȯ�� �� 0�� ����� 
	for (auto str : b)vb.push_back(str - '0');			// �ƽ�Ű�� �ƴ� ������ ���� ����

	int carry = 0;
	for (int i = vb.size() - 1; i >= 0; i--) {			// �ڿ��� ���� ����
		int temp_sum = va[i] + vb[i];					// ���� 1�ڸ� ���� ������ ��

		if (carry == 1) {								// ���� ��꿡 �ø��� �ִٸ�
			temp_sum++;									// ��� ���ڸ��� ���� ���� ������Ʈ�� ���� �÷���
			carry = 0;									// �ø� �ʱ�ȭ
		}
		if (temp_sum > 9) {								// ���� 9�� ������
			temp_sum %= 10;								// 10���� ���� �������� ���ϰ�
			carry = 1;									// 1�� �ø���
		}												// ���� ���ʿ� �÷���� �ؼ� �� �κ��� �ؿ� ����
		
		res += (temp_sum + '0');						// int�� '0'�� ���ؼ� �ٽ� string���� �ٲ� 
	}
	if (carry == 1) res += '1';							// ��� �ڸ� ���� ���� �ø��� ���Ҵٸ� �����ش�
	
	reverse(res.begin(), res.end());					// ���ڸ����� ����ؼ� ���� �Ųٷ� �Ǿ� ������ �����´�
	va.clear(); vb.clear();								// ����� ���� �ʱ�ȭ

	return res;
}
int main() {
	// n��° �Ǻ���ġ ���ϱ�
	int n; cin >> n;
	a = "0", b = "1";

	if (n == 0 || n == 1) cout << n;
	else {
		for (int i = 2; i <= n; i++) {
			ans = fiboBig(a, b);
			a = b;
			b = ans;									// �� ĭ�� �ڷ� ���� �Ǻ���ġ ���� ����Ѵ�
		}
		cout << b;
	}
	return 0;
}

//-----------------------------------
//         | �޸�    |  �ð�
//-----------------------------------
// python  |  35012   |  60
//-----------------------------------
// cpp     |  2024	  |  116


//ref : https://gdlovehush.tistory.com/504