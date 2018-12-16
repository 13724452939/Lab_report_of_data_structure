//#include "pch.h"
#include <iostream>
using namespace std;
void quick_sort(int samples[], int low, int high);
int main()
{
	cout << "Please input the number of samples : ";
	int number_of_samples;
	cin >> number_of_samples;
	if (number_of_samples < 0)
		return -1;
	cout << "Please input the samples : ";
	int *samples = new int[number_of_samples + 1];
	samples[0] = number_of_samples;
	for (int i = 0; i < number_of_samples; ++i)
		cin >> samples[i + 1];
	cout << "---------------------" << endl << "original sample sequence    : ";
	for (int i = 0; i < number_of_samples; ++i)
		cout << samples[i + 1] << " ";
	quick_sort(samples, 1, number_of_samples);
	cout << endl << "final quick sort result     : ";
	for (int i = 0; i < number_of_samples; ++i)
		cout << samples[i + 1] << " ";
	delete[] samples;
	return 0;
}
int QUICK_SORT_TIMES = 0;//为了输出第一次快速排序结果而设置
void quick_sort(int samples[], int low, int high)
{
	if (low >= high)
		return;
	int pivotkey = samples[low], empty_location = low, left = low, right = high;
	++QUICK_SORT_TIMES;
	while (low < high)
	{
		for (; high > low; --high)
			if (samples[high] < pivotkey)
			{
				samples[empty_location] = samples[high];
				empty_location = high;
				++low;
				break;
			}
		for (; high > low; ++low)
			if (samples[low] > pivotkey)
			{
				samples[empty_location] = samples[low];
				empty_location = low;
				--high;
				break;
			}
	}
	samples[empty_location] = pivotkey;
	if (1 == QUICK_SORT_TIMES)
	{
		cout << endl << "the first quick sort result : ";
		for (int i = 0; i < samples[0]; ++i)
			cout << samples[i + 1] << " ";
	}
	quick_sort(samples, left, empty_location - 1);
	quick_sort(samples, empty_location + 1, right);
}
