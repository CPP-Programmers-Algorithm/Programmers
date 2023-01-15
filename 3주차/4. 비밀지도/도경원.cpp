#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

// 배열을 2진법으로 변환
// vector<int>에 넣기
// 비트 


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer;
    
    for (size_t i = 0; i < n; i++)
    {
        int a = arr1[i];                                    //요소를 불러옴
        int b = arr2[i];

        bitset<16> firstMap(a);                             //비트로 전환
        bitset<16> secondMap(b);                            //비트로 전환
        bitset<16> mapCombined(firstMap | secondMap);       //두 비트의 합집합
  
        string lastMap = "";                                // 맵을 담을 변수선언
        for (size_t j = 0; j < n; j++)
        {
            if (mapCombined[n-j-1] == 1) {                  // bitset의 요소는 뒤에서부터 시작되서 거꾸로 뒤집어줘야 함
                lastMap.append("#");
            }
            else {
                lastMap.append(" ");                         // 1이 아니라면 공백
            }
        }
        answer.push_back(lastMap);                           // vector에 넣어주기
    }
    return answer;
}

//ref :https://ideone.com/0xBPjU

