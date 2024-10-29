#include <iostream>
#include <unordered_set>
using namespace std;

int main() {

	int N, M = 0;
	int num = 0;
	cin >> N;
	cin >> M;

	unordered_set<string> S;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		S.insert(s);
	}

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (S.find(s) != S.end()) {
			num++;
		}
	}

	cout << num;

	return 0;
}