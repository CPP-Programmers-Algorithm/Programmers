#include <string>
#include <vector>

using namespace std;

int minL[1000001];
int minR[1000001];

int solution(vector<int> a) {
    int answer = 0;
    //�����ּҰ�����
    minL[0] = a[0];
    minR[a.size() - 1] = a[a.size() - 1];

    //�����ּҰ�����
    for (int i = 1; i < a.size(); i++)
    {
        if (minL[i - 1] > a[i]) minL[i] = a[i];
        else minL[i] = minL[i - 1];
    }

    //������ �ּҰ�����
    for (int i = a.size()-2; i >= 0; i--)
    {
        if (minR[i + 1] > a[i]) minR[i] = a[i];
        else minR[i] = minR[i + 1];
    }

    // ��ǥ idx���� minL�� minR�� ��
    // �� ��κ��� �۴ٸ� ��Ƴ��� �� ����
    // ������ ��Ƴ��� �� �ִ� ����� ���� �����߱� ������
    for (int i = 0; i < a.size(); i++) {
        if (a[i] <= minL[i] || a[i] <= minR[i]) answer++;
    }

    return answer;
}



//