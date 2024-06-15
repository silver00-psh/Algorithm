#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

set<string> s;

int main()
{
	int N = 0;
	int M = 0;
	cin >> N;
	cin >> M;

	string name;
	vector<string> ans;

	for (int i = 0; i < N; i++)
	{
		cin >> name;
		s.insert(name);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> name;
		auto it = s.find(name);// name이 없으면 end()와 같은 반복자 반환
		if (it != s.end()) ans.push_back(name);
	}

	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}
	
	return 0;
}