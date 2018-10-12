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
			//i=1: 첫 계단, i=2: 첫 계단 + 두번째 계단.
		}
		else {
			DP[i] = max(stairs[i] + DP[i - 2], stairs[i] + stairs[i - 1]);
			//max(3번째 계단 + 첫 계단, 3번째 계단 + 2번째 계단)
		}
	}

	for (int i = 4; i <= N; i++) {
		DP[i] = max(stairs[i] + DP[i - 2], stairs[i] + stairs[i - 1] + DP[i - 3]);
		//max(4번째 계단 + 첫 계단 + 두번째 계단, 4번째 계단 + 3번째 계단 + 첫 계단), ...
	}

	cout << DP[N] << '\n';

	return 0;
}