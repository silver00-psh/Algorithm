#include <iostream>
#include <string>
#include <set>
using namespace std;

struct compare
{
	bool operator() (const string &a, const string &b) const
	{
		if (a.size() == b.size()) return a < b;
		else
			return a.size() < b.size();
	}
};

int main()
{
	int num = 0;
	cin >> num;
	set<string, compare> s;

	for (int i = 0; i < num; i++)
	{
		string s1;
		cin >> s1;
		s.insert(s1);
	}

	set<string>::iterator iter = s.begin();

	for (iter; iter != s.end(); iter++)
	{
		cout << *iter << "\n";
	}
	return 0;
}