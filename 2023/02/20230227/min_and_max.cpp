// 2023.02.27., 최댓값과 최솟값, https://school.programmers.co.kr/learn/courses/30/lessons/12939
#include <string>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;

string solution(string s) {
    string answer = "";
    char delimeter = ' ';
    int num;
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    
    istringstream iss(s);
    string buffer;
    
    while (getline(iss, buffer, delimeter))
    {
        num = stoi(buffer);
        minimum = num < minimum ? num : minimum;
        maximum = num > maximum ? num : maximum;
    }
    
    answer = to_string(minimum) + " " + to_string(maximum);
    
    return answer;
}