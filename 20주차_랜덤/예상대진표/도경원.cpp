#include <iostream>
using namespace std;

void MatchNum(int &num) {
	int matchNum;
	matchNum = num / 2;
	if (num % 2 != 0)matchNum += 1;
	num = matchNum;
}


int solution(int n, int a, int b)
{
	int answer = 0;

	while (a != b) {
		MatchNum(a);
		MatchNum(b);
		answer++;
	}
	return answer;
}