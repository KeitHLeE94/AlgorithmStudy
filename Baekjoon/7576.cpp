#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;
int map[1000][1000];
bool visit[1000][1000];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int countNum = -1;

void BFS(queue<pair<int, int>> *Queue) {
	while (!Queue->empty()) {
		int qsize = Queue->size();

		for (int q = 0; q < qsize; q++) {
			int nextX = Queue->front().first;
			int nextY = Queue->front().second;

			for (int i = 0; i < 4; i++) {
				if (nextX + dx[i] < N && nextX + dx[i] >= 0 && nextY + dy[i] < M && nextY + dy[i] >= 0 && map[nextX + dx[i]][nextY + dy[i]] == 0) {
					map[nextX + dx[i]][nextY + dy[i]] = 1;
					Queue->push(make_pair(nextX + dx[i], nextY + dy[i]));
				}
			}

			Queue->pop();
		}
		countNum++;
	}
}

int main() {
	cin >> M >> N;

	queue<pair<int, int>> Queue;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				Queue.push(make_pair(i, j));
			}
		}
	}

	BFS(&Queue);

	int result = countNum;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				result = -1;
			}
		}
	}

	cout << result << '\n';

	return 0;
}