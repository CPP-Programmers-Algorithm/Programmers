#include <iostream>

using namespace std;

int N;
// 값을 저장할 행렬
int mdistance[104][104];

int main()
{
    cin >> N;
    // 행렬에 입력값 넣기
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {         
            cin >> mdistance[i][j];            
        }
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++) 
            {
                if (mdistance[i][k] ==1 && mdistance[k][j] == 1)
                {
                    mdistance[i][j] = 1;
                }
            }
        }
    }
  
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << mdistance[i][j] << " ";
        }
        cout << "\n";
    }
}
