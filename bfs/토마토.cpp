#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
vector<int> store[1001];
queue<pair<int, int>> q;
bool visit[1001][1001] = { false, };
int N, M = 0;
int cnt = 0;

void bfs(int x, int y)
{
	visit[x][y] = true;
	while (!q.empty())
	{
		for (int i = 0; i < 4; i++)
		{
			int x_ = q.front().first + dx[i];
			int y_ = q.front().second + dy[i];
			if (x_ < M && y_ < N && x_ >= 0 && y_ >= 0 
				&& visit[x_][y_] == false && store[x_][y_] == 0)
			{
				q.push(make_pair(x_, y_));
				store[x_][y_] = store[q.front().first][q.front().second] + 1;
				visit[x_][y_] = true;
				continue;
			}
			else continue;
		}
		cnt = store[q.front().first][q.front().second];
		q.pop();
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int num = 0;
			cin >> num;
			store[i].push_back(num);
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (store[i][j] == 1) q.push(make_pair(i, j));
		}
	}
	bfs(q.front().first, q.front().second);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (store[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << cnt - 1;

	return 0;
}