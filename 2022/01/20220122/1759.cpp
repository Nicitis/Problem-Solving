// 백준 1759: 암호 만들기
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char alpha[15];

bool IsVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool EligiblePassword(string password)
{
    int consonant, vowel = 0;

    for (int i = 0; i < password.length(); i++)
    {
        if (IsVowel(password[i]))
            vowel++;
    }
    consonant = password.length() - vowel;

    return vowel >= 1 && consonant >= 2;
}

void PrintPasswords(int l, int c, int curIdx, int remainedChar, string password)
{
    if (remainedChar == 0)
    {
        if (EligiblePassword(password))
            cout << password << '\n';
        return;
    }

    for (int i = curIdx; i <= c - remainedChar; i++)
    {
        PrintPasswords(l, c, i + 1, remainedChar - 1, password + alpha[i]);
    }
}

int main()
{
    int l, c;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> l >> c;

    for (int i = 0; i < c; i++)
        cin >> alpha[i];

    sort(alpha, alpha + c);

    PrintPasswords(l, c, 0, l, "");

    return 0;
}