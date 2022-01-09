// 순열 구현하기
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Permutation(vector<int>& list, int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i < end; i++)
        {
            cout << list[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i < end; i++)
    {
        swap(list[start], list[i]);
        Permutation(list, start + 1, end);
        swap(list[start], list[i]);
    }
}

// next permutation은 현재보다 더 큰 순열을 찾아 만드는 방식.

int main()
{
    vector<int> v({1, 2, 3, 4});

    Permutation(v, 0, v.size());
    
    return 0;
}