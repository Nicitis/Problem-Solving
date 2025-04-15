#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long x;
    vector<long long> factors, big_factors;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x;
    x++;
    factors.push_back(1LL);
    
    // get factors
    for (long long i = 2LL; i * i <= x; i++)
    {
        if (x % i == 0LL)
        {
            factors.push_back(i);
            if (i * i < x)
                big_factors.push_back(x / i);
        }
    }
    for (auto it = big_factors.rbegin(); it < big_factors.rend(); it++)
        factors.push_back(*it);

    for (long long f : factors)
    {
        cout << f << " ";
    }

    return 0;
}