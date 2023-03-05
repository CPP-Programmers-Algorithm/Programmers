#include<cstring>
#include<string>
#include<deque>
#include<unordered_map>
using namespace std;

unordered_map<char, int> priority[6]
= {
	{
		{'+', 1},
		{'-', 2},
		{'*', 3}
	},
	{
		{'+', 1},
		{'-', 3},
		{'*', 2}
	},
	{
		{'-', 1},
		{'+', 2},
		{'*', 3}
	},
	{
		{'-', 1},
		{'+', 3},
		{'*', 2}
	},
	{
		{'*', 1},
		{'-', 2},
		{'+', 3}
	},
	{
		{'*', 1},
		{'-', 3},
		{'+', 2}
	}
};
long long solution(string expression) {
	long long answer = 0;
	for (int j = 0; j < 6; j++) {
		long long num = 0;
		deque<long long> NumStack;
		deque<char> OperStack;
		for (int i = 0; i < expression.size(); i++) {
			if (expression[i] >= 48) {
				num *= 10;
				num += (expression[i] - 48);
			}
			else {
				NumStack.push_front(num);
				num = 0;
				if (OperStack.empty()) {
					OperStack.push_front(expression[i]);
				}
				else {
					char topOper = OperStack.front();
					//우선순위가 자신보다 낮은 것이 나오거나 -> 빼는 과정에서 스택이 빌 때까지 계산해준다.
					while (priority[j][topOper] <= priority[j][expression[i]]) {
						OperStack.pop_front();
						long long num2 = NumStack.front();
						NumStack.pop_front();
						long long num1 = NumStack.front();
						NumStack.pop_front();
						long long ret = 0;
						switch (topOper)
						{
						case '+':
							ret = num1 + num2;
							break;
						case '-':
							ret = num1 - num2;
							break;
						case '*':
							ret = num1 * num2;
							break;
						default:
							break;
						}
						NumStack.push_front(ret);
						if (OperStack.empty()) break;
						topOper = OperStack.front();
					}
					OperStack.push_front(expression[i]);
				}
			}
		}
		NumStack.push_front(num);
		//우선순위 높은 것부터 위에 남아있기 때문에 우선순위 고려해서 순서 안지켜도 된다.
		while (!OperStack.empty()) {
			char topOper = OperStack.front();
			OperStack.pop_front();
			long long ret = 0;
			long long num2 = 0;
			long long num1 = 0;
			num2 = NumStack.front();
			NumStack.pop_front();
			num1 = NumStack.front();
			NumStack.pop_front();

			switch (topOper)
			{
			case '+':
				ret = num1 + num2;
				break;
			case '-':
				ret = num1 - num2;
				break;
			case '*':
				ret = num1 * num2;
				break;
			default:
				break;
			}
			NumStack.push_front(ret);
		}
		answer = answer < abs(NumStack.front()) ? abs(NumStack.front()) : answer;
	}
	return answer;
}