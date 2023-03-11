#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

map<char, int> m;

int solution(string s) {
    if (s.size() % 2 == 1) return 0;
    int answer = 0;
    queue<char> sets;
    for (int i = 0; i < s.length(); i++) {
        sets.push(s[i]);
    }

    m.insert({ '[',1 });  m.insert({ '{',1 }); m.insert({ '(',1 });
    m.insert({ ']',2 }); m.insert({ '}',2 }); m.insert({ ')',2 });

    for (int i = 0; i < sets.size(); i++) {
        queue<char> qTemp = sets;
        stack<char> st;
        bool resultTrue = true;
        while (!qTemp.empty()) {
            char frontChar = qTemp.front();
            qTemp.pop();
            if (st.empty()) {
                if (m[frontChar] == 2) {
                    resultTrue = false;
                    break;
                }
                st.push(frontChar);
                continue;
            }
            if (m[frontChar] == 2) {
                if (abs((int)st.top() - (int)frontChar) > 10) {
                    resultTrue = false;
                    break;
                }
                else {
                    st.pop();
                }
            }
            else
                st.push(frontChar);
        }
        if (resultTrue)
            answer++;

        char c = sets.front();
        sets.pop();
        sets.push(c);
    }

    return answer;
}