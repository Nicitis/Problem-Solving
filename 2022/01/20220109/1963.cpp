// 백준 1963: 소수 경로
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

bool visit[10000] = { false };
int isPrime[10000] = { false };

struct Step
{
    int number;
    int step;
};

void ConvertToStr(int number, char* dstStr)
{
    for (int i = 3; i >= 0; i--)
    {
        dstStr[i] = number % 10;
        number /= 10;
    }
}

int ConvertToInt(char* srcStr)
{
    int number = 0;
    for (int i = 0; i < 4; i++)
    {
        number = number * 10 + srcStr[i];
    }
    return number;
}

bool IsPrimeNumber(int number)
{
    int root = (int)sqrt(number);
    for (int i = 2; i <= root; i++)
    {
        if (number % i == 0)
            return false;
    }

    return true;
}

int PrimeNumberPath(int start, int end)
{
    queue<struct Step> q;
    char str[4] = { 0 };

    q.push({start, 0});
    visit[start] = true;

    while (!q.empty())
    {
        struct Step elem = q.front();
        q.pop();

        if (elem.number == end)
            return elem.step;

        ConvertToStr(elem.number, str);

        for (int i = 0; i < 4; i++)
        {
            char currNum = str[i];
            for (int digit = 0; digit <= 9; digit++)
            {
                if (i == 0 && digit == 0)
                    continue;
                
                // i번째 자릿수의 수를 digit으로 바꿔본다.
                str[i] = digit;
                int number = ConvertToInt(str);

                if (visit[number])
                    continue;
                
                if (isPrime[number])
                {
                    visit[number] = true;
                    q.push({number, elem.step + 1});
                }
            }
            str[i] = currNum;
        }
    }

    return -1;
}

int main()
{
    int t, start, end;

    for (int i = 1000; i <= 9999; i++)
    {
        isPrime[i] = IsPrimeNumber(i);
    }

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> start >> end;

        memset(visit, (int) false, sizeof(visit));

        int steps = PrimeNumberPath(start, end);
        if (steps == -1)
            cout << "Impossible\n";
        else
            cout << steps << '\n';
    }

    return 0;
}