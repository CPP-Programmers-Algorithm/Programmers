#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1, q2;
    ll one = 0, two = 0;
    for(int i : queue1) {
        q1.push(i);
        one += i;
    }
    for(int i : queue2) {
        q2.push(i);
        two += i;
    }

    while(1) {
        if (one == two) break;
        if (answer >= 600000) {
            answer = -1;
            break;
        }
        if (q1.empty() or q2.empty()) {
            answer = -1;
            break;
        }
        if (one < two) {
            int tmp = q2.front(); q2.pop();
            one += tmp; two -= tmp;
            q1.push(tmp);
            answer++;
        } else if (one > two) {
            int tmp = q1.front(); q1.pop();
            one -= tmp; two += tmp;
            q2.push(tmp);
            answer++;
        }
    }
    return answer;
}

int main() {
    vector<int> q1 = {1, 4}, q2 = {4, 8};
    int ans = solution(q1, q2);
    printf("%d\n", ans);
}