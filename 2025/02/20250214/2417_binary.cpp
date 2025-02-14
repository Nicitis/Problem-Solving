#include <iostream>
#include <climits>

using namespace std;

long long binary(long long sqrN)
{
    long long min = 0LL;
    long long max = 3037000499LL;
    long long mid;

    long long q = max + 1;
    do
    {
        mid = (min + max) / 2LL;
        
        long long sqrMid = mid * mid;
        if (sqrMid >= sqrN)
        {
            q = mid;
            max = mid - 1;
            if (sqrMid == sqrN)
                break;
        }
        else
            min = mid + 1LL;
    } while (min <= max);
    
    return q;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    cout << binary(n);

    return 0;
}