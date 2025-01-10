#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 987654321

int map[100][100];
int N, M;
int m[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} }; //left, right, up, down

void input_data()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> map[y][x];
}

void repair_map()
{
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			if (map[y][x] == -1)
				map[y][x] = 0;
}

bool melting_cheese()
{
	bool flag = false;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
		{
			if (map[y][x] == 1)
			{
				int cnt = 0;
				for (int i = 0; i < 4; i++)
				{
					int n_y = y + m[i][0];
					int n_x = x + m[i][1];
					if (n_y >= 0 && n_y < N && n_x >= 0 && n_x < M && map[n_y][n_x] == -1)
						cnt++;
				}
				if (cnt >= 2)
					map[y][x] = 0;
				else
					flag = true;
			}
		}
	return flag;
}

void bfs()
{
	queue<pair<int, int>> q; //y, x;
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int n_y = y + m[i][0];
			int n_x = x + m[i][1];
			if (n_y >= 0 && n_y < N && n_x >= 0 && n_x < M && map[n_y][n_x] == 0)
			{
				map[n_y][n_x] = -1;
				q.push(make_pair(n_y, n_x));
			}
		}
	}
}

void solve()
{
	int time = 0;
	int flag = true;
	while (flag)
	{
		bfs();
		flag = melting_cheese();
		repair_map();
		time++;
	}
	cout << time << "\n";
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	input_data();
	solve();
	return 0;
}