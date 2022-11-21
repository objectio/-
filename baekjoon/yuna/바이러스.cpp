#include <iostream>
#include <string.h>

using namespace std;

int n, m;
int map[101][101] = { 0 };
int visit[101] = { 0 };
int cnt = 0;

void dfs(int k) {
	visit[k] = 1;
	cnt++;
	for (int i = 1; i <= n; i++) {
		if (map[i][k] && map[k][i] && !visit[i]) {
			dfs(i);
		}
	}
}

int main() {
	int x, y;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		map[x][y] = map[y][x] = 1;
	}

	dfs(1);
	cout << cnt - 1 << endl;	// 1번 컴퓨터 제외

	return 0;
}