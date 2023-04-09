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
#define INF 0x3f3f3f3f/3
#define endl "\n"
using namespace std;

int solution(string s) {
	int answer = s.length();
	for (int i = 1; i <= s.length() / 2; i++) {
		int cnt = 1;
		int totalMinus = 0;
		int countNum = 0;
		string findStr = s.substr(0, i);
		for (int j = i; j < s.length(); j += i) {
			string str2 = s.substr(j, i);
			//���ϴ� ���ڶ� ���� ��� cnt����
			if (findStr == str2)
				cnt++;
			else {
				//������ string ������Ʈ
				findStr = str2;
				//������ ��ǥ�� str �ϳ��� ���� ������ ����
				totalMinus += cnt - 1;
				//�տ� ������ ���� ���� ���� �ϳ� ����
				if (cnt > 1)
					countNum += log10(cnt) + 1;
				//���� �ʱ�ȭ
				cnt = 1;
			}
		}
		if (cnt > 1) {
			//������ ��ǥ�� str �ϳ��� ���� ������ ����
			totalMinus += cnt - 1;
			//�տ� ������ ���� ���� ���� �ϳ� ����
			countNum += log10(cnt) + 1;
		}
		answer = min(answer, (int)s.length() - (totalMinus * i) + countNum);
	}
	return answer;
}