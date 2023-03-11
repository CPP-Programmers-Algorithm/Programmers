#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

long long solution(vector<long long> distance, vector<long long> price)
{
	long long totalPrice = 0;
	int disIdx = 0, priceA = 0, priceB = 1;

	for (int i = 0; i < distance.size(); i++)
	{
		totalPrice += (price[priceA] * distance[disIdx]);
		if (price[priceA] <= price[priceB])
			priceB++;
		else
		{
			priceA = priceB;
			priceB = priceA + 1;
		}
		disIdx++;
	}
	return totalPrice;
}

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n;
	cin >> n;

	vector<long long> dis;
	vector<long long> price;

	for (int i = 0; i < n - 1; i++)
	{
		long long d;
		cin >> d;
		dis.push_back(d);
	}

	for (int i = 0; i < n; i++)
	{
		long long p;
		cin >> p;
		price.push_back(p);
	}

	cout << solution(dis, price);
}
