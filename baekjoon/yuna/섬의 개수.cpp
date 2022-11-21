#include <iostream>
#include <string.h>

using namespace std;

int w, h;
int map[50][50] = { 0 };
int visit[50][50] = { 0 };
int cnt = 0;

//ºÏ,³²,¼­,µ¿, ºÏ¼­, ºÏµ¿, ³²¼­, ³²µ¿
int dw[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int dh[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };

void dfs(int x, int y) {
	visit[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		int nh = dw[i] + x;
		int nw = dh[i] + y;
		if (nw >= 0 && nh >= 0 && nw < w && nh < h) {
			if (map[nh][nw] && !visit[nh][nw]) {
				visit[nh][nw] = 1;
				dfs(nh, nw);
			}
		}
	}
}

int main() {

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] && !visit[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << endl;

		//ÃÊ±âÈ­
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		cnt = 0;
	}

	return 0;
}