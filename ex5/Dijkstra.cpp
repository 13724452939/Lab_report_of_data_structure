#include <iostream>
#include<stack>
using namespace std;
const int N = 100; // 城市的个数可修改
const int INF = 1e7; // 初始化无穷大为10000000
int map[N][N],dist[N],p[N],n,m;//n城市的个数，m为城市间路线的条数，map为邻接矩阵，dist为最短距离 
bool flag[N]; //如果flag[i]等于true，说明顶点i已经加入到集合S;否则顶点i属于集合V-S
void findpath(int u);//用栈来找路径上的点 
void Dijkstra(int u);//找最短路径 

int main()
{
    int u,v,w,st;
	cout << "请输入城市的个数："<<endl;
    cin >> n;//n城市的个数
    cout << "请输入城市之间的路线的个数："<<endl;
    cin >>m;//路线个数m 
    cout << "请输入城市之间的路线以及距离："<<endl;
    for(int i=0;i<n;i++)//初始化图的邻接矩阵
    	for(int j=0;j<n;j++)
            map[i][j]=INF;//初始化邻接矩阵为无穷大
    while(m--)
    {
        cin >> u >> v >> w;
        map[u-1][v-1] =min(map[u-1][v-1],w); //邻接矩阵储存，保留最小的距离
    }
    cout <<"请输入小明所在的位置："<<endl;
    cin >> st;//st为起始点  ,st为1即数组中的0 
    Dijkstra(st-1);//求最短路径 
    cout <<"小明所在的位置："<<st<<endl;
    for(int i=0;i<n;i++)
	{
    	cout <<"小明："<<st<<" - "<<"要去的位置："<<i+1<<endl;
   		if(dist[i] == INF)
        	cout << "sorry,无路可达"<<endl;
    	else
			cout << "最短距离为:"<<dist[i]<<endl;
    }
    findpath(st-1);
    return 0;
   }
  
void Dijkstra(int u)//u==st-1
{
	for(int i=0; i<n; i++)
	{
    	dist[i] =map[u][i]; //初始化源点u到其他各个顶点的最短路径长度
    	flag[i]=false; 
    	if(dist[i]==INF)
    		p[i]=-1; //源点u到该顶点的路径长度为无穷大，说明顶点i与源点u不相邻
    	else
    		p[i]=u; //说明顶点i与源点u相邻，设置顶点i的前驱p[i]=u
    }
    dist[u] = 0;
    flag[u]=true;   //初始时，集合S中只有一个元素：源点u
    for(int i=0; i<n; i++)
    {
        int temp = INF,t = u;
        for(int j=0; j<n; j++) //在集合V-S中寻找距离源点u最近的顶点t
        if(!flag[j]&&dist[j]<temp)
        {
            t=j;
            temp=dist[j];
        }
        if(t==u) return ; //找不到t，跳出循环
        flag[t]= true;  //否则，将t加入集合
        for(int j=0;j<n;j++)//更新集合V-S中与t邻接的顶点到源点u的距离
            if(!flag[j]&& map[t][j]<INF)//!s[j]表示j在V-S中  
            	if(dist[j]>(dist[t]+map[t][j]))
                {
                	dist[j]=dist[t]+map[t][j] ;
                	p[j]=t ;
                }
    }
}
void findpath(int u)
{
	int x;
	stack<int>s;//利用C++自带的函数创建一个栈s，需要程序头部引入#include<stack>
	cout<<"源点为："<<u+1<<endl;
	for(int i=0;i<n;i++)
	{
		x=p[i];
		while(x!=-1)
		{
    		s.push(x);//将前驱依次压入栈中
	  		x=p[x];
    	}
    	cout<<"源点到其他各顶点最短路径为：";
    	while(!s.empty())
    	{
			cout<<(s.top()+1)<<"——";//依次取栈顶元素
			s.pop();//出栈
    	}
    	cout<<i+1<<";最短距离为："<<dist[i]<<endl;
	}
}  

/*
请输入城市的个数：
5
请输入城市之间的路线的个数：
11
请输入城市之间的路线以及距离：
1 5 12
5 1 8
1 2 16
2 1 29
5 2 32
2 4 13
4 2 27
1 3 15
3 1 21
3 4 7
4 3 19
请输入小明所在的位置：
5
小明所在的位置：5
小明：5 - 要去的位置：1
最短距离为:8
小明：5 - 要去的位置：2
最短距离为:24
小明：5 - 要去的位置：3
最短距离为:23
小明：5 - 要去的位置：4
最短距离为:30
小明：5 - 要去的位置：5
最短距离为:0
源点为：5
源点到其他各顶点最短路径为：5——1;最短距离为：8
源点到其他各顶点最短路径为：5——1——2;最短距离为：24
源点到其他各顶点最短路径为：5——1——3;最短距离为：23
源点到其他各顶点最短路径为：5——1——3——4;最短距离为：30
源点到其他各顶点最短路径为：5;最短距离为：0
*/
	
