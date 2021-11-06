// 백준 11651: 좌표 정렬하기 2(C++)
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

bool compare(std::pair<int, int> pos1, std::pair<int, int> pos2)
{
    if (pos1.second != pos2.second)
        return pos1.second < pos2.second;
    else if (pos1.second == pos2.second)
        return pos1.first < pos2.first;
}

int main()
{
    int n;
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;

    std::vector<std::pair<int, int>> pos(n);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> pos[i].first >> pos[i].second;
    }

    std::sort(pos.begin(), pos.end(), compare);

    for (int i = 0; i < n; i++)
        std::cout << pos[i].first << ' ' << pos[i].second << '\n';
}