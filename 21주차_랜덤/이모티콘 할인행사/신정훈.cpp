#include <iostream>
#include <vector>
using namespace std;


vector<int> sales = { 0, 10, 20, 30, 40 };

void process(vector<int>& selected, int idx, const vector<vector<int>>& users, const vector<int>& emoticons, int& pls, int& answerSum)
{
	if (idx == emoticons.size())
	{
		int plusTemp = 0;
		int sumTemp = 0;
		for (int i = 0; i < users.size(); i++)
		{
			int sum = 0;
			for (int j = 0; j < emoticons.size(); j++)
			{
				int sale = selected[j];
				if (sale >= users[i][0])
				{
					sum += emoticons[j] * (0.01 * (100 - sale));
				}
			}
			if (sum >= users[i][1])
			{
				sum = 0;
				plusTemp++;
			}
			else
			{
				sumTemp += sum;
			}
		}
		if (plusTemp > pls || (plusTemp == pls && sumTemp > answerSum))
		{
			pls = plusTemp;
			answerSum = sumTemp;
		}
	}
	else
	{
		for (int i = 0; i < sales.size(); i++)
		{
			selected.push_back(sales[i]);
			process(selected, idx + 1, users, emoticons, pls, answerSum);
			selected.pop_back();
		}
	}
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
	vector<int> answer;
	vector<int> selected;
	int pls = 0;
	int answerSum = 0;

	process(selected, 0, users, emoticons, pls, answerSum);

	answer.push_back(pls);
	answer.push_back(answerSum);

	return answer;
}
