// 백준 1011: Fly me to the Alpha Centauri
#include <iostream>

using namespace std;

int MinJump(int start, int end)
{
    int jump = 0;
    int distance = end - start;
    int speed = 0;
    int brakingDistance = 0;

    while (distance > 0)
    {
        // K + 1 거리
        if (brakingDistance + speed + 1 <= distance)
        {
            speed++;
            brakingDistance += speed;
        }
        // K - 1 거리
        else if (brakingDistance > distance && speed > 1)
        {
            brakingDistance -= speed;
            speed--;
        }
        // K 거리 (조절 없음)

        distance -= speed;
        jump++;
    }

    return jump;
}

int main()
{
    int t, x, y;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        cout << MinJump(x, y) << '\n';
    }

    return 0;
}