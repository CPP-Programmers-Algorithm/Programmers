#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
string dp[10001] = {"0", "1"};

string bigSum(string a, string b) { // a > b
    string ret = "";
    int next = 0;

    for(int i = 0; i < b.size(); i++) {
        ret += (a[i] - '0' + b[i] - '0' + next) % 10 + '0';
        next = (a[i] - '0' + b[i] - '0' + next) / 10;
    }
    for(int i = b.size(); i < a.size(); i++) {
        ret += (a[i] - '0' + next) % 10 + '0';
        next = (a[i] - '0' + next) / 10;
    }

    if (next) ret += next + '0';
    return ret;
}

int main() {
    scanf("%d", &n);

    for(int i = 2; i <= n; i++) {
        dp[i] = bigSum(dp[i - 1], dp[i - 2]);
    }
    for(int i = dp[n].size() - 1; i >= 0; i--) printf("%c", dp[n][i]);
}