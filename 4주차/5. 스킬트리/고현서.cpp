#include <string>
#include <vector>
#include<map>

using namespace std;

map<char, int> skillNum;
int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (int i = 0; i < skill.size(); i++) {
		skillNum[skill[i]] = i + 1;
	}
	for (int i = 0; i < skill_trees.size(); i++) {
		int nextLevel = 1;
		bool isRight = true;
		for (int j = 0; j < skill_trees[i].size(); j++) {
			if (!skillNum[skill_trees[i][j]]) continue;
			if (nextLevel != skillNum[skill_trees[i][j]]) {
				isRight = false;
				break;
			}
			nextLevel++;
		}
		if (isRight)
			answer++;
	}
	return answer;
}