#include <string>
#include <vector>
#include <iostream>

using namespace std;

int CompressedLength(int slice, int patternCount)
{
    int length = slice;
    if (patternCount > 1) // 패턴 길이가 두 자리 이상일 경우엔 글자 두 개가 필요하다.
        length += to_string(patternCount).length();
    return length;
}

/*
1. 정해진 길이 N에서 패턴을 추출한다.
2. 해당 패턴이 몇 번 반복되는지 확인하고 압축된 문자열의 길이를 tempLength에 기록한다.
3. 위 과정을 반복하여 전체 문자열의 압축 길이를 구한다.
4. 단, 문자열의 길이보다 압축된 길이가 커지면 시도를 중단한다.
5. 길이를 1부터 (문자열의 길이 - 1)까지 반복하여 가장 짧은 압축 길이(기본: 문자열의 길이)를 구한다.
*/

int solution(string s) {
    int answer = s.length();
    
    if (s.length() == 1)
        return 1;
    
    for (int slice = 1; slice <= s.length() / 2 + s.length() % 2; slice++)
    {
        int compressed = 0; // 압축 길이
            
        string currentPattern = s.substr(0, slice);
        int index = slice;
        int patternCount = 1;
        
        while (index < s.length())
        {
            string nextPattern = s.substr(index, slice);
            // 패턴을 구한다.
            if (currentPattern == nextPattern)
            {
                patternCount++;
            }
            else
            {
                compressed += CompressedLength(slice, patternCount);
                currentPattern = nextPattern;
                patternCount = 1;
            }
            
            index += slice;
            if (index >= s.length()) // 끝났을 경우
            {
                if (index == s.length())
                {
                    compressed += CompressedLength(slice, patternCount);
                }
                else
                {
                    compressed += s.length() % slice; // 나머지
                }
            }
        }
        answer = min(answer, compressed);
    }
    
    return answer;
}