#include <string>
#include <vector>

using namespace std;

int numIdx[500501];
int endNum;
// _ <- 이 모양
int Calc_1(vector<int>& ans, int startNum, int cnt) {
	for (int i = 1; i < cnt; i++) {
		ans[numIdx[startNum] + i] = startNum + i;
		numIdx[startNum + i] = numIdx[startNum] + i;
	}
	return startNum + cnt - 1;
}
int startDec;
// \ <- 이 모양
int Calc_2(vector<int>& ans, int startNum, int cnt) {
	int dec = startDec;
	int num = startNum;
	for (int i = numIdx[startNum]; i >= 0; i--) {
		ans[i] = num;
		numIdx[num] = i;

		i -= (dec--);
		num++;

		if (num >= startNum + cnt)
			break;
	}
	startDec--;
	return num - 1;
}
int startInc = 0;
int incRate = 0;
// / <- 이 모양
int Calc_3(vector<int>& ans, int startNum, int cnt) {
	int inc = startInc;
	int num = startNum;
	for (int i = numIdx[startNum]; i < endNum; i++) {
		ans[i] = num;
		numIdx[num] = i;

		i += (inc++);
		num++;

		if (num >= startNum + cnt)
			break;
	}
	incRate++;
	startInc = 2 * incRate - 1;
	return num - 1;
}
vector<int> solution(int n) {
	startDec = n - 1;
	endNum = (n / (double)2) * (1 + n);
	vector<int> answer(endNum, 0);
	numIdx[1] = 0;

	int startNum = Calc_3(answer, 1, n);

	int calcSwitch = 0;
	for (int i = n; i >= 2; i--) {
		switch (calcSwitch % 3)
		{
		case 0:
			startNum = Calc_1(answer, startNum, i);
			break;
		case 1:
			startNum = Calc_2(answer, startNum, i);
			break;
		case 2:
			startNum = Calc_3(answer, startNum, i);
			break;
		default:
			break;
		}
		calcSwitch++;
	}
	return answer;
}