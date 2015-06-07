//////////////////////////////////////////////////////////////////////////
// FileName:    Main.cpp
// Description: Defines the  function templates and flow of program execution
// Author:      Smruti Tatavarthy
// Project:     Homework4(Programming in C++)
// Reference:   Programming in C++ - Dietel & Dietel(9th Edition)
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <Windows.h>
#include "TimeStamp.h"
#include "SelectionSort.h" // include definition of class Selection
using namespace std;

template<class T, typename A> void printArray(T &arr, T size);		//function template for adding random data to array or vector
template<class T, typename A> void createArray(T &arr, T size);		//prototype function template for printing data in array or vector

template<class T,typename A> void createArray(T &arr, A size)	//function template to put random numbers in array or vector
{
	//Sleep(200);			//use of sleep to enable srand function to generate random number
	srand(time(NULL));		//use of srand to generate random number
	for (int i = 0; i < size; i++)
	{
		
		arr[i] = rand();	
	}
	cout << endl;
	
}

template<class T,typename A> void printArray(T &arr, A size)	//function template to print array or vector
{	
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout <<' '<< arr[i] << ' ';
	}
	cout << endl;
	
}

void main()
{
	string timeString;
	TimeStamp ts;

	const int size = 20;	//small size
	const int size1 = 2000;	//large size
	int arr1[size];	//small array
	int arr2[size1]; //large array
	int arr1Copy[size];//copy of small array
	int arr2Copy[size1]; //copy of large array
	vector < int > numbers1(size); //small vector
	vector < int > numbers2(size1);	//large vector
	vector < int > numbers1Copy(size); //copy of small vector
	vector < int > numbers2Copy(size1); //copy of large vector

	
	
	int choice = 0;
	char ans;
	cout << "---------------------------------------------------" << endl;
	cout << "\n WELCOME TO SELECTION SORT" << endl;	
	cout << "---------------------------------------------------" << endl;
	SelectionSort sort;

	do
	{
		cout <<"\n HOW WOULD YOU LIKE TO SORT ?" <<endl<< "\n 1.ASCENDING" << endl << "\n 2.DESCENDING" << endl << "\n ENTER YOU CHOICE : ";
		cin.clear();
		cin.sync();
		cin >> choice;
		createArray(arr1, size);	//call helper function to put random data in small array

		
		

		switch (choice)
		{
		case 1:
			for (int i = 0; i < size; i++)		//making copy of small array
			{
				arr1Copy[i] = arr1[i];
			}

			createArray(arr2, size1);	//call helper function to put random data in large array
			for (int i = 0; i < size1; i++)  //making copy of large array
			{
				arr2Copy[i] = arr2[i];
			}

			createArray(numbers1, size);	//call helper fundtion to create a small vector
			numbers1Copy = numbers1;		//making copy of small vector


			createArray(numbers2, size1);		//call helper fundtion to create a large vector

			numbers2Copy = numbers2; 	//making copy of large vector
  
			cout << "\n SORTING SMALL ARRAYS IN ASCENDING ORDER" << endl;
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << " ARRAY BEFORE SORTING" << endl;			
			printArray(arr1, size);		//printing array before sorting
			timeString = ts.GetTime();
			cout << "\n "<< timeString << endl;
			sort.sortAscendingRecurse(arr1, size);		//call the sorting function to sort the array recursively
			cout << "\n SORTING ARRAY USING RECURSION" << endl;
			cout << " ---------------------------" << endl;			
			printArray(arr1, size);		//printing the array after sorting
			timeString = ts.GetTime();
			cout << "\n " << timeString << endl;
			sort.selectionSortAscending(arr1Copy, size);	//call the sorting function to sort the copy of original array using iteration
			cout << "\n SORTING ARRAY USING ITERATION" << endl;
			cout << " ---------------------------" << endl;
			printArray(arr1Copy, size);		//printing the copy of original array after sorting			
			timeString = ts.GetTime();
			cout << "\n " << timeString << endl;
			cout << "\n SORTING SMALL VECTORS IN ASCENDING ORDER" << endl;
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "\n VECTOR BEFORE SORTING" << endl;
			printArray(numbers1, size);		//printing the vector before sorting
			timeString = ts.GetTime();
			cout << "\n " << timeString << endl;
			sort.sortAscendingRecurse(numbers1, size);		//call the sorting function to sort the vector recursively	
			cout << "\n SORTING VECTOR USING RECURSION" << endl;
			cout << " ---------------------------" << endl;			
			printArray(numbers1, size);		//printing the vector after sorting
			timeString = ts.GetTime();
			cout << "\n " << timeString << endl;
			sort.selectionSortAscending(numbers1Copy, size);		//call the sorting function to sort the copy of original vector using iteration
			cout << "\n SORTING VECTOR USING ITERATION" << endl;
			cout << " ---------------------------" << endl;			
			printArray(numbers1Copy, size);		//printing the copy of original vector after sorting
			timeString = ts.GetTime();
			cout << "\n " << timeString << endl;			
			
			cout << "\n TIME TAKEN FOR SORTING LARGE ARRAYS IN ASCENDING ORDER" << endl;
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			//cout << " ARRAY BEFORE SORTING" << endl;
			//printArray(arr2, size1);		//printing the large array before sorting						
			//cout << timeString << endl;
			cout << "\n TIME BEFORE SORTING LARGE ARRAY USING RECURSION--" ;			
			timeString = ts.GetTime();
			cout << timeString << endl;
			sort.sortAscendingRecurse(arr2, size1);		//call the sorting function to sort the large array recursively
			cout << "\n TIME AFTER SORTING LARGE ARRAY USING RECURSION--";			
			timeString = ts.GetTime();
			cout << timeString << endl;
			//printArray(arr2, size1);		//printing the large array after sorting						
			cout << "\n TIME BEFORE SORTING LARGE ARRAY USING ITERATION--" ;	
			timeString = ts.GetTime();
			cout << timeString << endl;
			sort.selectionSortAscending(arr2Copy, size1);		//call the sorting function to sort the copy of original large array using iteration
			cout << "\n TIME AFTER SORTING LARGE ARRAY USING ITERATION--" ;
			timeString = ts.GetTime();
			cout << timeString << endl;
			//printArray(arr2Copy, size1);		//printing the copy of original large array after sorting
			


			cout << "\n TIME FOR SORTING LARGE VECTORS IN ASCENDING ORDER" << endl;
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "\n TIME BEFORE SORTING THE VECTOR USING RECURSION--";			
			//printArray(numbers2, size1);		//printing the large vector before sorting			
			//cout << "\n SORTING VECTOR USING RECURSION" << endl;			
			timeString = ts.GetTime();
			cout << timeString << endl;
			sort.sortAscendingRecurse(numbers2, size1);			//call the sorting function to sort the large vector recursively	
			cout << "\n TIME AFTER SORTING THE VECTOR USING RECURSION--";
			timeString = ts.GetTime();
			cout << timeString << endl;
			//printArray(numbers2, size1);					//printing the large vector after sorting
			//cout << "\n SORTING VECTOR USING ITERATION" << endl;
			//cout << " ---------------------------" << endl;
			cout << "\n TIME BEFORE SORTING THE VECTOR USING ITERATION--";
			timeString = ts.GetTime();
			cout  << timeString << endl;
			sort.selectionSortAscending(numbers2Copy, size1);		//call the sorting function to sort the large vector using iteration	
			//printArray(numbers2Copy, size1);					//printing the large vector after sorting
			cout << "\n TIME AFTER SORTING THE VECTOR USING ITERATION--";
			timeString = ts.GetTime();
			cout << timeString << endl;
			break;

		case 2:				////same logic as above for descending order

			for (int i = 0; i < size; i++)		//making copy of small array
			{
				arr1Copy[i] = arr1[i];
			}

			createArray(arr2, size1);	//call helper function to put random data in large array
			for (int i = 0; i < size1; i++)  //making copy of large array
			{
				arr2Copy[i] = arr2[i];
			}

			createArray(numbers1, size);	//call helper fundtion to create a small vector
			numbers1Copy = numbers1;		//making copy of small vector


			createArray(numbers2, size1);		//call helper fundtion to create a large vector

			numbers2Copy = numbers2; 	//making copy of large vector
			
			cout << "\n SORTING SMALL ARRAYS IN DESCENDING ORDER" << endl;
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << " ARRAY BEFORE SORTING" << endl;			
			printArray(arr1, size);				//print function to print array before sortin
			timeString = ts.GetTime();			//use of timestamp library to prin the time bfore sort
			cout << "\n" << timeString << endl;
			sort.sortDescendingRecurse(arr1, size);		//using sort function to sort recursively in descending order
			cout << "\n SORTING ARRAY USING RECURSION" << endl;
			cout << " ---------------------------" << endl;
			printArray(arr1, size);				//printing the array after sorting
			timeString = ts.GetTime();			//use of timestamp library to prin the time after sort
			cout << "\n" << timeString << endl;
			sort.selectionSortDescending(arr1Copy, size);		//use of sort function to sort copy of original array using iteration
			cout << "\n SORTING ARRAY USING ITERATION" << endl;
			cout << " ---------------------------" << endl;
			printArray(arr1Copy, size);		//printing after sorting
			timeString = ts.GetTime();
			cout << "\n" << timeString << endl;
			cout << "\n SORTING SMALL VECTORS" << endl;
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "\n BEFORE VECTOR SORTING" << endl;
			printArray(numbers1, size);		//printing vector before sort
			timeString = ts.GetTime();
			cout << "\n" << timeString << endl;
			sort.sortDescendingRecurse(numbers1, size);			//use sort function to sort in descending order recursively
			cout << "\n SORTING VECTOR USING RECURSION" << endl;
			cout << " ---------------------------" << endl;
			printArray(numbers1, size);			//printing the vector after sorting
			timeString = ts.GetTime();
			cout << "\n" << timeString << endl;
			sort.selectionSortDescending(numbers1Copy, size);	//use sort function to sort the copy of original vector using iteration
			cout << "\n SORTING VECTOR USING ITERATION" << endl;
			cout << " ---------------------------" << endl;			
			printArray(numbers1Copy, size);			//printing the vector after sorting
			timeString = ts.GetTime();
			cout << "\n" << timeString << endl;

			cout << "\n TIME TAKEN FOR SORTING LARGE ARRAYS IN DESCENDING ORDER" << endl;
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			//cout << " BEFORE SORTING" << endl;
			//cout << timeString << endl;
			cout << "\n TIME BEFORE SORTING LARGE ARRAY USING RECURSION--";	
			timeString = ts.GetTime();
			cout << timeString << endl;
			sort.sortDescendingRecurse(arr2, size1);
			//printArray(arr2, size1);
			cout << "\n TIME AFTER SORTING LARGE ARRAY USING RECURSION--";
			timeString = ts.GetTime();
			cout  << timeString << endl;
			cout << "\n TIME BEFORE SORTING LARGE ARRAY USING ITERATION--";
			timeString = ts.GetTime();
			cout  << timeString << endl;
			sort.selectionSortDescending(arr2Copy, size1);
			//printArray(arr2Copy, size1);
			cout << "\n TIME AFTER SORTING LARGE ARRAY USING ITERATION--";	
			timeString = ts.GetTime();
			cout  << timeString << endl;			

			cout << "\n TIME TAKEN FOR SORTING LARGE VECTORS IN DESCENDING ORDER" << endl;
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			//cout << " BEFORE SORTING" << endl;
			//printArray(numbers2, size1);
			cout << "\n TIME BEFORE SORTING LARGE VECTOR USING RECURSION--";
			timeString = ts.GetTime();
			cout  << timeString << endl;
			sort.sortDescendingRecurse(numbers2, size1);
			//printArray(numbers2, size1);
			cout << "\n TIME AFTER SORTING LARGE VECTOR USING RECURSION--" ;		
			timeString = ts.GetTime();
			cout  << timeString << endl;
			cout << "\n TIME BEFORE SORTING LARGE VECTOR  USING ITERATION--";		
			timeString = ts.GetTime();
			cout << timeString << endl;
			sort.selectionSortDescending(numbers2Copy, size1);
			//printArray(numbers2Copy, size1);
			cout << "\n TIME AFTER SORTING LARGE VECTOR  USING ITERATION--" ;		
		    timeString = ts.GetTime();
			cout  << timeString << endl;
			break;

		default:
			cout << " SORRY !!!! INVALID NUMBER ENTERED\n" << endl;
			break;
		}


		
	cout << "\n PRESS 'Y' or 'y' TO CONTINUE or PRESS ANY KEY TO EXIT : ";
	cin.clear();
	cin.sync();

	cin >> ans;
	choice = 0;
		
	} while ((ans == 'Y') || (ans == 'y'));

}