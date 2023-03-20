#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void  count(int x, int y,int size, int first)
{
    int half = size / 2;
	bool same = true;
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (test[i][j] != first)
			{
				same = false;
				break;

				
			}
		}
	}
	if (same == true)
	{
		if (test[x][y] == 0)
		{
			answer[0]++;
		}
		else if (test[x][y] == 1)
		{
			answer[1]++;
		}
		return;
	}

	count(x, y, half, test[x][y]);
	count(x + half, y, half, test[x + half][y]);
	count(x, y+half, half, test[x][y+half]);
	count(x+half, y+ half, half, test[x+half][y+half]);
}

vector<int> solution(vector<vector<int>> arr) {
	int size = arr.size();
	count(0, 0, size, arr[0][0]);
	return answer;
}
