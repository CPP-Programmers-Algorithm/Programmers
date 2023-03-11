#include <string>
#include <vector>
#include<set>

using namespace std;

bool isVisited[8];
set<string> s;
void DFS(vector<string>& user_id, vector<string>& banned_id, int idx) {
	if (idx == banned_id.size()) {
		string str;
		for (int i = 0; i < user_id.size(); i++) {
			if (isVisited[i])
				str += user_id[i];
		}
		s.insert(str);
		return;
	}
	for (int i = 0; i < user_id.size(); i++) {
		if (isVisited[i])
			continue;
		if (user_id[i].size() != banned_id[idx].size())
			continue;
		bool isSame = true;
		for (int j = 0; j < user_id[i].size(); j++) {
			if (banned_id[idx][j] == '*')
				continue;
			if (banned_id[idx][j] != user_id[i][j]) {
				isSame = false;
				break;
			}
		}
		if (isSame) {
			isVisited[i] = true;
			DFS(user_id, banned_id, idx + 1);
			isVisited[i] = false;
		}
	}
}
int solution(vector<string> user_id, vector<string> banned_id) {
	DFS(user_id, banned_id, 0);
	return s.size();
}