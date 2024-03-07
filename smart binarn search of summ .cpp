#include <iostream>
#include <chrono>
const int N = 5500;
int arr[N];

int binarn(int start, int end, int n) {
	//if we want to take time of random element n=rand()*rand()%N
	//else n=1 because it is the longest time
	//yes, I understand that there aren't russian comments 
	while ((n > arr[start]) and (n < arr[end]) and end != start + 1) {
		if ((n >= (arr[start] + arr[end]) / 2))
			start = (end + start) / 2;
		else
			end = ((end + start)) / 2;
	}
	if (n > arr[end] or arr[end] != n)
		end = -1;
	return end;
}

int func(int arr[], int N, int n) {
	int start = 0, end = N - 1;
	int i = end;
	//???????????? ???????? ? ???????? ????? 
	while (arr[start] + arr[i] != n and start < end) {
		i = binarn(start + 1, end, n - arr[start]);
		if (i == -1) {
			start += 1;
			i = start + 1;
		}
	}
	if (start == end)
	{
		start = -1;
		i = -1;
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
			func(arr, N, -1);
		auto end = std::chrono::steady_clock::now();
		auto time_span =
			std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << "";
		std::cout << time_span.count() << std::endl;
	}
	return 0;
}