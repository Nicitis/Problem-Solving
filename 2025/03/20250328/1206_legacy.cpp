#include <iostream>
#include <cmath>
#include <cfloat>

using namespace std;

/*
0.5 -> 0.5 * 2 = 1점(0~10) -> 최소 2명 or 4,6,8,10, ..., 20명
0.25 -> 0.25 * 4 = 1점 -> 최소 4명, 8, 12, 16, .., 40명
0.125 -> 0.125 * 8 = 1점 -> 최소 8명, 16명, ... 80명
즉, 2, 4, 8의 최소 공배수를 구하는 것이 문제

무조건 답이 존재하므로 ~53, 2:13~
단, 0이 들어올 경우 최소 1명이 필요하다고 가정한다.
0이 아닐 경우, 정수 K를 곱해서 정수가 되는 수가 나올 때 K를 최소 인원으로 계산한다.

부동소수점 문제가 있으므로 계산시 주의해야 한다. 
따라서 고정 소수점을 사용하는 게 나을 것.

예를 들어,
0.5, 0.301이 들어오면
2의 배수와 0.301에 대한 K의 배수로 계산해야 한다.
0.301 * 100 = 30.1
0.301 * 6 = 1.806
0.301 * 106 = 31.906?
만약 원래 숫자가 0.301999...~0.302라면 0.302 * 106 = 32.012로 106이 정답이 된다.
즉, 평균 점수 x에 대하여 x * k <= i < (x+0.001) * k인 정수 i가 존재할 때

왓? 소수점 셋째 자리에서 자른 값이요?



*/

int FindMinimumMultiplier(double x);

void TestCase(int n)
{
    double avg;
    for (int i = 0; i < n; i++)
    {
        cin >> avg;
        cout << avg << "'s min multiplier: " << FindMinimumMultiplier(avg) << "\n";
    }
}

int FindMinimumMultiplier(double x)
{
    if (x == 0.0)
        return 1;

    for (int i = 1;;i++)
    {
        if (ceil(x*i) < ceil(((x*1000+1)/1000.0)*i))
        {
            cout << "Ceil = " << ceil(x*i) 
                << ", ((x*1000+1)/1000.0)*i = " 
                << ((x*1000+1)/1000.0)*i << "\n";
            return i;
        }
    }
}

int main()
{
    int n;
    double avg;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    TestCase(n);
    for (int i = 0; i < n; i++)
    {
        cin >> avg;
    }

    return 0;
}