//#include "pch.h"
#include <iostream>
#include <climits>//INT_MAX
#include <stack>
using namespace std;
void show_graph(const int number_of_vertex, const char vertex[], int **adjacency_matrix);//两个**的话用const很复杂
void find_the_shortest_path(const int number_of_vertex, const char vertex[], int **adjacency_matrix, const int number_of_starting_vertex);
int main()
{
	cout << "Please input the number of vertexes : ";
	int number_of_vertex;
	cin >> number_of_vertex;//结点个数
	cin.get();
	if (number_of_vertex <= 0)
	{
		cout << "Your input is wrong." << endl;
		return 0;
	}
	char * vertex = new char[number_of_vertex];//用来存放结点的数据
	cout << "Please input the vertexex : ";
	for (int i = 0; i < number_of_vertex; ++i)
	{
		vertex[i] = cin.get();
		if (vertex[i] == ' ' || vertex[i] == '	' || vertex[i] == '\n')
			--i;
	}
	cin.get();
	cout << "Please input the adjacency matrix : " << endl;
	int ** adjacency_matrix = new int*[number_of_vertex];//创建动态二维数组的第一维
	for (int i = 0; i < number_of_vertex; ++i)
		adjacency_matrix[i] = new int[number_of_vertex]; //分配第二维，每一行的空间。
	for (int i = 0; i < number_of_vertex; ++i)
		for (int j = 0; j < number_of_vertex; ++j)
		{
			cin >> adjacency_matrix[i][j];
			if (adjacency_matrix[i][j] <= 0)
				adjacency_matrix[i][j] = INT_MAX;
		}
	cin.get();
	cout << "Please input the starting vertex : ";
	char starting_vertex;
	starting_vertex = cin.get();
	int number_of_starting_vertex = -1;
	for (int i = 0; i < number_of_vertex; ++i)
		if (starting_vertex == vertex[i])
		{
			number_of_starting_vertex = i;
			break;
		}
	if (-1 == number_of_starting_vertex)
	{
		cout << "You input is wrong, there is no such vertex." << endl;
		return 0;
	}
	//show_graph(number_of_vertex,vertex,adjacency_matrix);//测试用，输出图的邻接矩阵和节点数据 
	find_the_shortest_path(number_of_vertex, vertex, adjacency_matrix, number_of_starting_vertex);
	for (int i = 0; i < number_of_vertex; ++i)
		delete[] adjacency_matrix[i];//释放每个第二维的空间
	delete[] adjacency_matrix;//释放第一维
	delete[] vertex;
	return 0;
}

void show_graph(const int number_of_vertex, const char vertex[], int **adjacency_matrix)
{
	cout << "-------------------------" << endl;
	for (int i = 0; i < number_of_vertex; ++i)
		cout << vertex[i] << ' ';
	cout << endl;
	for (int i = 0; i < number_of_vertex; ++i)
	{
		for (int j = 0; j < number_of_vertex; ++j)
			if (INT_MAX == adjacency_matrix[i][j])
				cout << "∞" << ' ';
			else
				cout << adjacency_matrix[i][j] << ' ';
		cout << endl;
	}
	cout << "-------------------------" << endl;
}

void find_the_shortest_path(const int number_of_vertex, const char vertex[], int **adjacency_matrix, const int number_of_starting_vertex)
{
	int * shortest_path = new int[number_of_vertex];//shortest_path表示最短路径 
	bool *flag = new bool[number_of_vertex];
	int *p = new int[number_of_vertex];
	for (int i = 0; i < number_of_vertex; ++i)
	{
		shortest_path[i] = adjacency_matrix[number_of_starting_vertex][i]; //初始化起点starting_vertex到其他各个顶点的最短路径长度
		flag[i] = false;
		if (shortest_path[i] == INT_MAX)
			p[i] = -1;//源点u到该顶点的路径长度为无穷大，说明顶点i与起点starting_vertex不相邻
		else
			p[i] = number_of_starting_vertex;//说明顶点i与起点starting_vertex相邻，设置顶点i的前驱p[i]=number_of_starting_vertex
	}
	shortest_path[number_of_starting_vertex] = 0;
	flag[number_of_starting_vertex] = true;//初始时，集合S中只有一个元素：起点 starting_vertex
	for (int i = 0; i < number_of_vertex; ++i)
	{
		int temp = INT_MAX, t = number_of_starting_vertex;
		for (int j = 0; j < number_of_vertex; j++) //在集合V-S中寻找距离源点u最近的顶点t
			if (!flag[j] && shortest_path[j] < temp)
			{
				t = j;
				temp = shortest_path[j];
			}
		if (t == number_of_starting_vertex)
			break; //找不到t，跳出循环
		flag[t] = true;  //否则，将t加入集合
		for (int j = 0; j < number_of_vertex; ++j)//更新集合V-S中与t邻接的顶点到源点u的距离
			if (!flag[j] && adjacency_matrix[t][j] < INT_MAX)//!s[j]表示j在V-S中  
				if (shortest_path[j] > (shortest_path[t] + adjacency_matrix[t][j]))
				{
					shortest_path[j] = shortest_path[t] + adjacency_matrix[t][j];
					p[j] = t;
				}
	}
	int x;
	stack <int> s;//利用C++自带的函数创建一个栈s，需要程序头部引入#include<stack>
	cout << "-------------------------" << endl;
	for (int i = 0; i < number_of_vertex; i++)
	{
		x = p[i];
		while (x != -1)
		{
			s.push(x);//将前驱依次压入栈中
			x = p[x];
		}
		cout << vertex[i] << " (" << shortest_path[i] << ") : ";
		while (!s.empty())
		{
			cout << vertex[s.top()] << " ";//依次取栈顶元素
			s.pop();//出栈
		}
		cout << vertex[i] << endl;
	}
	delete[] p;
	delete[] shortest_path;
	delete[] flag;
}
/* example 1:
Please input the number of vertexes : 5
Please input the vertexex : a b c d e
Please input the adjacency matrix :
-1 5 -1 7 15
-1 -1 5 -1 -1
-1 -1 -1 -1 1
-1 -1 2 -1 -1
-1 -1 -1 -1 -1
Please input the starting vertex : a
-------------------------
a (0) : a
b (5) : a b
c (9) : a d c
d (7) : a d
e (10) : a d c e
*/

/* example 2:
Please input the number of vertexes : 5
Please input the vertexex : a b c d e
Please input the adjacency matrix :
-1 16 15 -1 12
29 -1 -1 13 -1
21 -1 -1 7 -1
-1 27 19 -1 -1
8 32 -1 -1 -1
Please input the starting vertex : e
-------------------------
a (8) : e a
b (24) : e a b
c (23) : e a c
d (30) : e a c d
e (0) : e
*/
