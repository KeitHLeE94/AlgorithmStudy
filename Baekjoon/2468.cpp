#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int map[100][100];
int caseMap[100][100];
bool visit[100][100];
int countArea = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void editMap(int rain) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] <= rain) {
				caseMap[i][j] = 0;
			}
			else {
				caseMap[i][j] = 1;
			}
		}
	}
}

void BFS(queue<pair<int, int>> *Queue, vector<int> *result, int startX, int startY) {
	visit[startX][startY] = true;
	Queue->push(make_pair(startX, startY));

	while (!Queue->empty()) {
		int nextX = Queue->front().first;
		int nextY = Queue->front().second;
		Queue->pop();

		for (int i = 0; i < 4; i++) {
			if (nextX + dx[i] >= 0 && nextX + dx[i] < N && nextY + dy[i] >= 0 && nextY + dy[i] < N && caseMap[nextX + dx[i]][nextY + dy[i]] != 0 && !visit[nextX + dx[i]][nextY + dy[i]]) {
				visit[nextX + dx[i]][nextY + dy[i]] = true;
				Queue->push(make_pair(nextX + dx[i], nextY + dy[i]));
			}
		}
	}

	countArea++;
}

int main() {
	cin >> N;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			map[i][j] = 0;
		}
	}

	int rainMax = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (rainMax < map[i][j]) {
				rainMax = map[i][j];
			}
		}
	}

	queue<pair<int, int>> Queue;
	vector<int> result;

	for (int i = 0; i <= rainMax; i++) {
		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < 100; k++) {
				caseMap[j][k] = 0;
				visit[j][k] = false;
			}
		}
		editMap(i);
		countArea = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (caseMap[j][k] != 0 && !visit[j][k]) {
					BFS(&Queue, &result, j, k);
				}
			}
		}
		result.push_back(countArea);
	}

	sort(result.begin(), result.end());

	cout << result[result.size() - 1] << '\n';
	
	return 0;
}