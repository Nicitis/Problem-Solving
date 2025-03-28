#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

/*
1. 방을 교환한다
2. 학생별 점수를 재갱신
3. 1번과 A번 사이의 Gap 확인
*/

int roomStdNum[101]; // 방별로 소유 학생의 학번을 기록록
int score[101];      // 학번별 학점
int n, a, b, m;

bool HasToSwap(int scoreGood, int scoreBad)
{
    if (scoreGood >= 0 && scoreBad >= 0)
    {
        return scoreGood + 2 <= scoreBad;
    }
    else if (scoreGood >= 0 && scoreBad < 0)
    {
        return false;
    }
    else if (scoreGood < 0 && scoreBad >= 0)
    {
        return true;
    }
    else
    {
        return scoreGood + 4 <= scoreBad;
    }
}

bool SwapRoomsAndCheckGap()
{
    int posStdNum1, posStdNumA, temp;

    // 1. 방 교환 및 점수 갱신
    for (int i = 1; i < n; i++)
    {
        if (HasToSwap(score[roomStdNum[i]], score[roomStdNum[i + 1]]))
        {
            // cout << "swap pos " << i << "(stdnum: " << roomStdNum[i] << ")"
            //     ", and pos " << i + 1<< "(stdnum: " << roomStdNum[i + 1] << ")" << "\n";
            score[roomStdNum[i]] += 2;
            score[roomStdNum[i + 1]] -= 2;

            temp = roomStdNum[i];
            roomStdNum[i] = roomStdNum[i + 1];
            roomStdNum[i + 1] = temp;
        }
    }

    // // print state
    // cout << "Room: ";
    // for (int i = 1; i <= n; i++)
    //     cout << roomStdNum[i] << " ";
    // cout << "\n";

    // 2. 위치 확인
    for (int i = 1; i <= n; i++)
    {
        if (roomStdNum[i] == 1)
        {
            posStdNum1 = i;
        }
        else if (roomStdNum[i] == a)
        {
            posStdNumA = i;
        }
    }

    // cout << "pos 1 = " << posStdNum1 << ", pos a = " << posStdNumA << "\n";

    // 3. gap 확인
    return abs(posStdNum1 - posStdNumA) <= b;
}

int main()
{
    int maxStreak = 0, streak = 0, goodDays = 0,temp;

    cin >> n >> a >> b >> m;

    // first week
    memset(score, 0, sizeof(score));
    for (int i = 1; i <= n; i++)
        roomStdNum[i] = i;

    for (int i = 1; i <= m; i++)
    {
        // cout << "print score: ";
        // for (int j = 1; j <= n; j++)
        //     cout << score[j] << " ";
        // cout <<"\n";
        
        if (SwapRoomsAndCheckGap())
        {
            goodDays++;
            streak++;
        }
        else
        {
            streak = 0;
        }
        
        maxStreak = max(maxStreak, streak);

        // last week
        if (i == m)
            break;

        for (int num = 1; num <= n; num++)
            cin >> score[num];
        for (int num = 1; num <= n; num++)
        {
            cin >> temp;
            score[num] -= temp;
        }
    }

    cout << goodDays << " " << maxStreak << "\n";

    return 0;
}