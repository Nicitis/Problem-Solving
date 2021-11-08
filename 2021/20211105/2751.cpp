// 백준 2751: 수 정렬하기 2(C++)
// 힙(max-heap) 정렬
// size를 하나씩 줄여가며 heapify를 시도한다.
// heapify가 끝난 다음에는 첫 번째 수를 마지막 수와 swap한다.
// size=1이 될 때까지 반복
// 첫 번째에 heap을 만든 이후에는, 이미 정렬되어 있으므로 
// 루트를 빼더라도 한 번의 heapify만으로 heap을 만들 수 있다.
#include <iostream>

int N[1000001];

void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << '\n';
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int index, int size)
{
    int max, left, right;
    left = index * 2 + 1;
    right = index * 2 + 2;

    if (left >= size)
        return;

    if (right >= size)
        max = left;
    else if (arr[left] >= arr[right])
        max = left;
    else
        max = right;

    if (arr[max] > arr[index])
    {
        swap(&arr[max], &arr[index]);
        heapify(arr, max, size);
    }
}

void heapsort(int arr[], int size)
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
        std::cin >> N[i];

    heapsort(N, len);

    PrintArray(N, len);
}