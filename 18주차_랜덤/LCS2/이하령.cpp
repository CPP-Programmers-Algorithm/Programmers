#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

string s1, s2;
int dp[1001][1001];
int mx;
string ans = "";

int main() {
    cin >> s1 >> s2;
    int x = 1, y = 1;
    for(int i = 0; i < s1.size(); i++) {
        for(int j = 0; j < s2.size(); j++) {
            if (s1[i] == s2[j]) dp[x][y] = dp[x-1][y-1] + 1;
            else if (s1[i] != s2[j]) dp[x][y] = max(dp[x-1][y], dp[x][y-1]);
            y++;
        }
        x++; y = 1;
    }

    int n = s1.size(), m = s2.size();
    mx = dp[s1.size()][s2.size()];

    if (mx == 0) {
        printf("0");
        return 0;
    }

    while(dp[n][m]) {
        int tmp = dp[n][m];
        if (dp[n-1][m] == tmp) {
            n--;
        } else if (dp[n][m-1] == tmp) {
            m--;
        } else {
            ans.push_back(s2[m-1]);
            n--; m--;
        }
    }

    printf("%d\n", mx);
    reverse(ans.begin(), ans.end());
    cout << ans;
}