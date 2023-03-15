#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    
    vector<long long> answer;
    int k;
    int n;
    long long num;
 
    for (int i = 0; i < numbers.size(); i++)
    {
       
        // 짝수일때
        if (numbers[i] % 2 == 0)
        {
            answer.push_back(numbers[i]+1);
        }
        // 홀수일떄
        else
            {
                long long bit = 1;
                      
                while (true)
                {              
                    if ((numbers[i] & bit) == 0)
                    {
                        break;
                    }
                    bit *= 2;
                }
                //  바로전 자리수가 f값
                bit = bit / 2;
                answer.push_back(numbers[i] + bit);
            } 
    } 
    return answer;
}
