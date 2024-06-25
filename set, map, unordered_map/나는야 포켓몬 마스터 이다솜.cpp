#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> ans;
unordered_map<string, string> page;
vector<string> name;

int main()
{
	int N, M = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		page.insert({ s, to_string(i) });
		name.push_back(s);
	}

	for (int i = 0; i < M; i++)
	{
		string quiz;
		cin >> quiz;
		if ((quiz.front() >= 'A' && quiz.front() <= 'Z') 
			|| (quiz.back() >= 'A' && quiz.back() <= 'Z'))
		{
			unordered_map<string, string>::iterator it = page.find(quiz);
			if ((*it).first == quiz) ans.push_back((*it).second);
		}
		else
		{
			ans.push_back(name[stoi(quiz) - 1]);
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}
	return 0;
}