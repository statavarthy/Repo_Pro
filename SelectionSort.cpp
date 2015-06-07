//////////////////////////////////////////////////////////////////////////
// FileName:    SelectionSort.cpp
// Description: Defines the member functions provided in the interface Selection.h.
// Author:      Smruti Tatavarthy
// Project:     Homework4(Programming in C++)
// Reference:   Programming in C++ - Dietel & Dietel(9th Edition)
//////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<vector>
#include "SelectionSort.h"

using namespace std;


//method for sorting arrays in the Ascending order using iteration
void SelectionSort::selectionSortAscending(int arr[], int n)		
{
	int j = 0, temp = 0, i = 0, tmpIndex = 0;
	for (i = 0; i < n - 1; i++)
	{
		tmpIndex = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[tmpIndex])
				tmpIndex = j;
		if (tmpIndex != i)
		{
			temp = arr[i];
			arr[i] = arr[tmpIndex];
			arr[tmpIndex] = temp;
		}
	}

}
//method for sorting vectors in the Ascending order using iteration
void SelectionSort::selectionSortAscending(vector <int> &arr, int n)
{
	int j = 0, temp = 0, i = 0, tmpIndex = 0;
	for (i = 0; i < n - 1; i++)
	{
		tmpIndex = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[tmpIndex])
				tmpIndex = j;
		if (tmpIndex != i)
		{
			temp = arr[i];
			arr[i] = arr[tmpIndex];
			arr[tmpIndex] = temp;
		}
	}

}
//method for sorting arrays in the descending order using iteration
void SelectionSort::selectionSortDescending(int arr[], int n)
{
	int j = 0, temp = 0, i = 0, tmpIndex = 0;
	for (i = 0; i < n - 1; i++)
	{
		tmpIndex = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] >arr[tmpIndex])
				tmpIndex = j;
		if (tmpIndex != i)
		{
			temp = arr[i];
			arr[i] = arr[tmpIndex];
			arr[tmpIndex] = temp;
		}
	}

}
//method for sorting vectors in the descending order using iteration

void SelectionSort::selectionSortDescending(std::vector<int>& arr, int n)
{
	int j = 0, temp = 0, i = 0, tmpIndex = 0;
	for (i = 0; i < n - 1; i++)
	{
		tmpIndex = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] >arr[tmpIndex])
				tmpIndex = j;
		if (tmpIndex != i)
		{
			temp = arr[i];
			arr[i] = arr[tmpIndex];
			arr[tmpIndex] = temp;
		}
	}

}
//method for sorting arrays in the Ascending order using recursion
void SelectionSort::sortAscendingRecurse(int arr[], int size)
{
	try {

		int maxIndex = 0, temp = 0, index = 0;
		for (index = maxIndex; index < size; index++)
		{
			if (arr[index] > arr[maxIndex])
			{
				maxIndex = index;
			}
		}
		temp = arr[size - 1];
		arr[size - 1] = arr[maxIndex];
		arr[maxIndex] = temp;

		if (size > 1)
		{
			sortAscendingRecurse(arr, --size);
		}
	}
	catch (int index) {
		cout << index;
	}


}
//method for sorting vectors in the Ascending order using recursion

void SelectionSort::sortAscendingRecurse(vector<int>& numbers1, int size)
{

	int maxIndex = 0, temp = 0, index = 0;
	for (index = maxIndex; index < size; index++)
	{
		if (numbers1[index] > numbers1[maxIndex])
		{
			maxIndex = index;
		}
	}
	temp = numbers1[size - 1];
	numbers1[size - 1] = numbers1[maxIndex];
	numbers1[maxIndex] = temp;

	if (size > 1)
	{
		sortAscendingRecurse(numbers1, --size);
	}


}

//method for sorting arrays in the descending order using recursion

void SelectionSort::sortDescendingRecurse(int arr[], int size)
{
	int maxIndex = 0, temp = 0, index = 0;
	for (index = maxIndex; index < size; index++) {
		if (arr[index] < arr[maxIndex]) {
			maxIndex = index;
		}
	}
	temp = arr[size - 1];
	arr[size - 1] = arr[maxIndex];
	arr[maxIndex] = temp;

	if (size > 1)
	{
		sortDescendingRecurse(arr, --size);
	}
}

//method for sorting vectors in the descending order using recursion

void SelectionSort::sortDescendingRecurse(vector<int>& arr, int size)	
{
	int maxIndex = 0, temp = 0, index = 0;
	for (index = maxIndex; index < size; index++)
	{
		if (arr[index] < arr[maxIndex])
		{
			maxIndex = index;
		}
	}
	temp = arr[size - 1];
	arr[size - 1] = arr[maxIndex];
	arr[maxIndex] = temp;

	if (size > 1) {
		sortDescendingRecurse(arr, --size);
	}
}





















