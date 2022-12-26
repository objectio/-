#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//다익스트라 알고리즘을 이용한 문제풀이

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;

	vector<int> dist(N + 1, 500001);
	vector<pair<int, int> > map[52];
	dist[1] = 0;
	priority_queue<pair<int, int>> pq;	//정점까지의 거리, 정점의 번호

	//map 초기화
	for (int i = 0; i < road.size(); i++) {
		int first = road[i][0];
		int second = road[i][1];
		int third = road[i][2];
		map[first].push_back(make_pair(second, third));
		map[second].push_back(make_pair(first, third));
	}

	pq.push(make_pair(0, 1));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (dist[current] < cost) continue;

		for (int i = 0; i < map[current].size(); i++) {
			int there = map[current][i].first;
			int nextDist = cost + map[current][i].second;

			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}


	for (int i = 0; i < dist.size(); i++) {
		if (dist[i] <= K) answer++;
	}

	return answer;
}