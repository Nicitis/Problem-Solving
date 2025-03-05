#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool DoesLied(vector<int>& inputs, vector<string>& answers)
{
    int dest = inputs[inputs.size() - 1];
    for (int i = 0; i < inputs.size() - 1; i++)
    {
        if ((inputs[i] >= dest && answers[i].compare("too low") == 0) ||
        (inputs[i] <= dest && answers[i].compare("too high") == 0))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> inputs;
    vector<string> answers;

    int input;
    string answer;

    while (true)
    {
        cin >> input;

        if (input == 0)
            break;

        cin.ignore();
        getline(cin, answer);

        inputs.push_back(input);
        answers.push_back(answer);

        if (answer.compare("right on") == 0)
        {
            bool result = DoesLied(inputs, answers);

            cout << (result ? "Stan is dishonest\n" : "Stan may be honest\n");

            inputs.clear();
            answers.clear();
            continue;
        }
    }

    return 0;
}