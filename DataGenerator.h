#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>


template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}
void GenerateRandomData(int a[], int n);


// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n);


// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n);


// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n);

void GenerateData(int a[], int n, int dataType);

