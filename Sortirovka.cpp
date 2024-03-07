#include <iostream>
#include <chrono>
const int N = 11;
int arr[N];

void ip_Puzirkov(int arr[], int N) {
	bool flag_sort = false;
	int i = 0;
	while (flag_sort != true) {
		flag_sort = true;
		i = 0;
		while (i < N - 1) {
			if (arr[i] > arr[i + 1]) {
				int y = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = y;
				flag_sort = false;
			}
			i += 1;
		}
	}
}

void ip_vibor(int arr[], int N) {
	int i = 0;
	while (i < N - 1) {
		int j = i, min = 1000000, index = 0;
		while (j < N) {
			if (arr[j] < min) {
				min = arr[j];
				index = j;
			}
			j += 1;
		}
		j = index;
		while (j > i) {
			arr[j] = arr[j - 1];
			j -= 1;
		}
		arr[i] = min;
		i += 1;
	}
}

void ip_vstavka(int arr[], int N) {
	int i = 1;
	while (i < N) {
		int j = -1, min = arr[i], index = 0;
		while (j < i) {
			if (arr[j] <= min and arr[j + 1] >= min) {
				index = j;
				break;
			}
			j += 1;
		}
		j = i;
		while (j > index) {
			arr[j] = arr[j - 1];
			j -= 1;
		}
		arr[index + 1] = min;
		i += 1;
	}

}

void ip_bistro(int(&arr)[N], int start, int end) {
	if (end - start > 0) {
		int center = (end + start) / 2;
		int i = start;
		while (i <= end) {
			if (arr[i]<arr[center] and i>center) {
				int j = i, arg = arr[i];
				while (j > start) {
					arr[j] = arr[j - 1];
					j -= 1;
				}
				arr[start] = arg;
				center += 1;
			}
			else {
				if (arr[i] >= arr[center] and i < center) {
					int j = i, arg = arr[i];
					while (j < end) {
						arr[j] = arr[j + 1];
						j += 1;
					}
					arr[end] = arg;
					center -= 1;
					i -= 1;
				}
			}
			i += 1;
		}
		ip_bistro(arr, start, center - 1);
		ip_bistro(arr, center + 1, end);
	}
}

void ip_slianie(int arr[N], int N) {
	int q = 1, i = 0;
	while (q * (i - 10) < N) {
		int j1 = 0;
		int j2 = 0;
		while (j1 < q and q * i + j1 < N and q * (i + 1) + j2 < N) {
			if (arr[q * i + j1] > arr[q * (i + 1) + j2]) {
				int k = q * (i + 1) + j2, arg = arr[q * (i + 1) + j2];
				while (k > q * i + j1) {
					arr[k] = arr[k - 1];
					k -= 1;
				}
				arr[q * i + j1] = arg;
				j1 += 1;
				j2 += 1;
			}
			else {
				j1 += 1;
			}
		}
		i += 2;
		if (q * i >= N and 2 * q < N) {
			i = 0;
			q *= 2;
		}
	}
}

void Bystraya(int a[], unsigned N, int start)
{
	int i = start;
	int j = N - 1;
	int m = N / 2;
	int M = a[m];
	while (i <= j)
	{
		while (a[i] <= M)
		{
			++i;
		}
		while (a[j] >= M)
		{
			--j;
		}
		if (i < j)
		{
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	if (j > 0)
	{
		Bystraya(a, j + 1, 0);
	}
	if (i < N)
	{
		Bystraya(a, N - i, i + 1);
	}
}
void perestanovka(int(&arr)[N], int first_position, int second_position) {
	if (first_position > second_position) {
		int i = first_position, arg = arr[first_position];
		while (i > second_position) {
			arr[i] = arr[i - 1];
			i -= 1;
		}
		arr[second_position] = arg;
	}
	else {
		int i = first_position, arg = arr[first_position];
		while (i < second_position) {
			arr[i] = arr[i + 1];
			i += 1;
		}
		arr[second_position] = arg;
	}
}

int main() {
	int i = 0;
	while (i < N) {
		arr[i] = rand() % 10;
		i += 1;
	}
	i = 0;
	while (i < N) {
		std::cout << arr[i] << " ";
		i += 1;
	}
	ip_slianie(arr, N);
	int r = 0;
	std::cout << "\n";
	while (r < N) {
		std::cout << arr[r] << " ";
		r += 1;
	}
	return 0;
}