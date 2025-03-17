#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int answer = n / 5;
    int weight = (n / 5) * 5;

    if (n == 4 || n == 7)
    {
        cout << -1;
        return 0;
    }
    
    while (weight != n)
    {
        if (weight > n)
        {
            weight -= 5;
            answer--;
        }
        while (weight < n)
        {
            weight += 3;
            answer++;
        }
    }
    cout << answer;
    return 0;
}