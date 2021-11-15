// 백준 2331: 반복수열(C++)
#include <iostream>

using namespace std;

int nextSeq[360000];
int power_p[10]; // 각 자연수(1~9)를 p번 곱한 수

void calculate_power(int multiply)
{
    int p;
    for (int i = 1; i < 10; i++)
    {
        p = multiply;
        power_p[i] = i;
        while (--p)
        {
            power_p[i] *= i;
        }
    }
}

int generate_next_number(int number, int multiply)
{
    int next = 0;
    int i;
    while (number > 0)
    {
        next += power_p[number % 10];
        number /= 10;
    }
    return next;
}

// 그래프를 만들며 중복되는 수열 번호의 시작점을 찾는다.
int find_repeated_number(int seqNum, int multiply)
{
    nextSeq[seqNum] = generate_next_number(seqNum, multiply);
    
    // 방문한 적 없을 경우 계속 진행
    if (nextSeq[nextSeq[seqNum]] == 0)
        return find_repeated_number(nextSeq[seqNum], multiply);
    // 방문했던 적이 있다면, 반복되는 첫 번째 수를 반환
    else
        return nextSeq[seqNum];
}

int get_index(int startNum, int target)
{
    int index = 1;
    int cur = startNum;
    while (cur != target)
    {
        cur = nextSeq[cur];
        index++;
    }

    return index;
}

int main()
{
    int a, p;
    ios_base::sync_with_stdio(false);

    scanf("%d %d", &a, &p);

    // n^p 계산
    calculate_power(p);

    printf("%d\n", get_index(a, find_repeated_number(a, p)) - 1);
}

// #include <cstdio>

// int power_p[10]; // 각 자연수(1~9)를 p번 곱한 수

// void calculate_power(int multiply)
// {
//     int p;
//     for (int i = 1; i < 10; i++)
//     {
//         p = multiply;
//         power_p[i] = i;
//         while (--p)
//         {
//             power_p[i] *= i;
//         }
//     }
// }

// int generate_next_number(int number, int multiply)
// {
//     int next = 0;
//     int i;
//     while (number > 0)
//     {
//         next += power_p[number % 10];
//         number /= 10;
//     }
//     return next;
// }

// int main()
// {
//     int a, p, i = 1, count = -1;
//     int d[1000] = { 0 };

//     scanf("%d %d", &a, &p);

//     calculate_power(p);

//     d[1] = a;

//     while (true)
//     {
//         d[i + 1] = generate_next_number(d[i], p);
//         i++;
//         // 중복된 수가 있을 경우 수열 생성 종료
//         for (int j = 1; j < i; j++)
//         {
//             if (d[j] == d[i])
//             {
//                 count = j - 1;
//                 break;
//             }
//         }
//         if (count != -1)
//             break;
//     }
//     printf("%d\n", count);
// }