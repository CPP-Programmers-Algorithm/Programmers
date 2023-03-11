#include <iostream>
using namespace std;

int NperTwo(int n) {
	while (n % 2 == 0) {
		n /= 2;
	}
	return n;
}
int solution(int n)
{
	int ans = 0;
	while (n != 0)
	{
		n = NperTwo(n);
		n--; ans++;
	}
	return ans;
}