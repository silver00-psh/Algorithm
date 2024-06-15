#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int num = 0;
vector<char> sector[101] = {};
queue<pair<int, int>> q;
bool visit[101][101] = { false, };
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs(int x, int y)
{
	visit[x][y] = true;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		int fir = q.front().first;
		int sec = q.front().second;

		for (int i = 0; i < 4; i++)
		{
			int new_fir = fir + dx[i];
			int new_sec = sec + dy[i];
			if (new_fir < num && new_fir >= 0 && new_sec < num && new_sec >= 0
				&& visit[new_fir][new_sec] == false && sector[x][y] == sector[new_fir][new_sec])
			{
				q.push(make_pair(new_fir, new_sec));
				visit[new_fir][new_sec] = true;
			}
			else continue;
		}
		q.pop();
	}
}

//5
//RRRBB
//GGBBB
//BBBRR
//BBRRR
//RRRRR

int main()
{
	cin >> num;
	int cnt = 0;
	int cnt_ = 0;
	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < num; j++)
		{
			sector[i].push_back(s[j]);
		}
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (visit[i][j] == false)
			{
				bfs(i, j);
				cnt++;
			}
			else continue;
		}
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			visit[i][j] = false;
			if (sector[i][j] == 'G')
			{
				sector[i][j] = 'R';
			}
			else continue;
		}
	}



	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (visit[i][j] == false)
			{
				bfs(i, j);
				cnt_++;
			}
			else continue;
		}
	}

	cout << cnt << " " << cnt_;

	return 0;