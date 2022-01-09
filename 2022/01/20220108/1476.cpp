// 백준 1476: 날짜 계산
#include <iostream>

using namespace std;

int solution(int e, int s, int m)
{
    int year = 1, currE = 1, currS = 1, currM = 1;

    while (currE != e || currS != s || currM != m)
    {
        if (++currE > 15)
            currE = 1;
        if (++currS > 28)
            currS = 1;
        if (++currM > 19)
            currM = 1;
        year++;
    }
    return year;
}

int main()
{
    int e, s, m;

    cin >> e >> s >> m;

    cout << solution(e, s, m);

    return 0;
}