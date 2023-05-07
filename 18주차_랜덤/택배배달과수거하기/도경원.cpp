#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;
    int box = 0;     // ����� �ù��� ����
    stack<int> D, P; // �� ���� ��� Ȥ�� ȸ���� �ù��� ����

    for (auto i : deliveries)
        D.push(i);
    for (auto i : pickups)
        P.push(i);


    while (!D.empty() && D.top() == 0) // ���� �ְ� ����� �ù�� ���� �� ����
        D.pop();
    while (!P.empty() && P.top() == 0) // ���� �ְ� ȸ���� �ù�� ���� �� ����
        P.pop();


    while (!(D.empty() && P.empty()))
    {
        answer += max(D.size() * 2, P.size() * 2); // ���� �ָ� �ִ� ���� ���� �湮

        box = 0;
        while (!D.empty() && box <= cap)
        {
            if (D.top() + box <= cap) // D.top() ���� ����� �ù踦 ���� ���� �� ���� ��
                box += D.top();
            else
            {
                D.top() -= (cap - box); // �Ϻθ� ���� ��
                break;
            }
            D.pop();
        }

        box = 0;
        while (!P.empty() && box <= cap)
        {
            if (P.top() + box <= cap) // P.top() ������ ȸ���� �ù踦 ���� ���� �� ���� ��
                box += P.top();
            else
            {
                P.top() -= (cap - box); // �Ϻθ� ���� ��
                break;
            }
            P.pop();
        }
    }
    return answer;
}


// ȥ�� Ǯ�� �������� ������ ���� ī�Ǽ����̶�� �Ϸ��� �����Խ��ϴ�
//https://velog.io/@yeongori/%ED%83%9D%EB%B0%B0-%EB%B0%B0%EB%8B%AC%EA%B3%BC-%EC%88%98%EA%B1%B0%ED%95%98%EA%B8%B0-c