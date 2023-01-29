#include <iostream>
#include <queue>
using namespace std;

//N번째큰수 // 시간초과 ㅠㅠ

// priority queue
// 모든 원소 중 가장 큰 수를 top에 유지시킨다
// top -> 요소 중 가장 값을 반환한다 
// pop -> top의 요소를 제거한다

int main() {
    priority_queue<int, vector<int>, greater<int>>pq;
    vector<int> skipline;
    int n;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    int idx = n - 1;

    for (size_t i = 1; i < n; i++)// 마지막 행을 제외한 모든 행을 비교한다
    {
        int stop = 1;
        for (size_t j = 0; j < n; j++)
        {
            int temp;
            int minNum;
            cin >> temp;
            minNum = pq.top();

            if (minNum < temp)
            {
                pq.pop();
                pq.push(temp);
                stop = 0;

            }
            else { skipline.push_back(j); }
        }
        if (stop == 1) { break; }
    }
    for (size_t i = 0; i < skipline.size(); i++)
    {
        cout << skipline[i] << " ";
    }
    cout << endl;
    cout << pq.top();

    return 0;
}