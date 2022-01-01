// 백준 2667: 단지번호붙이기(C++)
// dfs를 돌며 같은 단지 내의 집의 수를 계산하고, 이를 오름차순으로 정렬
#include <cstdio>
#include <vector>
#include <algorithm>

char map[25][25];
bool visit[25][25];

// 동서남북에 대한 좌표 delta 값
int dx_arr[] = { 0, -1, 1, 0 };
int dy_arr[] = { -1, 0, 0, 1 };

bool is_available_house(int x, int y)
{
    return !visit[y][x] && map[y][x] == 1;
}

int get_number_of_house(int x, int y, int n)
{
    int number = 1, i, dx, dy;
    visit[y][x] = true;

    // 단지를 방문하며 단지 크기를 조사한다.
    for(i = 0; i < 4; i++)
    {
        dx = dx_arr[i];
        dy = dy_arr[i];
        if (x + dx < 0 || 
            x + dx >= n||
            y + dy < 0 ||
            y + dy >= n)
            continue;
            
        if (is_available_house(x + dx, y + dy))
            number += get_number_of_house(x + dx, y + dy, n);
    }
    return number;
}

int main()
{
    int n, x, y;
    std::vector<int> numbers_of_houses(0);

    // 아파트 지도 생성
    scanf("%d", &n);

    getchar();

    for (y = 0; y < n; y++)
    {
        for (x = 0; x < n; x++)
        {
            map[y][x] = getchar() - '0';
        }
        getchar(); // skip '\n'
    }

    // 단지별 집 수 구하기
    for (y = 0; y < n; y++)
    {
        for (x = 0; x < n; x++)
        {
            // 확인하지 않은 집이 있다면, 단지 내 집의 수를 구한다
            if (is_available_house(x, y))
                numbers_of_houses.push_back(get_number_of_house(x, y, n));
        }
    }

    std::sort(numbers_of_houses.begin(), numbers_of_houses.end());

    printf("%llu\n", numbers_of_houses.size());

    for (int number : numbers_of_houses)
    {
        printf("%d\n", number);
    }
}