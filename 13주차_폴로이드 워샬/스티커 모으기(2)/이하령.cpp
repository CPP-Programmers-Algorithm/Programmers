#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int dp[100000];

int solution(vector<int> sticker)
{
    if (sticker.size() == 1) return sticker[0];
    int answer = 0;
    dp[0] = sticker[0];
    if (sticker.size() > 1) dp[1] = max(sticker[0], sticker[1]);

    for(int i = 2; i < sticker.size() - 1; i++) {
        dp[i] = max(dp[i-2] + sticker[i], dp[i-1]);
    }
    answer = dp[sticker.size() - 2];

    memset(dp, 0, sizeof(dp));
    if (sticker.size() > 1) dp[1] = sticker[1];
    if (sticker.size() > 2) dp[2] = max(sticker[1], sticker[2]);
    for(int i = 3; i < sticker.size(); i++) {
        dp[i] = max(dp[i-2] + sticker[i], dp[i-1]);
    }

    return max(answer, dp[sticker.size()-1]);
}

int main() {
    vector<int> sticker = {1};

    printf("%d", solution(sticker));
}