#include<iostream>
#include<unordered_map>
#include<cmath>
#include<vector>

using namespace std;
unordered_map<string, string> parent;
unordered_map<string, int> don;
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    for (int i = 0; i < enroll.size(); i++) {
        don[enroll[i]] = 0;
        parent[enroll[i]] = referral[i];
    }
    parent["-"] = "X";
    for (int i = 0; i < seller.size(); i++) {
        string me = seller[i];
        int curDon = amount[i] * 100;
        string p = "";
        while (p != "X") {
            p = parent[me];
            int myDon = ceil(curDon * 0.9);
            if (myDon < 1) {
                don[me] += curDon;
                break;
            }
            don[me] += myDon;
            curDon -= myDon;
            me = p;
        }
    }
    for (int i = 0; i < enroll.size(); i++) {
        answer.push_back(don[enroll[i]]);
    }
    return answer;
}