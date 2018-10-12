#include <iostream>
#include <algorithm>

using namespace std;

int N;
int stairs[301];
int DP[301];

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> stairs[i];
	}

	for (int i = 1; i <= 3 && i <= N; i++) {
		if (i != 3) {
			DP[i] = stairs[i] + DP[i - 1];
			//i=1: ù ���, i=2: ù ��� + �ι�° ���.
		}
		else {
			DP[i] = max(stairs[i] + DP[i - 2], stairs[i] + stairs[i - 1]);
			//max(3��° ��� + ù ���, 3��° ��� + 2��° ���)
		}
	}

	for (int i = 4; i <= N; i++) {
		DP[i] = max(stairs[i] + DP[i - 2], stairs[i] + stairs[i - 1] + DP[i - 3]);
		//max(4��° ��� + ù ��� + �ι�° ���, 4��° ��� + 3��° ��� + ù ���), ...
	}

	cout << DP[N] << '\n';

	return 0;
}