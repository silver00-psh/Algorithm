#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	int num = 0;
	cin >> num;
	
	for (int i = 0; i < num; i++)
	{
		int n = 0;
		cin >> n;
		s.insert(n);
	}

	set<int>::iterator iter = s.begin();

	for (iter; iter != s.end(); iter++)
	{
		cout << *iter << "\n";
	}
	return 0;
}