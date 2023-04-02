#include<iostream>
#include<vector>
using namespace std;

int dp_right[1000001];
int dp_left[1000001];
int solution(vector<int> a) {
	int answer = 0;
	int maxSize = a.size() - 1;
	dp_left[0] = 1000000001;
	dp_right[maxSize] = 1000000001;
	for (int i = 1; i <= maxSize; i++) {
		dp_right[maxSize - i] = min(a[maxSize - i + 1], dp_right[maxSize - i + 1]);
		dp_left[i] = min(a[i - 1], dp_left[i - 1]);
	}

	for (int i = 0; i <= maxSize; i++) {
		if (dp_right[i] < a[i] && dp_left[i] < a[i])
			continue;
		answer++;
	}
	return answer;
}