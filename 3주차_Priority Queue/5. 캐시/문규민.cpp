#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> cities)
{
    int answer = 0;
    vector<string> cache;
    vector<string> cities_lower;

    if (n == 0)
    {
        cout << cities.size() * 5;
        return cities.size() * 5;
    }

    // cities의 도시명들을 전부 소문자로 바꾸어 cities_lower에 저장
    for (int i = 0; i < cities.size(); i++)
    {
        string str = "";
        for (int j = 0; j < cities[i].size(); j++)
            str += tolower(cities[i][j]);
        cities_lower.push_back(str);
    }

    for (int i = 0; i < cities.size(); i++)
    {
        string str_lower = "";
        for (int j = 0; j < cities[i].size(); j++)
        {
            str_lower += tolower(cities[i][j]);
        }

        vector<string>::iterator it = find(cache.begin(), cache.end(), str_lower);  // 현재 순번 도시의 위치 (iterator)

        if (cache.size() < n)
        {
            if (it != cache.end())
            {
                answer += 1;
                if(cache.size() > 0)    cache.erase(it);
                cache.push_back(cities_lower[i]);
            }
            else
            {
                answer += 5;
                cache.push_back(cities_lower[i]);
            }
        }
        else
        {
            if (it != cache.end())
            {
                answer += 1;
                cache.erase(it);
                cache.push_back(cities_lower[i]);
            }
            else
            {
                answer += 5;
                cache.erase(cache.begin());
                cache.push_back(cities_lower[i]);
            }
        }
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();

    int n = 2;
    vector<string> cities = { "Jeju", "Pangyo", "NewYork", "newyork" };
    solution(n, cities);
}
