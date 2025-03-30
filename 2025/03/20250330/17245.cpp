#include <iostream>
#include <map>
#include <cmath>

using namespace std;

/*
매 칸 쌓인 컴퓨터의 개수 합: maximum = 1000 * 1000 * 10,000,000
=10^(3+3+7)=10^13
칸의 수: 1000*1000=1,000,000
합 구하기: O(n^2)
최대 가능한 시간 복잡도: n^2=1,000,000, n^3=1,000,000,000, 
n^2logn 정도가 한계다

n^2의 자료가 정렬되어야 하고, 순서대로 탐색해야 하며, 각 자료별로 개수가 여러 개 존재

map[1,000,000] 쓰기

1. map 기록하기: map[H]=높이가 H인 컴퓨터의 수
2. 전체 컴퓨터 수 세기
3. (현재 높이)-(이전 높이 H)만큼 높이를 채워보고, 절반을 넘으면 종료
4. 그렇지 않다면 현재 남은 컴퓨터 수를 map[현재 높이 H]만큼 빼고, 이전 높이를 현재 높이 H로 바꾼다.

그런데 (현재 높이 - 이전 높이)가 2 이상이라면, 한 칸씩 올려가면서 절반을 넘엇는지 검사해줘야 한다
예를 들어 현재 컴퓨터 수가 currentComputers이고 목표가 halfOfComputers라면
halfOfComputers - currentComputers < (currentH - prevH) * cells일 땐
prevH < newH < currentH에 대하여 
halfOfComputers - currentComputers < (newH - prevH) * cells인
가장 작은 정수 newH를 찾아야 한다.

*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, answer, coms, remainedCells;
    map<int, int> heightMap;
    long long totalComputers = 0LL, halfOfComputers, currentComputers, currentHeight;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> coms;
            totalComputers += coms;
            heightMap[coms] += 1;
        }
    }

    remainedCells = n*n - heightMap[0];
    halfOfComputers = (long long)(ceil(totalComputers / 2.0));
    currentHeight = 0LL;
    currentComputers = 0LL;
    answer = 0;

    // cout << "Half of computers/All computers = " << halfOfComputers << "/" << totalComputers << "\n";

    for (auto p : heightMap)
    {
        long long h = p.first;
        int cells = p.second;

        if (h == 0)
            continue;

        long long increase = remainedCells * (h - currentHeight);
        if (currentComputers >= halfOfComputers)
            break;
        else if (halfOfComputers - currentComputers >= increase)
        {
            currentComputers += remainedCells * (h - currentHeight);
            // cout << "currentComputers += " << remainedCells 
            //     << "*(" << h << "-" << currentHeight << ")->" 
            //     << currentComputers << "\n";
            remainedCells -= cells;
            answer += h - currentHeight;
            currentHeight = h;
        }
        else // 다음 컴퓨터 높이가 되기 전에 절반을 넘길 경우, 한 칸씩 올려본다
        {
            for (int i = currentHeight; i < h; i++)
            {
                currentComputers += remainedCells;
                answer++;
                if (currentComputers >= halfOfComputers)
                    break;
            }
            break;
        }
    }

    cout << answer << "\n";

    return 0;
}