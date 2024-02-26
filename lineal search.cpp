#include <iostream>
#include <chrono>
const int N = 1000000;
int arr[N];

int func(int arr[], int N, int n) {
	//Если ищем случайный элемент n=rand()*rand()%N;
	//Если ищем элемент, которого нет, то n=N;
	int i = 0;
	while (i < N and arr[i] != n) {
		i += 1;
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
		for (unsigned cnt = 100000; cnt != 0; --cnt)
			func(arr, N, rand() * rand() % N);
		auto end = std::chrono::steady_clock::now();
		auto time_span =
			std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << "";
		std::cout << time_span.count() << std::endl;
	}
	return 0;
}