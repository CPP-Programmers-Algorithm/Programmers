#include <string>
#include <vector>
//�����ٽ� : ���ڸ� string���� �ٷ� �� �ֳ�

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    int zero = 0, round = 0;

    while (s != "1")
    {
        string tmp = "";
        int size = 0, num;
        round++;

        for (int i = 0; i < s.size(); i++) // ��Ģ�� ���� ���������� ��ȯ
        {
            if (s[i] == '0')
                zero++;
            else
                tmp += "1";
        }

        num = tmp.size();
        s = "";
        while (num > 0)
        {
            s += to_string(num % 2); //�ٽ� 2�������� ��ȯ
            num /= 2;
        }
    }

    answer[0] = round;
    answer[1] = zero;
    return answer;
}

// ����
//https://eunchanee.tistory.com/219