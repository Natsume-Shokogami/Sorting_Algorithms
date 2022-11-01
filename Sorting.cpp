#pragma once
#include "stdafx.h"
#include "Sorting.h"

using namespace std;

template <class type>
void Swap(type a, type b)
{
	type t = a;
	a = b;
	b = t;
}

void CopyArray(int* &source, int* &des, int n)
{
	//Copy all elements from array source to array des (both arrays have the same size n)
	for (int i = 0; i < n; i++)
		des[i] = source[i];
}

void Heapify(int* &a, int n, int i, int &count_cmp)
{
		//Heapify elements in subtree a[i]
	int largest = i;
	while (++count_cmp && i < n)
	{
		largest = i;
		if (++count_cmp && a[2 * i + 1] > a[2 * i + 2] && 2 * i + 1 < n)
			largest = 2 * i + 1;
		if (++count_cmp && a[2 * i + 2] > a[2 * i + 1] && 2 * i + 2 < n)
			largest = 2 * i + 2;

		/*a[i] must be more significant (in this case, larger) than its children
		,a[2*i+1] and a[2*i+2] to be a heap, swapthem if they are in incorrect positions*/
		//Also continue heapify if a[i] is not the largest
		if (++count_cmp && a[i] < a[largest]) {
			Swap(a[i], a[largest]);
			i = largest;
			/*This funtion use iterative heapify to reduce recursive call (thus reduce recursion level)
			to prevent stack overflow at high array size (>120000)*/
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* &a, int n, int &count_cmp)
{
	//Build a max heap
	for (int i = (n - 1) / 2; i >= 0; i--)
		Heapify(a, n, i, count_cmp);

	//Swap a[0] (largest element in the max heap and reheapify array a
	for (int i = n - 1; i >= 0; i--)
	{
		Swap(a[i], a[0]);
		Heapify(a, i, 0, count_cmp);
	}
}

void Merge(int* &a, int* &tempArray, int left, int mid, int right, int &count_cmp)
{
	//
	int LArrayCount = mid - left + 1;
	int RArrayCount = right - mid;

	int i, j, K;

	//Copy elements from the array to two part of the temp array
	for (i = 0; ++count_cmp && i < LArrayCount; i++)
	{
		tempArray[left + i] = a[left + i];
	}
	for (j = 0; ++count_cmp && j < RArrayCount; j++)
	{
		tempArray[mid + 1 + j] = a[mid + 1 + j];
	}

	//Merge two parts of the temp array to the main arrays
	i = 0; j = 0, K = 0;
	while (++count_cmp && i < LArrayCount && j < RArrayCount)
	{
		if (++count_cmp && tempArray[left + i] <= tempArray[mid + 1 + j])
		{
			a[left + K] = tempArray[left + i];
			i++; K++;
		}
		else //LTempArr[i]>RTempArr[j]
		{
			a[left + K] = tempArray[mid + 1 + j];
			j++; K++;
		}
	}

	//Copy the remaining elements of temporary array to array a
	while (++count_cmp && i < LArrayCount)
	{
		a[left + K] = tempArray[left + i];
		i++; K++;
	}
	while (++count_cmp && j < RArrayCount)
	{
		a[left + K] = tempArray[mid + 1 + j];
		j++; K++;
	}

}


int Min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

//Algorithm based on this article: Iterative Mergesort - Shivam Argawal - Last updated: 03 Oct 2022
//Link: https://www.geeksforgeeks.org/iterative-merge-sort/ - In turn based from: http://csg.sph.umich.edu/abecasis/class/2006/615.09.pdf
//Optimization: 1/ Iterative merge sort used instead of recursive one; Reason: Large size of array -> High recursive level
//->Stack Overflow
//2/ Temporary array initialized once outside of the merge function -> Only need to free memory once -> Significantly improve
//execution time
void MergeSort(int* &a, int left, int right, int &count_cmp)
{
	if (left >= right)
		return;//base case

	int *tempArray = new int[right - left + 1];
	CopyArray(a, tempArray, right - left + 1);
	int curSize, leftStart,  mid, rightEnd;
	for (curSize = 1; curSize <= right - 1; curSize *= 2)
	{
		for (leftStart = left; leftStart < right; leftStart += 2 * curSize)
		{
			mid = Min(leftStart + curSize - 1, right);  ++count_cmp;
				rightEnd = Min(leftStart + 2 * curSize - 1, right);  ++count_cmp;
			Merge(a, tempArray, leftStart, mid, rightEnd, count_cmp);
		}
	}
	delete tempArray;
	/*int mid = (left + right) / 2;
	MergeSort(a, left, mid);
	MergeSort(a, mid + 1, right);
	Merge(a, left, mid, right);*/
}




/* Quick sort reference- Link: https://www.algolist.net/Algorithms/Sorting/Quicksort
Date: Unknown, likely 2009 - Author: AlgoList - Title: QuickSort*/


void QuickSort(int* &a, int left, int right, int &count_cmp)
{
	int i = left, j = right;
	//Initiate the pivot at middle of each subarray to avoid the worst case
	//with sorted or reversed array
	int pivot = a[left + (right - left) / 2];

	//Partition
	while (++count_cmp && i <= j)
	{
		while (++count_cmp && a[i] < pivot)
			i++;
		while (++count_cmp && a[j] > pivot)
			j--;

		if (++count_cmp && i <= j) {

			Swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	//Recursion to partion each half of the subarray
	if (++count_cmp && left < j)
	{
		QuickSort(a, left, j, count_cmp);
	}
	if (++count_cmp && i < right)
	{
		QuickSort(a, i, right, count_cmp);
	}
}

int GetMax(int* a, int n)
{
	//Return the value of the element having greatest value in array a
	if (n <= 0)
		return INT_MIN; //Error code if the number of element in a<= 0

	//Initiate the first max value is the value of the array's first element
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	return max;
}

//Pseudocode learnt from the course's theoretical classes
void RadixSort(int* &a, int n, int &count_cmp)
{
	int max = GetMax(a, n), greatestRadix = 0, i, j, k, exp = 1;
	int count[10];

	//Find how many degit of the greatest element of array a has
	for (i = max; ++count_cmp && i > 0; i/= 10)
	{ 
		greatestRadix++;
	}

	/*Initialize a 2D count array with 10 rows(or 10 buckets from 0 to 9)
	and n columns */
	int **bucket = new int*[10];
	for (i = 0; ++count_cmp && i < 10; i++)
	{
		bucket[i] = new int[n];
		count[i] = 0;//Place the counter of each bucket to 0
	}

	for (j = greatestRadix; ++count_cmp && j > 0; j--)
	{
		for (i = 0; ++count_cmp && i < 10; i++)
			count[i] = 0;//Reset each bucket counter to 0
		for (i = 0; ++count_cmp && i < n; i++)
		{
			//Place each element of a to each bucket and increase counter of that bucket by 1
			//Exp = 10 ^ i; exp is used to extract the i st/nd/rd/th digit of each element
			bucket[(a[i] / exp) % 10][count[(a[i] / exp) % 10]] = a[i];
			count[(a[i] / exp) % 10]++;			
		}

		//Copy each element from each bucket to the appropriate position in array a
		k = 0;
		for (i = 0; ++count_cmp && i < 10; i++)
		{
			for (int l = 0; ++count_cmp && l < count[i]; l++)
			{
				a[k] = bucket[i][l];
				k++;
			}
		}

		//Multiply exp by 10 to extract the next digit
		exp *= 10;
	}
}

//Citation: GeeksforGeeks Insertion sort
//Link: https://www.geeksforgeeks.org/insertion-sort/
//Author: N/A ; Last updated: 18 Oct 2022
//Secondary: Programming Pearls - Jon Louis Bentley - 2000 - Page 116
void InsertionSort(int* &a, int n, int &count_cmp)
{
	count_cmp = 0;
	//Function to do
	int i, j, key;
	for (i = 1; ++count_cmp && i < n; i++)
	{
		key = a[i];
		j = i - 1;
		//Move element of a[0...i-1] that higher than key towards one index
		while (++count_cmp && j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		//Place the element with value key before the element just greater than it
		a[j + 1] = key;
	}
}

//Flash sort
/* Citiation link: https://www.w3resource.com/javascript-exercises/searching-and-sorting-algorithm/searching-and-sorting-algorithm-exercise-12.php (Source code based on there)*/
/* Last updated: August 19 2022*/
//Code in the first source is in Javascript
/*Second citation: https://codelearn.io/sharing/flash-sort-thuat-toan-sap-xep-than-thanh
Author: HaiDuc014, Last updated: March 18 2021*/
//Code copies from the source due to unknown bug in my code
void FlashSort(int* &a, int n, int &count_cmp)
{
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0;++count_cmp && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++count_cmp && i < n; i++)
	{
		if (++count_cmp && a[i] < minVal)
			minVal = a[i];
		if (++count_cmp && a[i] > a[max])
			max = i;
	}
	if (++count_cmp && a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; ++count_cmp && i < m; i++)
		l[i] += l[i - 1];
	HoanVi(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (++count_cmp && nmove < n - 1)
	{
		while (++count_cmp && j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		if (++count_cmp && k < 0) break;
		while (j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	InsertionSort(a, n, count_cmp);

	//int max = 0, min = a[0];
	//int i, j, k;

	////Initialize the relative number of buckets
	//int bucketCount = int(0.45 * n);
	//int *bucket = new int[bucketCount];

	////Finding the minimum element and maximum element index of the array a
	//for (i = 1; ++count_cmp && i < n; i++)
	//{
	//	if (++count_cmp && a[i] < min)
	//	{
	//		min = a[i];
	//	}
	//	if (++count_cmp && a[i] > a[max])
	//	{
	//		max = i;
	//	}
	//}

	////If min element equals to maximum element in array a (or all elements have the same value)
	////, do nothing
	//if (++count_cmp && min == a[max])
	//	return;

	//double c1 = (double)(bucketCount - 1) / (a[max] - min);

	//for (k = 0; ++count_cmp && k < bucketCount; k++)
	//{
	//	bucket[k] = 0;
	//}
	//for (j = 0; ++count_cmp && j < n; j++) {
	//	k = int(c1*(a[j] - min));
	//	++bucket[k];
	//}

	//for (int p = 1; ++count_cmp && p < bucketCount; p++)
	//{
	//	bucket[p] += bucket[p - 1];
	//}
	//
	////Permutation
	//int move = 0, t, flash;
	//j = 0;
	//Swap(a[max], a[0]);

	//while (++count_cmp && move < n - 1)
	//{
	//	while (++count_cmp && j > bucket[k] - 1)
	//	{
	//		++j;
	//		k = int(c1 * (a[j] - min));
	//	}
	//	if (++count_cmp && k < 0)
	//		break;
	//	flash = a[j];
	//	while (++count_cmp && j != bucket[k])
	//	{
	//		k = int(c1*(flash - min));
	//		t = --bucket[k];
	//		Swap(a[t], flash);
	//		move++;
	//	}
	//}

	////Insertion sort is used after each element are put in its apporiate bucket
	//InsertionSort(a, n, count_cmp);
	//delete[] bucket;
}

void SelectionSort(int* &a, int n, int &count_cmp)
{
	//Function to do selection sort with comparison counter
	int maxIndex;
	for (int i = 0; ++count_cmp && i < n - 1; i++)
	{
		maxIndex = i;
		for (int j = i + 1; ++count_cmp && j < n; j++)
		{
			if (++count_cmp && a[j] > a[maxIndex])
				maxIndex = j;
		}
		Swap(a[i], a[maxIndex]);
	}
}

//Reference: Done by myself
void BubbleSort(int* &a, int n, int &count_cmp)
{
	//Function  to do bubble sort
	for (int i = 0; i<n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] > a[i])
				Swap(a[j], a[i]);
		}
}


//Title : ShellSort - Author: GeekforGeeks - Last updated: 24 Oct 2022
void ShellSort(int* &a, int n, int &count_cmp)
{
	int temp, i, j;
	//Start with a big gap first, then reduce the gap interval by 1 each time
	for (int gap = n / 2; ++count_cmp && gap > 0; gap--)
	{
		//Do an insertion sort starts from position gap with the length of each move equals to the gap
		for (i = gap; i < n; i++)
		{
			temp = a[i];
			//Insertion
			for (j = i; ++count_cmp && j >= gap && a[j - gap] > temp; j = j - gap)
			{
				a[j] = a[j - gap];
			}
		}
		//Insert temp to the apporiate position
		a[j] = temp;
	}
}

// Reference link: https://www.stdio.vn/giai-thuat-lap-trinh/bubble-sort-va-shaker-sort-01Si3U
//Title: Bubble Sort và Shaker Sort - Author: Shiro Nguyen - Last updated: August 18 2020
//Source code not by me
void ShakerSort(int* &a, int n, int &count_cmp)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (++count_cmp && Left < Right)
	{
		for (int i = Left; ++count_cmp && i < Right; i++)
		{
			if (++count_cmp &&a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; ++count_cmp && i > Left; i--)
		{
			if (++count_cmp && a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}

//Citation: Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.; Stein, Clifford (2001),
//"8.2 Counting Sort", Introduction to Algorithms (2nd ed.) - pp.168 - 170
//(Algorithm from an Wikipedia page (Counting sort) linked to that book
//Second reference: https://github.com/jainaman224/Algo_Ds_Notes/tree/master/Counting_Sort/
//Title: Counting_Sort
//Author: somya-kapoor -Last updated:25 May 2019
void CountingSort(int* &a, int n, int &count_cmp)
{
	count_cmp = 0;
	int* Output = new int[n];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	int countArraySize = GetMax(a, n) - min, i;
	int* countArray = new int[countArraySize - min + 1];

	//Initialize the countArray array with zeros
	for (i = 0; ++count_cmp && i < countArraySize - min + 1; i++)
	{
		countArray[i] = 0;
	}

	//If an element with value a[i] is meet, increase the a[i] bucket counter by one
	for (i = 0; ++count_cmp && i < n; ++i)
	{
		countArray[a[i] - min]++;
	}

	//Change the value of each bucket corresponding to the real value in the output array
	for (int i = 1; ++count_cmp && i < countArraySize - min + 1; i++)
	{
		countArray[i] += countArray[i - 1];
	}

	//Generate output array
	for (int i = 0; ++count_cmp && i < n; i++)
	{

		Output[countArray[a[i] - min] - 1] = a[i];
		countArray[a[i] - min]--;
	}

	//Copy output array to array a
	CopyArray(Output, a, n);

	//Delete temporary arrays
	delete[] countArray;
	delete[] Output;
}



