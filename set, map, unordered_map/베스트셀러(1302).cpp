#include <iostream>
#include <map>
using namespace std;

int main() {

	int N = 0;
	cin >> N;
	map<string, int> S;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (S.find(s) != S.end()) {
			S[s]++;
		}
		else {
			S[s] = 1;
		}
	}
	int max = 0;
	string res;
	for (auto& i : S)
		if (i.second > max)
			res = i.first, max = i.second;

	cout << res;
	return 0;
}