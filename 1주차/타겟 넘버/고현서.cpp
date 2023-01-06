#include <string>
#include <vector>

using namespace std;

vector<int> num;
int answer;
int tar;
void DFS(int idx, int sum) {
    if (idx == num.size())
    {
        if (tar == sum)
            answer++;
        return;
    }
    DFS(idx + 1, sum + num[idx]);
    DFS(idx + 1, sum - num[idx]);
}

int solution(vector<int> numbers, int target) {
    num = numbers;
    tar = target;
    DFS(0, 0);
    return answer;
}