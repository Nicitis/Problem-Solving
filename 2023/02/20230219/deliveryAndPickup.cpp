#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    long long nextPos = n - 1;
    
    while (nextPos >= 0)
    {
        // 집을 방문하여 수거
        // 1. 택배 배송
        int capDelivery, capPickup;
        long long x = nextPos;
        capDelivery = capPickup = cap;
        while (capDelivery > 0 && x >= 0)
        {
            if (deliveries[x] > capDelivery)
            {
                deliveries[x] -= capDelivery;
                capDelivery = 0;
            }
            else
            {
                capDelivery -= deliveries[x];
                deliveries[x] = 0;
                x--;
            }
        }
        // 2. 재활용 택배 상자 수거
        x = nextPos;
        while (capPickup > 0 && x >= 0)
        {
            if (pickups[x] > capPickup)
            {
                pickups[x] -= capPickup;
                capPickup = 0;
            }
            else
            {
                capPickup -= pickups[x];
                pickups[x] = 0;
                x--;
            }
        }
        answer += (nextPos + 1) * 2;
        // 다음 위치를 갱신
        while (nextPos > -1 && deliveries[nextPos] == 0 && pickups[nextPos] == 0)
            nextPos--;
    }
    
    return answer;
}

int main()
{
    int cap, n;
    vector<int> deliveries = {1,0,2,0,1,0,2};
    vector<int> pickups = {0,2,0,1,0,2,0};

    cap = 2; n = 7;

    cout << solution(cap, n, deliveries, pickups) << endl;

    return 0;
}