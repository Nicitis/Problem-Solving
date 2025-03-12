#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, runner, sumOfRunners;
    cin >> n;

    sumOfRunners = n * (n+1) / 2;
    
    for (int i = 1; i < n; i++)
    {
        cin >> runner;
        sumOfRunners -= runner;
    }

    cout << sumOfRunners << '\n';

    return 0;
}