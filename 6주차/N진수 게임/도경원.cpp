#include <string>
#include <algorithm>
#include <vector>

using namespace std;

char number[18] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                   'A', 'B', 'C', 'D', 'E', 'F' };                      // 10 이상의 수를 저장해주기 위해 저장한다

string number_to_n(int num, int n) {
    string result;
    if (num == 0) {
        return "0";
    }
    while (num > 0) {               // 해당 숫자 char을 넣어줌
        result += number[num % n];  // 82%8 = 2 ; 10%8 = 2 ; 1%8 = 1 ;
        num /= n;                   // 82/8 = 10; 10/8 = 1 ; 1/8 = 0 ; 
    }                               // 82 -> 122;  // 1의 자리부터 계산해서 계속 위로 밀어내는 방식
    reverse(result.begin(), result.end());
    return result;
}

string solution(int n, int t, int m, int p) { 
    
    // n : 진수
    // t : 미리 구할 숫자갯수     ( 튜브가 게임동안에 말해야 할 숫자들 )
    // m : 게임에 참여하는 인원   ( m을 한번 돌면 튜브가 말해야 하는 숫자포함됨 )
    // p : 튜브순서

    string answer = "";
    string temp;
    int mt = m * t;
                                                  // 앞으로 말해질 모든 수 //
    for (int num = 0; temp.size() <= mt; num++) { // mt는 튜브가 말해야 하는 숫자가 모두 포함되어 있다
        string ngame = number_to_n(num, n);
        temp += ngame;
    }
                                                  // 튜브가 말할 수 추출 //
    for (int i = 0; i < t; i++) {                 // t의 갯수만큼 수를 가져옴
        answer += temp.at((m * i) + (p - 1));     // m 차례를 돌고 p를 더하면 튜브차례 (index 라서 p-1)
    }

    return answer;
}


// 코드가 잘 짜여 있는 것이 각자 해야 할 역활이 명확하고
// 위계가 있다

// ref : https://velog.io/@huijae0817/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98C3%EC%B0%A8n%EC%A7%84%EC%88%98-%EA%B2%8C%EC%9E%84