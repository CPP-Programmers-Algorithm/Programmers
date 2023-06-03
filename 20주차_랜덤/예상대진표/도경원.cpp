#include <iostream>
using namespace std;

//예상대진표

void MatchNum(int &num) {
	int matchNum;
	matchNum = num / 2;
	if (num % 2 != 0) matchNum += 1;
	num = matchNum;
}


int solution(int n, int a, int b)
{
	int answer = 0;

	while (a != b) { // a b 가 같아질 때까지 반복 , 레퍼런스로 전달
		MatchNum(a);
		MatchNum(b);
		answer++;
	}
	return answer;
}