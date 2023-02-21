// 2023.02.21., 숫자 카드 나누기, https://school.programmers.co.kr/learn/courses/30/lessons/135807

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isDividerOfOne(int a, vector<int> arrayA, vector<int> arrayB)
{
    int countA, countB, len;
    countA = countB = 0;
    len = max(arrayA.size(), arrayB.size());
    
    for (int i = 0; i < len; i++)
    {
        if (i < arrayA.size() && arrayA[i] % a == 0)
            countA++;
        if (i < arrayB.size() && arrayB[i] % a == 0)
            countB++;
        if (countA > 0 && countB > 0)
            return false;
    }
    if (countA == arrayA.size() || countB == arrayB.size())
        return true;
    else
        return false;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    // 정답 a의 범위는 0<a<max{min(arrayA), min(arrayB)}이다.
    vector<int>::iterator minA = min_element(arrayA.begin(), arrayA.end());
    vector<int>::iterator minB = min_element(arrayB.begin(), arrayB.end());
    int range = max(*minA, *minB);
    
    // 간단한 체크 함수: 1부터 N까지 반복
    for (int a = range; a >= 1; a--)
    {
        if (isDividerOfOne(a, arrayA, arrayB))
        {
            return a;
        }
    }
    
    return 0;
}

// 시간 복잡도 문제 때문에 시간이 4000ms를 넘는다. 그래서 포기. 나중에 다시 풀 예정.