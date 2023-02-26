// 2023.02.23., 숫자 카드 나누기, https://school.programmers.co.kr/learn/courses/30/lessons/135807

#include <vector>
#include <algorithm>

using namespace std;

// a와 b의 최대공약수를 구한다.
int getGCD(int a, int b)
{
    if (b > a)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    while (b != 0)
    {
        int n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int arrayGCD(vector<int> array)
{
    int gcd = array[0];
    for (int i = 1; i < array.size(); i++)
    {
        gcd = getGCD(gcd, array[i]);
    }
    return gcd;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    // 한쪽의 gcd가 다른쪽을 모두 나눌 수 없다면 이는 조건을 만족하는 a이다.
    int answer, gcd, maxA, maxB;
    gcd = arrayGCD(arrayA);
    for (int i = 0; i < arrayB.size(); i++)
    {
        if (arrayB[i] % gcd == 0)
        {
            gcd = 0;
            break;
        }
    }
    maxA = gcd;
    
    gcd = arrayGCD(arrayB);
    for (int i = 0; i < arrayA.size(); i++)
    {
        if (arrayA[i] % gcd == 0)
        {
            gcd = 0;
            break;
        }
    }
    maxB = gcd;
    answer = max(maxA, maxB);
    
    return answer;
}