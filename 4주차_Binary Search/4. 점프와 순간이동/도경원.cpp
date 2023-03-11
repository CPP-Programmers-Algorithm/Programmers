#include<iostream>
using namespace std;

int solution(int n) {
	int ans = 0;
	while (n > 0) {
		if (n % 2 == 0) n /= 2; // 2로 나눠진다면 2로 나눈다
		else {
			n -= 1; // 2로 나눠지지 않는다면 2로 나눠질 때까지 뺀다 
			ans++;  // 2배수로 움직이는 게 빠르므로 2배수가 될때까지만 건전지를 쓰며 전진하는 것
		}
	}
	return ans;
}