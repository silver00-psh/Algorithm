#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	set<string> S;

	for (int i = 0; i < s.size(); i++)
	{
		string ans = "";
		for (int j = i; j < s.size(); ++j)
		{
			ans.push_back(s[j]);
			S.insert(ans);
		}
	}

	cout << S.size();

	return 0;
}