// 백준 1107: 리모컨
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

bool availableButtons[10];

bool IsAvailableChannel(int channel)
{
    do
    {
        if (availableButtons[channel % 10] == false)
            return false;
        channel /= 10;
    } while (channel > 0);
    return true;
}

int LengthOfChannel(int channel)
{
    int len = 0;
    do
    {
        channel /= 10; 
        len++;
    } while (channel > 0);
    return len;
}

int MinNumberOfPressing(int channel)
{
    int result = channel > 100 ? channel - 100 : 100 - channel;

    if (channel == 100)
        return 0;

    // 누를 수 있는 채널이고 채널 길이가 더 짧다면 채널 길이가 버튼을 누르는 횟수가 됨
    if (IsAvailableChannel(channel))
    {
        result = min(result, LengthOfChannel(channel));
        return result;
    }

    // 바로 누를 수 없는 채널은 최대한 가까운 채널을 먼저 누른 후 +, -로 접근한다.
    int d = 1;
    while (channel + d != 100 && channel - d != 100)
    {
        if (channel - d >= 0 && IsAvailableChannel(channel - d))
        {
            result = min(result, LengthOfChannel(channel - d) + d);
            break;
        }
        if (IsAvailableChannel(channel + d))
        {
            result = min(result, LengthOfChannel(channel + d) + d);
            break;
        }
        d++;
    }
    return result;
}

int main()
{
    int channel, m;

    cin >> channel >> m;

    memset(availableButtons, (int)true, sizeof(availableButtons));

    for (int i = 0; i < m; i++)
    {
        int button;
        cin >> button;
        availableButtons[button] = false;
    }

    cout << MinNumberOfPressing(channel);

    return 0;
}