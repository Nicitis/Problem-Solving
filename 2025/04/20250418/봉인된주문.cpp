#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#include <iostream>

using namespace std;

long long llPow(long long x, long long p)
{
    if (x == 0)
        return 0;
    if (p == 0)
        return 1;
    
    if (p % 2 == 0)
    {
        long long ans = llPow(x, p / 2);
        return ans * ans;
    }
    else
    {
        return llPow(x, p - 1) * x;
    }
}

long long numberOfScrollByLength(int length)
{
    return 26LL * (llPow(26, length)-1) / 25;
}

long long getScrollId(string& scroll)
{
    int length = scroll.size();
    long long id = numberOfScrollByLength(length - 1) + 1;
    long long mult = 1;
    for (int i = length - 1; i >= 0; i--, mult *= 26)
    {
        id += (scroll[i]-'a')*mult;
    }
    return id;
}

string getScrollById(long long id)
{
    string scroll = "";
    int length;
    for (int i = 0; i <= 11; i++)
    {
        long long numberOfScrolls = numberOfScrollByLength(i);
        if (id <= numberOfScrolls)
        {
            length = i - 1;
            id -= numberOfScrolls;
            break;
        }
    }
    long long div = 1;
    for (int i = length - 1; i >= 0; i--, div *= 26)
    {
        char c = (id / div) % 26 + 'a';
        scroll = c + scroll;
    }
    return scroll;
}

string solution(long long n, vector<string> bans) {
    string answer;
    
    vector<long long> ban_ids;
    
    // 1. 각 bans에 대한 주문 번호를 구한다.
    for (string ban : bans)
    {
        ban_ids.push_back(getScrollId(ban));
    }
    
    // 2. 오름차순 정렬하여, 금지된 주문 번호가 n 이하라면 n을 증가시킨다.
    sort(ban_ids.begin(), ban_ids.end());
    for (long long id : ban_ids)
    {
        if (n >= id)
            n++;
    }
    
    // 3. n에 해당하는 주문을 구한다.
    answer = getScrollById(n);
    
    return answer;
}

int main()
{
    string str;
    cin >> str;

    cout << getScrollId(str);

    return 0;
}