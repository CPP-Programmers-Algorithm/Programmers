#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef long long ll;
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

vector<int> ans = {0, 0};
vector<int> v;
int dis[] = {10, 20, 30, 40};

void go(vector<vector<int>> users, vector<int> emo) {
    if (v.size() == emo.size()) {
        int plusService = 0, emoticonCost = 0;
        for(int i = 0; i < users.size(); i++) {
            int tmpCost = 0, tmpService = 0; // i 사용자가 지불한 금액, service 가입 여부
            for(int j = 0; j < v.size(); j++) {
                if (v[j] >= users[i][0]) { // 사용자가 원하는 할인율 이상인 경우
                    tmpCost += (100 - v[j]) * (emo[j] / 100);
                    if (tmpCost >= users[i][1]) {
                        tmpCost = 0;
                        tmpService = 1;
                        break;
                    }
                }
            }
            plusService += tmpService, emoticonCost += tmpCost;
        }
        if (plusService > ans[0]) {
            ans = {plusService, emoticonCost};
        } else if (plusService == ans[0]) ans[1] = max(ans[1], emoticonCost);
    } else {
        for(int i = 0; i < 4; i++) {
            v.push_back(dis[i]);
            go(users, emo);
            v.pop_back();
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    go(users, emoticons);
    return ans;
}

int main() {
    vector<vector<int>> users = {{40, 10000}, {25, 10000}} ;
    vector<int> emoticons = {{7000, 9000}};

    vector<int> sol = solution(users, emoticons);
    printf("%d %d\n", sol[0], sol[1]);
}