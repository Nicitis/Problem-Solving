#include <iostream>

using namespace std;

int main()
{
    int sum, diff;
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> sum >> diff;
    
    int a = (sum + diff) / 2;
    int b = (sum - diff) / 2;

    // 축구 점수가 조건을 만족해야 한다.
    if (a < 0 || b < 0 || a < b || a + b != sum || ((a - b != diff) && (b - a != diff)))
        cout << "-1";
    else
        cout << a << " " << b;
    
    return 0;
}