#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
    stack<int> st;
    int N, maxNum = 0, next;
    vector<char> operations;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> next;

        // 더 높은 숫자라면 계속 push
        while (next > maxNum)
        {
            maxNum++;
            st.push(maxNum);
            operations.push_back('+');
            operations.push_back('\n');
        }
        // pop을 시도하고, 값이 맞지 않으면 실패
        if (st.top() != next)
        {
            operations.clear();
            operations.push_back('N');
            operations.push_back('O');
            operations.push_back('\n');
            break;
        }
        operations.push_back('-');
        operations.push_back('\n');
        st.pop();
    }
    operations.push_back(0);
    cout << operations.data();

    return 0;
}