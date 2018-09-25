#include<iostream>
#include<climits>
using namespace std;
void output_sequence_list(int sequence_list[],int length);
void input_position_output_corresponding_data(int sequence_list[],int length);
void insert_new_data(int sequence_list[],int length);
void delete_data(int sequence_list[],int length);
int main()
{
	int length;
	cout << "the length of sequence list is:";
	cin >> length;//读取顺序表长度 
	int *sequence_list=new int [length+1];//要插入一个元素所以要多一个长度 
	for (int i=0;i<length+1;i++)
		sequence_list[i]=INT_MIN;//初始化全部元素为一常数 输出顺序表时对应元素若为该常数说明未进行定义 
	cout << "now input data:" << endl;
	for (int i=0;i<length;++i)
	{
		cout << "the " << (i+1) << " data is:";
		cin >> sequence_list[i];
	}//输入顺序表中元素 
	output_sequence_list(sequence_list,length);
	input_position_output_corresponding_data(sequence_list,length);
	insert_new_data(sequence_list,length);
	output_sequence_list(sequence_list,length);
	delete_data(sequence_list,length);
	output_sequence_list(sequence_list,length);
	delete [] sequence_list;
	return 0;
}

void output_sequence_list(int sequence_list[],int length)
{
	cout << "----------------" << endl;
	cout << "output sequence list now:" << endl;
	for (int i=0;i<(length+1);++i)
		if (sequence_list[i]==INT_MIN)
			continue;
		else 
			cout << sequence_list[i] << " ";
	cout << endl << "----------------" << endl;
}

void input_position_output_corresponding_data(int sequence_list[],int length)
{
	cout << "the location you want to know:";
	int location_find;
	cin >> location_find;//查找数据的位置 
	if ((location_find>length+1) || (location_find<=0) || (sequence_list[location_find-1]==INT_MIN))
		cout << "sorry,this location has no data." << endl;
	else
		cout << sequence_list[location_find-1] << endl;
}

void insert_new_data(int sequence_list[],int length)
{
	cout << "where you want to insert new data:";
	int location_insert;
	cin >> location_insert;//插入新数据的位置 
	if ((location_insert>length+1) || (location_insert<=0))
	{
		cout << "sorry,you insert the new data in the wrong place." << endl;
		return;
	}
	cout << "the data you want to insert:";
	int data_insert;
	cin >> data_insert;//插入的新数据 
	for (int i=length;i>=location_insert;--i)
		sequence_list[i]=sequence_list[i-1];
	sequence_list[location_insert-1]=data_insert;
}

void delete_data(int sequence_list[],int length)
{
	cout << "where do you want to delete data element:";
	int location_delete;
	cin >> location_delete;//待删除数据的位置 
	if ((location_delete>length+1) || (location_delete<=0))//如果要删除的位置大于该顺序表长度或者小于等于0则表明输入有误 
		cout << "sorry,the location of the data you want to delete is wrong." << endl;
	else
	{ 
		for (int i=location_delete-1;i<length;++i)
			sequence_list[i]=sequence_list[i+1];
		sequence_list[length]=INT_MIN;
	} 
}
