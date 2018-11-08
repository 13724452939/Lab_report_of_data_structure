#include <iostream>
using namespace std;
struct node{
	char data;
	node *left_child,*right_child;
};
int NUMBER_OF_NEW_NODE=0;//全局变量用来统计 
node * creat_binary_tree(const int number,node *p,const char data_stored_sequentially[]);
node * delete_binary_tree(node *p);
node * pre_order_traverse(node *p);
node * in_order_traverse(node *p);
node * post_order_traverse(node *p);
int main() 
{
	int number;
	cout << "the number of nodes in the binary tree: ";
	cin >> number;
	cin.get();
	if (number<=0)
	{
		cout << "wrong input." << endl;
		return 0; 
	}
	char * data_stored_sequentially=new char [number];
	for (int i=0;i<number;++i)
	{
		data_stored_sequentially[i]=cin.get();
		if (data_stored_sequentially[i]==' ' || data_stored_sequentially[i]=='	' || data_stored_sequentially[i]=='\n')
			--i;
	}
	node *root=new node;//二叉树根节点 
	root=creat_binary_tree(number,root,data_stored_sequentially);
	delete [] data_stored_sequentially;//释放存放结点的字符数组 
	cout << endl << "--------------" <<endl;
	cout << "pre_order : ";
	root=pre_order_traverse(root);
	cout << endl;
	cout << "in_order  : ";
	root=in_order_traverse(root);
	cout << endl;
	cout << "post_order: ";
	root=post_order_traverse(root);
	root=delete_binary_tree(root);//删除二叉树 释放动态空间 
	return 0;
}

node * creat_binary_tree(const int number,node *p,const char data_stored_sequentially[])
{
	++NUMBER_OF_NEW_NODE;
	if (NUMBER_OF_NEW_NODE>number || data_stored_sequentially[NUMBER_OF_NEW_NODE-1]=='0')
		return NULL;
	if (NUMBER_OF_NEW_NODE!=1)
		p=new node;
	p->data=data_stored_sequentially[NUMBER_OF_NEW_NODE-1];
	p->left_child=creat_binary_tree(number,p->left_child,data_stored_sequentially);
	p->right_child=creat_binary_tree(number,p->right_child,data_stored_sequentially);
	return p;
}

node * delete_binary_tree(node *p)
{
	if (p->left_child!=NULL)
		p->left_child=delete_binary_tree(p->left_child);
	if (p->right_child!=NULL)
		p->right_child=delete_binary_tree(p->right_child);
	delete p;
	return NULL;
}

node * pre_order_traverse(node *p)
{
	cout << p->data << ' ';
	if (p->left_child!=NULL)
		p->left_child=pre_order_traverse(p->left_child);
	if (p->right_child!=NULL)
		p->right_child=pre_order_traverse(p->right_child);
	return p;
}

node * in_order_traverse(node *p)
{
	if (p->left_child!=NULL)
		p->left_child=in_order_traverse(p->left_child);
	cout << p->data << ' ';
	if (p->right_child!=NULL)
		p->right_child=in_order_traverse(p->right_child);
	return p;
}

node * post_order_traverse(node *p)
{
	if (p->left_child!=NULL)
		p->left_child=post_order_traverse(p->left_child);
	if (p->right_child!=NULL)
		p->right_child=post_order_traverse(p->right_child);
	cout << p->data << ' ';
	return p;
}

