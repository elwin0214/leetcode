
/*

https://leetcode.com/problems/word-pattern/
Word Pattern My Submissions Question


Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

思路：
边界值较多，特殊情况多，比如："abba","dog dog dog dog"

*/
#include <vector>
#include <map>
#include <set>

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct Compare{

public:
bool operator()(const string& s1,const string& s2)
{
	return s1==s2;
}
};
class Solution {
public:
bool wordPattern(string pattern, string str) 
{
	int start=0;
	int end=0;
	vector<string> words;
	while(end<str.size())
	{
		while(str[end+1]!=' ' && end<str.size())
		{
			end++;
		}
		words.push_back(string(str,start,end-start+1));
		end=end+2;
		start=end;
	}
	if(pattern.size()!=words.size())
		return false;

	map<char,int> rmap;
	int index=0;
	set<string> rset;
	for(int index=0; index<pattern.size(); index++)
	{
		char key=pattern[index];
		map<char, int>::iterator it = rmap.find(key);
		rset.insert(words[index]);
		if(it==rmap.end())
		{
			rmap.insert(pair<char,int>(key,index));
		}
		else
		{
			if(!(words[it->second]==words[index]))return false;
		}
	}
	if(rset.size()!=rmap.size())
		return false;
	return true;
}

bool equalWiths(string &str,int i,int j)
{
	while(str[i]==str[j] && j<str.size())
	{
		if((j==str.size()-1 && str[i+1]==' '))return true;
		if(str[i]==' ')return true;
		i++;
		j++;
	}
	return false;
}
};
class A{
private:
	int value;
public:
	A(int value):value(value){
		cout<<"con A"<<endl;

	}
	A(const A &a):value(a.value){
		cout<<"copy con A"<<endl;
	}
	A& operator=(const A &a){
		if(this==&a)return *this;
		cout<<"assign con A"<<endl;
		value=a.value;
		return *this;
	}
	int getValue(){return value;}
};
int main(){
 

	// cout<<(*it->second=="ab")<<endl;
	// m.insert(pair<int,A>(1,A(2)));
	// m.insert(pair<int,A>(2,A(20)));

	// map<int,A>::iterator it=m.find(2);
	// cout<<it->second.getValue();
 
 // cout<<endl;
	//cout<<("a"=="a")<<endl;
	// cout<<(string("a")=="a")<<endl;
	// string ss="abc";
	// cout<<ss.substr(1,1);
	Solution s;
	 cout<<s.wordPattern("abba","dog cat cat dog")<<endl;
	cout<<s.wordPattern("abba","dog cat cat dog")<<endl;
	cout<<s.wordPattern("abba","dog dog dog dog")<<endl;

}