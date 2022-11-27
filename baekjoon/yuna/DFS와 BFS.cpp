#include <iostream>
#include <queue>
using namespace std;

int n, m, v, x, y;
int map[1001][1001];    //간선
int visit[1001];    //노드방문여부

//깊이우선탐색
void dfs(int v) {
	cout << v << " ";
	visit[v] = 1;
	for (int i = 1; i <= n; i++) {
		if (map[v][i] == 1 && !visit[i]) {
			visit[i] = 1;
			dfs(i);
		}
	}
}

//너비우선탐색
void bfs(int v) {
	queue<int> q;
	q.push(v);
	visit[v] = 1;

	while (!q.empty()) {
		v = q.front();	//먼저 들어온 노드 반환
		q.pop();
		cout << v << " ";

		for (int i = 1; i <= n; i++) {
			if (map[v][i] && !visit[i]) {
				q.push(i);
				visit[i] = 1;
			}
		}
	}
}

int main() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		map[x][y] = map[y][x] = 1;	//존재하는 간선
	}

	dfs(v);
	cout << endl;
	fill_n(visit, 1001, 0);
	bfs(v);

	return 0;
}