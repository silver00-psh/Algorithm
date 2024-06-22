#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int> a;
set<int> b;
vector<int> v;

int main()
{
	int num = 0;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int N = 0;
		cin >> N;
		a.insert(N);
	}
	int num1 = 0;
	cin >> num1;
	for (int i = 0; i < num1; i++)
	{
		int M = 0;
		cin >> M;
		auto it = a.find(M);
		if (it != a.end()) v.push_back(1);
		else v.push_back(0);
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
	return 0;
}