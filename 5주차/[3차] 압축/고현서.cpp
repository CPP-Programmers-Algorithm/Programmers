#include <string>
#include <vector>
#include<map>

using namespace std;

map<string, int> dic;
vector<int> solution(string msg) {
	vector<int> answer;
	for (int i = 1; i <= 26; i++) {
		char ch = (char)(i + 64); string str = "";
		str += ch;
		dic.insert({ str,i });
	}

	string w = "";
	int last = 27;
	w += msg[0];
	for (int i = 0; i < msg.size(); i++) {
		if (i + 1 >= msg.size()) {
			if (dic.find(w) != dic.end()) {
				answer.push_back(dic[w]);
			}
			break;
		}

		string next = w + msg[i + 1];
		if (dic.find(next) == dic.end()) {
			dic.insert({ next,last++ });
			answer.push_back(dic[w]);
			w = msg[i + 1];
			continue;
		}
		w = next;
	}
	return answer;
}