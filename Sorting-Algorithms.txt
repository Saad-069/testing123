
#include <iostream>
using namespace std;

void insertionSort(int arr[], int index) {
	
	for (int i = 1; i < index; i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {

			arr[j+1] = arr[j];
			j--;
		}
		arr[j + 1] = key;

}

}
void print(int arr[], int index) {

	for (int i = 0; i < index; i++) {
		cout << " " << arr[i] << " ";
	}

}
void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}
void bubbleSort(int arr[], int index) {

	for (int i = 1; i < index; i++) {

		for (int k = 0; k < index; k++) {
			if (arr[i] < arr[k]) {
				swap(arr[i], arr[k]);
			}
		}


	}

}
void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		mergeSort(arr, left, mid);

	
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

void merge(int arr[], int left, int mid, int right) {
	int leftSize = mid - left + 1;
	int rightSize = right - mid;
	int *leftArray = new int;
	int* rightArray = new int;

	 leftArray[leftSize];
	rightArray[rightSize];


	for (int i = 0; i < leftSize; i++) {
		leftArray[i] = arr[left + i];
	}
	for (int j = 0; j < rightSize; j++) {
		rightArray[j] = arr[mid + 1 + j];
	}

	
	int i = 0;  	int j = 0;  
	int k = left;  

	while (i < leftSize && j < rightSize) {
		if (leftArray[i] <= rightArray[j]) {
			arr[k] = leftArray[i];
			i++;
		}
		else {
			arr[k] = rightArray[j];
			j++;
		}
		k++;
	}

	while (i < leftSize) {
		arr[k] = leftArray[i];
		i++;
		k++;
	}


	while (j < rightSize) {
		arr[k] = rightArray[j];
		j++;
		k++;
	}
}

int main()

{


	int a = 8,b=4;
	int arr[10];
	arr[0] = 3;
	arr[1] = 54;
	arr[2] = 1;
	arr[3] = 4;
	arr[4] =25;
	arr[5] = 546;
	arr[6] = 17;
	arr[7] = 8;
	arr[8] = 9;
	arr[9] = 11;
	bubbleSort(arr, 10);
	print(arr, 10);
	
	//insertionSort(arr, 10);


}

