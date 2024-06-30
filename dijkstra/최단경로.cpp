#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 10000000

vector<pair<int, int>> map[20001];
priority_queue<pair<int, int>> pq; //가중치, 노드 번호
int d[300001];

void dijkstra(int start)
{
	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;
		
		for (int i = 0; i < map[now].size(); i++)
		{
			int cost = dist + map[now][i].second; // 2.여기서 원상복구
			if (cost < d[map[now][i].first])
			{
				d[map[now][i].first] = cost;
				pq.push(make_pair(-cost, map[now][i].first)); // 1.여기서 -붙여서 최소값으로 인식
			}	
		}
	}
}

int main()
{
	int V, E = 0;
	cin >> V >> E;
	int x = 0;
	cin >> x;

	for (int i = 0; i < E; i++)
	{
		int u, v, w = 0;
		cin >> u >> v >> w;
		map[u].push_back(make_pair(v, w));
	}

	fill(d, d + 300001, INF);
	dijkstra(x);

	for (int i = 1; i <= V; i++)
	{
		if (d[i] == INF) cout << "INF" << "\n";
		else cout << d[i] << "\n";
	}
	return 0;
}