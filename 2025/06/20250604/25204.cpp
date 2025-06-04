/*
X가 Y의 접두사 -> X<Y (X가 앞섬)
즉, min(x.size(), y.size())까지 두 문자열이 동일
할 경우, 길이가 짧은 쪽이 앞섬.

X와 Y가 달라지는 부분이 i번째 문자 -> 그 경우,
1. 하나만 - -> Xi == -이면 Y<X
2. 둘다 알파벳: 알파벳 순서대로. 
단, 대문자는 소문자보다 앞섬(애초에 대문자가 소문자보다
ascii 코드 값이 낮으므로, 글자 순서대로 하면 된다.

별 다른 제약이 없으므로, 정렬은 단순히 sort를 사용하도록 한다.

이때 문제가 생긴 것은 두 개 문자의 사전순 비교를 할 때였다.
단순히 ascii 코드 값을 비교하는 게 사전순 비교가 아니라, 소문자와 대문자
를 비교할 땐 a가 B보다 앞서도록 해야 했다. 왜냐하면 '알파벳 순서를 따른다'
라고 명시하고 있기 때문이다. ascii 상으로는 B<a이지만, 알파벳으로는
a<b(B)이기 때문. 따라서 비교를 할 때 소문자로 바꾸어서 처리하도록 했다.

이때 무슨 함수를 써야 할지 기억이 나질 않았는데,
<cctype>의 toupper(int), tolower(int)를 사용하면 된다고 한다. 다음부터
잘 활용해보자.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

char lower(const char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    else
        return c;
}

bool compare(const string& a, const string& b)
{
    int size = min(a.size(), b.size());

    for (int i = 0; i < size; i++)
    {
        if (a[i] != b[i])
        {
            if (a[i] == '-')
                return false;
            else if (b[i] == '-')
                return true;
            // 같은 알파벳일 때
            else if (lower(a[i]) == lower(b[i]))
                return a[i] < b[i];
            // 다른 알파벳일 때(사전순(소문자 기준))
            else
                return lower(a[i]) < lower(b[i]);
        }
    }
    return a.size() < b.size();
}

int main()
{
    int t;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<string> strArr;
        string str;
        strArr.clear();
        strArr.reserve(n);

        for (int i = 0; i < n; i++)
        {
            cin >> str;
            strArr.push_back(str);
        }

        sort(strArr.begin(), strArr.end(), compare);

        for (const string& str : strArr)
            cout << str << "\n";
    }

    return 0;
}