#include <iostream>
#include <queue>
using namespace std;

//N��°ū�� // �ð��ʰ� �Ф�
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

    for (size_t i = 1; i < n; i++)// ������ ���� ������ ��� ���� ���Ѵ�
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