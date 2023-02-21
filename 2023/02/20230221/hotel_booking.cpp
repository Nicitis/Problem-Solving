// 20230221, 호텔 대실, https://school.programmers.co.kr/learn/courses/30/lessons/155651
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 문자열 "15:00"와 같이 주어진 시간을 숫자 1500으로 변환해준다.
int TimeToNumber(string time)
{
    int number = 0;
    for (int i = 0; i < 5; i++)
    {
        if (i == 2)
            continue;
        number = number * 10 + (time[i] - '0');
    }
    return number;
}

// 정수로 주어진 시간에 주어진 시간을 더한다(해당 문제에서는 N분).
int AddMinute(int iTime, int add)
{
    iTime += add;
    if (iTime % 100 > 60)
        iTime = iTime + 100 - 60; // 시간을 1시간 추가하고 60분을 뺀다.
    return iTime;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    // 입실시간 배열과 퇴실시간 배열을 만든다.
    vector<int> arrivingTimes;
    vector<int> leavingTimes;
    
    for (int i = 0; i < book_time.size(); i++)
    {
        arrivingTimes.push_back(TimeToNumber(book_time[i][0]));
        leavingTimes.push_back(TimeToNumber(book_time[i][1]));
    }
    stable_sort(arrivingTimes.begin(), arrivingTimes.end());
    stable_sort(leavingTimes.begin(), leavingTimes.end());
    
    // 입실시간이 될 때마다 퇴실시간 배열을 보고 이미 퇴실한 방을 대상으로 청소를 하고 방을 비운다.
    // 최대로 동시에 사용하는 방의 개수가 필요한 방의 개수 answer가 된다.
    int count = 0;
    int endBookIndex = 0;
    for (int i = 0; i < arrivingTimes.size(); i++)
    {
        while (endBookIndex < leavingTimes.size() && 
               arrivingTimes[i] >= AddMinute(leavingTimes[endBookIndex], 10)) // 입실 이전에 퇴실 후 청소까지 끝난 방이 있다면
        {
            endBookIndex++;
            count--;
        }
        count++;
        if (answer < count)
            answer = count;
    }
    return answer;
}