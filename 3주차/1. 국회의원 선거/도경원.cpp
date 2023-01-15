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
		otherNums[i] = temp;								// 다른 투표자들 정보 넣음
	}
	sort(otherNums.begin(), otherNums.end(), greater<int>()); // 내림차순정리


	while (meNum <= otherNums[0]) {							// 가장 큰 수가 맨 앞에 오게 설정
		otherNums[0]--;										// 맨앞의 수 하나 뺌

		meNum++;											// 내껀 더해야지
		answer++;											// 조작횟수증가
		if (otherNums[0] < otherNums[1]) {					// 다른 투표자들 표 수 비교 후 다시 오름차순정리
			sort(otherNums.begin(), otherNums.end(), greater<int>());
		}
	}

	cout << answer;

	return 0;
}


//#include <bits/stdc++.h>
//https://www.geeksforgeeks.org/c-sharp-data-types/