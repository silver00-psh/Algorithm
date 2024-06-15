#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int num = 0;
	cin >> num;
	while (num--)
	{
		cin >> s;
		int cnt = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(') cnt++;
			else cnt--;

			if (cnt < 0)
			{
				cout << "NO" << "\n";
				break;
			}

			if (i == s.size() - 1)
			{
				if (cnt != 0)
				{
					cout << "NO" << "\n";
					break;
				}
				else
				{
					cout << "YES" << "\n";
					break;
				}
			}
		}
	}

	return 0;
}