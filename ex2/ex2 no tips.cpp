#include<iostream>
using namespace std;

struct linked_list{
	int data;
	linked_list *next;
};

void output_linked_list(linked_list *head_pointer);
linked_list * creat_linked_list(int linked_list_data,linked_list *former_pointer); 
void input_position_output_corresponding_data(linked_list *head_pointer,int length);
void insert_new_data(linked_list *head_pointer,int length);
void delete_data(linked_list *head_pointer,int length);
linked_list * delete_linked_list(linked_list *p);
int main()
{
	int length;
	cin >> length;//读取顺序表长度 
	linked_list *head_pointer=new linked_list;//头指针 
	if (length<=0)
	{
		cout << "Sorry,the length is wrong, can not be established.";
		delete head_pointer;//如果长度不合法就要删除创建的动态头指针并且结束程序 
		return 0;
	}
	int *data_list=new int [length]; 
	for (int i=0;i<length;++i)
		cin >> data_list[i];//输入顺序表中元素
	linked_list *control_pointer=new linked_list;//工具指针 
	control_pointer=creat_linked_list(data_list[0],head_pointer);//因为第一个所以是头指针 
	for (int i=1;i<length;++i)
		control_pointer=creat_linked_list(data_list[i],control_pointer);//创建单链表 
	output_linked_list(head_pointer);
	input_position_output_corresponding_data(head_pointer,length);
	insert_new_data(head_pointer,length);
	output_linked_list(head_pointer);
	delete_data(head_pointer,length);
	output_linked_list(head_pointer);	
	
	//删除动态内存 
	control_pointer=head_pointer->next;
	while(control_pointer!=NULL)
		control_pointer=delete_linked_list(control_pointer);
	delete control_pointer;
	delete head_pointer;
	delete [] data_list;
	return 0;
}

linked_list * creat_linked_list(int linked_list_data,linked_list *former_pointer)
{
	linked_list *p=new linked_list;//p指针是当前顺序的地址 
	p->data=linked_list_data;
	former_pointer->next=p;
	p->next=NULL;
	return p;
} 

linked_list * delete_linked_list(linked_list *p)
{
	linked_list *next_pointer=p->next;
	delete p;
	return next_pointer;
}

void output_linked_list(linked_list *head_pointer)
{
	linked_list *p=head_pointer->next;
	do
	{
		cout << p->data << ' ';
		p=p->next;	
	}while(p!=NULL);
	cout << endl;
}

void input_position_output_corresponding_data(linked_list *head_pointer,int length)
{
	int location_find;
	cin.sync();
	cin >> location_find;//查找数据的位置
	if ((location_find>length) || (location_find<=0)) 
		cout << "sorry,this location has no data." << endl;
	else
	{
		linked_list *p=head_pointer;
		for (int i=0;i<location_find;++i)
			p=p->next;
		cout << p->data << endl;
	}
}

void insert_new_data(linked_list *head_pointer,int length)
{
	int location_insert;
	cin.sync();
	cin >> location_insert;//插入新数据的位置 
	if ((location_insert>length+1) || (location_insert<=0))
	{
		cout << "sorry,you insert the new data in the wrong place." << endl;
		return;
	}
	int data_insert;
	cin >> data_insert;//插入的新数据 
	linked_list *p=head_pointer;
	linked_list *new_insert=new linked_list;
	new_insert->data=data_insert;
	for (int i=1;i<location_insert;++i)
		p=p->next;
	new_insert->next=p->next;
	p->next=new_insert;
}

void delete_data(linked_list *head_pointer,int length)
{
	int location_delete;
	cin.sync();
	cin >> location_delete;//待删除数据的位置 
	if ((location_delete>length+1) || (location_delete<=0))//如果要删除的位置大于该顺序表长度或者小于等于0则表明输入有误 
		cout << "sorry,the location of the data you want to delete is wrong." << endl;
	else
	{ 
		linked_list *p=head_pointer;
		for (int i=1;i<location_delete;++i)
			p=p->next;
		linked_list *delete_pointer=p->next;
		p->next=p->next->next;
		delete delete_pointer;//因为删除节点所以要现在就释放这个动态内存 不然找不到该地址会造成消耗内存问题 
	} 
}
