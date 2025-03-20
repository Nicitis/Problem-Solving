#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

struct Participant
{
    string name;
    int score;
    bool isHidden;

    Participant(string inName, int inScore, bool inIsHidden)
        : name(inName)
        , score(inScore)
        , isHidden(inIsHidden)
    {}

    bool operator<(Participant& other)
    {
        if (score == other.score)
            return name < other.name;
        return score > other.score;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<Participant> participants;
    string input, token, name;
    regex e(":\"?\\b\\w+\\b\"?");

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        regex_iterator<string::iterator> rit(input.begin(), input.end(), e);
        regex_iterator<string::iterator> rend;

        token = rit->str();
        name = token.substr(2, token.size() - 3);
        ++rit;
        token = rit->str();
        int score = stoi(token.substr(1));
        ++rit;
        token = rit->str();
        bool isHidden = (bool)stoi(token.substr(1));

        participants.push_back(Participant(name, score, isHidden));
    }

    sort(participants.begin(), participants.end());

    int rank = 1;
    int prevRank = 1;
    int prevScore = -1;
    for (Participant p : participants)
    {
        int curRank = rank;

        if (p.score != prevScore)
            prevRank = rank;
        else
            curRank = prevRank;
        
        if (!p.isHidden)
            cout << curRank << " " << p.name << " " << p.score << "\n";
        prevScore = p.score;
        ++rank;
    }

    return 0;
}