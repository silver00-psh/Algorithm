#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 100000000

vector<pair<int, int>> city[1001];
priority_queue<pair<int, int>> pq;
int d[100001];

void dijkstra(int start)
{
	pq.push(make_pair(0, start));
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;
		
		for (int i = 0; i < city[now].size(); i++)
		{
			int cost = dist + city[now][i].second;
			if (cost < d[city[now][i].first])
			{
				d[city[now][i].first] = cost;
				pq.push(make_pair(-cost, city[now][i].first));
			}
		}
	}
}

int main()
{
	int N, M = 0;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c = 0;
		cin >> a >> b >> c;
		city[a].push_back(make_pair(b, c));
	}

	int start, end = 0;
	cin >> start >> end;

	fill(d, d + 100001, INF);
	dijkstra(start);

	cout << d[end];
	return 0;
}
