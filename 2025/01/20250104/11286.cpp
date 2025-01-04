#include <cstdio>
#include <vector>

using namespace std;

vector<int> heap;

int abs(int num)
{
    return num >= 0 ? num : -num;
}

// -1이면 a, 1이면 b가 작음
int compare(int a, int b)
{
    if (abs(a) == abs(b))
    {
        if (a == b) return 0;
        else return a < b ? -1 : 1;
    }
    return abs(a) < abs(b) ? -1 : 1;
}

int HeapPop()
{
    int top = heap[1];
    int idx = 1;
    int child = idx * 2;
    
    heap[1] = heap[heap.size() - 1];
    heap.pop_back();

    while (child < heap.size())
    {
        if (child + 1 < heap.size() && compare(heap[child], heap[child + 1]) > 0)
            child = child + 1;
        if (compare(heap[idx], heap[child]) < 0)
            break;
        
        int temp = heap[idx];
        heap[idx] = heap[child];
        heap[child] = temp;

        idx = child;
        child = idx * 2;
    }

    return top;
}

void HeapPush(int n)
{
    int idx = heap.size();
    int temp;

    heap.push_back(n);

    while (idx > 1)
    {
        if (compare(heap[idx / 2], heap[idx]) < 0)
            return;
        temp = heap[idx / 2];
        heap[idx / 2] = heap[idx];
        heap[idx] = temp;
        idx /= 2;
    }
}

void print_heap()
{
    for (int i = 0; i < heap.size(); i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main()
{
    int n, input;

    scanf("%d", &n);

    heap.push_back(0); // padding

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);

        if (input == 0)
        {
            if (heap.size() <= 1)
                printf("%d\n", 0);
            else
                printf("%d\n", HeapPop());
        }
        else
        {
            HeapPush(input);
        }
    }

    return 0;
}