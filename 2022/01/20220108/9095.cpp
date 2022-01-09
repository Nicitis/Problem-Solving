// 백준 9095: 1, 2, 3 더하기(by 브루트포스)
#include <iostream>

using namespace std;

int solution(int number)
{
    int result = 0;
    
    if (number < 0)
        return 0;
    if (number == 0)
        return 1;
    
    result = solution(number - 1) +
        solution(number - 2) +
        solution(number - 3);
    
    return result;
}

int main()
{
    int t, n;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << solution(n) << '\n';
    }
    return 0;
}