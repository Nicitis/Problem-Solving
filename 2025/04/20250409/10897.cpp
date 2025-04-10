#include <iostream>

#define MOD 1000000007

using namespace std;

int main()
{
    int d;
    long long child;
    long long prevGens = 1ll;
    long long numberOfAllGens = 1ll;
    long long numberOfAllPrevGens = 0ll;
    long long parentNumber = 1, number;
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> d;

    cin >> child;
    cout << parentNumber << "\n"; // 첫 번째 자손은 무조건 1

    for (int l = 2; l <= d; l++)
    {
        cin >> child;
        
        long long numberOfParentGen = (parentNumber - numberOfAllPrevGens - 1);
        while (numberOfParentGen < 0) numberOfParentGen += MOD;

        long long prevChildren = (numberOfParentGen * l) % MOD;
        number = (numberOfAllGens + prevChildren + child) % MOD;
        prevGens = (prevGens * l) % MOD;
        numberOfAllPrevGens = numberOfAllGens; // C((l+1)-2)
        numberOfAllGens = (numberOfAllGens + prevGens) % MOD; // C((l+1)-1)
        parentNumber = number;

        cout << number << "\n";
    }

    return 0;
}