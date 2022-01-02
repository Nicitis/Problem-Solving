// 백준 2875: 대회 or 인턴
#include <iostream>
#include <cmath>

using namespace std;

// 팀의 최대 수를 구하고 남은 잉여 인원을 K에서 뺀다. 그 다음에 인턴쉽을 위해 팀의 수를 줄인다.
int main()
{
    int n, m, k, team = 0;

    cin >> n >> m >> k;

    if (n > m * 2) // 여자가 남자의 두 배 이상 많으면
    {
        team = m;
        k -= n - (m * 2);
    }
    else // 남자가 여자의 절반보다 많거나 같으면
    {
        team = n / 2;
        k -= n % 2 + m - team;
    }
    if (k > 0)
        team -= (int)ceil(k / 3.0);
    
    cout << team;

    return 0;
}