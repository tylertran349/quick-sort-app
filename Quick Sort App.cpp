#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int* firstElement, int* secondElement) {
	int t = *firstElement;
	*firstElement = *secondElement;
	*secondElement = t;
}

int partition (int arr[], int start, int end) {
	int pivot = arr[end]; // Sets pivot to be last element in array
	int i = (start - 1); // Index of smaller element and indicates the right position of pivot found so far
	for (int j = start; j <= end - 1; j++) {
		if (arr[j] < pivot) {
			i++; // Increments index of smaller element if current element is smaller than pivot
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[end]);
	return (i + 1);
}

void quickSort(int arr[], int start, int end) {
	if (start < end) {
		int partitionIndex = partition(arr, start, end); // Find partition index
		quickSort(arr, start, partitionIndex - 1); // Sort elements to left of pivot
		quickSort(arr, partitionIndex + 1, end); // Sort elements to right of pivot
	}
}

// Function to print array
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {10, 7, 8, 9, 1, 5};
	int size = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, size - 1);
	cout << "Sorted array: " << endl;
	printArray(arr, size);
}
