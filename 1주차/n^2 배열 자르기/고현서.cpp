#include <vector>
#include<math.h>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for (long long i = left; i <= right; i++) {
        answer.push_back(max((i % n) + 1, (long long)(floor)(i / n) + 1));
    }
    return answer;
}