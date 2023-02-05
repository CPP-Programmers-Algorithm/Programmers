#include <string>
#include <algorithm>
#include <vector>

using namespace std;

char number[18] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                   'A', 'B', 'C', 'D', 'E', 'F' };                      // 10 �̻��� ���� �������ֱ� ���� �����Ѵ�

string number_to_n(int num, int n) {
    string result;
    if (num == 0) {
        return "0";
    }
    while (num > 0) {               // �ش� ���� char�� �־���
        result += number[num % n];  // 82%8 = 2 ; 10%8 = 2 ; 1%8 = 1 ;
        num /= n;                   // 82/8 = 10; 10/8 = 1 ; 1/8 = 0 ; 
    }                               // 82 -> 122;  // 1�� �ڸ����� ����ؼ� ��� ���� �о�� ���
    reverse(result.begin(), result.end());
    return result;
}

string solution(int n, int t, int m, int p) { 
    
    // n : ����
    // t : �̸� ���� ���ڰ���     ( Ʃ�갡 ���ӵ��ȿ� ���ؾ� �� ���ڵ� )
    // m : ���ӿ� �����ϴ� �ο�   ( m�� �ѹ� ���� Ʃ�갡 ���ؾ� �ϴ� �������Ե� )
    // p : Ʃ�����

    string answer = "";
    string temp;
    int mt = m * t;
                                                  // ������ ������ ��� �� //
    for (int num = 0; temp.size() <= mt; num++) { // mt�� Ʃ�갡 ���ؾ� �ϴ� ���ڰ� ��� ���ԵǾ� �ִ�
        string ngame = number_to_n(num, n);
        temp += ngame;
    }
                                                  // Ʃ�갡 ���� �� ���� //
    for (int i = 0; i < t; i++) {                 // t�� ������ŭ ���� ������
        answer += temp.at((m * i) + (p - 1));     // m ���ʸ� ���� p�� ���ϸ� Ʃ������ (index �� p-1)
    }

    return answer;
}


// �ڵ尡 �� ¥�� �ִ� ���� ���� �ؾ� �� ��Ȱ�� ��Ȯ�ϰ�
// ���谡 �ִ�

// ref : https://velog.io/@huijae0817/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98C3%EC%B0%A8n%EC%A7%84%EC%88%98-%EA%B2%8C%EC%9E%84