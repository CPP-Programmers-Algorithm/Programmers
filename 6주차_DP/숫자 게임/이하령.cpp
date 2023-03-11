#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), greater<>());

    int AIdx = 0, BIdx = 0;
    while (AIdx < A.size() and BIdx < B.size()) {
        while(B[BIdx] <= A[AIdx]) {
            AIdx++;
            if (AIdx == A.size()) break;
        }
        if (AIdx == A.size()) break;
        if (B[BIdx] > A[AIdx]) {
            answer++;
            BIdx++; AIdx++;
        }
    }
    return answer;
}