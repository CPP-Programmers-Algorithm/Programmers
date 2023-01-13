#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++) {
        int a = arr1[i], b = arr2[i];
        string binary1 = bitset<16>(a).to_string();
        string binary2 = bitset<16>(b).to_string();
        string tmp = "";
        for(int j = 16-n; j < 16; j++) {
            tmp.push_back((binary1[j] == '1' or binary2[j] == '1') ? '#' : ' ');
        }
        answer.push_back(tmp);
    }
    return answer;
}