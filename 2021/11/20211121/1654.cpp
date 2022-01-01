// 백준 1654: 랜선 자르기(C++)
#include <iostream>
#include <vector>
#include <cmath>
// #include <random> // dbg

#define MAXLEN 10000

using namespace std;

vector<long long> cableLength(MAXLEN + 1);

long long GetNumberOfCable(int length, int k)
{
    int i, number = 0; // 케이블 개수
    long long temp; 
    for (i = 1; i <= k; i++)
    {
        temp = 0LL;
        while (temp + length <= cableLength[i])
        {
            temp += length;
            number++;
        }
    }
    return number;
}

long long BinarySearch(long long min, long long max, int k, int n)
{
    long long m; 

    while (true)
    {
        m = (long long)round((min + max)/2.0);

        if (min == max)
            return m;

        if (GetNumberOfCable(m, k) >= n)
        {
            min = m;
        }
        else
        {
            max = m - 1;
        }
    }
}

int main()
{
    // random_device rd;
    // mt19937 gen(rd());
    // std::uniform_int_distribution<long long> dis(1LL, 2147483647LL);

    int k, n, i;
    long long len;
    ios_base::sync_with_stdio(false);
    cin >> k >> n;

    len = 0; // 전체 케이블 길이

    for (i = 1; i <= k; i++)
    {
        // cableLength[i] = dis(gen);
        // cout << cableLength[i] << '\n';
        cin >> cableLength[i];
        len += cableLength[i];
    }

    cout << BinarySearch(0, len/n, k, n);
}