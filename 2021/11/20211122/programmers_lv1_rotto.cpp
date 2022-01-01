// 프로그래머스 레벨 1: 로또의 최고 순위와 최저 순위
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 로또 순위를 결정하는 함수
int lotto_rank(int correct)
{
    if (correct <= 1)
        return 6;
    else
        return 7 - correct;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) 
{
    vector<int> answer(0);
    int correct = 0, zero_count = 0, constant = 0, i;

    // 일치하는 수의 개수를 센다
    for (auto& num : win_nums)
    {
        if (find(lottos.begin(), lottos.end(), num) != lottos.end())
            correct++;
    }

    // 0의 개수를 센다
    for (i = 0; i < 6; i++)
    {
        if (lottos[i] == 0)
            zero_count++;
    }

    answer.push_back(lotto_rank(correct+zero_count)); // 최고
    answer.push_back(lotto_rank(correct)); // 최저

    return answer;
}

int main()
{
    int i;
    vector<int> lottos(6, 0);
    vector<int> win_nums(6, 0);
    for (i = 0; i < 6; i++)
    {
        cin >> lottos[i];
    }
    for (i = 0; i < 6; i++)
    {
        cin >> win_nums[i];
    }
    auto ans = solution(lottos, win_nums);
    cout << ans[0] << ' ' << ans[1];
}