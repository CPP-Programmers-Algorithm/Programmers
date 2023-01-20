#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int getIdx(string skill, char c) {
    for(int i = 0; i < skill.size(); i++) {
        if (skill[i] == c) return i;
    }
    return -1;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i = 0; i < skill_trees.size(); i++) {
        int isAnswer = 1;
        vector<int> v;
        for(int j = 0; j < skill_trees[i].size(); j++) {
            int idx = getIdx(skill, skill_trees[i][j]);
            if (idx == -1) continue;
            v.push_back(idx);
        }
        int pre = -1;
        for(int j = 0; j < v.size(); j++) {
            if (v[j]-pre > 1) isAnswer = 0;
            pre = v[j];
        }
        answer += isAnswer;
    }
    return answer;
}

int main() {
    printf("%d", solution("CBD", {"BACDE", "CBADF", "AECB", "BDA"}));
}