#include <iostream>
#include <chrono>
const int N = 550;
int arr[N];

int func(int arr[], int N, int n) {
	int i = 0;
	while (i < N and arr[i] != n) {
		i += 1;
	}

	if (arr[i] == n and i != 0) {
		int y = arr[i];
		arr[i] = arr[i - 1];
		arr[i - 1] = y;
	}
	else
		i = -1;
	return i;
}

int main() {
	int p = 90;

	for (int l = 0; l < 20; ++l) {
		int i = 0;
		while (i < N) {
			arr[i] = i;
			i += 1;
		}
		auto begin = std::chrono::steady_clock::now();
		for (unsigned cnt = 100000; cnt != 0; --cnt)
			func(arr, N, rand() * rand() % N * (100 - p) / 100 * 100 / (100 - p));
		auto end = std::chrono::steady_clock::now();
		auto time_span =
			std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << "";
		std::cout << time_span.count() << std::endl;
	}
	return 0;
}