#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

// sol 1) O(2^n)

int solution1(vector<int> numbers, int target) {
    int answer = 0;
    int idx = 0;

    queue<int> q;
    q.push(0);

    for(int i = 0; i < numbers.size(); i++) {
        int qs = q.size();
        for(int j = 0; j < qs; j++) {
            int t = q.front(); q.pop();
            q.push(t + numbers[i]);
            q.push(t - numbers[i]);
        }
    }
    while(!q.empty()) {
        if (q.front() == target) answer++;
        q.pop();
    }
    return answer;
}

// sol 2) O(n*2000)

int dp[20][2001];

int DP(vector<int> numbers, int idx, int sum, int target) {
    if (idx == -1) {
        if (sum == 0) return 1;
        return 0;
    }
    if (dp[idx][sum + 1000] != -1) return dp[idx][sum + 1000];
    int ret = DP(numbers, idx - 1, sum - numbers[idx], target) + DP(numbers, idx - 1, sum + numbers[idx], target);
    return dp[idx][sum + 1000] = ret;
}

int solution2(vector<int> numbers, int target) {
    memset(dp, -1, sizeof(dp));
    return DP(numbers, numbers.size() - 1, target, target);
}