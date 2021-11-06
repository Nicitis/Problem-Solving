// 백준 11650: 좌표 정렬하기(C++)
// 힙 정렬에서 정렬 기준을 변경함
#include <iostream>

typedef struct _vector
{
    int x;
    int y;
} Pos;

Pos posArray[1000001];

void PrintArray(Pos arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i].x << " " << arr[i].y << '\n';
}

int compare(Pos a, Pos b)
{
    if (a.x > b.x)
        return 1;
    else if (a.x < b.x)
        return -1;
    else if (a.y > b.y)
        return 1;
    else if (a.y < b.y)
        return -1;
    else
        return 0;
}

void swap(Pos* a, Pos* b)
{
    Pos temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Pos arr[], int index, int size)
{
    int max, left, right;
    left = index * 2 + 1;
    right = index * 2 + 2;

    if (left >= size)
        return;

    if (right >= size)
        max = left;
    else if (compare(arr[left], arr[right]) >= 0)
        max = left;
    else
        max = right;

    if (compare(arr[max], arr[index]) > 0)
    {
        swap(&arr[max], &arr[index]);
        heapify(arr, max, size);
    }
}

void heapsort(Pos arr[], int size)
{
    for (int i = (size - 1) / 2; i >= 0; i--)
        heapify(arr, i, size);
    
    while (size > 1)
    {
        // swap
        swap(&arr[0], &arr[--size]);
        // heapify
        heapify(arr, 0, size);
    }
}

int main()
{
    int len;
    std::ios_base::sync_with_stdio(false);
    std::cin >> len;

    for (int i = 0; i < len; i++)
    {
        Pos pos;
        std::cin >> pos.x >> pos.y;
        posArray[i] = pos;
    }

    heapsort(posArray, len);

    PrintArray(posArray, len);
}