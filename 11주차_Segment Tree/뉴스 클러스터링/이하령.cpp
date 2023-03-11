#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
using namespace std;

map<string, int> mp1, mp2;
string s = "";

bool chk(char a) {
    if (a >= 'a' and a <= 'z') return true;
    if (a >= 'A' and a <= 'Z') return true;
    return false;
}

int solution(string str1, string str2) {
    int hap = 0, gyo = 0;
    for(int i = 0; i < str1.size(); i++) {
        if ('A' <= str1[i] and str1[i] <= 'Z') str1[i] += 32;
    }
    for(int i = 0; i < str2.size(); i++) {
        if ('A' <= str2[i] and str2[i] <= 'Z') str2[i] += 32;
    }

    for(int i = 0; i < str1.size()-1; i++) {
        if (!chk(str1[i]) or !chk(str1[i+1])) continue;
        s = ""; s += str1[i]; s += str1[i+1];
        mp1[s]++;
    }
    for(int i = 0; i < str2.size()-1; i++) {
        if (!chk(str2[i]) or !chk(str2[i+1])) continue;
        s = ""; s += str2[i]; s += str2[i+1];
        mp2[s]++;
    }
    for(auto i : mp1) {
        if (mp2.find(i.first) != mp2.end()) {
            gyo += min(mp2[i.first], mp1[i.first]);
            hap += max(mp2[i.first], mp1[i.first]);
        } else {
            hap += mp1[i.first];
        }
    }
    for(auto i : mp2) {
        if (mp1.find(i.first) == mp1.end()) hap += mp2[i.first];
    }
    return gyo == 0 and hap == 0 ? 65536 : floor(double(double(gyo) / hap) * 65536);
}

int main() {
    string s1 = "ab", s2 = "ba_bd";
    printf("%d", solution(s1, s2));
}