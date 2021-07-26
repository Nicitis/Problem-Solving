#include <cstdio>
#include <vector>

using namespace std;

// int main(void)
// {
//     int N, maxLength = 0;

//     scanf("%d", &N);

//     vector<pair<int, int>> pairs(N + 1, make_pair(0, 0));
    
//     for (int i = 1; i <= N; i++)
//     {
//         scanf("%d", &pairs[i].first);
//     }

//     // 계산
//     for (int i = N; i >= 1; i--)
//     {
//         int tempMax = 0;
//         for (int j = i; j <= N; j++)
//         {
//             if (pairs[i].first < pairs[j].first &&
//                 tempMax < pairs[j].second)
//                 tempMax = pairs[j].second;
//         }
//         pairs[i].second = tempMax + 1;
//         if (maxLength < pairs[i].second)
//             maxLength = pairs[i].second;
//     }

//     printf("%d", maxLength);
// }

// 또다른 방법
// 앞에서부터 계산한다. 하나의 수를 추가할 때마다 앞에 있는 모든 dp를 검사하며, 자신보다 작은 수에 대한 dp 중 (가장 dp가 큰 값 + 1)을 dp로 계산한다.
int main(void)
{
    int N, maxLength = 0;

    scanf("%d", &N);

    vector<pair<int, int>> pairs(N + 1, make_pair(0, 0));
    
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &pairs[i].first);
    }

    // 계산
    for (int i = 1; i <= N; i++)
    {
        pairs[i].second = 1;
        for (int j = 1; j < i; j++)
        {
            if (pairs[j].first < pairs[i].first &&
                pairs[j].second == pairs[i].second)
                pairs[i].second++;
        }
        if (maxLength < pairs[i].second)
            maxLength = pairs[i].second;
    }

    printf("%d", maxLength);
}