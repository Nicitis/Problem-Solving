#include <iostream>

using namespace std;

int main()
{
    int n, startN, length = 0;
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    startN = n;
    
    do
    {
        n = (n % 10) * 10 + (n % 10 + n / 10) % 10;
        length++;
    } while (n != startN);

    cout << length;
    
    return 0;
}