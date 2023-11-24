// 백준-14889 스타트와 링크
#include <cstdio>
#include <vector>
#include <cmath>

#define MAX 987654321

using namespace std;

// 신규 멤버를 추가할 때 추가되는 능력치
int additional_power(vector<vector<int>> m, vector<int> team_indices, int new_idx)
{
    int n = team_indices.size();
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += m[team_indices[i]][new_idx] + m[new_idx][team_indices[i]];
    }
    return total;
}

// get minimal delta power
int solve(vector<vector<int>> m, int n, vector<int> team_indices, int team_power)
{
    int min_del = MAX;
    int last_idx = team_indices[team_indices.size() - 1];
    int needed_members = n / 2 - team_indices.size();

    if (needed_members == 0)
    {
        // get delta power
        vector<int> other_team;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != team_indices[cnt])
            {
                team_power -= additional_power(m, other_team, i);
                other_team.push_back(i);
            }
            else
                cnt++;
        }
        return (int)abs((double)team_power);
    }

    // 현재 n이 6이고(n/2 == 3) 뽑아야 할 인원이 한 명 남았을 때, 
    // [last_idx + 1, n - needed_members]만큼 순회
    for (int i = last_idx + 1; i <= n - needed_members; i++)
    {
        // pick
        int new_power = team_power + additional_power(m, team_indices, i);
        team_indices.push_back(i);
        int temp = solve(m, n, team_indices, new_power);
        team_indices.pop_back();
        if (temp < min_del)
            min_del = temp;
    }

    return min_del;
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<vector<int>> m(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &m[i][j]);

    vector<int> team_indices;
    int result = MAX;
    for (int i = 0; i <= n / 2; i++)
    {
        team_indices.push_back(i);
        int temp = solve(m, n, team_indices, 0);
        team_indices.pop_back();
        if (temp < result)
            result = temp;
    }
    printf("%d\n", result);

    return 0;
}