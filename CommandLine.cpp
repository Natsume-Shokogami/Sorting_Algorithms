#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Sorting.h"

using namespace std;

bool checkStringAllNumber(char s[])
{
	//Check if the string's character is comprised of number characters, true if it is and false if not
	int size = strlen(s);

	for (int i = 0; i < size; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return false;
	}

	return true;
}

void AlgorithmTimeAndCmpOutput(char algor[], int* &inputArray, int* &tempArray, int size, double &time_out, long long &cmp_out)
{
	CopyArray(inputArray, tempArray, size);
	string algorithm(algor);
	auto start = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span = end - start;
	if (algorithm.compare("insertion-sort") == 0)
	{
		CopyArray(tempArray, inputArray, size);
		cmp_out = 0;
		start = std::chrono::high_resolution_clock::now();
		InsertionSort(inputArray, 0, size-1, cmp_out);
		end = std::chrono::high_resolution_clock::now();

		//Create a new time_span object, put the time counted to algorithmTimeCount array
		time_span = end - start;

		//Measuring time count of each algorithm
		time_out = time_span.count() * 1000;

		//
	}
	else if (algorithm.compare("selection-sort") == 0)
	{
		CopyArray(tempArray, inputArray, size);
		cmp_out = 0;
		start = std::chrono::high_resolution_clock::now();
		SelectionSort(inputArray, size, cmp_out);
		end = std::chrono::high_resolution_clock::now();

		//Create a new time_span object, put the time counted to algorithmTimeCount array
		time_span = end - start;

		//Measuring time count of each algorithm
		time_out = time_span.count() * 1000;
	}
	else if (algorithm.compare("bubble-sort") == 0)
	{
		CopyArray(tempArray, inputArray, size);
		cmp_out = 0;
		start = std::chrono::high_resolution_clock::now();
		BubbleSort(inputArray, size, cmp_out);
		end = std::chrono::high_resolution_clock::now();

		//Create a new time_span object, put the time counted to algorithmTimeCount array
		time_span = end - start;

		//Measuring time count of each algorithm
		time_out = time_span.count() * 1000;
	}
	else if (algorithm.compare("heap-sort") == 0)
	{
		CopyArray(tempArray, inputArray, size);
		cmp_out = 0;
		start = std::chrono::high_resolution_clock::now();
		HeapSort(inputArray, size, cmp_out);
		end = std::chrono::high_resolution_clock::now();

		//Create a new time_span object, put the time counted to algorithmTimeCount array
		time_span = end - start;

		//Measuring time count of each algorithm
		time_out = time_span.count() * 1000;
	}
	else if (algorithm.compare("quick-sort") == 0)
	{
		CopyArray(tempArray, inputArray, size);
		cmp_out = 0;
		start = std::chrono::high_resolution_clock::now();
		QuickSort(inputArray, 0, size - 1, cmp_out);
		end = std::chrono::high_resolution_clock::now();

		//Create a new time_span object, put the time counted to algorithmTimeCount array
		time_span = end - start;

		//Measuring time count of each algorithm
		time_out = time_span.count() * 1000;
	}
	else if (algorithm.compare("merge-sort") == 0)
	{
		CopyArray(tempArray, inputArray, size);
		cmp_out = 0;
		start = std::chrono::high_resolution_clock::now();
		MergeSort(inputArray, 0, size - 1, cmp_out);
		end = std::chrono::high_resolution_clock::now();

		//Create a new time_span object, put the time counted to algorithmTimeCount array
		time_span = end - start;

		//Measuring time
		time_out = time_span.count() * 1000;
	}
	else if (algorithm.compare("shell-sort") == 0)
	{
		CopyArray(tempArray, inputArray, size);
		cmp_out = 0;
		start = std::chrono::high_resolution_clock::now();
		ShellSort(inputArray, size, cmp_out);
		end = std::chrono::high_resolution_clock::now();

		//Create a new time_span object, put the time counted to algorithmTimeCount array
		time_span = end - start;

		//Measuring time
		time_out = time_span.count() * 1000;
	}
	else if (algorithm.compare("flash-sort") == 0)
	{
		CopyArray(tempArray, inputArray, size);
		cmp_out = 0;
		start = std::chrono::high_resolution_clock::now();
		FlashSort(inputArray, size, cmp_out);
		end = std::chrono::high_resolution_clock::now();

		//Create a new time_span object, put the time counted to algorithmTimeCount array
		time_span = end - start;

		//Measuring time count of each algorithm
		time_out = time_span.count() * 1000;
	}
	else if (algorithm.compare("shaker-sort") == 0)
	{
		CopyArray(tempArray, inputArray, size);
		cmp_out = 0;
		start = std::chrono::high_resolution_clock::now();
		ShakerSort(inputArray, size, cmp_out);
		end = std::chrono::high_resolution_clock::now();

		//Create a new time_span object, put the time counted to algorithmTimeCount array
		time_span = end - start;

		//Measuring time count of each algorithm
		time_out = time_span.count() * 1000;
	}
	else if (algorithm.compare("radix-sort") == 0)
	{
		CopyArray(tempArray, inputArray, size);
		cmp_out = 0;
		start = std::chrono::high_resolution_clock::now();
		RadixSort(inputArray, size, cmp_out);
		end = std::chrono::high_resolution_clock::now();

		//Create a new time_span object, put the time counted to algorithmTimeCount array
		time_span = end - start;

		//Measuring time count of each algorithm
		time_out = time_span.count() * 1000;
	}
	else if (algorithm.compare("counting-sort") == 0)
	{
		CopyArray(tempArray, inputArray, size);
		cmp_out = 0;
		start = std::chrono::high_resolution_clock::now();
		CountingSort(inputArray, size, cmp_out);
		end = std::chrono::high_resolution_clock::now();

		//Create a new time_span object, put the time counted to algorithmTimeCount array
		time_span = end - start;

		//Measuring time count of each algorithm
		time_out = time_span.count() * 1000;
	}
	else
	{
		cout << "Error: Sorting algorithm invalid or currently not available" << endl;
		return;
	}
}

void AlgorithmMode(int argc, char **argv)
{
	ifstream inputdata;
	int size = 0;//Size of input array
	int* inputArray;

	//Initialize comparison and time counter
	long long algorithmCmpCount;
	//Initialize an array to store time count of each algorithm
	double algorithmTimeCounter = 0;

	//Initialize the input array based on input command
	switch (argc)
	{
	case 5:
	{
		//Command 1:

		if (!checkStringAllNumber(argv[3]))//Third argument is given input, or command 1
		{
			//Open file specified in the command (Both the execution and input file be in the same folder)
			inputdata.open(argv[3]);

			//If the file is not found, return an error notice and exit
			if (!inputdata.is_open())
			{
				cout << "Error: File not found" << endl;
				return;
			}

			//Get input data from the input file if the file is found
			string data;
			getline(inputdata, data);//Take the first line to indicate how many elements are there in the input file
			size = atoi(data.c_str());
			int i = 0;
			inputArray = new int[size];

			while (getline(inputdata, data, ' ') && i < size)
			{
				inputArray[i] = atoi(data.c_str());
				i++;
			}

			//First part of output for command 4
			cout << "ALGORITHM MODE: " << endl;
			cout << "Input file: " << argv[argc - 2] << endl;
			cout << "Input size: " << size << endl;

			//Initialize temporary array
			int* tempArray = new int[size];
			AlgorithmTimeAndCmpOutput(argv[2], inputArray, tempArray, size, algorithmTimeCounter, algorithmCmpCount);

			//Output running time and comparison count of the algorithm 
			cout << "-------------------------------------------------------------" << endl;
			string outputArgument(argv[argc - 1]);
			if (outputArgument.compare("-time") == 0 || outputArgument.compare("-both") == 0)
			{
				cout << "Running Time: " << algorithmTimeCounter << " ms  " << endl;
			}
			if (outputArgument.compare("-comp") == 0 || outputArgument.compare("-both") == 0)
			{
				cout << "Comparisons: " << algorithmCmpCount << endl;
			}
			else
			{
				cout << "Invalid output parameter" << endl;
				return;
			}
			inputdata.close();
		}
		else
		{
			//Command 3:
			size = atoi(argv[3]);
			
			cout << "ALGORITHM MODE: " << endl;
			cout << "Input size: " << size << endl;
			inputArray = new int[size];
			int* tempArray = new int[size];

			for (int i = 0; i < 4; i++)
			{
				GenerateData(inputArray, size, i);
				AlgorithmTimeAndCmpOutput(argv[2], inputArray, tempArray, size, algorithmTimeCounter, algorithmCmpCount);
				switch (i)
				{
				case 0:
				{
					cout << "\nRandom data:" << endl;
					break;
				}
				case 1:
				{
					cout << "\nSorted data:" << endl;
					break;
				}
				case 2:
				{
					cout << "\nReversed data:" << endl;
					break;
				}
				case 3:
				{
					cout << "\nNearly sorted data:" << endl;
					break;
				}
				}

				//Output running time and comparison count of the algorithm 
				cout << "-------------------------------------------------------------" << endl;
				string outputArgument(argv[argc - 1]);
				if (outputArgument.compare("-time") == 0 || outputArgument.compare("-both") == 0)
				{
					cout << "Running Time: " << algorithmTimeCounter << " ms  " << endl;
				}
				if (outputArgument.compare("-comp") == 0 || outputArgument.compare("-both") == 0)
				{
					cout << "Comparisons: " << algorithmCmpCount << endl;
				}
				else
				{
					cout << "Invalid output parameter" << endl;
					return;
				}
			}

		}
		

		break;
	}
	case 6:
	{
		//Command 2
		size = atoi(argv[3]);
		inputArray = new int[size];
		int *tempArray = new int[size];
		string inputOrder(argv[4]);

		//First part of output for command 5
		cout << "ALGORITHM MODE: " << endl;
		cout << "Input size: " << argv[3] << endl;
		cout << "Input order: ";

		if (inputOrder.compare("-rand") == 0)
		{
			GenerateRandomData(inputArray, size);
			cout << "Random" << endl;
		}
		else if (inputOrder.compare("-nsorted") == 0)
		{
			GenerateNearlySortedData(inputArray, size);
			cout << "Nearly sorted" << endl;
		}
		else if (inputOrder.compare("-sorted") == 0)
		{
			GenerateSortedData(inputArray, size);
			cout << "Sorted" << endl;
		}
		else if (inputOrder.compare("-rev") == 0)
		{
			GenerateReverseData(inputArray, size);
			cout << "Reversed" << endl;
		}
		else
		{
			cout << "Error: Invalid input order" << endl;
			return;
		}
		AlgorithmTimeAndCmpOutput(argv[2], inputArray, tempArray, size, algorithmTimeCounter, algorithmCmpCount);
		//Output running time and comparison count of the algorithm 
		cout << "-------------------------------------------------------------" << endl;
		string outputArgument(argv[5]);
		if (outputArgument.compare("-time") == 0 || outputArgument.compare("-both") == 0)
		{
			cout << "Running Time: " << algorithmTimeCounter << " ms  " << endl;
		}
		if (outputArgument.compare("-comp") == 0 || outputArgument.compare("-both") == 0)
		{
			cout << "Comparisons: " << algorithmCmpCount << endl;
		}
		else
		{
			cout << "Invalid output parameter" << endl;
			return;
		}

		break;
	}
	default:
	{
		///Not enough / excessive arguments
		cout << "Error: Invalid arguments" << endl;
		return;
	}
	}

	
}

void ComparisonMode(int argc, char **argv)
{
	ifstream inputdata;
	int size;//Size of input array
	int* inputArray;
	//Initialize the input array based on input command
	switch (argc)
	{
	case 6:
	{
		//Command 4:

		//Open file specified in the command (Both the execution and input file be in the same folder)
		inputdata.open(argv[4]);

		//If the file is not found, return an error notice and exit
		if (!inputdata.is_open())
		{
			cout << "Error: File not found" << endl;
			return;
		}

		//Get input data from the input file if the file is found
		string data;
		getline(inputdata, data);//Take the first line to indicate how many elements are there in the input file
		size = atoi(data.c_str()); 
		int i = 0;
		inputArray = new int[size];

		while (getline(inputdata, data, ' ') && i < size)
		{
			inputArray[i] = atoi(data.c_str());
			i++;
		}
		inputdata.close();
		//First part of output for command 4
		cout << "COMPARISON MODE: " << endl;
		cout << "Input file: " << argv[argc - 2] << endl;
		cout << "Input size: " << size << endl;

		break;
	}
	case 7:
	{
		//Command 5
		size = atoi(argv[4]);
		inputArray = new int[size];
		string inputOrder(argv[argc-2]);

		//First part of output for command 5
		cout << "COMPARISON MODE: " << endl;
		cout << "Input size: " << argv[argc - 3] << endl;
		cout << "Input order: ";

		if (inputOrder.compare("-rand") == 0)
		{
			GenerateRandomData(inputArray, size);
			cout << "Random" << endl;
		}
		else if (inputOrder.compare("-nsorted") == 0)
		{
			GenerateNearlySortedData(inputArray, size);
			cout << "Nearly sorted" << endl;
		}
		else if (inputOrder.compare("-sorted") == 0)
		{
			GenerateSortedData(inputArray, size);
			cout << "Sorted" << endl;
		}
		else if (inputOrder.compare("-rev") == 0)
		{
			GenerateReverseData(inputArray, size);
			cout << "Reversed" << endl;
		}
		else
		{
			cout << "Error: Invalid input order" << endl;
			return;
		}
		break;
	}
	default:
	{
		///Not enough / excessive arguments
		cout << "Error: Invalid arguments" << endl;
		return;
	}
	}
	
	//Initialize comparison and time counter
	long long algorithmCmpCounter[2];


	//Initialize an array to store time count of each algorithm
	double algorithmTimeCount[2];

	//Initialize temporary array
	int* tempArray = new int[size];

	//string algorithmString[2] = {a1, a2};
	for (int i = 0; i < 2; i++)
	{
		AlgorithmTimeAndCmpOutput(argv[i + 2], inputArray, tempArray, size, algorithmTimeCount[i], algorithmCmpCounter[i]);

	}

	//Output running time and comparison count of each algorithm 
	cout << "-------------------------------------------------------------" << endl;
	string outputArgument(argv[argc - 1]);
	if (outputArgument.compare("-time") == 0 || outputArgument.compare("-both") == 0)
	{
		cout << "Running Time: " << algorithmTimeCount[0] << " ms  |  " << algorithmTimeCount[1] << " ms " << endl;
	}
	if (outputArgument.compare("-comp") == 0 || outputArgument.compare("-both") == 0)
	{
		cout << "Comparisons: " << algorithmCmpCounter[0] << " | " << algorithmCmpCounter[1] << endl;
	}
	else
	{
		cout << "Invalid output parameter" << endl;
		return;
	}
}

void CommandOutput(int argc, char *argv[])
{
	if (argc <= 1 || argc > 7)
	{
		cout << "Error: Too few or too much argument " << endl;
		return;
	}

	if (strcmp(argv[1], "-a") == 0)
		return AlgorithmMode(argc, argv);
	else if (strcmp(argv[1], "-c") == 0)
		return ComparisonMode(argc, argv);
	else//Error code
		cout << "Error: No such mode found" << endl;

}

int main(int argc, char* argv[])
{
	CommandOutput(argc, argv);
	return 1;
}
