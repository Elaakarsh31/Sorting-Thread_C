//Sorting through Threads

#include "bits.h"
#define log(x) cout << x << endl
#define line cout << endl
using namespace std;
using namespace std::literals::chrono_literals;

void swap(int arr[], int i, int j) //swaping elements in array
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int arr[], int l, int r) //partition elements with a pivot
{
	int pivot = arr[r];
	int i = l - 1;
	for (int j = l; j < r; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr, i, j);
		}
	}
	swap(arr, i + 1, r);
	return i + 1;
}

void QuickSort(int arr[], int l, int r) // using quicksort here
{
	if (l < r)
	{
		future<int> Pivot = async(launch::async, partition, arr, l, r); // calling a thread
		int pi = Pivot.get();
		QuickSort(arr, l, pi - 1);
		QuickSort(arr, pi + 1, r);
	}
}

int main()
{
	int arr[5] = {5, 4, 3, 2, 1};
	thread t(QuickSort, arr, 0, 4); // creating a thread
	t.join();
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
}
