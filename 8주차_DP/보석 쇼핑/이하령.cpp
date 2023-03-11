#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;

map<string, int> st;
set<string> store;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {1, 1000000};
    int le = 0, ri = 0;
    for(int i = 0; i < gems.size(); i++) store.insert(gems[i]);
    while(ri < gems.size()) {
        if (st.size() == store.size()) {
            if (answer[1] - answer[0] > ri - le - 1) {
                answer[1] = ri, answer[0] = le + 1;
            }
            st[gems[le++]]--; st[gems[ri++]]++;
        } else {
            st[gems[ri++]]++;
            if (st[gems[le]] > 1) {
                st[gems[le++]]--;
            }
        }
        while(store.size() == st.size()) {
            if (answer[1] - answer[0] > ri - le - 1) {
                answer[1] = ri, answer[0] = le + 1;
            }
            st[gems[le]]--;
            if (st[gems[le]] == 0) {
                st.erase(st.find(gems[le]));
            }
            le++;
        }
    }
    return answer;
}

int main() {
    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    vector<int> ans = solution(gems);
    printf("%d %d", ans[0], ans[1]);
}