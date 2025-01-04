#include <iostream>
#include <queue>
#include <vector>

struct compare
{
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b))
        {
            return a > b;
        }
        return abs(a) > abs(b);
    }
    
    int abs(int num)
    {
        return num >= 0 ? num : -num;
    }
};


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::priority_queue<int, std::vector<int>, compare> pq;
    std::vector<int> result;
    int n;

    std::cin >> n;

    int input;
    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        if (input == 0)
        {
            if (pq.empty())
                result.push_back(0);
                // std::cout << 0 << '\n';
            else
            {
                result.push_back(pq.top());
                // std::cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(input);
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << '\n';
    }

    return 0;
}