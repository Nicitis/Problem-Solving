// 백준 2805: 나무 자르기(C++)
#include <iostream>

#define LIMIT 1000000
#define MAXHEIGHT 1000000000LL

using namespace std;

int heightsOfTree[LIMIT];

long long GetTreeLength(int h, int n)
{
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (heightsOfTree[i] > h)
            sum += heightsOfTree[i] - h;
    }

    return sum;
}

int BinarySearch(int n, int m)
{
    int low = 0, high = MAXHEIGHT;
    int mid, answer = 0; // 정답이 되는 높이
    
    while (low <= high)
    {
        mid = (low + high) >> 1;
        if (GetTreeLength(mid, n) >= m)
        {
            answer = mid;
            low = mid + 1; // 높이를 올린다.
        }
        else
        {
            high = mid - 1;
        }
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> heightsOfTree[i];

    cout << BinarySearch(n, m) << '\n';

    return 0;
}