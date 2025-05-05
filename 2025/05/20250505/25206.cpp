#include <iostream>
#include <cmath>

using namespace std;

double GradeStrToScore(string& gradeStr)
{
    double score;
    switch(gradeStr[0])
    {
        case 'A':
            score = 4.0;
            break;
        case 'B':
            score = 3.0;
            break;
        case 'C':
            score = 2.0;
            break;
        case 'D':
            score = 1.0;
            break;
        case 'F':
            return 0.0;
        case 'P':
            return -1.0;
    }

    if (gradeStr[1] == '+')
        score += 0.5;

    return score;
}

int main()
{
    string nameStr, classNumberStr, gradeStr;

    double totalScore = 0;
    int totalClassNumber = 0;

    for (int i = 0; i < 20; i++)
    {
        cin >> nameStr >> classNumberStr >> gradeStr;

        int classNumber = classNumberStr[0] - '0';
        double score = GradeStrToScore(gradeStr);
        if (score < 0.0)
            continue;
        totalClassNumber += classNumber;
        totalScore += classNumber * score;
    }

    cout << totalScore / totalClassNumber;

    return 0;
}