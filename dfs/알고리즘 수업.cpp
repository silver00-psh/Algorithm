#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[100001];
int cnt[100001] = { 0, };
bool visit[100001] = { false };
int cmt = 1;

void dfs(int x)
{
	visit[x] = true;
	cnt[x] = cmt++;

	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (!visit[y]) dfs(y);
	}
}

int main()
{
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	int N, M, R = 0;
	cin >> N;
	cin >> M;
	cin >> R;

	for (int i = 0; i < M; i++)
	{
		int u, v = 0;
		cin >> u;
		cin >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i < N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(R);

	for (int i = 1; i <= N; i++)
	{
		cout << cnt[i] << "\n";
	}

	return 0;
}