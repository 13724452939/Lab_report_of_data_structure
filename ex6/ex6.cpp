//#include "pch.h"
#include <iostream>
#include <algorithm>//sort(begin,end,way)
void binary_search(int samples[], int number_of_samples, int key);
using namespace std;
int main()
{
	cout << "Please input the number of tests : ";
	int number_of_tests;
	cin >> number_of_tests;
	cout << "------------------------------------------" << endl;
	while (number_of_tests-- > 0)
	{
		cout << "Please input the number of samples : ";
		int number_of_samples;
		cin >> number_of_samples;
		int * samples = new int[number_of_samples+1];
		samples[0] = number_of_samples;
		cout << "Please input the samples : ";
		for (int i = 0; i < number_of_samples; ++i)
			cin >> samples[i + 1];
		sort(samples + 1, samples + number_of_samples + 1);//Sort(start,end,排序方法)没有第三个参数时默认按升序排序,结束为末尾位置的下一个地址
		//cout << endl << "samples: "; for (int i = 0; i < number_of_samples; ++i) cout << samples[i + 1] << " "; cout << endl;
		cout << "Please input the key :";
		int key;
		cin >> key;
		binary_search(samples, number_of_samples,key);
		delete [] samples;
	}
	return 0;
}
void binary_search(int samples[], int number_of_samples, int key)
{
	int low = 1, high = number_of_samples;//samples[0]存放的是长度number_of_samples
	int mid;
	int times = 0;
	bool judge=false;
	while (low <= high)
	{
		mid = (low + high) / 2;//整形所以默认就是向下取整
		++times;
		if (key == samples[mid])
		{
			judge = true;
			break;	
		}
		else
			if (key < samples[mid])
				high = mid - 1;
			else
				if (key > samples[mid])
					low = mid + 1;
	}
	cout << "----------judge-position-times------------" << endl;
	cout << judge << " ";
	if (true == judge)
		cout << mid << " " << times << endl;
	else
		cout << 0 << " " << times << endl;
	cout << "----------judge-position-times------------" << endl;
}

