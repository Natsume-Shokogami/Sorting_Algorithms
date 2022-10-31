#pragma once
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <climits>
#include "DataGenerator.h"

using namespace std;

template <class type>
void Swap(type a, type b);

void CopyArray(int* &source, int* &des, int n);

void Heapify(int* &a, int n, int i, int &count_cmp);

void HeapSort(int* &a, int n, int &count_cmp);

void Merge(int* &a, int* &tempArray, int left, int mid, int right, int &count_cmp);

int Min(int a, int b);

void MergeSort(int* &a, int left, int right, int &count_cmp);

void QuickSort(int* &a, int left, int right, int &count_cmp);

int GetMax(int* a, int n);

void RadixSort(int* &a, int n, int &count_cmp);

void InsertionSort(int* &a, int n, int &count_cmp);

void FlashSort(int* &a, int n, int &count_cmp);

void SelectionSort(int* &a, int n, int &count_cmp);

void BubbleSort(int* &a, int n, int &count_cmp);

void ShellSort(int* &a, int n, int &count_cmp);

void ShakerSort(int* &a, int n, int &count_cmp);

void CountingSort(int* &a, int n, int &count_cmp);



