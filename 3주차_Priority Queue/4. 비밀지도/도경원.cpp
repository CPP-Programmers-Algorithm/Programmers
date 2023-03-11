#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

// �迭�� 2�������� ��ȯ
// vector<int>�� �ֱ�
// ��Ʈ 


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer;
    
    for (size_t i = 0; i < n; i++)
    {
        int a = arr1[i];                                    //��Ҹ� �ҷ���
        int b = arr2[i];

        bitset<16> firstMap(a);                             //��Ʈ�� ��ȯ
        bitset<16> secondMap(b);                            //��Ʈ�� ��ȯ
        bitset<16> mapCombined(firstMap | secondMap);       //�� ��Ʈ�� ������
  
        string lastMap = "";                                // ���� ���� ��������
        for (size_t j = 0; j < n; j++)
        {
            if (mapCombined[n-j-1] == 1) {                  // bitset�� ��Ҵ� �ڿ������� ���۵Ǽ� �Ųٷ� ��������� ��
                lastMap.append("#");
            }
            else {
                lastMap.append(" ");                         // 1�� �ƴ϶�� ����
            }
        }
        answer.push_back(lastMap);                           // vector�� �־��ֱ�
    }
    return answer;
}

//ref :https://ideone.com/0xBPjU

