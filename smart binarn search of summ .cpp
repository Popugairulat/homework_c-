#include <iostream>
#include <chrono>
const int N = 100;
int arr[N];

int func(int arr[], int N, int n) {
	//when we need random element n=rand()*rand()%(2*N-1)
	//when we need the worst time n=1
	int start = 0;
	int end = N - 1;
	int medium;
	while (arr[start] + arr[end] != n) {
		medium = (start + end) / 2;
		if (arr[medium] * 2 > n)
			end = medium;
		else
			start = medium;
		if (arr[end - 1] + arr[end] < n or n < arr[start - 1] + arr[start])
			break;
		if (end - start == 1)
			break;
	}
	if (arr[start] + arr[end] == n)
		return  (1);
	else
		return 0;
}

int main() {

	int i = 0;
	while (i < N) {
		arr[i] = 2 * i;
		i += 1;
	}
	for (int i = 0; i < 20; ++i) {
		auto begin = std::chrono::steady_clock::now();
		for (unsigned cnt = 1000000; cnt != 0; --cnt)
			func(arr, N, 1);
		auto end = std::chrono::steady_clock::now();
		auto time_span =
			std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << "";
		std::cout << time_span.count() << std::endl;
	}
	return 0;
}