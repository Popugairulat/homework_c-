#include <iostream>
#include <chrono>
const int N = 1000000;
int arr[N];
int func(int arr[], int N, int n) {
	//ищем элемент в отсортированном массиве
	int start = 0, end = N - 1;
	while ((n > arr[start]) and (n < arr[end]) and end != start) {
		if ((n > (arr[start] + arr[end]) / 2))
			start = (end + start) / 2;
		else
			end = ((end + start)) / 2;
	}
	if (n > arr[end])
		end = 0;
	return end;
}

int main() {
	// Создаем отсортированный массив
	int i = 0;
	while (i < N) {
		arr[i] = i;
		i += 1;
	}
	for (int i = 0; i < 20; ++i) {
		// выполняем несколько раз
		auto begin = std::chrono::steady_clock::now();
		for (unsigned cnt = 1000000; cnt != 0; --cnt)
			func(arr, N, rand() % N);
		auto end = std::chrono::steady_clock::now();
		auto time_span =
			std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << "";
		std::cout << time_span.count() << std::endl;
	}

	return 0;
}
