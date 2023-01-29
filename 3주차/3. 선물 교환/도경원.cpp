#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// ����ʰ� // ������ ����
void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();
    int sCount;
    string answer = "";

    vector<vector<int>> node;
	vector<int>	gift;
    queue<int> q;

    int n;
    cin >> n;
    gift.resize(n);
    node.resize(n);
    
    sCount = n;

    // ���� ���� ����
    // �������
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            int temp;
            cin >> temp;

            gift[temp - 1] += 1;        //�������� ����
            node[i].push_back(temp - 1);          // �������

        }
    }

    for (size_t i = 0; i < n; i++)
    {
        if (gift[i] < 2) { q.push(i);}
        // ���� ������ 2���� ������ Ż���� ���
    }

    while (!q.empty()) {

        int idx = q.front();
        gift[   node[idx][0]  ]--;           // �νǳ�尡 ����Ű�� ����� ������ �������
        gift[   node[idx][1]  ]--;           // �νǳ�尡 ����Ű�� ����� ������ �������

        q.pop();
        sCount--;                               //������ �л����� ����

        for (size_t i = 0; i < 2; i++)          // ����� ��尡 �Բ� ���������� �˻�
        {
            int linkNodeIdx = node[idx][i];
            for (size_t j = 0; j < 2; j++)
            {
                if (node[linkNodeIdx][j] == idx) {
                    q.push(linkNodeIdx);            // �νǳ�尡 ����Ű�� ��尡 �νǳ�带 ����Ű�� �ִٸ�
                }                                   // �� ��嵵 �νǳ�忡 �ִ´�
            }   
        }
    }

    answer.append(to_string(sCount));
    if (sCount == 0) { cout << answer; return 0; }                  // �����л��� ������ ���⼭ ����


    answer.append("\n");
    for (size_t i = 0; i < n; i++)
    {
        if (gift[i] == 2) {
            answer.append(to_string(i+1) + " "); // �ε����� �ƴ� ��Ҹ� ��Ÿ���Ƿ� +1 ���ش�
        }
    }

    cout << answer;
	return 0;
}