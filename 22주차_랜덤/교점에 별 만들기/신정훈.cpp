#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<vector<long long>> longLine(line.size(), vector<long long>(line[0].size()));
    for (int i = 0; i < line.size(); i++)
    for (int j = 0; j < line[i].size(); j++)
        longLine[i][j] = line[i][j];
    
    vector<pair<long long,long long>> answer;
vector<string> aanswer;
long long maxX = -9223372036854775807;
long long maxY = -9223372036854775807;
long long minX = 9223372036854775807;
long long minY = 9223372036854775807;
    for (int i = 0; i < longLine.size(); i++)
	{
		for (int j = 0; j < longLine.size(); j++)
		{
			if (i == j)
			{
				continue;
			}
			long long AD = longLine[i][0] * longLine[j][1];
			long long BC = longLine[i][1] * longLine[j][0];
			long long BF = longLine[i][1] * longLine[j][2];
			long long ED = longLine[i][2] * longLine[j][1];
			long long EC = longLine[i][2] * longLine[j][0];
			long long AF = longLine[i][0] * longLine[j][2];
			if (AD - BC == 0)
			{
				continue;
			}
			else
			{
				if ((BF - ED) % (AD - BC) == 0 && (EC - AF) % (AD - BC) == 0)
				{

					long x = ((BF - ED) / (AD - BC));
					long y = ((EC - AF) / (AD - BC));
					if (x > maxX)
					{
						maxX = x;
					}
					if (x < minX)
					{
						minX = x;
					}
					if (y > maxY)
					{
						maxY = y;
					}
					if (y < minY)
					{
						minY = y;
					}
					answer.push_back({ x, y });
				}

			}
		}
	}
    for (long long i = maxY; i >= minY; i--)
	{
		string a = "";
		for (long long j = minX; j <= maxX; j++)
		{
			a += ".";
			for (int k = 0; k < answer.size(); k++)
			{
				if (answer[k].first == j && answer[k].second == i)
				{
a.back() = '*';
					break;
				}
			}
		}
		aanswer.push_back(a);
	}
    return aanswer;
    
}
