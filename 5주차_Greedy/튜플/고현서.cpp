#include <string>
#include <vector>
#include<sstream>
#include<algorithm>
#include<map>
using namespace std;

map<int, int> strings;
bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
	if (p1.second == p2.second) {
		return p1.first > p2.first;
	}
	return p1.second > p2.second;
}
vector<int> solution(string s) {
	vector<int> answer;
	string str = s.substr(0, s.length() - 2);
	string str2 = str.substr(1, str.length() - 1);

	istringstream iss(str2);
	string str_buf;
	vector<string> stringVec;
	while (getline(iss, str_buf, '{')) {
		istringstream iss2(str_buf);
		string str_buf2;
		while (getline(iss2, str_buf2, '}')) {
			stringVec.push_back(str_buf2);
		}
	}
	vector<int>temp;
	for (int i = 0; i < stringVec.size(); i++) {
		if (stringVec[i].length() == 1 && stringVec[i][0] == ',')
			continue;
		istringstream iss2(stringVec[i]);
		string str_buf2;
		while (getline(iss2, str_buf2, ',')) {
			int num = stoi(str_buf2);
			if (strings[num] == 0) {
				temp.push_back(num);
			}
			strings[num]++;
		}
	}
	vector<pair<int, int>> vecTemp(strings.begin(), strings.end());
	sort(vecTemp.begin(), vecTemp.end(), cmp);
	for (auto num : vecTemp) {
		answer.push_back(num.first);
	}
	return answer;
}