#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	int meNum;
	int answer = 0;
	vector<int> otherNums;

	cin >> n;
	cin >> meNum;
	otherNums.resize(n);
	for (size_t i = 0; i < n - 1; i++)
	{
		int temp;
		cin >> temp;
		otherNums[i] = temp;								// �ٸ� ��ǥ�ڵ� ���� ����
	}
	sort(otherNums.begin(), otherNums.end(), greater<int>()); // ������������


	while (meNum <= otherNums[0]) {							// ���� ū ���� �� �տ� ���� ����
		otherNums[0]--;										// �Ǿ��� �� �ϳ� ��

		meNum++;											// ���� ���ؾ���
		answer++;											// ����Ƚ������
		if (otherNums[0] < otherNums[1]) {					// �ٸ� ��ǥ�ڵ� ǥ �� �� �� �ٽ� ������������
			sort(otherNums.begin(), otherNums.end(), greater<int>());
		}
	}

	cout << answer;

	return 0;
}


//#include <bits/stdc++.h>
//https://www.geeksforgeeks.org/c-sharp-data-types/