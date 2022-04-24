#include <string>
#include <vector>
#include <cctype>
#include <set>
#include <iostream>
#include <algorithm>

#define FACTOR 65536

using namespace std;

bool IsValidElement(string element)
{
    return isalpha(element[0]) && isalpha(element[1]);
}

multiset<string> MakeMultiset(string str)
{
    multiset<string> ms;
    char char_elem[3];
    
    for (int i = 0; i < str.length() - 1; i++)
    {
        char_elem[0] = tolower(str[i]);
        char_elem[1] = tolower(str[i + 1]);
        string elem = string(char_elem);
        
        if (IsValidElement(elem))
        {
            ms.insert(elem);
        }
    }
    
    return ms;
}

int solution(string str1, string str2) {
    
    multiset<string> set1 = MakeMultiset(str1);
    multiset<string> set2 = MakeMultiset(str2);
    vector<string> intersect_set(1000);
    vector<string> union_set(2000);
    
    auto it = set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), intersect_set.begin());
    intersect_set.resize(it-intersect_set.begin());
    
    it = set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), union_set.begin());
    union_set.resize(it-union_set.begin());
    
    int similarity;
    
    if (union_set.size() == 0)
        similarity = FACTOR;
    else
        similarity = FACTOR * intersect_set.size() / union_set.size();
    
    return similarity;
}

int main()
{
    // 테스트용 함수
    string str1, str2;
    char arr1[1000], arr2[1000];
    cin.getline(arr1, 1000);
    cin.getline(arr2, 1000);
    str1 = string(arr1);
    str2 = string(arr2);
    cout << solution(str1, str2);

    return 0;
}