#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> a) {
    vector<int> tmp = a;
    sort(tmp.begin(), tmp.end());
    int mn = tmp[0];

    int answer = 0;
    int leftMn = 1000000001, rightMn = 1000000001;

    int index = 0;
    while(a[index] != mn) {
        if (leftMn > a[index]) {
            answer++;
            leftMn = a[index];
        }
        index++;
    }

    index = a.size() - 1;
    while(a[index] != mn) {
        if (rightMn > a[index]) {
            answer++;
            rightMn = a[index];
        }
        index--;
    }

    return answer + 1;
}

int main() {
    vector<int> v = {3, 2, 4, 1, 0};
    printf("%d", solution(v));
}