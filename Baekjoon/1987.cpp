#include <iostream>
#include <string>

using namespace std;

int R, C;
char map[20][20];
bool alphabets[26] = { false, };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int maxNum = 1;

void DFS(int startX, int startY, int count) {
	alphabets[map[startX][startY] - 'A'] = true;
	for (int i = 0; i < 4; i++) {
		if (startX + dx[i] >= 0 && startX + dx[i] < R && startY + dy[i] >= 0 && startY + dy[i] < C && !alphabets[map[startX + dx[i]][startY + dy[i]] - 'A']) {
			alphabets[map[startX + dx[i]][startY + dy[i]] - 'A'] = true;
			DFS(startX + dx[i], startY + dy[i], count + 1);
			alphabets[map[startX + dx[i]][startY + dy[i]] - 'A'] = false;
		}
	}
	if (maxNum < count) {
		maxNum = count;
	}
}

int main() {
	cin >> R >> C;

	string input;
	for (int i = 0; i < R; i++) {
		cin >> input;

		for (int j = 0; j < C; j++) {
			map[i][j] = input[j];
		}
	}

	DFS(0, 0, 1);

	cout << maxNum << '\n';

	return 0;
}