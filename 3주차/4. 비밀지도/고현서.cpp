#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	string str = "";
	for (int i = 0; i < n; i++) {
		string ans = "";
		for (int j = n - 1; j >= 0; j--) {
			ans += ((arr1[i] >> j) & 1) || ((arr2[i] >> j) & 1) == 1 ? "#" : " ";
		}
		answer.push_back(ans);
	}
	return answer;
}