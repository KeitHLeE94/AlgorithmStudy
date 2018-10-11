#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int cnt;
int map[25][25];
bool visit[25][25];

void BFS(queue<pair<int, int>> *Queue, int startX, int startY, vector<int> *result) {
	visit[startX][startY] = true;
	Queue->push(make_pair(startX, startY));

	while (!Queue->empty()) {
		int nextX = Queue->front().first;
		int nextY = Queue->front().second;
		Queue->pop();

		if (nextY + 1 < N && map[nextX][nextY + 1] != 0 && !visit[nextX][nextY+1]) {
			visit[nextX][nextY + 1] = true;
			Queue->push(make_pair(nextX, nextY + 1));
			cnt++;
		}
		if (nextX + 1 < N && map[nextX + 1][nextY] != 0 && !visit[nextX + 1][nextY]) {
			visit[nextX + 1][nextY] = true;
			Queue->push(make_pair(nextX + 1, nextY));
			cnt++;
		}
		if (nextY - 1 >= 0 && map[nextX][nextY - 1] != 0 && !visit[nextX][nextY - 1]) {
			visit[nextX][nextY - 1] = true;
			Queue->push(make_pair(nextX, nextY - 1));
			cnt++;
		}
		if (nextX - 1 >= 0 && map[nextX - 1][nextY] != 0 && !visit[nextX - 1][nextY]) {
			visit[nextX-1][nextY] = true;
			Queue->push(make_pair(nextX - 1, nextY));
			cnt++;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			map[i][j] = 0;
			visit[i][j] = false;
		}
	}

	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;

		for (int j = 0; j < input.length(); j++) {
			map[i][j] = input[j] - '0';
		}
	}

	queue<pair<int, int>> Queue;
	vector<int> result;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j] && map[i][j] != 0) {
				cnt = 1;
				BFS(&Queue, i, j, &result);
				result.push_back(cnt);
			}
		}
	}

	cout << result.size() << '\n';

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}

	return 0;
}