#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string GetFirstWord(string& originalWord)
{
    string result(originalWord);
    reverse(result.begin() + 2, result.end());

    for (int i = 1; i < originalWord.size() - 2; i++)
    {
        for (int j = i + 1; j < originalWord.size(); j++)
        {
            // [0, i), [i, j), [j, wordSize)로 단어를 분리
            string newWord(originalWord);
            
            std::reverse(newWord.begin(), newWord.begin() + i);
            std::reverse(newWord.begin() + i, newWord.begin() + j);
            std::reverse(newWord.begin() + j, newWord.end());

            if (newWord < result)
                result = newWord;
        }
    }
    return result;
}

int main()
{
    string originalWord;

    cin >> originalWord;

    cout << GetFirstWord(originalWord);

    return 0;
}