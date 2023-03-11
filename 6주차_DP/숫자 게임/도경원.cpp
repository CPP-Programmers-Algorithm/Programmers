#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 정렬해주고 A보다 더 큰 수가 B에서 나올 때 업데이트

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int lastidx = 0; // B idx 업데이트 용

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < A.size(); i++){
        for (int j = lastidx; j < A.size(); j++){ // 큰 수가 나오면 그 다음 수부터 검사한다
            if (A[i] < B[j]) {
                lastidx = j+1;
                answer++;
                break;
            }
        }
    }
    return answer;
}

int main() {
    int n; cin >> n;

    vector<int> teamA;
    vector<int> teamB;

    for (int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        teamA.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        teamB.push_back(tmp);
    }
    cout << solution(teamA, teamB);

}