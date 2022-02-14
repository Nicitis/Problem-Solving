// unique를 사용하는 예제
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<string> s;

int main()
{
	s.push_back("a");
	s.push_back("b");
	s.push_back("a");
	s.push_back("c");
	s.push_back("b");
	s.push_back("a");
	s.push_back("b");
	
	printf("막넣은 백터s\n");
	for(int i=0;i<s.size();i++)
		cout<<s[i]<<"\t";
	printf("\n\n");
	
	printf("정렬 sort(s.begin(), s.end());\n");
	sort(s.begin(), s.end());
	for(int i=0;i<s.size();i++)
		cout<<s[i]<<"\t";
	printf("\n\n");

	printf("백터.erase(unique(s.begin(),s.end()),s.end())\n");
	s.erase(unique(s.begin(),s.end()),s.end());
	for(int i=0;i<s.size();i++)
		cout<<s[i]<<"\t";
	printf("\n\n");
}