#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int GetPokemonIndex(string input)
{
    int number = 0;
    int idx = 0;
    while (idx < input.size())
    {
        if (input[idx] >= '0' && input[idx] <= '9')
        {
            number = number * 10 + (input[idx] - '0');
            idx++;
        }
        else
            return -1;
    }
    return number;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;

    cin >> N >> M;

    vector<string> pokemonNames;
    map<string, int> pokemonNumberMap;
    string name;

    pokemonNames.push_back("");
    for (int i = 1; i <= N; i++)
    {
        cin >> name;
        pokemonNames.push_back(name);
        pokemonNumberMap[name] = i;
    }

    string question;
    for (int i = 0; i < M; i++)
    {
        cin >> question;
        int index = GetPokemonIndex(question);
        if (index == -1) // name to number
        {
            cout << pokemonNumberMap[question] << '\n';
        }
        else // number to name
        {
            cout << pokemonNames[index] << '\n';
        }
    }

    return 0;
}