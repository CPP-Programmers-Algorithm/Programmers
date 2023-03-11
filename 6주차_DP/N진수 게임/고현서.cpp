#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//n진수 변환
string nArithmetic(int num, int n) {
	if (num == 0) return "0";
	string ret = "";
	while (num > 0) {
		if ((num % n) >= 10)
			ret += (char)((num % n) + 55);
		else
			ret += (char)((num % n) + 48);
		num /= n;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
string solution(int n, int t, int m, int p) {
	string answer = "";
	string longGame = "";
	int startIdx = -1;
	int num = 0;
	while (true) {
		longGame += nArithmetic(num++, n);
		for (int i = startIdx + 1; i < longGame.size(); i++) {
			if (answer.size() == t) {
				return answer;
			}
			int cur = (i + 1) % m == 0 ? m : (i + 1) % m;
			if (cur == p)
				answer += longGame[i];

			startIdx = i;
		}
	}
}