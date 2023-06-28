#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

string sol(string s) {
    string ret = "";
    stack<char> st;
    int n = 0;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (st.size() < 2) st.push(s[i]);
            else if (st.top() == '1') {
                st.pop();
                if (st.top() == '1') {// 11이 연속으로 있다면
                    st.pop();
                    n++;
                }
                else { // 아니라면 원상복구
                    st.push('1');
                    st.push('0');
                }
            } else st.push('0');
        } else st.push('1');
    }

    while(!st.empty()) {
        char t = st.top(); st.pop();
        if (t == '0' and n) {
            for(int i = 0; i < n; i++) ret += "011";
            ret += t;
            n = 0;
        } else ret += t;
    }
    if (n) for(int i = 0; i < n; i++) ret += "011";
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<string> solution(vector<string> s) {
    vector<string> ans;

    for(string t : s) {
        ans.push_back(sol(t));
    }
    return ans;
}

int main() {
    vector<string> s = {"1110","100111100","0111111010", "1100111011101001"};
    vector<string> t = solution(s);

    for(string tmp: t) cout << tmp << endl;
}