#include <iostream>
#include <string>

using namespace std;

char word[1000001];
int main()
{
    int freq[26] = { 0 };
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> word;

    int i = 0;
    while (word[i])
    {
        char c = word[i++];
        if (c >= 'A' && c <= 'Z')
            freq[c - 'A']++;
        else
            freq[c - 'a']++;
    }

    char mostFrequentC;
    int maximumFrequency = 0;
    bool multipleAlphabet = false;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > maximumFrequency)
        {
            maximumFrequency = freq[i];
            mostFrequentC = i + 'A';
            multipleAlphabet = false;
        }
        else if (freq[i] == maximumFrequency)
        {
            multipleAlphabet = true;
        }
    }

    cout << (multipleAlphabet ? '?' : mostFrequentC) << "\n";

    return 0;
}