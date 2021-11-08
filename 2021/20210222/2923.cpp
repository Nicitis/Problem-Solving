// 3. 백준 2923 숫자 게임(https://www.acmicpc.net/problem/2923)
#include <iostream>

using namespace std;

const int CASE = 100000;
int A[CASE];
int B[CASE];

void AddAsc(int* numberPtr, int input, int length)
{
    int index = 0;
    while (index < length)
    {
        if (numberPtr[index] > input)
        {
            int prev = numberPtr[index];
            for (int curIdx = index + 1; curIdx < length; curIdx++)
            {
                int temp = numberPtr[curIdx];
                numberPtr[curIdx] = prev;
                prev = temp;
            }
            numberPtr[length] = prev;
            break;
        }
        index++;
    }
    numberPtr[index] = input;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        
        AddAsc(A, a, i); // 시간 초과남. 다음 날에 다시 풀어보자.
        AddAsc(B, b, i);

        int max = 0;
        for (int j = 0; j <= i; j++)
        {
            if (A[j] + B[i - j] > max)
                max = A[j] + B[i - j];
        }

        cout << max;
    }

    return 0;
}