#include <iostream>
#include <cmath>
#include <cfloat>
#include <string>
#include <vector>

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
즉, 평균 점수 x에 대하여 x * k <= i < (x+0.001) * k인 정수 i가 존재할 때, 필요한 최소 인원은 k이다.

이때 모든 k를 구하여 최소 공배수 lcd(k)를 구하면 정답이다.
*/

struct Fixed
{
    int integer;
    int fractional;

    Fixed(int inInteger, int inFractional)
        : integer(inInteger)
        , fractional(inFractional)
    {}

    void operator+=(const Fixed& rhs)
    {
        int fractionalSum = fractional + rhs.fractional;
        integer = integer + rhs.integer + fractionalSum / 1000;
        fractional = fractionalSum % 1000;
    }

    bool operator<(const Fixed& rhs) const
    {
        if (integer < rhs.integer)
            return true;
        else if (integer == rhs.integer && fractional < rhs.fractional)
            return true;
        return false;
    }

    Fixed ceil() const
    {
        int newInt = integer;
        if (fractional > 0)
            newInt++;
        return Fixed(newInt, 0);
    }

    string to_string() const
    {
        return std::to_string(integer) + "." + std::to_string(fractional);
    }
};

int FindMinimumMultiplier(double x)
{
    if (x == 0.0)
        return 1;

    int multiplied = round(x * 1000.0);
    // cout << "multiplied : " << multiplied << "="<<x << "*1000\n";
    int integer = multiplied / 1000;
    int fractional = multiplied % 1000;

    Fixed fixed(integer, fractional);
    Fixed nextFixed(integer + (fractional + 1) / 1000, (fractional + 1) % 1000);

    Fixed lowerFixed(fixed);
    Fixed upperFixed(integer, fractional);

    for (int i = 1;;i++)
    {
        if (lowerFixed.ceil() < upperFixed)
        {
            // cout << lowerFixed.to_string() << "'s ceil : " << lowerFixed.ceil().to_string() << ", upper : " << upperFixed.to_string() << "\n";
            return i;
        }

        lowerFixed += fixed;
        upperFixed += nextFixed;
    }
}

int gcd(int a, int b)
{
    int r;
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcd(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int n;
    double avg;
    vector<int> multipliers;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    // TestCase(n);
    for (int i = 0; i < n; i++)
    {
        cin >> avg;
        multipliers.push_back(FindMinimumMultiplier(avg));
        cout << i+1 << "th multiplier : " << multipliers[i] << "\n";
    }

    int allLcd = multipliers[0];
    for (int i = 1; i < n; i++)
    {
        allLcd = lcd(allLcd, multipliers[i]);
    }
    cout << allLcd << "\n";

    return 0;
}