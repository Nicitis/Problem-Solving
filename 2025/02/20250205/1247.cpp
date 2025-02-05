#include <iostream>

#define THRESHOLD 4611686018427387904LL

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    for (int T = 0; T < 3; T++)
    {
        int N;
        std::cin >> N;

        long long division = 0;
        long long remainder = 0;
        long long next;

        for (int i = 0; i < N; i++)
        {
            std::cin >> next;
            // next의 절댓값이 THRESHOLD보다 크거나 같을 경우, division을 ++ 또는 --하고 next에서 THRESHOLD 또는 -THRESHOLD를 더함
            // 다음으로, remainder에 next를 더해주는데 만약 절댓값이 THRESHOLD보다 커지면 division에 반영
            // division, remainder가 0이면 0, division이 양수이거나 0이면서 remainder가 0 이상이면 양수, 비슷한 논리로 음수 표현
            if (next >= THRESHOLD)
            {
                next -= THRESHOLD;
                division++;
            }
            else if (next <= -THRESHOLD)
            {
                next += THRESHOLD;
                division--;
            }
            
            remainder += next;
            if (remainder >= THRESHOLD)
            {
                remainder -= THRESHOLD;
                division++;
            }
            else if (remainder <= -THRESHOLD)
            {
                remainder += THRESHOLD;
                division--;
            }
        }
        char result;
        if (division > 0 || (division == 0 && remainder > 0))
            result = '+';
        else if (division < 0 || (division == 0 && remainder < 0))
            result = '-';
        else
            result = '0';
        std::cout << result << '\n';
    }

    return 0;
}