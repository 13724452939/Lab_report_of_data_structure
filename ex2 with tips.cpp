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
	cout << "the length of sequence list is:";
	cin >> length;//��ȡ˳����� 
	linked_list *head_pointer=new linked_list;//ͷָ�� 
	if (length<=0)
	{
		cout << "Sorry,the length is wrong, can not be established.";
		delete head_pointer;//������Ȳ��Ϸ���Ҫɾ�������Ķ�̬ͷָ�벢�ҽ������� 
		return 0;
	}
	int *data_list=new int [length]; 
	for (int i=0;i<length;++i)
	{
		cout << "the " << (i+1) << " data is:";
		cin >> data_list[i];
	}//����˳�����Ԫ��
	linked_list *control_pointer=new linked_list;//����ָ�� 
	control_pointer=creat_linked_list(data_list[0],head_pointer);//��Ϊ��һ��������ͷָ�� 
	for (int i=1;i<length;++i)
		control_pointer=creat_linked_list(data_list[i],control_pointer);//���������� 
	output_linked_list(head_pointer);
	input_position_output_corresponding_data(head_pointer,length);
	insert_new_data(head_pointer,length);
	output_linked_list(head_pointer);
	delete_data(head_pointer,length);
	output_linked_list(head_pointer);	
	
	//ɾ����̬�ڴ� 
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
	linked_list *p=new linked_list;//pָ���ǵ�ǰ˳��ĵ�ַ 
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
	cout << "the location you want to know:";
	int location_find;
	cin.sync();
	cin >> location_find;//�������ݵ�λ��
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
	cout << "where do you want to insert new data:";
	int location_insert;
	cin.sync();
	cin >> location_insert;//���������ݵ�λ�� 
	if ((location_insert>length+1) || (location_insert<=0))
	{
		cout << "sorry,you insert the new data in the wrong place." << endl;
		return;
	}
	cout << "the data you want to insert:";
	int data_insert;
	cin >> data_insert;//����������� 
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
	cout << "where do you want to delete data element:";
	int location_delete;
	cin.sync();
	cin >> location_delete;//��ɾ�����ݵ�λ�� 
	if ((location_delete>length+1) || (location_delete<=0))//���Ҫɾ����λ�ô��ڸ�˳����Ȼ���С�ڵ���0������������� 
		cout << "sorry,the location of the data you want to delete is wrong." << endl;
	else
	{ 
		linked_list *p=head_pointer;
		for (int i=1;i<location_delete;++i)
			p=p->next;
		linked_list *delete_pointer=p->next;
		p->next=p->next->next;
		delete delete_pointer;//��Ϊɾ���ڵ�����Ҫ���ھ��ͷ������̬�ڴ� ��Ȼ�Ҳ����õ�ַ����������ڴ����� 
	} 
}
