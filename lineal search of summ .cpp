#include <iostream>
#include <chrono>
const int N = 5500;
int arr[N];

int func(int arr[], int N, int n) {
	int i = 0;
	int j = 1;
	while (i < N) {
		while (j < N and arr[i] + arr[j] != n) {
			j += 1;
		}
		i += 1;
		j = i + 1;
	}
	return i;
}

int main() {

	int i = 0;
	while (i < N) {
		arr[i] = i;
		i += 1;
	}
	for (int i = 0; i < 20; ++i) {
		auto begin = std::chrono::steady_clock::now();
		for (unsigned cnt = 1000; cnt != 0; --cnt)
			func(arr, N, rand() * rand() % (2 * N - 1));
		auto end = std::chrono::steady_clock::now();
		auto time_span =
			std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << "";
		std::cout << time_span.count() << std::endl;
	}
	return 0;
}