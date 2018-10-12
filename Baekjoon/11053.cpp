#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
	cin >> N;

	vector<int> numbers;
	int DP[1010] = { 0, };
	int max = 0;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		numbers.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		int min = 0;

		for (int j = 0; j < i; j++) {
			if (numbers[i] > numbers[j] && min < DP[j]) {
				min = DP[j];
			}
		}
		DP[i] = min + 1;

		if (max < DP[i]) {
			max = DP[i];
		}
	}

	cout << max << '\n';

	return 0;
}