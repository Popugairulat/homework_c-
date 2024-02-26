#include <iostream>
#include <chrono>
const int N = 55000;
int arr[N];
int counter[N];

int func(int arr[], int N, int n) {
	int i = 0;
	while (i < N and arr[i] != n) {
		i += 1;
	}
	if (arr[i] == n and i != 0) {
		counter[i] += 1;
		if (counter[i] > counter[i - 1]) {
			int y = counter[i];
			counter[i] = counter[i - 1];
			counter[i - 1] = y;
			y = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = y;
		}
	}
	else
		i = -1;
	return i;
}

int main() {
	int u = 0;
	int mass[6] = { 0, 10, 25, 50, 75, 90 };
	while (u < 6) {
		int p = mass[u];
		u += 1;
		for (int l = 0; l < 20; ++l) {
			int i = 0;
			while (i < N) {
				arr[i] = i;
				counter[i] = 0;
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
		std::cout << "\n";
	}
	return 0;
}