#include <iostream>
#include <cstring>
using namespace std;
int dp[100][100], n, m;

int Factorial(int f, int l) {
	if (dp[f][l] != -1)
	{
		return dp[f][l];
	}
	if (l == 0 || f == 0) 
	{
		return 1;
	}
	if (f <= l)
	{
		return 1;
	}

	
		return dp[f][l] = Factorial(f - 1, l - 1) + Factorial(f - 1, l);
	

}

int main() {
	
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	int las = m - n;
	int fir = n + las - 1;
	if (fir == las || fir <= 0 || las <= 0)
	{
		dp[fir][las] = 1;
	}
	Factorial(fir, las);


	cout << dp[fir][las];
	

	return 0;
}
