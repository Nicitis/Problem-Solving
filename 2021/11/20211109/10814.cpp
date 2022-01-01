// 백준 10814: 나이순 정렬(C++)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct PERSON_DATA
{
    string name;
    int old;
} PData;

bool ComparePeople(PData left, PData right)
{
    return left.old < right.old;
}

void PrintPeopleData(vector<PData> people)
{
    for (auto p : people) 
        cout << p.old << " " << p.name << '\n';
}

int main()
{
    int n;
    vector<PData> people;

    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        PData newPerson;
        cin >> newPerson.old >> newPerson.name;
        people.push_back(newPerson);
    }
    
    stable_sort(people.begin(), people.end(), ComparePeople);

    PrintPeopleData(people);
}