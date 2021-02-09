// HW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const int NUMBERS = 1000;

void mergeFunction(int arr[], int lowLeft, int highLeft, int highRight)
{
	int lowRight, size;
	int *mergedArr;
	int iRight, iLeft, iRes;
	int i, iArr;

	lowRight = highLeft + 1;
	size = highRight - lowLeft + 1;
	mergedArr = new int[size];

	iLeft = lowLeft;
	iRight = lowRight;
	iRes = 0;
	while (iLeft <= highLeft && iRight <= highRight) {
		if (arr[iLeft] < arr[iRight]) {
			mergedArr[iRes] = arr[iLeft];
			iLeft++;
			iRes++;
		}
		else {
			mergedArr[iRes] = arr[iRight];
			iRight++;
			iRes++;
		}
	}

	while (iLeft <= highLeft) {
		mergedArr[iRes] = arr[iLeft];
		iLeft++;
		iRes++;
	}

	while (iRight <= highRight) {
		mergedArr[iRes] = arr[iRight];
		iRight++;
		iRes++;
    }

	for (i = 0, iArr = lowLeft; i < size; i++, iArr++) {
		arr[iArr] = mergedArr[i];
	}

	delete[]mergedArr;

}

void mergeSort(int arr[], int low, int high) {
	int mid;
	if (low == high) {
		return;
	}
	else {
		mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		mergeFunction(arr, low, mid, high);
	}
}

int binarySearch(int arr[], int min, int max, int target)
{
	if (max >= min) {
		int mid = min + (max - min) / 2;

		if (arr[mid] == target) {
			return mid;
		}

		if (arr[mid] > target) {
			return binarySearch(arr, min, mid - 1, target);
		}

		return binarySearch(arr, mid + 1, max, target);
	}

	return -1;
}

int main()
{
	int bubble[NUMBERS];
	int merge[NUMBERS];
	int i, j, temp, randNumSeed, randNum, result;

	//Creating arrays

	for (i = 0; i < NUMBERS; i++) {
		bubble[i] = rand() % NUMBERS + 1;
		merge[i] = bubble[i];
	}

	// bubble sort

	for (i = 1; i < NUMBERS; i++) {
		for (j = 0; j < NUMBERS - 1; j++) {
			if (bubble[j] > bubble[j + 1]) {
				temp = bubble[j];
				bubble[j] = bubble[j + 1];
				bubble[j + 1] = temp;
			}
		}
	}

	// merge sort

	mergeSort(merge, 0, NUMBERS - 1);

	// picking random element
	randNumSeed = rand() % NUMBERS;
	randNum = merge[randNumSeed];

	// binary search to find element
	result = binarySearch(merge, 0, NUMBERS - 1, randNum);

	//print result

	if (result == -1) {
		cout << "Not found" << endl;
	}
	else {
		cout << "Element is found at index " << result;
	}


}

