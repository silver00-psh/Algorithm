#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[1001];
bool visit[1001] = { false, };
queue<int> q;
int cnt = 0;
int N, M = 0;

void bfs(int x)
{
	visit[x] = true;
	q.push(x);
	while (!q.empty())
	{
		int y = q.front();
		for (int i = 0; i < graph[y].size(); i++)
		{
			if (!visit[graph[y][i]])
			{
				q.push(graph[y][i]);
				visit[graph[y][i]] = true;
			}
			else continue;
		}
		q.pop();

		if (q.empty())
		{
			cnt++;
			for (int i = 1; i <= N; i++)
			{
				if (!visit[i]) bfs(i);
			}
		}
	}
}

int main()
{
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int u, v = 0;
		cin >> u;
		cin >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	bfs(1);
	cout << cnt << endl;

	return 0;
}